#include "smallwidget.h"
#include "ui_smallwidget.h"

smallWidget::smallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::smallWidget)
{
    ui->setupUi(this);

    //QSpinBox移动 QSlider跟着移动
    ui->spinBox->setRange(0,300);
    void(QSpinBox:: * spSignal )(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, spSignal,ui->horizontalSlider, &QSlider::setValue);

    //QSlider滑动 QSpinBox跟着改变
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);

}

smallWidget::~smallWidget()
{
    delete ui;
}

void smallWidget::setNum(int num){
    ui->spinBox->setValue(num);
}

int smallWidget::getNum(){
    return ui->spinBox->value();
}
