#ifndef OpencvOperBase_H
#define OpencvOperBase_H

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <iostream>
#include <QDebug>

using namespace std;

namespace OpencvOperBase {
    /**
     * @brief cv::Matx固定矩阵类  cv::Vec固定向量类
     */
    static void fun_00();

    /**
     * @brief 基础类型操作 CV_MAKETYPE、CV_Assert、depth、type、CV_8U、CV_8UC1、CV_8UC3
     */
    static void fun_01();
    /**
     * @brief 基础类型操作 depth、type、size
     */
    static void fun_010();

    /**
     * @brief 图像运算之saturate_cast
     */
    static void fun_02();

    /**
     * @brief 图像运算之 卷积操作(掩模操作) filter2D
     */
    static void fun_03();

    /**
     * @brief CV::Mat和 CV::Scalar结合的操作
     */
    static void fun_04();

    /**
     * @brief copyTo(src, dst)
     */
    static void fun_05();

    /**
     * @brief 对角矩阵 cv::Mat::eye(2, 2, CV_8UC1);
     */
    static void fun_06();

    /**
     * @brief mat内数据类型转换 convertTo
     */
    static void fun_07();

    /**
     * @brief 返回最大最小值 minMaxLoc
     */
    static void fun_08();

    /**
     * @brief soble minMaxLoc
     */
    static void fun_09();
    /**
     * @brief addWeighted 和 multiply
     */
    static void fun_10();

    /**
     * @brief Mat 和 Vec 之间的最简单操作
     */
    static void fun_11();
    /**
     * @brief Mat 和 Vec 之间的操作 2
     */
    static void fun_12();

    /**
     * @brief Mat 和 Vec 之间的操作 3
     */
    static void fun_13();

    /**
     * @brief cv::RNG 产生随机数
     */
    static void fun_14();

    /**
     * @brief cv::RNG  uniform  产生随机数2
     */
    static void fun_15();

    /**
     * @brief 创建一个卷积核 getStructuringElement 其实也可用用 cv::Mat_
     */
    static void fun_16();

    /**
     * @brief createTrackbar
     */
    static void fun_17();

    /**
     * @brief  cv 重映射值 remap 和 创建自定义通道图片 create
     */
    static void fun_18();

    /**
     * @brief 通道复制：mixChannels 函数
     */
    static void fun_19();
}

#endif // OpencvOperBase_H
