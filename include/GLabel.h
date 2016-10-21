#ifndef G_LABEL_H
#define G_LABEL_H

#include "Common.h"

typedef enum
{
    LABEL_FONT_TINY = 10,
    LABEL_FONT_SMALL = 10,
    LABEL_FONT_MIDDLE = 12,
    LABEL_FONT_MIDDLE_BIG = 13,
    LABEL_FONT_BIG = 14,
    LABEL_FONT_GIANT = 16,
    LABEL_FONT_HUGE = 18,
}GLabelFontSize;

class GLabel : public QLabel
{
    Q_OBJECT
public:
    GLabel(QWidget* parent = NULL); 
    GLabel(QString text, QWidget* parent = NULL);
    ~GLabel();

    void setLabelFontSize(GLabelFontSize size);
};

#endif
