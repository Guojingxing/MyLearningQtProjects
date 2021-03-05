#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionNew->setIcon(QIcon(":/icon.jpg"));

    //点击新建按钮 弹出一个对话框
    connect(ui->actionNew, &QAction::triggered,[=](){
        //对话框 分类
        //模态对话框(不可以对其他窗口进行操作)
        //模态创建 阻塞功能
        QDialog dlg(this);
        dlg.resize(200,100);
        dlg.exec();

        qDebug() << "模态对话框弹出了";

    });
    connect(ui->actionNew2, &QAction::triggered,[=](){
        //非模态对话框(可以对其他窗口进行操作)
        QDialog * dlg2 = new QDialog(this);
        dlg2->setWindowIcon(QIcon(":/icon.jpg"));
        dlg2->resize(200,100);
        dlg2->show();
        dlg2->setAttribute(Qt::WA_DeleteOnClose); //55号 属性
        qDebug() << "非模态对话框弹出了";
    });
    //消息对话框
    //错误对话框
    connect(ui->actionNew3, &QAction::triggered,[=](){
        QMessageBox::critical(this,"critical", "错误");
    });
    //信息对话框
    connect(ui->actionNew4, &QAction::triggered,[=](){
        QMessageBox::information(this,"info", "信息");
    });
    connect(ui->actionNew5, &QAction::triggered,[=](){
        //第五个参数：默认关联回车的按键
        QMessageBox::question(this,"ques", "提问", QMessageBox::Save|QMessageBox::Cancel, QMessageBox::Cancel);
    });

    connect(ui->actionNew6, &QAction::triggered,[=](){

        //颜色对话框
        QColor color = QColorDialog::getColor(QColor(255,0,0));
        qDebug()<<"r = "<< color.red() << "; g = "<< color.green() << "; b = " << color.blue();
    });

    connect(ui->actionOpen, &QAction::triggered, [=](){
        //文件对话框 参数1 父亲  参数2 标题  参数3 默认打开路径  参数4 过滤器
       QString str = QFileDialog::getOpenFileName(this, "打开", "E:\\", "pdf和txt文件(*.pdf;*.txt)");
       qDebug() << str;
    });

    connect(ui->actionFont, &QAction::triggered, [=](){
       //字体对话框
        bool flag;
       QFont font = QFontDialog::getFont(&flag, QFont("幼圆",32,10,true));
       qDebug() << "Font: " << font.family().toUtf8().data() << "; size:"<<font.pointSize() << "; isBold:" << font.bold() << "; isItalic:" << font.italic();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

