#include "OpencvOperBase.h"

/************************ cv::Matx固定矩阵类  cv::Vec固定向量类 **************************/
//模拟cv内部定义方式
typedef cv::Matx<float, 4, 4> Matx44f;
typedef cv::Matx<double, 4, 4> Matx44d;
typedef cv::Matx<float, 1, 2> Matx12f;
typedef cv::Matx<double, 1, 2> Matx12d;

//模拟cv内部定义方式
typedef cv::Vec<uchar, 2> Vec2b;
typedef cv::Vec<uchar, 4> Vec4b;
typedef cv::Vec<int, 2> Vec2i;
typedef cv::Vec<int, 4> Vec4i;
typedef cv::Vec<float, 4> Vec4f;

void OpencvOperBase::fun_00(){
    //cv::Matx固定矩阵类。 赋值方式是序列构造器方式 sequential container
    cv::Matx <float,3,2> Matx55f = {1.1, 2.3, 3.1, 4.5, 5.2, 6.4};
    cout << Matx55f << endl;
    cout << Matx55f(1,1)<< endl; //cout 4.5
    cout << Matx55f(2,1) << endl; //cout 6.4

    //cv::Vec固定向量类
    cv::Vec4i v4i = {1,2,3,4};
    cout << v4i << endl;
}

/************************ 基础类型操作了解 **************************/
#define CV_8UC3 CV_MAKETYPE(CV_8U,3)
#define CV_8UC2 CV_MAKETYPE(CV_8U,2)
#define CV_8UC1 CV_MAKETYPE(CV_8U,1)
#define CV_8SC1 CV_MAKETYPE(CV_8S,1)
void OpencvOperBase::fun_01(){
    cv::Mat src, dst;
    src = cv::imread("D:/Desktop/small_girl.jpg");
    std::cout << CV_8UC3 << endl;
    std::cout << CV_8UC2 << endl;
    std::cout << CV_8UC1 << endl;
    std::cout << CV_8SC1 << endl;
    std::cout << src.depth();
    CV_Assert(src.depth() == CV_8U);//depth = (deepth-1) 深度depth+1(0-255),CV_8U值为0只是枚举范围不是位数
    CV_Assert(src.type() == CV_8UC3);//三通道,这里才是通道数 C * (depth-1)

    CV_Assert(src.depth() == CV_8UC1);
    CV_Assert(src.depth() == CV_8UC3);
}
/************************基础类型操作了解**************************/
void OpencvOperBase::fun_010(){
    cv::Mat src, dst;
    src = cv::imread("D:/Desktop/small_girl.jpg");
    cout << src.depth() << endl;//深度(像素单通占用位宽)
    cout << src.type() << endl;//类型,表示深度*通道
    cout << src.size() << endl;//返回的是一个 MatSize [宽, 高]

    dst = cv::Mat::zeros(src.size(), src.type());//通过size 和 type 可以对新矩阵进行赋值
}

