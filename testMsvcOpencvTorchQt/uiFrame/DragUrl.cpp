
#include "DragUrl.h"
#include "ui_DragUrl.h"

#include <QDragEnterEvent>
#include <QMimeData>

#include <QDebug>
#include <iostream>

#include <QImage>
#include <QPixmap>
#include <QString>

#include <iostream>
using namespace  std;

DragUrl::DragUrl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DragUrl)
{
    ui->setupUi(this);

    this->setAcceptDrops(true);
}

DragUrl::~DragUrl()
{
    delete ui;
}

void DragUrl::dragEnterEvent(QDragEnterEvent* e)
{
    //dragEnterEvent 进入即相应，dropEvent 鼠标释放相应
    //filter 放行
    qDebug() << __LINE__ << __FUNCTION__;
    if (true)
    {
        e->acceptProposedAction();
    }
}
void DragUrl::dropEvent(QDropEvent* e)
{
    //filepath
    QList<QUrl> urls = e->mimeData()->urls();
    if (urls.isEmpty()) return;
    QString qStr = urls.first().toLocalFile();

    qDebug() << qStr  << __LINE__;
    //根据文件类型来做出对应的表达
    QString suffix = qStr.split(".").last();
    if(suffix == "jpg" || suffix == "png" ){
        QPixmap pixmap;
        pixmap.load(qStr);
        ui->label->setPixmap(pixmap);
    }
    else{
    }

    //cvt char*
    QByteArray qByteArrary = qStr.toLatin1();
    char* filePath = qByteArrary.data();

    qDebug() << __LINE__ << __FUNCTION__;
    cout << filePath << endl;
}



