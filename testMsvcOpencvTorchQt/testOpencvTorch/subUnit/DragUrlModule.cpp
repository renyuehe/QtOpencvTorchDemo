#include "DragUrlModule.h"
#include "ui_DragUrlModule.h"


#include <QDragEnterEvent>
#include <QMimeData>

#include <QImage>
#include <QPixmap>
#include <QString>

#include <QDebug>
#include <iostream>

#include <QHBoxLayout>

#include "CommonHandle.h"

DragUrlModule::DragUrlModule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DragUrlModule)
{
    ui->setupUi(this);
    this->setAcceptDrops(true);
}

DragUrlModule::~DragUrlModule()
{
    delete ui;
}

void DragUrlModule::dragEnterEvent(QDragEnterEvent* e)
{
    //dragEnterEvent 进入即相应，dropEvent 鼠标释放相应
    if (true)
    {
        e->acceptProposedAction();
    }
}
void DragUrlModule::dropEvent(QDropEvent* e)
{
    //filepath
    QList<QUrl> urls = e->mimeData()->urls();
    if (urls.isEmpty()) return;
    QString filePathName = urls.first().toLocalFile();


    //根据文件类型来做出对应的表达
    QString suffix = filePathName.split(".").last();

    if(suffix == "pt"){
        QPixmap pixmap =  CommonHandleSpace::GetFileIcon(filePathName);

        ui->label->setPixmap(pixmap);
    }
    else{
        ui->label->setText("format error");
    }
}

QString DragUrlModule::getCurrentFile()
{
    return this->m_currentFileName;
}

