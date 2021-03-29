#include "widget.h"
#include "ui_widget.h"
#include "smallwidget.h"
#include <QDebug>

widget::widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);

    //按钮获取widget_2中控件的值
    connect(ui->btn_getValue, &QPushButton::clicked, [=](){
        qDebug() << ui->widget_2->getNum();
        qDebug() << ui->widget_3->getNum();
    });

    connect(ui->btn_setToHalf, &QPushButton::clicked, [=](){
        ui->widget_2->setNum(50);
        ui->widget_3->setNum(60);
    });

}

widget::~widget()
{
    delete ui;
}

