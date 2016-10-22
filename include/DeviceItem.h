#ifndef __DEVICE_ITEM__
#define __DEVICE_ITEM__

#include "Common.h"
#include "GSeparator.h"
#include "GLabel.h"

class DeviceItem : public QWidget
{
	Q_OBJECT
	public:
        DeviceItem(QWidget *parent = 0);
		~DeviceItem();
		int getItemIndex();
		void setDeviceInfo(DEVICE_INFO);
	private:
		GLabel *mIsMasterLabel;
		GLabel *mDeviceNameLabel;
        GLabel *mVersionLabel;
		GLabel *mMacLabel;
		GLabel *mIPAddrLabel;
        GLabel *mLinkLabel;

		void initLayout();
		void initSignalAndSlot();

	signals:

};

#endif
