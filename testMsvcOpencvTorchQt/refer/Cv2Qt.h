#ifndef CV2QT_H
#define CV2QT_H
//qt
#include <QImage>
#include <QLabel>
//opencv
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//cv窗体嵌入widget需要头文件
#pragma comment  (lib,"User32.lib")
#pragma comment  (lib,"Gdi32.lib")
#include <opencv2/highgui/highgui_c.h>
#include <windows.h>


//线程
#include<QtConcurrent>


class Cv2Qt
{
public:
    Cv2Qt();
    //##### cv::Mat ---> QImage #####
    // Shallow copy
    static QImage mat2qimage_ref(cv::Mat &m, QImage::Format format);
    // Deep copy
    static QImage mat2qimage_cpy(cv::Mat &m, QImage::Format format);

    //##### QImage ---> cv::Mat #####
    // Shallow copy
    static cv::Mat qimage2mat_ref(QImage &img, int format);

    //##### cv::Mat ---> QImage #####
    static cv::Mat QImage_to_cvMat(const QImage &image, bool inCloneImageData = true);
    //##### QImage ---> cv::Mat #####
    static QImage cvMat_to_QImage(const cv::Mat &mat);

    static QLabel* cvMat_to_QLabel(const cv::Mat &mat);


    //窗口嵌入
    static void namedWindowToWidget(std::string namedWindowTitle, QWidget *VideoCaptureLabel);

    //cv视频转label显示
    static void VideoCaptureToWidget(QString filename, QLabel * label);

    //cv视频转label显示
    static void VideoCaptureToWidgetByThread(QString filename, QLabel * label);

};



class VideoCaptureLabel : public QObject
{
    Q_OBJECT
private:
    QString filename;
    QLabel * label;
public:
    VideoCaptureLabel(QString filename, QLabel * label, QObject *parent=nullptr);
    ~VideoCaptureLabel();
    void star();//多线程启动函数，在原有的代码基础上增加该函数
    void xunhuan();//死循环函数，用这个函数代替原有代码的函数

private:

    int myEnable;//标志位，用于退出死循环操作
};
#endif // CV2QT_H
