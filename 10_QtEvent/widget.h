#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimeEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    void timerEvent(QTimerEvent *te);
    int id1;
    int id2;
    QTimeEdit *timeEdit;

signals:
    void moveEvent(QMoveEvent *event);

public slots:
    void changeTime();
};
#endif // WIDGET_H
