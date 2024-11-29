#include "mainwindow.h"
#include "page_login.h"

#include <QApplication>
#include "mysql.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    mysql mydatabase;
    return a.exec();
}
