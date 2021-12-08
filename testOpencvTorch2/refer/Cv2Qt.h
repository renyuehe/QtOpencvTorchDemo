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
};

#endif
