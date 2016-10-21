#include "DeviceItem.h"

DeviceItem :: DeviceItem(QWidget *parent)
    : QWidget(parent)
	,mIsMasterLabel(NULL)
	,mDeviceNameLabel(NULL)
	,mMacLabel(NULL)
	,mIPAddrLabel(NULL)
	,mLinkLabel(NULL)
{
	initLayout();
	initSignalAndSlot();
	resize(DEVICEITEM_WIDTH, DEVICEITEM_HEIGHT);
}

DeviceItem :: ~DeviceItem()
{
}

void DeviceItem :: initLayout()
{
	mDeviceNameLabel = new GLabel(this);
	mDeviceNameLabel->setGeometry(80, 0, 100, DEVICEITEM_HEIGHT / 2);
	mDeviceNameLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

	mIsMasterLabel = new GLabel(this);
	mIsMasterLabel->setGeometry(180, 0, 100, DEVICEITEM_HEIGHT / 2);
	mIsMasterLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	
	GLabel *macLabel = new GLabel("MAC:", this);
	macLabel->setGeometry(80, 30, 50, DEVICEITEM_HEIGHT / 2);
	macLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

	mMacLabel = new GLabel(this);
	mMacLabel->setGeometry(130, 30, 150, DEVICEITEM_HEIGHT / 2);
	mMacLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

	GLabel *ipLabel = new GLabel("IPv4: ", this);
	ipLabel->setGeometry(280, 30, 50, DEVICEITEM_HEIGHT / 2);
	ipLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

	mIPAddrLabel = new GLabel(this);
	mIPAddrLabel->setGeometry(330, 30, 100, DEVICEITEM_HEIGHT / 2);
	mIPAddrLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

	mLinkLabel = new GLabel(this);
	mLinkLabel->setGeometry(500, 0, 150, DEVICEITEM_HEIGHT);
	mLinkLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	mLinkLabel->setOpenExternalLinks(true);

	GSeparator *hsp = new GSeparator(this);
	hsp->setGeometry(0, DEVICEITEM_HEIGHT - 1, DEVICEITEM_WIDTH, 1);
	
	DEVICE_INFO devInfo;
	setDeviceInfo(devInfo);
}


void DeviceItem :: initSignalAndSlot()
{
}

void DeviceItem :: setDeviceInfo(DEVICE_INFO devInfo)
{
	mDeviceNameLabel->setText(devInfo.deviceName);
    mIsMasterLabel->setText(devInfo.isMaster ? "- Master" : "- Slave");
	mMacLabel->setText(devInfo.macAddr);
	mIPAddrLabel->setText(devInfo.IPv4Addr.toString());
    QString url = "<a href=\"https://" + devInfo.IPv4Addr.toString() + "\">Manage Device";
	mLinkLabel->setText(url);
}
