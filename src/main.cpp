#include "MainWidget.h"

int main(int argc, char **argv)
{
	QApplication a(argc, argv);
	MainWidget w;
//	w.setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
	w.show();
	return a.exec();
}
