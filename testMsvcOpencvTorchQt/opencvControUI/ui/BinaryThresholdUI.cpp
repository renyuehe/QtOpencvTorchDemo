#include "BinaryThresholdUI.h"
#include "ui_BinaryThresholdUI.h"
#include <QFileDialog>

BinaryThresholdUI::BinaryThresholdUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BinaryThresholdUI)
{
    ui->setupUi(this);

    //拖拽
    this->setAcceptDrops(true);

    //新建窗口
    cv::namedWindow("binary_threshould", cv::WINDOW_AUTOSIZE);
    Cv2Qt::namedWindowToWidget("binary_threshould", ui->frame);

    //trackbar的最大值
    ui->horizontalSlider->setMaximum(255);
    ui->horizontalSlider->setThumbColor(QColor(Qt::GlobalColor::red));
}

BinaryThresholdUI::~BinaryThresholdUI()
{
    delete ui;
}

void BinaryThresholdUI::dragEnterEvent(QDragEnterEvent* e)
{
    //dragEnterEvent 进入即相应，dropEvent 鼠标释放相应
    //filter 放行
    if (true)
    {
        e->acceptProposedAction();
    }
}

void BinaryThresholdUI::dropEvent(QDropEvent* e)
{
    //filepath
    QList<QUrl> urls = e->mimeData()->urls();
    if (urls.isEmpty()) return;
    QString filename = urls.first().toLocalFile();

    //根据文件类型来做出对应的表达
    QString suffix = filename.split(".").last();
    if(suffix == "jpg" || suffix == "png" ){
        //读入图像
        this->m_img = cv::imread(filename.toStdString() , cv::IMREAD_COLOR);
        imshow("binary_threshould", m_img);
    }
    else{
    }
}


void BinaryThresholdUI::on_horizontalSlider_valueChanged(int value)
{
    if(!this->m_img.empty())
    {
        // 强制类型转换
        cv::Mat dst;

        // 二值化
        threshold(m_img, dst, value, 255, 0);
        imshow("binary_threshould", dst);
    }
}
