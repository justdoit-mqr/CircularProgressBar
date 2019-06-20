#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //ui->widget->setStyleSheet("border-image:url(./images/1.png)");
    //圆形进度条1
    circularProgressBar = new CircularProgessBar();
    //圆形进度条2
    circularProgressBar2 = new CircularProgessBar();
    circularProgressBar2->setCircleRatio(0.85);
    circularProgressBar2->setCirclePen(QPen(QBrush("#C6C6C6"),2));
    circularProgressBar2->setCircleBrush(QBrush("#FFFFFF"),QBrush("#636363"));
    circularProgressBar2->setArcPenBrush(QBrush("#2FB8E6"));
    circularProgressBar2->setTextProperty(QColor("#FFFFFF"),QFont("",16));
    //圆形进度条3
    circularProgressBar3 = new CircularProgessBar();
    circularProgressBar3->setCircleRatio(0.3,0.8,0.7);
    circularProgressBar3->setCircleBrush(QBrush("#373737"),QBrush("#212121"));
    circularProgressBar3->setArcPenBrush(QBrush("#816BCF"));
    circularProgressBar3->setTextProperty(QColor("#816BCF"),QFont("",18));
    //圆形进度条4
    circularProgressBar4 = new CircularProgessBar();
    circularProgressBar4->setCircleBrush(QBrush("#898989"),QBrush("#2C2C2C"));
    circularProgressBar4->setArcPenBrush(QBrush("#3BFF00"));
    circularProgressBar4->setTextProperty(QColor("#FFFFFF"),QFont("",18));
    QVector<qreal> dashs;
    dashs<<0.43<<0.42;
    circularProgressBar4->setArcPenDashPattern(dashs);
    //圆形进度条5
    circularProgressBar5 = new CircularProgessBar();
    circularProgressBar5->setCircleBrush(QBrush("#FFFFFF"),QBrush("#FFFFFF"));
    circularProgressBar5->setTextProperty(QColor("#000000"),QFont("",18));
    QVector<qreal> dashs5;
    dashs5<<0.43<<0.42;
    circularProgressBar5->setArcPenDashPattern(dashs5,true);
    //圆形进度条6
    circularProgressBar6 = new CircularProgessBar();
    QConicalGradient conicalGrad;
    conicalGrad.setAngle(90);
    conicalGrad.setColorAt(1.0, Qt::red);
    conicalGrad.setColorAt(0.8, Qt::yellow);
    conicalGrad.setColorAt(0.6, Qt::green);
    conicalGrad.setColorAt(0.4, Qt::cyan);
    conicalGrad.setColorAt(0.2, Qt::blue);
    conicalGrad.setColorAt(0, Qt::magenta);
    circularProgressBar6->setArcPenGradient(conicalGrad);

    ui->gridLayout->addWidget(circularProgressBar,0,0,1,1);
    ui->gridLayout->addWidget(circularProgressBar2,0,1,1,1);
    ui->gridLayout->addWidget(circularProgressBar3,0,2,1,1);
    ui->gridLayout->addWidget(circularProgressBar4,1,0,1,1);
    ui->gridLayout->addWidget(circularProgressBar5,1,1,1,1);
    ui->gridLayout->addWidget(circularProgressBar6,1,2,1,1);
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(setCircleProgressBar(int)));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::setCircleProgressBar(int value)
{
    qreal tmpValue = value/10.0;
    QString text = QString::number(tmpValue,'f',1).append("%");

    circularProgressBar->setProgressValue(tmpValue);
    circularProgressBar->setText(text);

    circularProgressBar2->setProgressValue(tmpValue);
    circularProgressBar2->setText(text.append("\nBrightness"));

    QString text3 = QString::number(tmpValue,'f',1);
    circularProgressBar3->setProgressValue(tmpValue);
    circularProgressBar3->setText(text3);

    text3.replace(text3.size()-2,2,"%");
    circularProgressBar4->setProgressValue(tmpValue);
    circularProgressBar4->setText(text3);

    circularProgressBar5->setProgressValue(tmpValue);
    circularProgressBar5->setText(text3);

    circularProgressBar6->setProgressValue(tmpValue);
    circularProgressBar6->setText(text3);
}
