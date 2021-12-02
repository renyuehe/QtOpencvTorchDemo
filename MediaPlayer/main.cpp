#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

//    w.mediaPlayer();
    w.videoPlayer();
    return a.exec();
}
