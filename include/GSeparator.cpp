#include "GSeparator.h"

GSeparator::GSeparator(QWidget* parent)
    :QLabel(parent)
{
    setObjectName("G_separator");
    setStyleSheet(QString("QLabel {background: #C5C5C5;}"));
}

GSeparator::~GSeparator()
{

}