/************************* 图像运算之saturate_cast *************************/
void OpencvOperBase::fun_02(){
    std::cout << int(cv::saturate_cast<uchar>(600)) << endl;
    std::cout << int(cv::saturate_cast<uchar>(600)) << endl;
    std::cout << int(cv::saturate_cast<uchar>(600)) << endl;
}
/************************* 图像运算之 卷积操作(掩模操作) *************************/
void OpencvOperBase::fun_03(){
    cv::Mat src, dst;
    src = cv::imread("D:/Desktop/small_girl.jpg");
    cv::Mat kernel = (cv::Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(src, dst, src.depth(), kernel);//卷积操作（掩模操作）
}
/************************* CV::Mat和 CV::Scalar结合的操作 *************************/
void OpencvOperBase::fun_04(){

    //返回的之4个值的,这里Scalar主要是用于返回4个通道的RGBA
    auto dst = cv::Scalar(127, 0, 255);
    std::cout << dst << endl;

    //
    /*** cv::Mat 和 cv::scalar 结合的用法 ***/
    cv::Mat M1(4,4,CV_8UC1,cv::Scalar(188));
    cout << M1 << endl;

    cv::Mat M2(4,4,CV_8UC2,cv::Scalar(188,122));
    cout << M2 << endl;
}
/************************* copyTo(src, dst) *************************/
void OpencvOperBase::fun_05(){
    cv::Mat src, dst;
    src = cv::imread("D:/Desktop/small_girl.jpg");
    src.copyTo(dst);
}
/************************* 对角矩阵 cv::Mat::eye(2, 2, CV_8UC1); *************************/
void OpencvOperBase::fun_06(){
    cv::Mat m1 = cv::Mat::eye(2, 2, CV_8UC1);
    cout << "m1 =" << endl << m1 << endl;

    cv::Mat m2 = cv::Mat::eye(2, 2, CV_8UC2);
    cout << "m2 =" << endl << m2 << endl;
}
/************************* mat内数据类型转换 convertTo *************************/
void OpencvOperBase::fun_07(){
    cv::Mat dst;
    cv::Mat src = cv::Mat::zeros(2, 2, CV_8UC1);
    src.convertTo(dst, CV_32F);
    cout << src << endl;
    cout << dst << endl;
}
/************************* 返回最大最小值 minMaxLoc  *************************/
void OpencvOperBase::fun_08(){
    //如果只返回最大最小值,不关心位置,可以使用任意多通道的图
    cv::Mat src, dst;
    src = cv::imread("D:/Desktop/small_girl.jpg");
    double minVal, maxVal;
    //注意在 python cv2中只能用src只能是灰度图,不能是原图
    minMaxLoc(src, &minVal, &maxVal); //find minimum and maximum intensities
    cout << minVal << "--------" << maxVal << endl;


    //注意如果要返回最大最小值 并且 要返回位置 就必须要使用单通道图（灰度图）
    cv::Mat src2, dst2;
    src2 = cv::imread("D:/Desktop/small_girl.jpg", 0);
    double minVal2, maxVal2;
    //注意在 python cv2中只能用src只能是灰度图,不能是原图
    CV_OUT cv::Point p1, p2;
    minMaxLoc(src2, &minVal2, &maxVal2, &p1, &p2); //find minimum and maximum intensities
    cout << minVal2 << "--------" << maxVal2 << endl;
    cout << p1 << "--------" << p2 << endl;
}
/************************* soble minMaxLoc  *************************/
void OpencvOperBase::fun_09(){
    cv::Mat gray_src, sobel_dst;
    gray_src = cv::imread("D:/Desktop/small_girl.jpg", 0);

    //ddepth深度,dx,dy,ksize核的大小,scale倍数,delta偏移,
    cv::Sobel(gray_src, sobel_dst, CV_32F, 1, 0);//如果原图不是这个深度,用这个深度会导致颜色溢出
    //    cv::Sobel(gray_src, sobel_dst, CV_64F, 1, 0);//如果原图不是这个深度,用这个深度会导致颜色溢出
    //    cv::Sobel(gray_src, sobel_dst, CV_8U, 1, 0);
    //    cv::Sobel(gray_src, sobel_dst, gray_src.depth(), 1, 0);
    namedWindow("My Image", cv::WINDOW_AUTOSIZE);
    imshow("My Image", sobel_dst);
    cv::waitKey(0);
}
/************************* addWeighted 和 multiply  *************************/
void OpencvOperBase::fun_10(){

    cv::Mat src1, src2, dst;
    src1 = (cv::Mat_<uchar>(2,2)<<3,3,3,3);
    src2 = (cv::Mat_<uchar>(2,2)<<3,3,3,3);

    double alpha = 0.5;
    if (src1.rows == src2.rows && src1.cols == src2.cols && src1.type() == src2.type()) {
        //图像相加
        addWeighted(src1, alpha, src2, (1.0 - alpha), 0.0, dst);
        //图像相乘
        //        multiply(src1, src2, dst, 1.0);

        cout << src1 << endl;
        cout << src2 << endl;
        cout << dst << endl;
    }

    cv::waitKey(0);
}
/************************* Mat 和 Vec 之间的最简单操作  **************************/
void OpencvOperBase::fun_11(){
    cv::Mat src, dst;
    src = cv::imread("D:/Desktop/small_girl.jpg", cv::IMREAD_COLOR);
    uchar b = src.at<cv::Vec3b>(500,500)[0];
    uchar g = src.at<cv::Vec3b>(500,500)[1];
    uchar r = src.at<cv::Vec3b>(500,500)[2];

    cout << "b:" << int(b) << endl;
    cout << "g:" << int(g) << endl;
    cout << "r:" << int(r) << endl;
}

/************************* Mat 和 Vec 之间的操作 **************************/
void OpencvOperBase::fun_12(){
    cv::Mat src, dst;
    src = cv::imread("D:/Desktop/small_girl.jpg", cv::IMREAD_COLOR);

    float alpha = 1.2;
    float beta = 0;

    dst = cv::Mat::zeros(src.size(), src.type());

    cv::Mat m1;
    src.convertTo(m1, CV_32F);

    int row ,col = 10;
    if(src.channels() == 3)
    {
        for(int i = 0; i < 500; i++)
        {
            float b = m1.at<cv::Vec3f>(row+i, col+i)[0];
            float g = m1.at<cv::Vec3f>(row+i, col+i)[1];
            float r = m1.at<cv::Vec3f>(row+i, col+i)[2];

            dst.at<cv::Vec3b>(row+i, col+i)[0] = cv::saturate_cast<uchar>(r*alpha + beta);
            dst.at<cv::Vec3b>(row+i, col+i)[1] = cv::saturate_cast<uchar>(g*alpha + beta);
            dst.at<cv::Vec3b>(row+i, col+i)[2] = cv::saturate_cast<uchar>(b*alpha + beta);
        }
    }
    else if(src.channels() == 1)
    {
        for(int i = 0; i < 500; i++)
        {
            float v = src.at<uchar>(row+i, col+i);

            dst.at<uchar>(row+i, col+i-1) = cv::saturate_cast<uchar>(v*alpha + beta);
            dst.at<uchar>(row+i, col+i) = cv::saturate_cast<uchar>(v*alpha + beta);
            dst.at<uchar>(row+i, col+i+1) = cv::saturate_cast<uchar>(v*alpha + beta);
        }
    }

    cv::imshow("src>>",src);
    cv::imshow("dst>>",dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

/************************* Mat 和 Vec 之间的操作  *************************/
void OpencvOperBase::fun_13(){
    cv::Mat src, dst;
    src = cv::imread("D:/Desktop/small_girl.jpg");

    float alpha = 1.2;
    float beta = 30;

    dst = cv::Mat::zeros(src.size(), src.type());
    cv::Mat m1;
    src.convertTo(m1, CV_32F);

    cout << src.cols << endl;
    cout << src.rows << endl;
    for (int row = 0; row < src.rows; row++) {
        for (int col = 0; col < src.cols; col++) {
            if (src.channels() == 3) {
                float b = m1.at<cv::Vec3f>(row, col)[0];// blue
                float g = m1.at<cv::Vec3f>(row, col)[1]; // green
                float r = m1.at<cv::Vec3f>(row, col)[2]; // red

                // output
                dst.at<cv::Vec3b>(row, col)[0] = cv::saturate_cast<uchar>(b*alpha + beta);
                dst.at<cv::Vec3b>(row, col)[1] = cv::saturate_cast<uchar>(g*alpha + beta);
                dst.at<cv::Vec3b>(row, col)[2] = cv::saturate_cast<uchar>(r*alpha + beta);
            }
            else if (src.channels() == 1) {
                float v = src.at<uchar>(row, col);
                dst.at<uchar>(row, col) = cv::saturate_cast<uchar>(v*alpha + beta);
            }
        }
    }
}

/************************* cv::RNG 产生随机数  *************************/
void OpencvOperBase::fun_14(){

    cv::RNG rng(0xFF);
    qDebug() << rng.state;
    for (int i = 0; i < 5; i++)
    {
        //返回 unsigned int
        //std::cout << rng.next() << "\n";//打印不了？
        qDebug() << __LINE__ << rng.next();
    }
}
/************************* cv::RNG 产生随机数2  *************************/
void OpencvOperBase::fun_15(){

    cv::RNG rng;
    cv::Point pt1, pt2;

    pt1.x = rng.uniform(0, 150);
    pt2.x = rng.uniform(0, 150);

    int r = rng.uniform(0, 255);

    cout << "pt1" << pt1  << endl;
    cout << r  << endl;
}

/************************* 创建一个卷积核 getStructuringElement  *************************/
void OpencvOperBase::fun_16(){
    cv::Mat hline = getStructuringElement(cv::MORPH_RECT,
                                          cv::Size(16, 20),
                                          cv::Point(-1, -1));

    cout << hline.rows << endl;
    cout << hline.cols << endl;
    cout << hline.dims << endl;
}

/************************* 回调函数 这里传入 ***/
// 回调函数
void onChangeTrackBar(int pos, void* usrdata)
{
    // 强制类型转换
    cv::Mat src = *(cv::Mat*)(usrdata);
    cv::Mat dst;

    // 二值化
    threshold(src, dst, pos, 255, 0);
    imshow("二值化", dst);
}

void OpencvOperBase::fun_17(){

    //trackbar的值
    int posTrackBar = 0;
    //trackbar的最大值
    int maxValue = 150;

    //读入图像，以灰度图形式读入
    cv::Mat img = cv::imread("D:\\Desktop\\small_girl.jpg", 0);

    //新建窗口
    cv::namedWindow("二值化");
    imshow("二值化", img);

    //
    /**
     * @brief 创建trackbar，我们把img作为数据传进回调函数中
     * winname:窗体名字,用于找到对应窗体
     * value:Trackbar的值
     * count:Trackbar的最大值
     * TrackbarCallback onChange:回调函数,当数值发生变化的时候调用的函数
     * void * userdata: 用户传入回调函数的参数,这里传入img
     */
    createTrackbar("pos", "二值化", &posTrackBar, maxValue, onChangeTrackBar, &img);
    cv::waitKey();
}

/******************** cv 重映射值 remap 和 创建自定义通道图片 create **********************/

void OpencvOperBase::fun_18(){
    //【0】变量定义
    cv::Mat srcImage, dstImage;
    cv::Mat map_x, map_y;

    //【1】载入原始图
    srcImage= cv::imread( "D:/Desktop/small_girl.jpg", 1 );
    if(!srcImage.data) {
        printf("读取图片错误，请确定目录下是否有imread函数指定的图片存在~！ \n");
        return;
    }
    imshow("src img", srcImage);

    //【2】创建和原始图一样的效果图，x重映射图，y重映射图
    dstImage.create(srcImage.size(), srcImage.type() );
    map_x.create(srcImage.size(), CV_32FC1 );
    map_y.create(srcImage.size(), CV_32FC1 );

    //【3】双层循环，遍历每一个像素点，改变map_x & map_y的值
    for(int j = 0; j < srcImage.rows;j++)
    {
        for(int i = 0; i < srcImage.cols;i++)
        {
            //改变map_x & map_y的值.
            //map_x 和 map_y 图中每个像素点分别装了原图像素点的映射位置
            //              map_x.at<float>(j,i)= static_cast<float>(i);
            map_x.at<float>(j,i)= static_cast<float>(srcImage.cols - i);
            map_y.at<float>(j,i)= static_cast<float>(j);
        }
    }

    //【4】进行重映射操作
    remap(srcImage, dstImage, map_x, map_y, cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(0,0,0) );

    //【5】显示效果图
    imshow("window map_x", map_x );
    //【5】显示效果图
    imshow("window map_y", map_y );

    //【5】显示效果图
    imshow("window dstImg", dstImage );
    cv::waitKey();
}

/*****************************************************/
// @brief 通道复制：mixChannels 函数
void OpencvOperBase::fun_19(){
    cv::Mat src = cv::imread("D:/Desktop/small_girl.jpg");
    cv::Mat hsvImg;

    imshow("src", src);

    //转换为 HSV 通道图像
    cvtColor(src, hsvImg, cv::COLOR_BGR2HSV);
    imshow("hsvImg", hsvImg);

    cv::Mat hImg = cv::Mat(src.size(), CV_8UC1);
    cv::Mat sImg = cv::Mat(src.size(), CV_8UC1);
    cv::Mat vImg = cv::Mat(src.size(), CV_8UC1);

    cv::Mat dst[] = { hImg,sImg,vImg };
    //hsvImg[0]->hImg[0] hImg 在 dst 中的通道索引为：0
    //hsvImg[1]->sImg[0] sImg 在 dst 中的通道索引为：1
    //hsvImg[2]->vImg[0] vImg 在 dst 中的通道索引为：2
    int fromTo[] = { 0,0,1,1,2,2 };

    /**
     * @brief 通道复制：mixChannels 函数. 主要就是把输入的图像（或图像集）的某些通道拆分复制给对应的输出图像（或图像集）的某些通道中，其中的对应关系由 fromTo 参数制定。
     * src，输入的图像或图像集，需要有相同的尺寸和深度。
     * nsrcs，输入图像个数。
     * dst，输出图像，所有图像必须被初始化，且大小和深度必须与 src[0] 相同。
     * ndsts，输出图像个数。
     * fromTo，输入图像通道与输出图像通道的对应关系
     * npairs，fromTo 的索引数，即有几个 fromTo。
     */
//    mixChannels(&src, 1, dst, 3, fromTo, 3);
    mixChannels(&hsvImg, 1, dst, 3, fromTo, 3);
    imshow("hImg", hImg);
    imshow("sImg", sImg);
    imshow("vImg", vImg);
}
