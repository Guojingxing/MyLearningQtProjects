#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>
#include <QSpinBox>
#include <QColorDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //stackWidget使用
    //设置默认定位到scrollArea
    ui->stackedWidget->setCurrentIndex(0);
    //toolBox按钮
    connect(ui->btn_toolBox, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    //scrollArea按钮
    connect(ui->btn_scrollArea, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    //tabWidget按钮
    connect(ui->btn_tabWidget, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    //下拉框
    QStringList list ;
    list << "wangximing" << "leiyangjuan" << "wangwuhong";
    ui->comboBox->addItems(list);

    //为下拉框设置默认值
    connect(ui->btn_choose, &QPushButton::clicked, [=](){
        //ui->comboBox->setCurrentIndex(2);
        ui->comboBox->setCurrentText("wangwuhong");//必须是下拉框里有的
    });

    //字体选择栏 打印字体
    connect(ui->fontComboBox, &QFontComboBox::currentFontChanged, [=](){
        QFont font = ui->fontComboBox->currentFont();
        qDebug() << font.family().toUtf8().data();
    });

    //选择字体 然后设置到textEdit中
    //text Edit是富文本框 plain text edit是纯文本框
    ui->textEdit->setFontPointSize(15);//设置文本框默认字体大小
    connect(ui->fontComboBox, &QFontComboBox::currentFontChanged, [=](){
        QFont font = ui->fontComboBox->currentFont();
        ui->textEdit->setFontFamily(font.family());
    });

    //设置默认字体大小
    ui->spinBox->setValue(15);
    ui->spinBox->setRange(10,50);
    //为textEdit设置字体大小
    connect(ui->spinBox, QOverload<int>::of(&QSpinBox::valueChanged), [=](int i){
        i = ui->spinBox->value();
        ui->textEdit->setFontPointSize(i);
    });

    //为textEdit设置字体颜色
    connect(ui->btn_color, &QPushButton::clicked,[=](){
        QColor color = QColorDialog::getColor();
        ui->textEdit->setTextColor(color);
    });

    //打印文本框中的内容到控制台
    connect(ui->btn_debug, &QPushButton::clicked, [=](){
        QTextCursor cursor = ui->textEdit->textCursor();//获取文本闪动的光标
        qDebug() << cursor.selectedText();//获取选中的文本
        qDebug() << cursor.anchor();//获取锚点所在位置（第一个字之前是0）
        qDebug() << cursor.atEnd();//光标是否在最后
    });

    //利用QLabel显示图片
    QPixmap img = QPixmap(":/icon.jpg");
    ui->lbl_image->setPixmap(img.scaledToWidth(ui->lbl_image->width()));

}
Widget::~Widget()
{
    delete ui;
}
