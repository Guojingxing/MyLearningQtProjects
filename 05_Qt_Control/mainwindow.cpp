#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QListWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->radioButton->setChecked(true);

    i = 0;
    //选中女后 打印信息
    connect(ui->radioButton_2, &QRadioButton::clicked, [=](){
        qDebug() << "Female checked!" << i;
        i++;
    });

    //状态state = 1全选 1半选 0不选
    connect(ui->checkBox_4, &QCheckBox::clicked, [=](int state){
        qDebug() << state;
    });
    connect(ui->checkBox_3, &QCheckBox::clicked, [=](int state){
        qDebug() << state;
    });

    QListWidgetItem *item = new QListWidgetItem("锄禾日当午");
    //添加一个元素
    ui->listWidget->addItem(item);

    QStringList list;
    list << "汗滴禾下土" << "谁知盘中餐" << "粒粒皆辛苦";
    //添加多个元素
    ui->listWidget->addItems(list);
    for (i=0;i<4;i++) {
        //设置列表内文本居中
        ui->listWidget->item(i)->setTextAlignment(Qt::AlignHCenter);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

