#include "SingleApp.h"

#define TIME_OUT  500 

SingleApp::SingleApp(int &argc, char **argv)
	: QApplication(argc, argv)
	, w(NULL)
	, m_isRunning(false)
	, m_localServer(NULL) {
	m_serverName = QFileInfo(QCoreApplication::applicationFilePath()).fileName();
	initLocalConnection();
}

bool SingleApp::isRunning() {
	return m_isRunning;
}

void SingleApp::newLocalConnection() {
	QLocalSocket *socket = m_localServer->nextPendingConnection();
	if(socket){
		socket->waitForReadyRead(2*TIME_OUT);
		delete socket;
		activateWindow();
	}
}

void SingleApp::initLocalConnection() {
	QLocalSocket socket;
	socket.connectToServer(m_serverName);
	if(socket.waitForConnected(TIME_OUT)) {
		fprintf(stderr, "%s already running.\n", m_serverName.toLocal8Bit().constData());
		m_isRunning = true;
		return;
	}
	newLocalServer();
}

void SingleApp::newLocalServer() {
	m_localServer = new QLocalServer(this);
	connect(m_localServer, SIGNAL(newConnection()), this, SLOT(newLocalConnection()));
	if(!m_localServer->listen(m_serverName)) {
		if(m_localServer->serverError() == QAbstractSocket::AddressInUseError) {
			QLocalServer::removeServer(m_serverName);
			m_localServer->listen(m_serverName);
		}
	}
}




void SingleApp::activateWindow() {
	if(w){
		w->show();
		w->raise();
		w->activateWindow(); // 激活窗口
	}
}
