#include "Cv2Qt.h"
#include <QDebug>
#include <QtConcurrent>

Cv2Qt::Cv2Qt()
{

}


//##### cv::Mat ---> QImage #####
// Shallow copy
QImage Cv2Qt::mat2qimage_ref(cv::Mat &m, QImage::Format format) {
    return QImage(m.data, m.cols, m.rows, m.step, format);
}


// Deep copy
QImage Cv2Qt::mat2qimage_cpy(cv::Mat &m, QImage::Format format) {
    return QImage(m.data, m.cols, m.rows, m.step, format).copy();
}


//##### QImage ---> cv::Mat #####
// Shallow copy
cv::Mat Cv2Qt::qimage2mat_ref(QImage &img, int format) {
    return cv::Mat(img.height(), img.width(), format, img.bits(), img.bytesPerLine());
}


//##### cv::Mat ---> QImage #####
QImage Cv2Qt::cvMat_to_QImage(const cv::Mat &mat ) {
  switch ( mat.type() )
  {
     // 8-bit, 4 channel
     case CV_8UC4:
     {
        QImage image( mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB32 );
        return image;
     }

     // 8-bit, 3 channel
     case CV_8UC3:
     {
        QImage image( mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888 );
        return image.rgbSwapped();
     }

     // 8-bit, 1 channel
     case CV_8UC1:
     {
        static QVector<QRgb>  sColorTable;
        // only create our color table once
        if ( sColorTable.isEmpty() )
        {
           for ( int i = 0; i < 256; ++i )
              sColorTable.push_back( qRgb( i, i, i ) );
        }
        QImage image( mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8 );
        image.setColorTable( sColorTable );
        return image;
     }

     default:
        qDebug("Image format is not supported: depth=%d and %d channels\n", mat.depth(), mat.channels());
        break;
  }
  return QImage();
}


QLabel * Cv2Qt::cvMat_to_QLabel(const cv::Mat &mat)
{
    QImage qimg = Cv2Qt::cvMat_to_QImage(mat);
    QPixmap pixmap = QPixmap::fromImage(qimg);

    QLabel * label = new QLabel;
    label->setPixmap(pixmap);
    return label;
}


void Cv2Qt::namedWindowToWidget(std::string namedWindowTitle, QWidget * VideoCaptureLabel)
{
       HWND hwnd = (HWND)cvGetWindowHandle(namedWindowTitle.c_str()); //转char*
       //取title窗体的父窗体句柄
       HWND hparent =::GetParent(hwnd);

       //改变某个子窗体的父窗口(子窗口句柄,新的父窗口句柄)
       ::SetParent(hwnd, (HWND)VideoCaptureLabel->winId());  //winId()取win32api要用的窗口句柄

       //显示窗体SW_SHOW  隐藏窗体SW_HIDE
       ::ShowWindow(hparent, SW_HIDE);
}



//##### QImage ---> cv::Mat #####
cv::Mat Cv2Qt::QImage_to_cvMat( const QImage &image, bool inCloneImageData) {
    switch ( image.format() )
    {
    // 8-bit, 4 channel
    case QImage::Format_RGB32:
    {
        cv::Mat mat( image.height(), image.width(), CV_8UC4, const_cast<uchar*>(image.bits()), image.bytesPerLine() );
        return (inCloneImageData ? mat.clone() : mat);
    }

        // 8-bit, 3 channel
    case QImage::Format_RGB888:
    {
        if ( !inCloneImageData ) {
            qDebug() << "ASM::QImageToCvMat() - Conversion requires cloning since we use a temporary QImage";
        }
        QImage swapped = image.rgbSwapped();
        return cv::Mat( swapped.height(), swapped.width(), CV_8UC3, const_cast<uchar*>(swapped.bits()), swapped.bytesPerLine() ).clone();
     }

     // 8-bit, 1 channel
     case QImage::Format_Indexed8:
     {
        cv::Mat  mat( image.height(), image.width(), CV_8UC1, const_cast<uchar*>(image.bits()), image.bytesPerLine() );

        return (inCloneImageData ? mat.clone() : mat);
     }

     default:
        qWarning("Image format is not supported: depth=%d and %d format\n", image.depth(), image.format());
        break;
  }

  return cv::Mat();
}


void Cv2Qt::VideoCaptureToWidget(QString filename, QLabel *label)
{
    cv::VideoCapture cap = cv::VideoCapture(filename.toStdString());
    if(!cap.isOpened())
        return;

    label->setAlignment(Qt::AlignCenter);
    label->setScaledContents(false);

    while (true){
        cv::Mat frame;
        cap >> frame;

        if(frame.empty())
            break;
        else
            label->setPixmap(QPixmap::fromImage(Cv2Qt::cvMat_to_QImage(frame)));

        cv::waitKey(42);
    }

    label->clear();
    cap.release();
    cv::destroyAllWindows();
}


void Cv2Qt::VideoCaptureToWidgetByThread(QString filename, QLabel *label)
{
    VideoCaptureLabel capLabel(filename, label);
    capLabel.star();
}


VideoCaptureLabel::VideoCaptureLabel(QString filename, QLabel *label, QObject *parent)
{
    this->label = label;
    this->filename = filename;
}




VideoCaptureLabel::~VideoCaptureLabel()
{

}

void VideoCaptureLabel::star()
{
    QtConcurrent::run(this,&VideoCaptureLabel::xunhuan);//多线程执行死循环启动，可以带参数，具体格式可以查阅网上其它资料
}

void VideoCaptureLabel::xunhuan()
{
//    cv::VideoCapture cap = cv::VideoCapture(this->filename.toStdString());
//    if(!cap.isOpened())
//        return;

//    label->setAlignment(Qt::AlignCenter);
//    label->setScaledContents(false);

//    while (true){
//        cv::Mat frame;
//        cap >> frame;

//        if(frame.empty())
//            break;
//        else
//            label->setPixmap(QPixmap::fromImage(Cv2Qt::cvMat_to_QImage(frame)));

//        cv::waitKey(42);
//    }

//    label->clear();
//    cap.release();
//    cv::destroyAllWindows();

    while(true){
        qDebug() << __LINE__ << "线程执行中";

        QThread::sleep(1);
        this->label->setText("haha");//报错崩溃,不同线程之间 ui 操作不能通过指针，需要通过信号槽解决问题
    }
}

