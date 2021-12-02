#include <QApplication>
#include <QDebug>
#include <DragUrl.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DragUrl w;
    w.show();

    return a.exec();
}
