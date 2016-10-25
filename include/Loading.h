#ifndef __LOADING_H__
#define __LOADING_H__

#include "Common.h"

class Loading : public QLabel
{
	Q_OBJECT
	public:
        Loading(QWidget *parent);
		~Loading();
		void start();
		void stop();

	private:
		QMovie *mLoadingMovie;
};

#endif
