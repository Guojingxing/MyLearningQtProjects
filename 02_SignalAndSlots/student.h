#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);
    int i;
signals:

public slots:
    //早期Qt版本必须写到这下面，高级版本可以写到public下，或者全局下
    //返回值是void，需要声明也需要实现
    //可以有参数，可以发生重载
    void treat();

    void treat(QString foodName);
};

#endif // STUDENT_H
