#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QDateTime>
#include <QCalendarWidget>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    id1 = startTimer(1000);//每隔1秒，返回值是定时器唯一标识

    id2 = startTimer(2000);//每隔2秒

    //定时器第二种方式
    QTimer * timer = new QTimer(this);
    timer->start(500);
    connect(timer, &QTimer::timeout, [=](){
        static int num = 1;
        ui->label_4->setText(QString::number(num++));
    });

    connect(ui->btn_pause, &QPushButton::clicked,[=](){
        if(timer->isActive())
        {
            timer->stop();
            ui->btn_pause->setText("继续");
        }
        else{
            timer->start();
            ui->btn_pause->setText("暂停");
        }
    });

    timeEdit = new QTimeEdit(this);
    timeEdit->setGeometry(QRect(50,10,150,25));
    QDateTime sysTime = QDateTime::currentDateTime();
    QStringList list = sysTime.toString("hh:mm:ss").split(':');
    timeEdit->setTime(QTime(list[0].toInt(),list[1].toInt(),list[2].toInt()));

    ui->calendarWidget->setSelectedDate(QDate::currentDate());
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    connect(ui->calendarWidget, &QCalendarWidget::selectionChanged,ui->dateTimeEdit,[=](){
        ui->dateTimeEdit->setDate(ui->calendarWidget->selectedDate());
        ui->dateTimeEdit->setTime(QTime::currentTime());
    });
    connect(ui->dateTimeEdit, &QDateTimeEdit::dateChanged,ui->calendarWidget,[=](){
        ui->calendarWidget->setSelectedDate(ui->dateTimeEdit->date());
    });

    //输出选中的日期
    connect(ui->calendarWidget, &QCalendarWidget::selectionChanged,[=](){
        qDebug() << ui->calendarWidget->selectedDate().toString("yyyy-MM-dd").toUtf8().data();
    });

    //输出选中的日期时间
    connect(ui->dateTimeEdit, &QDateTimeEdit::dateTimeChanged,[=](){
        ui->label->setText(ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd HH:mm:ss"));
    });

    //实时显示系统时间
    QTimer * currentTimer = new QTimer(this);
    currentTimer->start(1000);
    connect(currentTimer, &QTimer::timeout, this, &Widget::changeTime);
}

void Widget::timerEvent(QTimerEvent *ev){
    static int num = 1;
    if(ev->timerId() == id1)
        ui->label_2->setText(QString::number(num++));
    static int num2 = 1;
    if(ev->timerId() == id2)
        ui->label_3->setText(QString::number(num2++));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeTime(){
    QDateTime dateTime = QDateTime::currentDateTime();
    QString str = "当前系统时间："+dateTime.toString("yyyy-MM-dd HH:mm:ss dddd");
    ui->label_5->setText(str);
}
