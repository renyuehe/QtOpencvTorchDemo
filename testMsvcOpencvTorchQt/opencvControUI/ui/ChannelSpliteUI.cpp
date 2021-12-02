#include "ChannelSpliteUI.h"
#include "ui_ChannelSpliteUI.h"

ChannelSpliteUI::ChannelSpliteUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChannelSpliteUI)
{
    ui->setupUi(this);

    //拖拽
    this->setAcceptDrops(true);

    //新建窗口
    cv::namedWindow("channelSplite", cv::WINDOW_NORMAL);
    Cv2Qt::namedWindowToWidget("channelSplite", ui->frame);

    //初始化 img
    m_img = cv::Mat(ui->frame->width(),ui->frame->height(),
                    CV_8UC3,cv::Scalar(255,0,0));
}

ChannelSpliteUI::~ChannelSpliteUI()
{
    delete ui;
}

void ChannelSpliteUI::dragEnterEvent(QDragEnterEvent* e)
{
    //dragEnterEvent 进入即相应，dropEvent 鼠标释放相应
    //filter 放行
    if (true)
    {
        e->acceptProposedAction();
    }
}
void ChannelSpliteUI::dropEvent(QDropEvent* e)
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
        imshow("channelSplite", m_img);
    }
    else{
    }
}

void ChannelSpliteUI::on_pushButton_5_clicked()
{
    QString imgPathName = QFileDialog::getOpenFileName(nullptr,
                                                       ("文件对话框！"),
                                                       "F:",
                                                       ("图片文件(*png *jpg);;"));

    if(imgPathName.isNull())
        return;

    //读入图像
    this->m_img = cv::imread(imgPathName.toStdString() , cv::IMREAD_COLOR);
    imshow("channelSplite", m_img);
}

void ChannelSpliteUI::on_pushButton_4_clicked()
{
    if(this->m_img.empty())
        return;
    //B
    //Scalar(标量)
    //通道切割
    cv::Mat dst;
    m_img.copyTo(dst);

    std::vector<cv::Mat> ms(dst.channels()); //生成与通道数数目相等的图像容器
    cv::split(dst,ms); //分解与通道数数目相等的图像容器
    ms[1] = cv::Scalar(0);
    ms[2] = cv::Scalar(0);
    cv::merge(ms,dst); //合成与通道数数目相等的图像容器
    imshow("channelSplite", dst);
}

void ChannelSpliteUI::on_pushButton_3_clicked()
{
    if(this->m_img.empty())
        return;
    //G
    //Scalar(标量)
    //通道切割
    cv::Mat dst;
    m_img.copyTo(dst);

    std::vector<cv::Mat> ms(dst.channels()); //生成与通道数数目相等的图像容器
    cv::split(dst,ms); //分解与通道数数目相等的图像容器
    ms[0] = cv::Scalar(0);
    ms[2] = cv::Scalar(0);
    cv::merge(ms,dst); //合成与通道数数目相等的图像容器
    imshow("channelSplite", dst);
}

void ChannelSpliteUI::on_pushButton_2_clicked()
{
    if(this->m_img.empty())
        return;
    //R
    //Scalar(标量)
    //通道切割
    cv::Mat dst;
    m_img.copyTo(dst);

    std::vector<cv::Mat> ms(dst.channels()); //生成与通道数数目相等的图像容器
    cv::split(dst,ms); //分解与通道数数目相等的图像容器
    ms[0] = cv::Scalar(0);
    ms[1] = cv::Scalar(0);
    cv::merge(ms,dst); //合成与通道数数目相等的图像容器

    imshow("channelSplite", dst);
}

void ChannelSpliteUI::on_pushButton_clicked()
{
    if(this->m_img.empty())
        return;
    //RGB
    imshow("channelSplite", m_img);
}
