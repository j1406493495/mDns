#include "MainWidget.h"

static const QString PIC_PATH = "./pic/";
static const QString CLOSE_BTN_PRESSED_PIC = PIC_PATH + "exit_pressed.png";
static const QString CLOSE_BTN_UNPRESSED_PIC = PIC_PATH + "exit.png";
static const QString CLOSE_BTN_HOVER_PIC = PIC_PATH + "exit_hover.png";

MainWidget :: MainWidget(QWidget *parent)
	: QMainWindow(parent)
	,mDeviceTab(NULL)
	,mScanBtn(NULL)
    ,mHelpMenu(NULL)
    ,mAboutAction(NULL)
    ,mTimer(NULL)
	,mScanState(STOP)
    ,mLastClickTime(0)
{
	resize(MAINWINDOW_WIDTH, MAINWINDOW_HEIGHT);
	setFixedSize(width(), height());
	QDesktopWidget *desktop = QApplication::desktop();
	move((desktop->width() - width()) / 2, (desktop->height() - height()) / 2);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    createAction();
    createMenuBar();
    init();
    initSignalAndSlot();
}

MainWidget :: ~MainWidget()
{
}


void MainWidget :: init() 
{
    m_mDNS = qMDNS::getInstance();

	GLabel *headLabel = new GLabel("Discovered Devices", this);
	headLabel->setGeometry(10, 60, 200, 30);
	headLabel->setAlignment(Qt::AlignVCenter);

	mDeviceTab = new DeviceTab(this);
	mDeviceTab->setGeometry(20, 90, DEVICETAB_WIDTH, DEVICETAB_HEIGHT);

    mSelectNetCardBtn = new QPushButton(this);
	mSelectNetCardBtn->setGeometry(MAINWINDOW_WIDTH - 360, MAINWINDOW_HEIGHT - 80, 100, 40);
	mSelectNetCardBtn->setText("select");

	mScanBtn = new QPushButton(this);
	mScanBtn->setGeometry(MAINWINDOW_WIDTH - 240, MAINWINDOW_HEIGHT - 80, 100, 40);
	mScanBtn->setText("Scan");

    mClearBtn = new QPushButton(this);
    mClearBtn->setGeometry(MAINWINDOW_WIDTH - 120, MAINWINDOW_HEIGHT - 80, 100, 40);
    mClearBtn->setText("Clear");

    mTimer = new QTimer(this);
}


void MainWidget :: initSignalAndSlot()
{
	connect(mScanBtn, SIGNAL(clicked()), this, SLOT(startSearch()));
	connect(mClearBtn, SIGNAL(clicked()), mDeviceTab, SLOT(clearList()));
	connect(mSelectNetCardBtn, SIGNAL(clicked()), m_mDNS, SLOT(selectNetCard()));
	connect(this, SIGNAL(startScan()), m_mDNS, SLOT(lookup()));
    connect(menuBar(), SIGNAL(triggered(QAction *)), this, SLOT(onAction(QAction *)));
    connect(mTimer, SIGNAL(timeout()), this, SLOT(timeUp()));
}

void MainWidget :: startSearch()
{
    if (isFastClick()) {
        return;
    }
	switch(mScanState) {
		case STOP:
            Loading::instance()->start();
			mScanBtn->setText("Stop");
			mScanState = SCANNING;
            mTimer->start(1000);
			break;
		case SCANNING:
            Loading::instance()->stop();
			mScanBtn->setText("Scan");
			mScanState = STOP;
            mTimer->stop();
			break;
		default:
            Loading::instance()->stop();
			mScanBtn->setText("Scan");
			mScanState = STOP;
            mTimer->stop();
			break;
	}
	mDeviceTab->setScanState(mScanState);
}

void MainWidget :: createAction() {
    mAboutAction = new QAction("about", this);
    mAboutAction->setFont(QFont("Times", 11));
}

void MainWidget :: createMenuBar() {
    mHelpMenu = menuBar()->addMenu("Help");
    mHelpMenu->addAction(mAboutAction);
}

void MainWidget :: onAction(QAction *action) {
if (action->text() == "about") {
    QMessageBox::about(this, "About GWN Discovery Tool",
        "<h2>GWN Discovery Tool</h2>"
        "<p>Version: 1.0.0.5</p>"
        "<p>Contact Us: www.grandstream.com</p>"
        "<p>CopyRight &copy; 2016 grandstream Inc.</p>");
    }
}

void MainWidget :: timeUp() {
    m_mDNS->logFile(QString("start scan"));
    emit startScan();
}

bool MainWidget :: isFastClick() {
    bool flag = false;
    qint64 curTime = QDateTime::currentDateTime().toMSecsSinceEpoch();
    if (curTime - mLastClickTime < MIN_CLICK_DELAY_TIME) {
        flag = true;
    }
    mLastClickTime = curTime;
    return flag;
}

void MainWidget :: closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);

#if 0
    qWarning() << "reset interface";
    QList<QNetworkInterface> list = m_mDNS->getInterfaceList();
    int count = list.size();
    QString cmd = QString();
    QString interfaceName = QString();
    for (int i=0; i<count; i++)
    {
        QProcess process;
        interfaceName = list[i].humanReadableName();
        cmd = QString("netsh interface set interface \"").append(interfaceName).append(QString("\" enabled"));
        qWarning() << "cmd = " << cmd;
        process.start(cmd);
        process.waitForStarted();
        process.waitForFinished();
    }
#endif
}
