#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);

    //鼠标进入
    void enterEvent(QEvent *event);

    //鼠标离开
    void leaveEvent(QEvent *event);

    void mouseMoveEvent(QMouseEvent *ev) ;

    void mousePressEvent(QMouseEvent *ev);

    void mouseReleaseEvent(QMouseEvent *ev);

    bool event(QEvent *e);

private slots:


};

#endif // MYLABEL_H
