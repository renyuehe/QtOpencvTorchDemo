#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QPluginLoader>
#include "ComPluginInterface.h"
//#include "OpencvOper.h"
#include "Cv2Qt.h"
#include "QFileDialog"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUI();
    initMenuBar();
    initWorkSpace();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI(){
   ui->labelLeft->setScaledContents(true);
   ui->labelRight->setScaledContents(true);
}

void MainWindow::initMenuBar(){
    connect(ui->actionOpen, &QAction::triggered, this, [=](){
        QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                        ("文件对话框！"),
                                                        "F:",
                                                        ("图片文件(*png *jpg);;"));
        if(fileName.endsWith(QString("jpg")) || fileName.endsWith(QString("png")))
        {
            cv::Mat image=cv::imread(fileName.toStdString(),1);//一定要使用绝对路径，其他可以回报错

            QImage imageImg = Cv2Qt::cvMat_to_QImage(image);
            mSrcPixmap = QPixmap::fromImage(imageImg);


            QSize size(QSize(ui->labelLeft->width(), int(double((mSrcPixmap.height())/double(mSrcPixmap.width()))*ui->labelLeft->height())));
            qDebug() << size;
            mSrcPixmap = mSrcPixmap.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->labelLeft->setPixmap(mSrcPixmap);

//            ui->labelRight->setPixmap(mSrcPixmap);
        }

    });
}

void MainWindow::initWorkSpace(){
    m_pWorkSpaceWidget = new WorkSpaceWidget;
    ui->dockWidget_4->setWidget(m_pWorkSpaceWidget);
}

