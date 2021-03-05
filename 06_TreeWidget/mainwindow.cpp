#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTreeWidget>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //treeWidget树控件使用

    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList()<<"国家" <<"国家介绍");
    QTreeWidgetItem * ChinaItem = new QTreeWidgetItem(QStringList()<<"中国");
    QTreeWidgetItem * USItem = new QTreeWidgetItem(QStringList()<<"美国");
    QTreeWidgetItem * RussiaItem = new QTreeWidgetItem(QStringList()<<"俄罗斯");
    //加载顶层的节点
    ui->treeWidget->addTopLevelItem(ChinaItem);
    ui->treeWidget->addTopLevelItem(USItem);
    ui->treeWidget->addTopLevelItem(RussiaItem);
    //追加子节点
    QTreeWidgetItem * Beijing = new QTreeWidgetItem(QStringList()<<"北京");
    QTreeWidgetItem * Tianjin = new QTreeWidgetItem(QStringList()<<"天津");
    QTreeWidgetItem * Shanghai = new QTreeWidgetItem(QStringList()<<"上海");
    QTreeWidgetItem * Shenzhen = new QTreeWidgetItem(QStringList()<<"深圳");
    QList<QTreeWidgetItem * > children;
    children.append(Beijing);
    children.append(Tianjin);
    children.append(Shanghai);
    ChinaItem->addChildren(children);
    ChinaItem->addChild(Shenzhen);

}

MainWindow::~MainWindow()
{
    delete ui;
}

