#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QPluginLoader>
#include "ComPluginInterface.h"
#include "Communication.h"

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
    initSignalSlot();
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
    //打开图片
    connect(ui->actionOpen, &QAction::triggered, this, [=](){
        QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                        ("文件对话框！"),
                                                        "F:",
                                                        ("图片文件(*png *jpg);;"));
        if(fileName.endsWith(QString("jpg")) || fileName.endsWith(QString("png")))
        {
            BASE_MAT = cv::imread(fileName.toStdString(),1);//一定要使用绝对路径，其他可以回报错
            SRC_MAT = cv::imread(fileName.toStdString(),1);//一定要使用绝对路径，其他可以回报错
            if(ui->actionis_continuous_processing->isChecked())
                DST_MAT = SRC_MAT;
            cv::Mat dst;
            cv::resize(SRC_MAT, dst, cv::Size(0, 0), 0.5, 0.5);
            QPixmap TempSrcPixmap = QPixmap::fromImage(Cv2Qt::cvMat_to_QImage(dst));
            TempSrcPixmap.scaled(TempSrcPixmap.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->labelLeft->setPixmap(TempSrcPixmap);
        }
    });

    //对图片 连续处理
    connect(ui->actionis_continuous_processing, &QAction::triggered, this, [=](bool checked){
        if(checked){
            DST_MAT = SRC_MAT;
        }
        else {
            SRC_MAT = BASE_MAT;
            DST_MAT = cv::Mat();
        }
    });
}

void MainWindow::initSignalSlot(){
    //更新dst图片
    connect(Communication::GetInstance(), &Communication::signalUpdateDstimg, this, [=](){
        qDebug() << "aaaaaaaaaaaaaa";
        cv::Mat tempDst;
        cv::resize(DST_MAT, tempDst, cv::Size(0, 0), 0.5, 0.5);
        QPixmap TempSrcPixmap = QPixmap::fromImage(Cv2Qt::cvMat_to_QImage(tempDst));
        TempSrcPixmap.scaled(TempSrcPixmap.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->labelRight->setPixmap(TempSrcPixmap);
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


