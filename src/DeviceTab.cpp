#include "DeviceTab.h"

DeviceTab :: DeviceTab(QWidget *parent)
	: QWidget(parent)
	,mDeviceListWidget(NULL)
	,mDeviceListArea(NULL)
	,mScanState(STOP)
{
	initLayout();
	initSignalAndSlot();
	resize(DEVICETAB_WIDTH, DEVICETAB_HEIGHT);
}

DeviceTab :: ~DeviceTab()
{
}

void DeviceTab :: initLayout()
{
    m_mDNS = qMDNS::getInstance();

    mDeviceListWidget = new QListWidget();
	mDeviceListWidget->resize(DEVICETAB_WIDTH-2, DEVICETAB_HEIGHT-2);
	
	mDeviceListArea = new QScrollArea(this);
	mDeviceListArea->setGeometry(0, 0, DEVICETAB_WIDTH, DEVICETAB_HEIGHT);
	mDeviceListArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	mDeviceListArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	mDeviceListArea->setWidget(mDeviceListWidget);
}

void DeviceTab :: initSignalAndSlot()
{
    connect(m_mDNS, SIGNAL(refreshSignal(DEVICE_INFO)), this, SLOT(refresh(DEVICE_INFO)));
}

void DeviceTab :: refresh(DEVICE_INFO deviceInfo)
{
	if(mScanState == STOP) {
		return;
	}
    QList<QListWidgetItem *> list = mDeviceListWidget->findItems(deviceInfo.macAddr, Qt::MatchExactly);
    if(list.isEmpty()) {
        DeviceItem *devItem = new DeviceItem(this);
        devItem->setDeviceInfo(deviceInfo);
        QListWidgetItem *item = new QListWidgetItem(deviceInfo.macAddr);
        item->setFont(QFont("Times", 1, QFont::Normal));
        item->setTextColor(QColor(255, 255, 255));
        item->setSizeHint(QSize(DEVICEITEM_WIDTH, DEVICEITEM_HEIGHT));
        mDeviceListWidget->addItem(item);
        mDeviceListWidget->setItemWidget(item, devItem);
    } else {
        QListWidgetItem *item = list.first();
        DeviceItem *devItem = (DeviceItem *)mDeviceListWidget->itemWidget(item);
        devItem->setDeviceInfo(deviceInfo);
    }
    emit refreshTotalCount(mDeviceListWidget->count());
}

void DeviceTab :: clearList()
{
    mDeviceListWidget->clear();
    emit refreshTotalCount(0);
}

void DeviceTab :: setScanState(int state)
{
	mScanState = state;
}
