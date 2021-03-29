#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    setMouseTracking(true);
}

//鼠标进入
void myLabel::enterEvent(QEvent *event){
    qDebug() << "鼠标进入了";
}

//鼠标离开
void myLabel::leaveEvent(QEvent *event){
    qDebug() << "鼠标离开了";
}


//鼠标移动
void myLabel::mouseMoveEvent(QMouseEvent *ev){
    QString str = QString("鼠标移动了 x = %1, y = %2").arg(ev->x()).arg(ev->y());
    this->setText(str);
//    qDebug() << str;
}

//鼠标按下
void myLabel::mousePressEvent(QMouseEvent *ev){
    //globalX指的是相对桌面左上角
    if(ev->button() == Qt::LeftButton)
    {
        QString str = QString("鼠标左键按下了 x = %1, y = %2 globalX=%3").arg(ev->x()).arg(ev->y()).arg(ev->globalX());
        this->setText(str);
    }
    else if(ev->button() == Qt::MidButton)
    {
        QString str = QString("鼠标中键按下了 x = %1, y = %2 globalX=%3").arg(ev->x()).arg(ev->y()).arg(ev->globalX());
        this->setText(str);
    }
    else{
        QString str = QString("鼠标右键按下了 x = %1, y = %2 globalX=%3").arg(ev->x()).arg(ev->y()).arg(ev->globalX());
        this->setText(str);
    }
}

//鼠标释放
void myLabel::mouseReleaseEvent(QMouseEvent *ev){
    this->setText("鼠标释放了");
}

//QEvent事件分发器
bool myLabel::event(QEvent *e){
    if(e->type() == QEvent::MouseButtonPress){
        QMouseEvent *ev = static_cast<QMouseEvent *>(e);//C++静态类型转换
        if(ev->button() == Qt::LeftButton)
        {
            QString str = QString("鼠标左键按下了 x = %1, y = %2 globalX=%3").arg(ev->x()).arg(ev->y()).arg(ev->globalX());
            this->setText(str);
        }
        else if(ev->button() == Qt::MidButton)
        {
            QString str = QString("鼠标中键按下了 x = %1, y = %2 globalX=%3").arg(ev->x()).arg(ev->y()).arg(ev->globalX());
            this->setText(str);
        }
        else{
            QString str = QString("鼠标右键按下了 x = %1, y = %2 globalX=%3").arg(ev->x()).arg(ev->y()).arg(ev->globalX());
            this->setText(str);
        }

        return true;//true表示用户自己处理这个事件 不向下分发
    }

    return QLabel::event(e); //其他事件，交给父类处理，默认处理
}
