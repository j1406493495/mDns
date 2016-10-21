#ifndef __LOADING_H__
#define __LOADING_H__

#include "Common.h"

class Loading : public QLabel
{
	Q_OBJECT
	public:
        Loading();
		~Loading();
		void start();
		void stop();
        static Loading* instance();

	private:
        static Loading *mInstance;
		QMovie *mLoadingMovie;
};

#endif
