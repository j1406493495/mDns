#include "GLabel.h"

GLabel::GLabel(QWidget* parent)
    :QLabel(parent)
{
    GLabelFontSize size = LABEL_FONT_BIG;
    setProperty("class", "GLabel");
    setStyleSheet(QString(".GLabel {color: #000001; font-size: %1px;}").arg(size));
    setAlignment(Qt::AlignRight | Qt::AlignVCenter);
}

GLabel::GLabel(QString text, QWidget* parent)
    :QLabel(parent)
{
    GLabelFontSize size = LABEL_FONT_BIG;
    setProperty("class", "GLabel");
    setStyleSheet(QString(".GLabel {color: #000001; font-size: %1px;}").arg(size));
    setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    setText(text);
}

void GLabel::setLabelFontSize(GLabelFontSize size)
{
    setStyleSheet(QString(".GLabel {color: black; font-size: %1px;}").arg(size));
}

GLabel::~GLabel()
{

}
