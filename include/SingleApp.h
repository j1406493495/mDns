#ifndef SingleApp_H
#define SingleApp_H

#include "Common.h"

class SingleApp : public QApplication {
	Q_OBJECT
	public:
		SingleApp(int &argc, char **argv);

		bool isRunning();                // 是否已經有实例在运行
		QWidget *w;                        // MainWindow指针

		private slots:
			// 有新连接时触发
			void newLocalConnection();

	private:
		// 初始化本地连接
		void initLocalConnection();
		// 创建服务端
		void newLocalServer();
		// 激活窗口
		void activateWindow();

		bool m_isRunning;                // 是否已經有实例在运行
		QLocalServer *m_localServer;     // 本地socket Server
		QString m_serverName;            // 服务名称
};

#endif // SingleApp_H
