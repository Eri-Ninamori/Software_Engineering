#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_dlglogin.show();
    auto f = [&](){
        this->show();
    };
    connect(&m_dlglogin, &page_login::sendLoginSuccess, this, f);

    ui->treeWidget->setColumnCount(1);
    QStringList l;

    l << "嘉宾信息管理系统";
    QTreeWidgetItem *pf = new QTreeWidgetItem(ui->treeWidget, l);
    ui->treeWidget->addTopLevelItem(pf);

    l.clear();
    l << "嘉宾/接待组";
    QTreeWidgetItem *p1 = new QTreeWidgetItem(pf, l);

    l.clear();
    l << "管理组";
    QTreeWidgetItem *p2 = new QTreeWidgetItem(pf, l);

    pf->addChild(p1);
    pf->addChild(p2);

    ui->treeWidget->expandAll();
    ui->stackedWidget->setCurrentIndex(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
