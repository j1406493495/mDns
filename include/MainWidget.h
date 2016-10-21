#ifndef __MAIN_WIDGET_H__
#define __MAIN_WIDGET_H__

#include "DeviceTab.h"
#include "DeviceItem.h"
#include "Loading.h"
#include "GSeparator.h"
#include "GLabel.h"
#include "Common.h"

class MainWidget : public QMainWindow
{
	Q_OBJECT
	public :
		MainWidget(QWidget *parent = 0);
		~MainWidget();

	private:
	    qMDNS *m_mDNS;
		DeviceTab *mDeviceTab;
		QPushButton *mScanBtn;
		QPushButton *mClearBtn;
		QPushButton *mSelectNetCardBtn;

        QMenu *mHelpMenu;
        QAction *mAboutAction;

        QTimer *mTimer;

		int mScanState;
        qint64 mLastClickTime;

		void init();
		void initSignalAndSlot();
        void createAction();
        void createMenuBar();
        bool isFastClick();

	signals:
	    void startScan();

	public slots:
		void startSearch();
        void onAction(QAction *);

    private slots:
        void timeUp();
    protected:
        void closeEvent(QCloseEvent*);
};


#endif
