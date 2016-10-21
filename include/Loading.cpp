#include "Loading.h"

Loading* Loading :: mInstance = NULL;

Loading :: Loading()
    : QLabel()
    ,mLoadingMovie(NULL)
{
	mLoadingMovie = new QMovie("./pic/loading.gif");
    setMovie(mLoadingMovie);
    setFixedSize(100, 100);
    QDesktopWidget *desktop = QApplication::desktop();
    move((desktop->width() - width()) / 2, (desktop->height() - height()) / 2);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
}

Loading :: ~Loading()
{}

Loading* Loading :: instance()
{
    if(mInstance == NULL) {
        mInstance = new Loading();
    }
    return mInstance;
}

void Loading :: start()
{
	mLoadingMovie->start();
	show();
}

void Loading :: stop()
{
	mLoadingMovie->stop();
	close();
}

