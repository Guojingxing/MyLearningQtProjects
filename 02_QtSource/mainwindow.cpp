#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //添加ui资源步骤
    //将图片文件拷贝到项目位置下
    //右键项目->添加新文件->Qt->Qt resource file ->给资源文件起名
    //res 生成 res.qrc
    //open in editor编辑资源
    //添加前缀 添加文件
    //使用": + 前缀名 + 文件名"
    ui->actionNew->setIcon(QIcon(":/icon.jpg"));
    ui->actionOpen->setIcon(QIcon(":/icon.jpg"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

