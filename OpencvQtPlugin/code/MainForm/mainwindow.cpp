#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QPluginLoader>
#include "ComPluginInterface.h"
#include "Communication.h"

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
    loadAllPlugin();
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
            SRC_IMG = QPixmap::fromImage(imageImg);


            QSize size(QSize(ui->labelLeft->width(), int(double((SRC_IMG.height())/double(SRC_IMG.width()))*ui->labelLeft->height())));
            qDebug() << size;
            QPixmap TempSrcPixmap = Communication::GetInstance()->mSrcPixmap.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->labelLeft->setPixmap(TempSrcPixmap);

//            ui->labelRight->setPixmap(mSrcPixmap);
        }
    });

    connect(ui->actiontest, &QAction::triggered,this,[=](){
        qDebug() << &SRC_IMG;
        qDebug() << &SRC_IMG;
    });
}

void MainWindow::loadAllPlugin(){
    m_pComPluginManager = new ComPluginManager;

    //加载所有插件
    m_pComPluginManager->LoadAndInitAllPlugin();


    //遍历插件获取分类信息
    const QMap<QString, ComPluginInterface*>& mapPluginInterface = m_pComPluginManager->m_mapPluginInterface;
    for (QMap<QString, ComPluginInterface*>::const_iterator iter = mapPluginInterface.constBegin(); iter != mapPluginInterface.constEnd(); ++iter)
    {
        qDebug() << iter.key() << __LINE__;
    }

    //遍历所有插件提供的窗口
    const QMap<QString, QWidget*>& mapPluginWidget = m_pComPluginManager->m_mapPluginWidget;
    for (QMap<QString, QWidget*>::const_iterator iter = mapPluginWidget.constBegin(); iter != mapPluginWidget.constEnd(); ++iter)
    {
        QAction * curActioin = ui->menu_plugin->addAction(iter.key());
        ui->stackedWidget->addWidget(iter.value());
        connect(curActioin, &QAction::triggered, this, [=](){
            ui->stackedWidget->setCurrentWidget(iter.value());
        });
    }
}


