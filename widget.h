#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "circularprogessbar.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void setCircleProgressBar(int value);

private:
    Ui::Widget *ui;
    CircularProgessBar *circularProgressBar;
    CircularProgessBar *circularProgressBar2;
    CircularProgessBar *circularProgressBar3;
    CircularProgessBar *circularProgressBar4;
    CircularProgessBar *circularProgressBar5;
    CircularProgessBar *circularProgressBar6;

};

#endif // WIDGET_H
