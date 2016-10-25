#include "Loading.h"

Loading :: Loading(QWidget *parent)
    : QLabel(parent)
    ,mLoadingMovie(NULL)
{
	mLoadingMovie = new QMovie("./pic/loading.gif");
    setMovie(mLoadingMovie);
    setFixedSize(100, 100);
    setAttribute(Qt::WA_TranslucentBackground, true);
}

Loading :: ~Loading()
{}

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

