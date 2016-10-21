#ifndef __DEVICE_TAB__
#define __DEVICE_TAB__

#include "DeviceItem.h"
#include "Common.h"
#include "qMDNS.h"

class DeviceTab : public QWidget
{
	Q_OBJECT
	public: 
		DeviceTab(QWidget *parent = 0);
		~DeviceTab();
		void setScanState(int);

	private:
	    qMDNS *m_mDNS;
        QListWidget *mDeviceListWidget;
		QScrollArea *mDeviceListArea;
		void initLayout();
		void initSignalAndSlot();

		int mScanState;

	public slots:
	    void clearList();
		void refresh(DEVICE_INFO);
};

#endif
