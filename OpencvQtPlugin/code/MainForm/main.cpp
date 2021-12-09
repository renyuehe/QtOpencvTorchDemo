#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

#include <QPluginLoader>
#include <QWidget>
#include <QHBoxLayout>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << INDEXANALY_VERSION_STR << endl; //打印版本号
    MainWindow w;

    w.show();

    return a.exec();
}
