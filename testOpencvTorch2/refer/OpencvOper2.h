#ifndef OPENCVOPER2_H
#define OPENCVOPER2_H

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


namespace  OpencvOper2{
    /**
     * @brief 打开一张图片
     */
    void fun_01();
    /**
     * @brief 卷积操作(掩模操作) filter2D
     */
    void fun_02();
    /**
     * @brief 卷积操作(掩模操作) filter2D
     */
    void fun_03();

    /**
     * @brief fun_04
     */
    void fun_04();

    /**
     * @brief 制作浮雕效果
     * 函数：sobel 和 converTo 和 minMaxLoc
     */
    void fun_05();
    /**
     * @brief addWeighted 和 multiply
     */
    void fun_06();
    /**
     * @brief 像素操作已经 cv::Vec3b 等参数理解（固定向量cv::Vec... 固定矩阵cv::Matx...）
     */
    void fun_07();

    void fun_08();

    /**
     * @brief 绘制直线和文字
     */
    void fun_09();

    /**
     * @brief 高斯模糊
     */
    void fun_10();
    void fun_11();
    void fun_12();
    void fun_13();
    void fun_14();
    void fun_15();
    void fun_16();
    void fun_17();
    void fun_18();
    void fun_19();
    void fun_20();
    void fun_21();
    void fun_22();
    void fun_23();
    void fun_24();
    void fun_25();
    void fun_26();
    void fun_27();
    void fun_28();
    void fun_29();
    void fun_30();
    void fun_31();
    void fun_32();
    void fun_33();
    void fun_34();
    void fun_35();
}

#endif // OPENCVOPER2_H
