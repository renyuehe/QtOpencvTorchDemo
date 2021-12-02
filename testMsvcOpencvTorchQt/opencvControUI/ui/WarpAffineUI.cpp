#include "WarpAffineUI.h"
#include "ui_WarpAffineUI.h"

#define RETNULLPTR(ptr)   if(this->ptr.empty())return;

WarpAffineUI::WarpAffineUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WarpAffineUI)
{
    ui->setupUi(this);

    this->x00 = 1;
    this->x01 = 0;
    this->x02 = 0;
    this->x10 = 0;
    this->x11 = 1;
    this->x12 = 0;

    angle = 0;
    scale = 0;

    //拖拽
    this->setAcceptDrops(true);

    //新建窗口
    cv::namedWindow("warpAffineUI", cv::WINDOW_NORMAL);
    Cv2Qt::namedWindowToWidget("warpAffineUI", ui->frame);
}

WarpAffineUI::~WarpAffineUI()
{
    delete ui;
}

void WarpAffineUI::dragEnterEvent(QDragEnterEvent* e)
{
    //dragEnterEvent 进入即相应，dropEvent 鼠标释放相应
    //filter 放行
    if (true)
    {
        e->acceptProposedAction();
    }
}

void WarpAffineUI::dropEvent(QDropEvent* e)
{
    //filepath
    QList<QUrl> urls = e->mimeData()->urls();
    if (urls.isEmpty()) return;
    QString filename = urls.first().toLocalFile();

    //根据文件类型来做出对应的表达
    QString suffix = filename.split(".").last();
    if(suffix == "jpg" || suffix == "png" ){
        if(m_img.empty())
        {
            //读入图像
            this->m_img = cv::imread(filename.toStdString(), cv::IMREAD_COLOR);
            imshow("warpAffineUI", m_img);
        }
    }
    else{
    }
}

void WarpAffineUI::on_horizontalSlider_00_valueChanged(int value)
{
    RETNULLPTR(m_img)

    cv::Mat dst;

    qDebug() << __LINE__  << value;
    x00 = double(value)/100;
    qDebug() << __LINE__  << x00;
    cv::Mat M1 = (cv::Mat_<double>(2,3) << x00,x01,x02,x10,x11,x12);

    cv::warpAffine(m_img, dst, M1, m_img.size());
    cv::imshow("warpAffineUI", dst);
}


void WarpAffineUI::on_horizontalSlider_01_valueChanged(int value)
{
    RETNULLPTR(m_img)

    cv::Mat dst;

    x01 = double(value)/100;
    cv::Mat M1 = (cv::Mat_<double>(2,3) << x00,x01,x02,x10,x11,x12);

    cv::warpAffine(m_img,dst, M1, m_img.size());
    cv::imshow("warpAffineUI", dst);
}


void WarpAffineUI::on_horizontalSlider_02_valueChanged(int value)
{
    RETNULLPTR(m_img)
    cv::Mat dst;

    x02 = double(value)/100;
    cv::Mat M1 = (cv::Mat_<double>(2,3) << x00,x01,x02,x10,x11,x12);

    cv::warpAffine(m_img,dst, M1, m_img.size());
    cv::imshow("warpAffineUI", dst);
}


void WarpAffineUI::on_horizontalSlider_10_valueChanged(int value)
{
    RETNULLPTR(m_img)
    cv::Mat dst;

    x10 = double(value)/100;
    cv::Mat M1 = (cv::Mat_<double>(2,3) << x00,x01,x02,x10,x11,x12);

    cv::warpAffine(m_img, dst, M1, m_img.size());
    cv::imshow("warpAffineUI", dst);
}


void WarpAffineUI::on_horizontalSlider_11_valueChanged(int value)
{
    RETNULLPTR(m_img)
    cv::Mat dst;

    x11 = double(value)/100;
    cv::Mat M1 = (cv::Mat_<double>(2,3) << x00,x01,x02,x10,x11,x12);

    cv::warpAffine(m_img,dst, M1, m_img.size());
    cv::imshow("warpAffineUI", dst);
}


void WarpAffineUI::on_horizontalSlider_12_valueChanged(int value)
{
    RETNULLPTR(m_img)
    cv::Mat dst;

    x12 = double(value)/100;
    cv::Mat M1 = (cv::Mat_<double>(2,3) << x00,x01,x02,x10,x11,x12);

    cv::warpAffine(m_img,dst, M1, m_img.size());
    cv::imshow("warpAffineUI", dst);
}


void WarpAffineUI::on_verticalSlider_valueChanged(int value)
{
    RETNULLPTR(m_img)
    cv::Mat dst;

    this->angle = double(value)/100;
    cv::Mat M2 = cv::getRotationMatrix2D(cv::Point(m_img.cols/2, m_img.rows/2), this->angle, this->scale);
    cv::warpAffine(m_img,dst, M2, m_img.size());

    cv::imshow("warpAffineUI", dst);
}

void WarpAffineUI::on_verticalSlider_2_valueChanged(int value)
{
    RETNULLPTR(m_img)
    cv::Mat dst;

    this->scale = double(value)/100;
    cv::Mat M2 = cv::getRotationMatrix2D(cv::Point(m_img.cols/2, m_img.rows/2), this->angle, this->scale);
    cv::warpAffine(m_img,dst, M2, m_img.size());

    cv::imshow("warpAffineUI", dst);
}


void WarpAffineUI::on_pushButton_clicked()
{
    this->x00 = 1;
    this->x01 = 0;
    this->x02 = 0;
    this->x10 = 0;
    this->x11 = 1;
    this->x12 = 0;

    angle = 0;
    scale = 0;

    if(!m_img.empty()){
        cv::imshow("warpAffineUI", m_img);
    }
}









