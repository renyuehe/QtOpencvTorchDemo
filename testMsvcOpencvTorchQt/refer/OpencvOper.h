#ifndef OPENCVOPER_H
#define OPENCVOPER_H

#include <QDebug>
#include <QFileDialog>
#include <QFileDialog>
#include <vector>
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

//using namespace cv;
using namespace std;

namespace  OpencvOper{
    /**
     * @brief 打开图片
     */
    void openImgOper();

    /**
     * @brief 保存图片
     */
    void saveImgOper();

    /**
     * @brief 通道分离 通道合并
     */
    void channelSplite();

    /**
     * @brief 读取视频
     */
    void VideoCaptureOper();

    /**
     * @brief 转换色彩空间
     */
    void cvtColorOper();

    /**
     * @brief 基本绘图
     */
    void drawShapeOper();

    /**
     * @brief thresholdOper 阈值操作
     */
    void thresholdOper();

    /**
     * @brief adapterThresholdOper 自适应阈值
     */
    void adapterThresholdOper();

    /**
     * @brief 图像运算
     */
    void imgMathOperation();

    /**
     * @brief 图像运算2
     */
    void imgMathOperation2();

    /**
     * @brief 图像位运算2
     */
    void imgBitOperation();

    /**
     * @brief 几何变换
     */
    void transposeFlipOper();

    /**
     * @brief 仿射变换
     */
    void warpAffine();

    /**
     * @brief 透视变换
     */
    void warpPerspective();

    /**
     * @brief 形态学操作
     */
    void morphologicalOper();

    /**
     * @brief 滤波
     */
    void graphFilterOper();

    /**
     * @brief 边缘提取
     */
    void  CannyOper();

    /**
     * @brief 轮廓提取
     */
    void findContoursOper();

    /**
     * @brief 轮廓近似
     */
    void approxPolyDPOper();

    /**
     * @brief 凸包 与 凸性
     */
    void convexOper();

    /**
     * @brief 边界检测
     */
    void boundaryDetection();

    /**
     * @brief 轮廓性质
     */
    void contoursProperty();

    /**
     * @brief 霍夫直线检测
     */
    void huofuOper();

    /**
     * @brief 直方图均衡化
     */
    void hintDetact();

    /**
     * @brief 测试随便写
     */
    void test();
}


#endif // OPENCVOPER_H
