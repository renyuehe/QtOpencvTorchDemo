#ifndef COMMONHANDLE_H
#define COMMONHANDLE_H

#include <QPixmap>
#include <QString>
#include <QFileInfo>
#include <QFileIconProvider>
//#include <QtWinExtras/QtWinExtras>

#include <QDebug>
#define DBG(x) qDebug()<<__func__<<__LINE__<<x

namespace CommonHandleSpace {

    QPixmap GetFileIcon(QString path);

//    QPixmap GetFileIconEx(QString path);
}

#endif // COMMONHANDLE_H
