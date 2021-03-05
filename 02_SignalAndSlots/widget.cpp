#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
//Teacher 类 老师类
//Student 类 学生类

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个学生对象
    this->s = new Student(this);
    //创建一个老师对象
    this->t = new Teacher(this);

    this->btn = new QPushButton;

    btn->setParent(this);
    btn->setText("下课");
    btn->move(10, 10);
    setFixedSize(600,400);

    setWindowTitle("第二个程序");

    //老师饿了，学生请客的有参信号的槽连接
    void (Teacher::*teacherSignal) (QString)= &Teacher::hungry;//地址指向有参函数
    void (Student::*studentSlot) (QString) = &Student::treat;
    connect(t, teacherSignal, s, studentSlot);

    //无参信号
    void (Teacher::*teacherSignal2) (void)= &Teacher::hungry;//地址指向无参函数
    void (Student::*studentSlot2) (void) = &Student::treat;
    connect(t, teacherSignal2, s, studentSlot2);


    //调用下课函数(必须放在connect函数后面)
    //classIsOver();

    //断开连接
    //disconnect(t, teacherSignal, s, studentSlot);
    //disconnect(t, teacherSignal2, s, studentSlot2);

    connect(btn, &QPushButton::clicked, t, teacherSignal2);

    //拓展
    //1.信号可以连接信号
    //2.一个信号可以连接多个槽函数
    //3.多个信号 可以连接 同一个槽函数
    //4.信号和槽函数的参数 必须类型一一对应
    //5.信号和槽的参数个数 是不是要一致？信号的参数个数 可以多于槽函数的参数个数

    //Qt4版本以前的信号和槽连接方式
    //利用Qt4信号槽 连接无参版本
    connect(t, SIGNAL(hungry()), s, SLOT(treat()));

    //Qt4版本 优点，参数直观，缺点，类型不做检测
    //Qt5以上 支持Qt4的版本写法，反之不支持

    //lambda表达式
    [=](){
        btn->setText("abcd");
    }();

    int ref = []()->int{return 1000;}();
    qDebug() << "ref = " << ref;

    QPushButton * btn2 = new QPushButton;
    btn2->setText("close");
    btn2->move(200,0);
    btn2->setParent(this);

    //第三个参数是this，第四个参数是lambda表达式，可以省略第三个参数
    connect(btn2, &QPushButton::clicked, [=](){
        this->close();
    });
    //lambda表达式最常用[=](){};

    QPushButton * openClose = new QPushButton;
    openClose->setParent(this);
    openClose->setText("open");
    openClose->move(100,100);

    QWidget * w2 = new QWidget;

    connect(openClose, &QPushButton::clicked, w2, [=](){
        if(openClose->text()=="open"){
            w2->show();
            openClose->setText("close");
        }
        else{
            w2->hide();
            openClose->setText("open");
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::classIsOver(){
    //下课函数，出发老师饿了的信号，emit + 自定义信号
    emit t->hungry();
    emit t->hungry("宫保鸡丁");
}
