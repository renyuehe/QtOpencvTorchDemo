#include "ChannelRGBUI.h"
#include "ui_ChannelRGBUI.h"

ChannelRGBUI::ChannelRGBUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChannelRGBUI)
{
    ui->setupUi(this);


    //拖拽
    this->setAcceptDrops(true);

    //新建窗口
    cv::namedWindow("ChannelRGBUI", cv::WINDOW_NORMAL);
    Cv2Qt::namedWindowToWidget("ChannelRGBUI", ui->frame);
}

ChannelRGBUI::~ChannelRGBUI()
{
    delete ui;
}

void ChannelRGBUI::dragEnterEvent(QDragEnterEvent* e)
{
    //dragEnterEvent 进入即相应，dropEvent 鼠标释放相应
    //filter 放行
    if (true)
    {
        e->acceptProposedAction();
    }
}
void ChannelRGBUI::dropEvent(QDropEvent* e)
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
        imshow("ChannelRGBUI", m_img);
    }
    else{
    }
}

void ChannelRGBUI::on_pushButton_4_clicked()
{

    if(this->m_img.empty())
        return;
    //B
    cv::Mat dst = m_img;
    for (int i = 0;i<dst.rows;++i){
        for(int j=0;j<dst.cols;++j){
            dst.at<cv::Vec3b>(i,j)[0] = 0;
            dst.at<cv::Vec3b>(i,j)[1] = 0;
            dst.at<cv::Vec3b>(i,j)[2] = 255;
        }
    }

    imshow("ChannelRGBUI", dst);
}

void ChannelRGBUI::on_pushButton_3_clicked()
{
    if(this->m_img.empty())
        return;
    //G
    //通道切割
    cv::Mat dst;
    std::vector<cv::Mat> ms;

    cv::split(m_img,ms);
    ms[0] = cv::Scalar(0);
    ms[1] = cv::Scalar(255);
    ms[2] = cv::Scalar(0);
    //通道合并
    cv::merge(ms, dst);

    imshow("ChannelRGBUI", dst);
}

void ChannelRGBUI::on_pushButton_2_clicked()
{
    if(this->m_img.empty())
        return;
    //R
    //Scalar(标量)
    //通道切割
    cv::Mat dst;
    std::vector<cv::Mat> ms;

    cv::split(m_img,ms);
    ms[0] = cv::Scalar(0);
    ms[1] = cv::Scalar(0);
    ms[2] = cv::Scalar(255);
    //通道合并
    cv::merge(ms, dst);

    imshow("ChannelRGBUI", dst);
}
