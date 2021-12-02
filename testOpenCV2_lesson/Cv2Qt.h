#ifndef CV2QT_H
#define CV2QT_H
//qt
#include <QImage>
#include <QLabel>
//opencv
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

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

//    static void cvMat_to_QLabel(const cv::Mat &mat, QLabel *label);
    static QLabel *cvMat_to_QLabel(const cv::Mat &mat);
};

#endif // CV2QT_H
