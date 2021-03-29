#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{
    i = 0;
}

void Student::treat(){
    qDebug() << "请老师吃饭";
}

void Student::treat(QString foodName){
    //QString -> char * 先转成 QByteArray ( .toUtf8() )
    //再转成 char * ( 使用 .data() )
    qDebug() << "请老师吃" << foodName.toUtf8().data() << (i++);
}
