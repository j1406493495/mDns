#ifndef __COMMON_H__
#define __COMMON_H__

#include <QWidget>
#include <QDialog>
#include <QTextCodec>
#include <QPushButton>
#include <QDesktopWidget>
#include <QMainWindow>
#include <QApplication>
#include <QList>
#include <QMenu>
#include <QTimer>
#include <QMenuBar>
#include <QMessageBox>
#include <QAction>
#include <QLabel>
#include <QScrollArea>
#include <QMovie>
#include <QVariant>
#include <QApplication>
#include <QListWidget>
#include <QObject>
#include <QSize>
#include <QLocalSocket>
#include <QLocalServer>
#include <QFileInfo>
#include <QListWidgetItem>
#include <QHostAddress>
#include <QUdpSocket>
#include <QHostInfo>
#include <QDateTime>
#include <QSettings>
#include <QDir>
#include <QProcess>
#include <QNetworkInterface>

#define MAINWINDOW_WIDTH 740
#define MAINWINDOW_HEIGHT 500

#define DEVICETAB_WIDTH 700
#define DEVICETAB_HEIGHT 300

#define DEVICEITEM_WIDTH 680
#define DEVICEITEM_HEIGHT 60

#define MIN_CLICK_DELAY_TIME 300

typedef struct device_info {
	QString macAddr;
	QHostAddress IPv4Addr;
	QHostAddress IPv6Addr;
	QString deviceName;
	bool isMaster;
}DEVICE_INFO;

typedef enum {
	STOP = 0,
	SCANNING = 1,
}SCAN_STATE;

#endif
