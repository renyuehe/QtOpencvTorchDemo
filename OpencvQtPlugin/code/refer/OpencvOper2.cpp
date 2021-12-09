#include "OpencvOper2.h"

void OpencvOper2::fun_01()
{
    // read image
    cv::Mat image = cv::imread("D:\\Desktop\\small_girl.jpg");

    // 对图像进行所有像素用 （255- 像素值）
    cv::Mat invertImage;
    image.copyTo(invertImage); //copyTo

    // 图片 hwc 按顺序访问，内存中位置是连续的
    int size;
    if (image.isContinuous()) //isContinuous 连续的
        size = image.cols * image.rows * image.channels();

    // 每个像素点的每个通道255取反
    uchar* p1 = image.ptr<uchar>(0);// 获取像素指针
    uchar* p2 = invertImage.ptr<uchar>(0);
    //    uchar* p1 = image.ptr(0);// 获取像素指针,可以对模板函数这么写,但是不建议,最好指明类型
    //    uchar* p2 = invertImage.ptr(0);


    for (int pos = 0; pos < size; pos++) {
        *p2 = 255 - *p1; // 取反
        p2++;
        p1++;
    }

    // create windows
    namedWindow("My Test", cv::WINDOW_AUTOSIZE);
    namedWindow("My Invert Image", cv::WINDOW_AUTOSIZE);

    // display image
    imshow("My Test", image);
    imshow("My Invert Image", invertImage);

    // 关闭
    cv::waitKey(0);
    cv::destroyWindow("My Test");
    cv::destroyWindow("My Invert Image");
}

void OpencvOper2::fun_02()
{
    cv::Mat src, dst;
    src = cv::imread("D:/Desktop/small_girl.jpg");
    if (!src.data)
    {
        printf("could not load image...\n");
        return;
    }
    namedWindow("input image", cv::WINDOW_AUTOSIZE);
    imshow("input image", src);


    int cols = (src.cols-1) * src.channels();
    int offsetx = src.channels();
    int rows = src.rows;

    /*
    dst = cv::Mat::zeros(src.size(), src.type());
    for (int row = 1; row < (rows - 1); row++) {
        const uchar* previous = src.ptr<uchar>(row - 1);
        const uchar* current = src.ptr<uchar>(row);
        const uchar* next = src.ptr<uchar>(row + 1);
        uchar* output = dst.ptr<uchar>(row);
        for (int col = offsetx; col < cols; col++) {
            output[col] = cv::saturate_cast<uchar>(5 * current[col] - (current[col- offsetx] + current[col+ offsetx] + previous[col] + next[col]));
        }
    }
    */

    double t = cv::getTickCount();//returns the number of ticks after the certain event

    //卷积操作 filter2D
    cv::Mat kernel = (cv::Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    CV_Assert(src.depth() == CV_8U);//断言:src.depth()的通道为无符号整数8位(0-255)

    filter2D(src, dst, src.depth(), kernel);//卷积操作

    //getTickCount 计时单位是秒，getTickFrequency 单位是微妙。
    double timeconsume = (cv::getTickCount() - t) / cv::getTickFrequency();
    printf("tim consume %.2f\n", timeconsume);

    namedWindow("contrast image demo", cv::WINDOW_AUTOSIZE);
    imshow("contrast image demo", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper2::fun_03()
{
    // 加载图像
    cv::Mat testImage = cv::imread("D:/test.jpg");
    CV_Assert(testImage.depth() == CV_8U);
    namedWindow("test_image", cv::WINDOW_AUTOSIZE);
    imshow("test_image", testImage);

    // 使用Filter2D函数
    cv::Mat result;
    cv::Mat kern = (cv::Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(testImage, result, testImage.depth(), kern);

    // 显示结果
    namedWindow("result_image", cv::WINDOW_AUTOSIZE);
    imshow("result_image", result);
    cv::waitKey(0);
}

void OpencvOper2::fun_04()
{
    cv::Mat src;
    src = cv::imread("D:/Desktop/small_girl.jpg");
    if (src.empty()) {
        cout << "could not load image..." << endl;
        return;
    }
    namedWindow("input", cv::WINDOW_AUTOSIZE);
    imshow("input", src);

    cv::Mat dst;
    namedWindow("output", cv::WINDOW_AUTOSIZE);

    //转换颜色空间
    cv::cvtColor(src, dst, cv::COLOR_BGR2GRAY);
    printf("input image channels : %d\n", src.channels());
    printf("output image channels : %d\n", dst.channels());

    int cols = dst.cols;
    int rows = dst.rows;

    printf("rows : %d cols : %d\n", rows, cols);
    const uchar* firstRow = dst.ptr<uchar>(0);
    printf("fist pixel value : %d\n", *firstRow);

    cv::Mat M(100, 100, CV_8UC1, cv::Scalar(127));
    //cout << "M =" << endl << M << endl;

    cv::Mat m1;
    m1.create(src.size(), src.type());
    m1 = cv::Scalar(0, 0, 255);

    cv::Mat csrc;
    cv::Mat kernel = (cv::Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(src, csrc, -1, kernel);

    cv::Mat m2 = cv::Mat::eye(2, 2, CV_8UC1);
    cout << "m2 =" << endl << m2 << endl;

    imshow("output", m2);
    cv::waitKey(0);
}

void OpencvOper2::fun_05()
{
    cv::Mat image = imread("D:/Desktop/small_girl.jpg", cv::IMREAD_COLOR);
    if (image.empty()) {
        cout << "could not find the image resource..." << std::endl;
        return;
    }

    cv::Mat grayImg;
    cvtColor(image, grayImg, cv::COLOR_BGR2GRAY);

    cv::Mat sobelx;
    Sobel(grayImg, sobelx, CV_32F, 1, 0);

    double minVal, maxVal;
    minMaxLoc(sobelx, &minVal, &maxVal); //find minimum and maximum intensities
    cv::Mat draw;
    sobelx.convertTo(draw, CV_8U, 255.0 / (maxVal - minVal), -minVal * 255.0 / (maxVal - minVal));
    /*
    int height = image.rows;
    int width = image.cols;
    int channels = image.channels();
    printf("height=%d width=%d channels=%d", height, width, channels);
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (channels == 3) {
                image.at<Vec3b>(row, col)[0] = 0; // blue
                image.at<Vec3b>(row, col)[1] = 0; // green
            }
        }
    }
    */
    namedWindow("My Image", cv::WINDOW_AUTOSIZE);
    imshow("My Image", draw);
    cv::waitKey(0);
}

void OpencvOper2::fun_06()
{
    cv::Mat src1, src2, dst;
    src1 = cv::imread("D:/Desktop/small_girl.jpg");
    src2 = cv::imread("D:/Desktop/small_sea.jpg");
    if (!src1.data) {
        cout << "could not load image Linux Logo..." << endl;
        return;
    }
    if (!src2.data) {
        cout << "could not load image WIN7 Logo..." << endl;
        return;
    }

    double alpha = 0.5;
    if (src1.rows == src2.rows && src1.cols == src2.cols && src1.type() == src2.type()) {
        //图像相加
//        addWeighted(src1, alpha, src2, (1.0 - alpha), 0.0, dst);
        //图像相乘
        multiply(src1, src2, dst, 1.0);

        imshow("linuxlogo", src1);
        imshow("win7logo", src2);
        namedWindow("blend demo", cv::WINDOW_AUTOSIZE);
        imshow("blend demo", dst);
    }
    else {
        printf("could not blend images , the size of images is not same...\n");
        return;
    }

    cv::waitKey(0);
}

void OpencvOper2::fun_07()
{
    cv::Mat src, dst;
    src = cv::imread("D:/Desktop/small_girl.jpg");
    if (!src.data) {
        printf("could not load image...\n");
        return;
    }
    char input_win[] = "input image gray";
    cvtColor(src, src, cv::COLOR_BGR2GRAY);
    namedWindow(input_win, cv::WINDOW_AUTOSIZE);
    imshow(input_win, src);//显示灰度图

    // contrast and brigthtness changes
    int height = src.rows;
    int width = src.cols;
    dst = cv::Mat::zeros(src.size(), src.type());
    float alpha = 1.2;
    float beta = 30;

    cv::Mat m1;
    src.convertTo(m1, CV_32F);//m1 接收src的矩阵,矩阵的类型转换成CV_32F

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {

            if (src.channels() == 3) {
                //如果是RGB图
                float b = m1.at<cv::Vec3f>(row, col)[0];// blue
                float g = m1.at<cv::Vec3f>(row, col)[1]; // green
                float r = m1.at<cv::Vec3f>(row, col)[2]; // red

                // output: row 和 col 确定唯一的像素点, Vec3b表示三个通道的向量,at是个模板类<类型>
                dst.at<cv::Vec3b>(row, col)[0] = cv::saturate_cast<uchar>(b*alpha + beta);
                dst.at<cv::Vec3b>(row, col)[1] = cv::saturate_cast<uchar>(g*alpha + beta);
                dst.at<cv::Vec3b>(row, col)[2] = cv::saturate_cast<uchar>(r*alpha + beta);
            }
            else if (src.channels() == 1) {
                //如果是灰度图
                float v = src.at<uchar>(row, col);
                dst.at<uchar>(row, col) = cv::saturate_cast<uchar>(v*alpha + beta);
            }
        }
    }

    char output_title[] = "contrast and brightness change demo";
    namedWindow(output_title, cv::WINDOW_AUTOSIZE);
    imshow(output_title, dst);

    cv::waitKey(0);
}

void OpencvOper2::fun_08()
{
    //绘图跳过
}

void OpencvOper2::fun_09()
{
    const char WINTITLE[] = "randomlines-demo";

    cv::Mat image = cv::Mat::zeros(cv::Size(450, 450), CV_8UC3);
    namedWindow(WINTITLE, cv::WINDOW_AUTOSIZE);

    cv::RNG rng(0xffffff);

    cv::Point pt1, pt2;
    for (int i = 0; i < 100000; i++) {
        pt1.x = rng.uniform(0, image.cols);
        pt2.x = rng.uniform(0, image.cols);
        pt1.y = rng.uniform(0, image.rows);
        pt2.y = rng.uniform(0, image.rows);
        int r = rng.uniform(0, 255);
        int g = rng.uniform(0, 255);
        int b = rng.uniform(0, 255);

        //绘制直线
        line(image, pt1, pt2, cv::Scalar(b, g, r), 1, cv::LINE_8);
        //绘制文字
        putText(image, "Open CV Core Tutorial", cv::Point(image.cols / 2-200, image.rows / 2),
            cv::FONT_HERSHEY_PLAIN, 2.0, cv::Scalar(0, 255, 0), 3, cv::LINE_8);

        imshow(WINTITLE, image);
        if (cv::waitKey(10) >= 0)
        {
            return;
        }
    }
}

void OpencvOper2::fun_10()
{
    cv::Mat src, dst;
    src = cv::imread("D:/vcprojects/images/test.png");
    if (!src.data) {
        printf("could not load image...\n");
        return;
    }
    char input_title[] = "input image";
    char output_title[] = "blur image";
    namedWindow(input_title, cv::WINDOW_AUTOSIZE);
    namedWindow(output_title, cv::WINDOW_AUTOSIZE);
    imshow(input_title, src);

    blur(src, dst, cv::Size(11, 11), cv::Point(-1, -1));
    imshow(output_title, dst);


    cv::Mat gblur;
    GaussianBlur(src, gblur, cv::Size(11, 11), 11, 11);
    imshow("gaussian blur", gblur);

    cv::waitKey(0);
}

void OpencvOper2::fun_11()
{
    cv::Mat src, dst;
    src = cv::imread("D:/vcprojects/images/cvtest.png");
    if (!src.data) {
        printf("could not load image...\n");
        return;
    }
    namedWindow("input image", cv::WINDOW_AUTOSIZE);
    imshow("input image", src);

    //medianBlur(src, dst, 3);
    bilateralFilter(src, dst, 15, 100, 5);
    namedWindow("BiBlur Filter Result", cv::WINDOW_AUTOSIZE);
    imshow("BiBlur Filter Result", dst);

    cv::Mat resultImg;
    cv::Mat kernel = (cv::Mat_<int>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(dst, resultImg, -1, kernel, cv::Point(-1, -1), 0);
    imshow("Final Result", resultImg);

    cv::waitKey(0);
}


/***************************************************/
cv::Mat src12, dst12;
char OUTPUT_WIN12[] = "output image";
int element_size12 = 3;
int max_size12 = 21;
void CallBack_Demo(int, void*);
void CallBack_Demo(int, void*) {
    int s = element_size12 * 2 + 1;
    cv::Mat structureElement = getStructuringElement(cv::MORPH_RECT, cv::Size(s, s), cv::Point(-1, -1));
    // dilate(src12, dst12, structureElement, Point(-1, -1), 1);
    erode(src12, dst12, structureElement);
    imshow("output image", dst12);
    return;
}

void OpencvOper2::fun_12()
{
    src12 = cv::imread("D:/vcprojects/images/test1.png");
    if (!src12.data) {
        printf("could not load image...\n");
        return;
    }
    namedWindow("input image", cv::WINDOW_AUTOSIZE);
    imshow("input image", src12);

    namedWindow(OUTPUT_WIN12, cv::WINDOW_AUTOSIZE);
    cv::createTrackbar("Element Size :", OUTPUT_WIN12, &element_size12, max_size12, CallBack_Demo);
    CallBack_Demo(0, 0);

    cv::waitKey(0);
}
/***************************************************/

void OpencvOper2::fun_13()
{
    cv::Mat src, dst;
    src = cv::imread("D:/vcprojects/images/bin2.png");
    if (!src.data) {
        printf("could not load image...\n");
    }
    namedWindow("input image", cv::WINDOW_AUTOSIZE);
    imshow("input image", src);
    char output_title[] = "morphology demo";
    namedWindow(output_title, cv::WINDOW_AUTOSIZE);

    cv::Mat kernel = getStructuringElement(cv::MORPH_RECT, cv::Size(11, 11), cv::Point(-1, -1));
    cv::morphologyEx(src, dst, cv::MORPH_BLACKHAT, kernel);
    imshow(output_title, dst);

    cv::waitKey(0);
}
/***************************************************/
void OpencvOper2::fun_14()
{
    cv::Mat src, dst;
    src = cv::imread("D:/vcprojects/images/chars.png");
    if (!src.data) {
        printf("could not load image...\n");
        return;
    }

    char INPUT_WIN[] = "input image";
    char OUTPUT_WIN[] = "result image";
    namedWindow(INPUT_WIN, cv::WINDOW_AUTOSIZE);
    imshow(INPUT_WIN, src);

    cv::Mat gray_src;
    cvtColor(src, gray_src, cv::COLOR_BGR2GRAY);
    imshow("gray image", gray_src);

    cv::Mat binImg;
    adaptiveThreshold(~gray_src, binImg, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 15, -2);
    imshow("binary image", binImg);

    // 水平结构元素
    cv::Mat hline = getStructuringElement(cv::MORPH_RECT, cv::Size(src.cols / 16, 1), cv::Point(-1, -1));
    // 垂直结构元素
    cv::Mat vline = getStructuringElement(cv::MORPH_RECT, cv::Size(1, src.rows / 16), cv::Point(-1, -1));
    // 矩形结构
    cv::Mat kernel = getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3), cv::Point(-1, -1));

    cv::Mat temp;
    erode(binImg, temp, kernel);
    dilate(temp, dst, kernel);
    // morphologyEx(binImg, dst, CV_MOP_OPEN, vline);
    bitwise_not(dst, dst);
    //blur(dst, dst, Size(3, 3), Point(-1, -1));
    imshow("Final Result", dst);

    cv::waitKey(0);
}
/***************************************************/
void OpencvOper2::fun_15()
{
    cv::Mat src, dst;
    src = cv::imread("D:/vcprojects/images/cat.jpg");
    if (!src.data) {
        printf("could not load image...");
        return;
    }

    char INPUT_WIN[] = "input image";
    char OUTPUT_WIN[] = "sample up";
    namedWindow(INPUT_WIN, cv::WINDOW_AUTOSIZE);
    namedWindow(OUTPUT_WIN, cv::WINDOW_AUTOSIZE);
    imshow(INPUT_WIN, src);

    // 上采样
    pyrUp(src, dst, cv::Size(src.cols*2, src.rows * 2));
    imshow(OUTPUT_WIN, dst);

    // 降采样
    cv::Mat s_down;
    pyrDown(src, s_down, cv::Size(src.cols / 2, src.rows / 2));
    imshow("sample down", s_down);

    // DOG
    cv::Mat gray_src, g1, g2, dogImg;
    cvtColor(src, gray_src, cv::COLOR_BGR2GRAY);
    GaussianBlur(gray_src, g1, cv::Size(5, 5), 0, 0);
    GaussianBlur(g1, g2, cv::Size(5, 5), 0, 0);
    subtract(g1, g2, dogImg, cv::Mat());

    // 归一化显示
    normalize(dogImg, dogImg, 255, 0, cv::NORM_MINMAX);
    imshow("DOG Image", dogImg);

    cv::waitKey(0);
}

/**********************/
cv::Mat src16, gray_src16, dst16;
int threshold_value16 = 127;
int threshold_max16 = 255;
int type_value16 = 2;
int type_max16 = 4;
const char* output_title = "binary image";
void Threshold_Demo(int, void*);
void OpencvOper2::fun_16()
{
    src16 = cv::imread("D:/vcprojects/images/test.png");
    if (!src16.data) {
        printf("could not load image...\n");
        return;
    }
    namedWindow("input image", cv::WINDOW_AUTOSIZE);
    namedWindow("output_title", cv::WINDOW_AUTOSIZE);
    imshow("input image", src16);

    cv::createTrackbar("Threshold Value:", output_title, &threshold_value16, threshold_max16, Threshold_Demo);
    cv::createTrackbar("Type Value:", output_title, &type_value16, type_max16, Threshold_Demo);
    Threshold_Demo(0, 0);

    cv::waitKey(0);
}
void Threshold_Demo(int, void*) {
    cvtColor(src16, gray_src16, cv::COLOR_BGR2GRAY);
    threshold(src16, dst16, 0, 255, cv::THRESH_TRIANGLE | type_value16);
    imshow(output_title, dst16);
}
/**********************/

void OpencvOper2::fun_17()
{
    cv::Mat src, dst;
    int ksize = 0;

    src = cv::imread("D:/vcprojects/images/test1.png");
    if (!src.data) {
        printf("could not load image...\n");
        return;
    }

    char INPUT_WIN[] = "input image";
    char OUTPUT_WIN[] = "Custom Blur Filter Result";
    namedWindow(INPUT_WIN, cv::WINDOW_AUTOSIZE);
    namedWindow(OUTPUT_WIN, cv::WINDOW_AUTOSIZE);

    imshow(INPUT_WIN, src);

    // Sobel X 方向
    // Mat kernel_x = (Mat_<int>(3, 3) << -1, 0, 1, -2,0,2,-1,0,1);
    // filter2D(src, dst, -1, kernel_x, Point(-1, -1), 0.0);

    // Sobel Y 方向
    // Mat yimg;
    // Mat kernel_y = (Mat_<int>(3, 3) << -1, -2, -1, 0,0,0, 1,2,1);
    // filter2D(src, yimg, -1, kernel_y, Point(-1, -1), 0.0);

    // 拉普拉斯算子
    //Mat kernel_y = (Mat_<int>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
    //filter2D(src, dst, -1, kernel_y, Point(-1, -1), 0.0);
    int c = 0;
    int index = 0;
    while (true) {
        c = cv::waitKey(500);
        if ((char)c == 27) {// ESC
            break;
        }
        ksize = 5 + (index % 8) * 2;
        cv::Mat kernel = cv::Mat::ones(cv::Size(ksize, ksize), CV_32F) / (float)(ksize * ksize);
        filter2D(src, dst, -1, kernel, cv::Point(-1, -1));
        index++;
        imshow(OUTPUT_WIN, dst);
    }

    // imshow("Sobel Y", yimg);
}

void OpencvOper2::fun_18()
{
    cv::Mat src, dst;
    src = cv::imread("D:/vcprojects/images/test.jpg");
    if (!src.data) {
        printf("could not load image...\n");
        return;
    }
    char INPUT_WIN[] = "input image";
    char OUTPUT_WIN[] = "Border Demo";
    namedWindow(INPUT_WIN, cv::WINDOW_AUTOSIZE);
    namedWindow(OUTPUT_WIN, cv::WINDOW_AUTOSIZE);
    imshow(INPUT_WIN, src);
    /*
    int top = (int)(0.05*src.rows);
    int bottom = (int)(0.05*src.rows);
    int left = (int)(0.05*src.cols);
    int right = (int)(0.05*src.cols);
    RNG rng(12345);
    int borderType = BORDER_DEFAULT;

    int c = 0;
    while (true) {
        c = waitKey(500);
        // ESC
        if ((char)c == 27) {
            break;
        }
        if ((char)c == 'r') {
            borderType = BORDER_REPLICATE;
        } else if((char)c == 'w') {
            borderType = BORDER_WRAP;
        } else if((char)c == 'c') {
            borderType = BORDER_CONSTANT;
        }
        Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        copyMakeBorder(src, dst, top, bottom, left, right, borderType, color);
        imshow(OUTPUT_WIN, dst);
    }
    */

    GaussianBlur(src, dst, cv::Size(5, 5), 0, 0);
    imshow(OUTPUT_WIN, dst);

    cv::waitKey(0);
}

void OpencvOper2::fun_19()
{
    cv::Mat src, dst;
    src = cv::imread("D:/vcprojects/images/test.png");
    if (!src.data) {
        printf("could not load image...\n");
        return;
    }

    char INPUT_TITLE[] = "input image";
    char OUTPUT_TITLE[] = "sobel-demo";
    namedWindow(INPUT_TITLE, cv::WINDOW_AUTOSIZE);
    namedWindow(OUTPUT_TITLE, cv::WINDOW_AUTOSIZE);
    imshow(INPUT_TITLE, src);

    cv::Mat gray_src;
    GaussianBlur(src, dst, cv::Size(3, 3), 0, 0);
    cvtColor(dst, gray_src, cv::COLOR_BGR2GRAY);
    imshow("gray image", gray_src);

    cv::Mat xgrad, ygrad;
    Scharr(gray_src, xgrad, CV_16S, 1, 0);
    Scharr(gray_src, ygrad, CV_16S, 0, 1);

    // Sobel(gray_src, xgrad, CV_16S, 1, 0, 3);
    // Sobel(gray_src, ygrad, CV_16S, 0, 1, 3);
    convertScaleAbs(xgrad, xgrad);
    convertScaleAbs(ygrad, ygrad);
    imshow("xgrad", xgrad);
    imshow("ygrad", ygrad);

    cv::Mat xygrad = cv::Mat(xgrad.size(), xgrad.type());
    printf("type : %d\n", xgrad.type());
    int width = xgrad.cols;
    int height = ygrad.rows;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int xg = xgrad.at<uchar>(row, col);
            int yg = ygrad.at<uchar>(row, col);
            int xy = xg + yg;
            xygrad.at<uchar>(row, col) = cv::saturate_cast<uchar>(xy);
        }
    }
    //addWeighted(xgrad, 0.5, ygrad, 0.5, 0, xygrad);
    imshow(OUTPUT_TITLE, xygrad);

    cv::waitKey(0);
}

void OpencvOper2::fun_20()
{
    cv::Mat src, dst;
    src = cv::imread("D:/vcprojects/images/lena.png");
    if (!src.data) {
        printf("could not load image");
    }
    char input_title[] = "input image";
    char output_title[] = "Laplaiance Result";
    namedWindow(input_title, cv::WINDOW_AUTOSIZE);
    imshow(input_title, src);

    cv::Mat gray_src, edge_image;
    GaussianBlur(src, dst, cv::Size(3, 3), 0, 0);
    cvtColor(dst, gray_src, cv::COLOR_BGR2GRAY);

    Laplacian(gray_src, edge_image, CV_16S, 3);
    convertScaleAbs(edge_image, edge_image);

    threshold(edge_image, edge_image, 0, 255, cv::THRESH_OTSU | cv::THRESH_BINARY);
    namedWindow(output_title, cv::WINDOW_AUTOSIZE);
    imshow(output_title, edge_image);

    cv::waitKey(0);
}


cv::Mat src21, gray_src21, dst21;
int t1_value = 50;
int max_value = 255;
const char* OUTPUT_TITLE = "Canny Result";
void Canny_Demo(int, void*);
void OpencvOper2::fun_21()
{
    src21 = cv::imread("D:/vcprojects/images/lena.png");
    if (!src21.data) {
        printf("could not load image...\n");
        return;
    }

    char INPUT_TITLE[] = "input image";
    namedWindow(INPUT_TITLE, cv::WINDOW_AUTOSIZE);
    namedWindow(OUTPUT_TITLE, cv::WINDOW_AUTOSIZE);
    imshow(INPUT_TITLE, src21);

    cvtColor(src21, gray_src21, cv::COLOR_BGR2GRAY);
    cv::createTrackbar("Threshold Value:", OUTPUT_TITLE, &t1_value, max_value, Canny_Demo);
    Canny_Demo(0, 0);

    cv::waitKey(0);
}
void Canny_Demo(int, void*) {
    cv::Mat edge_output;
    blur(gray_src21, gray_src21, cv::Size(3, 3), cv::Point(-1, -1), cv::BORDER_DEFAULT);
    Canny(gray_src21, edge_output, t1_value, t1_value * 2, 3, false);

    //dst21.create(src.size(), src.type());
    //src.copyTo(dst21, edge_output);
    // (edge_output, edge_output);
    imshow(OUTPUT_TITLE, ~edge_output);
}

void OpencvOper2::fun_22()
{
    cv::Mat src, src_gray, dst;
    src = cv::imread("D:/vcprojects/images/lines.png");
    if (!src.data) {
        printf("could not load image...\n");
        return;
    }

    char INPUT_TITLE[] = "input image";
    char OUTPUT_TITLE[] = "hough-line-detection";
    namedWindow(INPUT_TITLE, cv::WINDOW_AUTOSIZE);
    namedWindow(OUTPUT_TITLE, cv::WINDOW_AUTOSIZE);
    imshow(INPUT_TITLE, src);

    // extract edge
    Canny(src, src_gray, 150, 200);
    cvtColor(src_gray, dst, cv::COLOR_GRAY2BGR);
    imshow("edge image", src_gray);

    vector<cv::Vec2f> lines;
    HoughLines(src_gray, lines, 1, CV_PI / 180, 150, 0, 0);
    for (size_t i = 0; i < lines.size(); i++) {
        float rho = lines[i][0]; // 极坐标中的r长度
        float theta = lines[i][1]; // 极坐标中的角度
        cv::Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a*rho, y0 = b*rho;
        // 转换为平面坐标的四个点
        pt1.x = cvRound(x0 + 1000 * (-b));
        pt1.y = cvRound(y0 + 1000 * (a));
        pt2.x = cvRound(x0 - 1000 * (-b));
        pt2.y = cvRound(y0 - 1000 * (a));
        cv::line(dst, pt1, pt2, cv::Scalar(0, 0, 255), 1, cv::LINE_AA);
    }

    /*
    vector<Vec4f> plines;
    HoughLinesP(src_gray, plines, 1, CV_PI / 180.0, 10, 0, 10);
    Scalar color = Scalar(0, 0, 255);
    for (size_t i = 0; i < plines.size(); i++) {
        Vec4f hline = plines[i];
        line(dst, Point(hline[0], hline[1]), Point(hline[2], hline[3]), color, 3, LINE_AA);
    }*/
    imshow(OUTPUT_TITLE, dst);

    cv::waitKey(0);
}

void OpencvOper2::fun_23()
{
    cv::Mat src, dst;
    src = cv::imread("D:/vcprojects/images/circle.png");
    if (!src.data) {
        printf("could not load image...\n");
        return;
    }
    char INPUT_TITLE[] = "input image";
    char OUTPUT_TITLE[] = "hough circle demo";
    namedWindow(INPUT_TITLE, cv::WINDOW_AUTOSIZE);
    namedWindow(OUTPUT_TITLE, cv::WINDOW_AUTOSIZE);
    imshow(INPUT_TITLE, src);

    // 中值滤波
    cv::Mat moutput;
    medianBlur(src, moutput, 3);
    cvtColor(moutput, moutput, cv::COLOR_BGR2GRAY);

    // 霍夫圆检测
    vector<cv::Vec3f> pcircles;
    HoughCircles(moutput, pcircles, cv::HOUGH_GRADIENT, 1, 10, 100, 30, 5, 50);
    src.copyTo(dst);
    for (size_t i = 0; i < pcircles.size(); i++) {
        cv::Vec3f cc = pcircles[i];
        circle(dst, cv::Point(cc[0], cc[1]), cc[2], cv::Scalar(0, 0, 255), 2, cv::LINE_AA);
        circle(dst, cv::Point(cc[0], cc[1]), 2, cv::Scalar(198, 23, 155), 2, cv::LINE_AA);
    }
    imshow(OUTPUT_TITLE, dst);

    cv::waitKey(0);
}


/**************************************/
cv::Mat src24, dst24, map_x24, map_y24;
const char* OUTPUT_TITLE24 = "remap demo";
int index24 = 0;
void update_map(void);
void OpencvOper2::fun_24()
{
    src24 = cv::imread("D:/vcprojects/images/test.png");
    if (!src24.data) {
        printf("could not load image...\n");
        return;
    }
    char input_win[] = "input image";
    namedWindow(input_win, cv::WINDOW_AUTOSIZE);
    namedWindow(OUTPUT_TITLE24, cv::WINDOW_AUTOSIZE);
    imshow(input_win, src24);

    map_x24.create(src24.size(), CV_32FC1);
    map_y24.create(src24.size(), CV_32FC1);

    int c = 0;
    while (true) {
        c = cv::waitKey(500);
        if ((char)c == 27) {
            break;
        }
        index24 = c % 4;
        update_map();
        remap(src24, dst24, map_x24, map_y24, cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(0, 255, 255));
        imshow(OUTPUT_TITLE24, dst24);
    }
}
void update_map(void) {
    for (int row = 0; row < src24.rows; row++) {
        for (int col = 0; col < src24.cols; col++) {
            switch (index24) {
            case 0:
                if (col > (src24.cols * 0.25) && col <= (src24.cols*0.75) && row > (src24.rows*0.25) && row <= (src24.rows*0.75)) {
                    map_x24.at<float>(row, col) = 2 * (col - (src24.cols*0.25));
                    map_y24.at<float>(row, col) = 2 * (row - (src24.rows*0.25));
                }
                else {
                    map_x24.at<float>(row, col) = 0;
                    map_y24.at<float>(row, col) = 0;
                }
                break;
            case 1:
                map_x24.at<float>(row, col) = (src24.cols - col - 1);
                map_y24.at<float>(row, col) = row;
                break;
            case 2:
                map_x24.at<float>(row, col) = col;
                map_y24.at<float>(row, col) = (src24.rows - row - 1);
                break;
            case 3:
                map_x24.at<float>(row, col) = (src24.cols - col - 1);
                map_y24.at<float>(row, col) = (src24.rows - row - 1);
                break;
            }
        }
    }
}
/**************************************/

void OpencvOper2::fun_25()
{
    cv::Mat src, dst;
    src = cv::imread("D:/vcprojects/images/test.png");
    if (!src.data) {
        printf("could not load image...\n");
        return;
    }

    cvtColor(src, src, cv::COLOR_BGR2GRAY);
    equalizeHist(src, dst);
    char INPUT_T[] = "input image";
    char OUTPUT_T[] = "result image";
    namedWindow(INPUT_T, cv::WINDOW_AUTOSIZE);
    namedWindow(OUTPUT_T, cv::WINDOW_AUTOSIZE);

    imshow(INPUT_T, src);
    imshow(OUTPUT_T, dst);

    cv::waitKey(0);
}

void OpencvOper2::fun_26()
{
    cv::Mat src = cv::imread("D:/vcprojects/images/test.png");
    if (!src.data) {
        printf("could not load image...\n");
        return;
    }
    char INPUT_T[] = "input image";
    char OUTPUT_T[] = "histogram demo";
    namedWindow(INPUT_T, cv::WINDOW_AUTOSIZE);
    namedWindow(OUTPUT_T, cv::WINDOW_AUTOSIZE);
    imshow(INPUT_T, src);

    // 分通道显示
    vector<cv::Mat> bgr_planes;
    split(src, bgr_planes);
    //imshow("single channel demo", bgr_planes[0]);

    // 计算直方图
    int histSize = 256;
    float range[] = { 0, 256 };
    const float *histRanges = { range };
    cv::Mat b_hist, g_hist, r_hist;
    calcHist(&bgr_planes[0], 1, 0, cv::Mat(), b_hist, 1, &histSize, &histRanges, true, false);
    calcHist(&bgr_planes[1], 1, 0, cv::Mat(), g_hist, 1, &histSize, &histRanges, true, false);
    calcHist(&bgr_planes[2], 1, 0, cv::Mat(), r_hist, 1, &histSize, &histRanges, true, false);

    // 归一化
    int hist_h = 400;
    int hist_w = 512;
    int bin_w = hist_w / histSize;
    cv::Mat histImage(hist_w, hist_h, CV_8UC3, cv::Scalar(0, 0, 0));
    normalize(b_hist, b_hist, 0, hist_h, cv::NORM_MINMAX, -1, cv::Mat());
    normalize(g_hist, g_hist, 0, hist_h, cv::NORM_MINMAX, -1, cv::Mat());
    normalize(r_hist, r_hist, 0, hist_h, cv::NORM_MINMAX, -1, cv::Mat());

    // render histogram chart
    for (int i = 1; i < histSize; i++) {
        line(histImage, cv::Point((i - 1)*bin_w, hist_h - cvRound(b_hist.at<float>(i - 1))),
            cv::Point((i)*bin_w, hist_h - cvRound(b_hist.at<float>(i))), cv::Scalar(255, 0, 0), 2, cv::LINE_AA);

        line(histImage, cv::Point((i - 1)*bin_w, hist_h - cvRound(g_hist.at<float>(i - 1))),
            cv::Point((i)*bin_w, hist_h - cvRound(g_hist.at<float>(i))), cv::Scalar(0, 255, 0), 2, cv::LINE_AA);

        line(histImage, cv::Point((i - 1)*bin_w, hist_h - cvRound(r_hist.at<float>(i - 1))),
            cv::Point((i)*bin_w, hist_h - cvRound(r_hist.at<float>(i))), cv::Scalar(0, 0, 255), 2, cv::LINE_AA);
    }
    imshow(OUTPUT_T, histImage);

    cv::waitKey(0);
}

/**********************************/
string convertToString(double d);

void OpencvOper2::fun_27()
{
    cv::Mat base, test1, test2;
    cv::Mat hsvbase, hsvtest1, hsvtest2;
    base = cv::imread("D:/vcprojects/images/test.jpg");
    if (!base.data) {
        printf("could not load image...\n");
        return;
    }
    test1 = cv::imread("D:/vcprojects/images/lena.png");
    test2 = cv::imread("D:/vcprojects/images/lenanoise.png");

    cvtColor(base, hsvbase, cv::COLOR_BGR2HSV);
    cvtColor(test1, hsvtest1, cv::COLOR_BGR2HSV);
    cvtColor(test2, hsvtest2, cv::COLOR_BGR2HSV);

    int h_bins = 50; int s_bins = 60;
    int histSize[] = { h_bins, s_bins };
    // hue varies from 0 to 179, saturation from 0 to 255
    float h_ranges[] = { 0, 180 };
    float s_ranges[] = { 0, 256 };
    const float* ranges[] = { h_ranges, s_ranges };
    // Use the o-th and 1-st channels
    int channels[] = { 0, 1 };
    cv::MatND hist_base;
    cv::MatND hist_test1;
    cv::MatND hist_test2;

    calcHist(&hsvbase, 1,  channels, cv::Mat(), hist_base, 2, histSize, ranges, true, false);
    normalize(hist_base, hist_base, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());

    calcHist(&hsvtest1, 1, channels, cv::Mat(), hist_test1, 2, histSize, ranges, true, false);
    normalize(hist_test1, hist_test1, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());

    calcHist(&hsvtest2, 1, channels, cv::Mat(), hist_test2, 2, histSize, ranges, true, false);
    normalize(hist_test2, hist_test2, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());

    double basebase = compareHist(hist_base, hist_base, cv::HISTCMP_INTERSECT);
    double basetest1 = compareHist(hist_base, hist_test1, cv::HISTCMP_INTERSECT);
    double basetest2 = compareHist(hist_base, hist_test2, cv::HISTCMP_INTERSECT);
    double tes1test2 = compareHist(hist_test1, hist_test2, cv::HISTCMP_INTERSECT);
    printf("test1 compare with test2 correlation value :%f", tes1test2);

    cv::Mat test12;
    test2.copyTo(test12);
    putText(base, convertToString(basebase), cv::Point(50, 50), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(0, 0, 255), 2, cv::LINE_AA);
    putText(test1, convertToString(basetest1), cv::Point(50, 50), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(0, 0, 255), 2, cv::LINE_AA);
    putText(test2, convertToString(basetest2), cv::Point(50, 50), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(0, 0, 255), 2, cv::LINE_AA);
    putText(test12, convertToString(tes1test2), cv::Point(50, 50), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(0, 0, 255), 2, cv::LINE_AA);

    namedWindow("base", cv::WINDOW_AUTOSIZE);
    namedWindow("test1", cv::WINDOW_AUTOSIZE);
    namedWindow("test2", cv::WINDOW_AUTOSIZE);

    imshow("base", base);
    imshow("test1", test1);
    imshow("test2", test2);
    imshow("test12", test12);

    cv::waitKey(0);
}
string convertToString(double d) {
    ostringstream os;
    if (os << d)
        return os.str();
    return "invalid conversion";
}
/**********************************/

/******************************/
cv::Mat src28; cv::Mat hsv28; cv::Mat hue28;
int bins28 = 12;
void Hist_And_Backprojection(int, void*);

void OpencvOper2::fun_28()
{
    src28 = cv::imread("D:/vcprojects/images/t1.jpg");
    if (src28.empty()) {
        printf("could not load image...\n");
        return;
    }
    const char*  window_image = "input image";
    namedWindow(window_image, cv::WINDOW_NORMAL);
    namedWindow("BackProj", cv::WINDOW_NORMAL);
    namedWindow("Histogram", cv::WINDOW_NORMAL);

    cvtColor(src28, hsv28, cv::COLOR_BGR2HSV);
    hue28.create(hsv28.size(), hsv28.depth());
    int nchannels[] = { 0, 0 };
    //通道复制
    mixChannels(&hsv28, 1, &hue28, 1, nchannels, 1);

    cv::createTrackbar("Histogram Bins:", window_image, &bins28, 180, Hist_And_Backprojection);
    Hist_And_Backprojection(0, 0);

    imshow(window_image, src28);
    cv::waitKey(0);
}
void Hist_And_Backprojection(int, void*) {
    float range[] = { 0, 180 };
    const float *histRanges = { range };
    cv::Mat h_hist;
    calcHist(&hue28, 1, 0, cv::Mat(), h_hist, 1, &bins28, &histRanges, true, false);
    normalize(h_hist, h_hist, 0, 255, cv::NORM_MINMAX, -1, cv::Mat());

    cv::Mat backPrjImage;
    //计算反向投影
    calcBackProject(&hue28, 1, 0, h_hist, backPrjImage, &histRanges, 1, true);
    imshow("BackProj", backPrjImage);

    int hist_h = 400;
    int hist_w = 400;
    cv::Mat histImage(hist_w, hist_h, CV_8UC3, cv::Scalar(0, 0, 0));
    int bin_w = (hist_w / bins28);
    for (int i = 1; i < bins28; i++) {
        rectangle(histImage,
            cv::Point((i - 1)*bin_w, (hist_h - cvRound(h_hist.at<float>(i - 1) * (400 / 255)))),
            //Point(i*bin_w, (hist_h - cvRound(h_hist.at<float>(i) * (400 / 255)))),
            cv::Point(i*bin_w, hist_h),
            cv::Scalar(0, 0, 255), -1);
    }
    imshow("Histogram", histImage);

    return;
}
/******************************/


/******************************/

cv::Mat src29, temp29, dst29;
int match_method = cv::TM_SQDIFF;
int max_track = 5;
const char* INPUT_T = "input image";
const char* OUTPUT_T = "result image";
const char* match_t = "template match-demo";
void Match_Demo(int, void*);

void OpencvOper2::fun_29()
{
    // 待检测图像
    src29 = cv::imread("D:/vcprojects/images/flower.png");
    // 模板图像
    temp29 = cv::imread("D:/vcprojects/images/t2.png");
    if (src29.empty() || temp29.empty()) {
        printf("could not load image...\n");
        return;
    }
    namedWindow(INPUT_T, cv::WINDOW_AUTOSIZE);
    namedWindow(OUTPUT_T, cv::WINDOW_NORMAL);
    namedWindow(match_t, cv::WINDOW_AUTOSIZE);
    imshow(INPUT_T, temp29);
    const char* trackbar_title = "Match Algo Type:";
    cv::createTrackbar(trackbar_title, OUTPUT_T, &match_method, max_track, Match_Demo);
    Match_Demo(0, 0);

    cv::waitKey(0);
}

void Match_Demo(int, void*) {
    int width = src29.cols - temp29.cols + 1;
    int height = src29.rows - temp29.rows + 1;
    cv::Mat result(width, height, CV_32FC1);

    //模板匹配(模式匹配)
    matchTemplate(src29, temp29, result, match_method, cv::Mat());
    normalize(result, result, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());

    cv::Point minLoc;
    cv::Point maxLoc;
    double min, max;
    src29.copyTo(dst29);
    cv::Point temLoc;
    minMaxLoc(result, &min, &max, &minLoc, &maxLoc, cv::Mat());
    if (match_method == cv::TM_SQDIFF || match_method == cv::TM_SQDIFF_NORMED) {
        temLoc = minLoc;
    } else {
        temLoc = maxLoc;
    }

    // 绘制矩形
    rectangle(dst29, cv::Rect(temLoc.x, temLoc.y, temp29.cols, temp29.rows), cv::Scalar(0, 0, 255), 2, 8);
    rectangle(result, cv::Rect(temLoc.x, temLoc.y, temp29.cols, temp29.rows), cv::Scalar(0, 0, 255), 2, 8);

    imshow(OUTPUT_T, result);
    imshow(match_t, dst29);
}

/******************************/


/******************************/
cv::Mat src30, dst30;
const char* output_win30 = "findcontours-demo";
int threshold_value30 = 100;
int threshold_max30 = 255;
void Demo_Contours(int, void*);

void OpencvOper2::fun_30()
{
    src30 = cv::imread("D:/vcprojects/images/happyfish.png");
    if (src30.empty()) {
        printf("could not load image...\n");
        return;
    }
    namedWindow("input-image", cv::WINDOW_AUTOSIZE);
    namedWindow(output_win30, cv::WINDOW_AUTOSIZE);
    imshow("input-image", src30);
    cvtColor(src30, src30, cv::COLOR_BGR2GRAY);

    const char* trackbar_title = "Threshold Value:";
    cv::createTrackbar(trackbar_title, output_win30, &threshold_value30, threshold_max30, Demo_Contours);
    Demo_Contours(0, 0);

    cv::waitKey(0);
}

void Demo_Contours(int, void*) {
    cv::Mat canny_output;
    vector<vector<cv::Point>> contours;
    vector<cv::Vec4i> hierachy;
    Canny(src30, canny_output, threshold_value30, threshold_value30 * 2, 3, false);
    findContours(canny_output, contours, hierachy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

    dst30 = cv::Mat::zeros(src30.size(), CV_8UC3);
    cv::RNG rng(12345);
    for (size_t i = 0; i < contours.size(); i++) {
        cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        drawContours(dst30, contours, i, color, 2, 8, hierachy, 0, cv::Point(0, 0));
    }
    imshow(output_win30, dst30);
}

/******************************/

/******************************/
cv::Mat src31, src_gray31, dst31;
int threshold_value31 = 100;
int threshold_max31 = 255;
const char* output_win31 = "convex hull demo";
void Threshold_Callback(int, void*);
cv::RNG rng31(12345);

void OpencvOper2::fun_31()
{
    src31 = cv::imread("D:/vcprojects/images/hand.png");
    if (!src31.data) {
        printf("could not load image...\n");
        return;
    }
    const char* input_win = "input image";
    namedWindow(input_win, cv::WINDOW_AUTOSIZE);
    namedWindow(output_win31, cv::WINDOW_NORMAL);
    const char* trackbar_label = "Threshold : ";

    cvtColor(src31, src_gray31, cv::COLOR_BGR2GRAY);
    blur(src_gray31, src_gray31, cv::Size(3, 3), cv::Point(-1, -1), cv::BORDER_DEFAULT);
    imshow(input_win, src_gray31);

    cv::createTrackbar(trackbar_label, output_win31, &threshold_value31, threshold_max31, Threshold_Callback);
    Threshold_Callback(0, 0);
    cv::waitKey(0);
}
void Threshold_Callback(int, void*) {
    cv::Mat bin_output;
    vector<vector<cv::Point>> contours;
    vector<cv::Vec4i> hierachy;

    threshold(src_gray31, bin_output, threshold_value31, threshold_max31, cv::THRESH_BINARY);
    findContours(bin_output, contours, hierachy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

    vector<vector<cv::Point>> convexs(contours.size());
    for (size_t i = 0; i < contours.size(); i++) {
        convexHull(contours[i], convexs[i], false, true);
    }

    // ╗Ток
    dst31 = cv::Mat::zeros(src31.size(), CV_8UC3);
    vector<cv::Vec4i> empty(0);
    for (size_t k = 0; k < contours.size(); k++) {
        cv::Scalar color = cv::Scalar(rng31.uniform(0, 255), rng31.uniform(0, 255), rng31.uniform(0, 255));
        drawContours(dst31, contours, k, color, 2, cv::LINE_8, hierachy, 0, cv::Point(0, 0));
        drawContours(dst31, convexs, k, color, 2, cv::LINE_8, empty, 0, cv::Point(0, 0));
    }
    imshow(output_win31, dst31);

    return;
}
/******************************/


/******************************/
cv::Mat src32, gray_src32, drawImg32;
int threshold_v32 = 170;
int threshold_max32 = 255;
const char* output_win32 = "rectangle-demo";
cv::RNG rng32(12345);
void Contours_Callback(int, void*);

void OpencvOper2::fun_32()
{
    src32 = cv::imread("D:/vcprojects/images/hotball.png");
    if (!src32.data) {
        printf("could not load image...\n");
        return;
    }
    cvtColor(src32, gray_src32, cv::COLOR_BGR2GRAY);
    blur(gray_src32, gray_src32, cv::Size(3, 3), cv::Point(-1, -1));

    const char* source_win = "input image";
    namedWindow(source_win, cv::WINDOW_AUTOSIZE);
    namedWindow(output_win32, cv::WINDOW_AUTOSIZE);
    imshow(source_win, src32);

    cv::createTrackbar("Threshold Value:", output_win32, &threshold_v32, threshold_max32, Contours_Callback);
    Contours_Callback(0, 0);

    cv::waitKey(0);
}

void Contours_Callback(int, void*) {
    cv::Mat binary_output;
    vector<vector<cv::Point>> contours;
    vector<cv::Vec4i> hierachy;
    threshold(gray_src32, binary_output, threshold_v32, threshold_max32, cv::THRESH_BINARY);
    //imshow("binary image", binary_output);
    findContours(binary_output, contours, hierachy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(-1, -1));

    vector<vector<cv::Point>> contours_ploy(contours.size());
    vector<cv::Rect> ploy_rects(contours.size());
    vector<cv::Point2f> ccs(contours.size());
    vector<float> radius(contours.size());

    vector<cv::RotatedRect> minRects(contours.size());
    vector<cv::RotatedRect> myellipse(contours.size());

    for (size_t i = 0; i < contours.size(); i++) {
        approxPolyDP(cv::Mat(contours[i]), contours_ploy[i], 3, true);
        ploy_rects[i] = boundingRect(contours_ploy[i]);
        minEnclosingCircle(contours_ploy[i], ccs[i], radius[i]);
        if (contours_ploy[i].size() > 5) {
            myellipse[i] = fitEllipse(contours_ploy[i]);
            minRects[i] = minAreaRect(contours_ploy[i]);
        }
    }

    // draw it
    drawImg32 = cv::Mat::zeros(src32.size(), src32.type());
    cv::Point2f pts[4];
    for (size_t t = 0; t < contours.size(); t++) {
        cv::Scalar color = cv::Scalar(rng32.uniform(0, 255), rng32.uniform(0, 255), rng32.uniform(0, 255));
        //rectangle(drawImg32, ploy_rects[t], color, 2, 8);
        //circle(drawImg32, ccs[t], radius[t], color, 2, 8);
        if (contours_ploy[t].size() > 5) {
            ellipse(drawImg32, myellipse[t], color, 1, 8);
            minRects[t].points(pts);
            for (int r = 0; r < 4; r++) {
                line(drawImg32, pts[r], pts[(r + 1) % 4], color, 1, 8);
            }
        }
    }

    imshow(output_win32, drawImg32);
    return;
}
/******************************/


/******************************/
cv::Mat src33, gray_src33;
int threshold_value33 = 80;
int threshold_max33 = 255;
const char* output_win33 = "image moents demo";
cv::RNG rng33(12345);
void Demo_Moments(int, void*);

void OpencvOper2::fun_33()
{
    src33 = cv::imread("D:/vcprojects/images/circle.png");
    if (!src33.data) {
        printf("could not load image...\n");
        return;
    }
    cvtColor(src33, gray_src33, cv::COLOR_BGR2GRAY);
    GaussianBlur(gray_src33, gray_src33, cv::Size(3, 3), 0, 0);

    char input_win[] = "input image";
    namedWindow(input_win, cv::WINDOW_AUTOSIZE);
    namedWindow(output_win33, cv::WINDOW_AUTOSIZE);
    imshow(input_win, src33);

    cv::createTrackbar("Threshold Value : ", output_win33, &threshold_value33, threshold_max33, Demo_Moments);
    Demo_Moments(0, 0);

    cv::waitKey(0);
}

void Demo_Moments(int, void*) {
    cv::Mat canny_output;
    vector<vector<cv::Point>> contours;
    vector<cv::Vec4i> hierachy;

    Canny(gray_src33, canny_output, threshold_value33, threshold_value33 * 2, 3, false);
    findContours(canny_output, contours, hierachy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

    vector<cv::Moments> contours_moments(contours.size());
    vector<cv::Point2f> ccs(contours.size());
    for (size_t i = 0; i < contours.size(); i++) {
        //cv::moments图像矩
        contours_moments[i] = moments(contours[i]);
        ccs[i] = cv::Point(static_cast<float>(contours_moments[i].m10 / contours_moments[i].m00), static_cast<float>(contours_moments[i].m01 / contours_moments[i].m00));
    }

    cv::Mat drawImg;// = Mat::zeros(src33.size(), CV_8UC3);
    src33.copyTo(drawImg);
    for (size_t i = 0; i < contours.size(); i++) {
        if (contours[i].size() < 100) {
            continue;
        }
        cv::Scalar color = cv::Scalar(rng33.uniform(0, 255), rng33.uniform(0, 255), rng33.uniform(0, 255));
        printf("center point x : %.2f y : %.2f\n", ccs[i].x, ccs[i].y);
        printf("contours %d area : %.2f   arc length : %.2f\n", i, contourArea(contours[i]), arcLength(contours[i], true));
        drawContours(drawImg, contours, i, color, 2, 8, hierachy, 0, cv::Point(0, 0));
        circle(drawImg, ccs[i], 2, color,2, 8);
    }

    imshow(output_win33, drawImg);
    return;
}

/******************************/


/******************************/
void OpencvOper2::fun_34()
{
    const int r = 100;
    cv::Mat src = cv::Mat::zeros(r * 4, r * 4, CV_8UC1);

    vector<cv::Point2f> vert(6);
    vert[0] = cv::Point(3 * r / 2, static_cast<int>(1.34*r));
    vert[1] = cv::Point(1 * r, 2 * r);
    vert[2] = cv::Point(3 * r / 2, static_cast<int>(2.866*r));
    vert[3] = cv::Point(5 * r / 2, static_cast<int>(2.866*r));
    vert[4] = cv::Point(3 * r, 2 * r);
    vert[5] = cv::Point(5 * r / 2, static_cast<int>(1.34*r));

    for (int i = 0; i < 6; i++) {
        line(src, vert[i], vert[(i + 1) % 6], cv::Scalar(255), 3, 8, 0);
    }

    vector<vector<cv::Point>> contours;
    vector<cv::Vec4i> hierachy;
    cv::Mat csrc;
    src.copyTo(csrc);
    findContours(csrc, contours, hierachy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));
    cv::Mat raw_dist = cv::Mat::zeros(csrc.size(), CV_32FC1);
    for (int row = 0; row < raw_dist.rows; row++) {
        for (int col = 0; col < raw_dist.cols; col++) {
            double dist = pointPolygonTest(contours[0], cv::Point2f(static_cast<float>(col), static_cast<float>(row)), true);
            raw_dist.at<float>(row, col) = static_cast<float>(dist);
        }
    }

    double minValue, maxValue;
    minMaxLoc(raw_dist, &minValue, &maxValue, 0, 0, cv::Mat());
    cv::Mat drawImg = cv::Mat::zeros(src.size(), CV_8UC3);
    for (int row = 0; row < drawImg.rows; row++) {
        for (int col = 0; col < drawImg.cols; col++) {
            float dist = raw_dist.at<float>(row, col);
            if (dist > 0) {
                drawImg.at<cv::Vec3b>(row, col)[0] = (uchar)(abs(1.0 - (dist / maxValue)) * 255);
            }
            else if (dist < 0) {
                drawImg.at<cv::Vec3b>(row, col)[2] = (uchar)(abs(1.0 - (dist / minValue)) * 255);
            } else {
                drawImg.at<cv::Vec3b>(row, col)[0] = (uchar)(abs(255 - dist));
                drawImg.at<cv::Vec3b>(row, col)[1] = (uchar)(abs(255 - dist));
                drawImg.at<cv::Vec3b>(row, col)[2] = (uchar)(abs(255 - dist));
            }
        }
    }

    const char* output_win = "point polygon test demo";
    char input_win[] = "input image";
    namedWindow(input_win, cv::WINDOW_AUTOSIZE);
    namedWindow(output_win, cv::WINDOW_AUTOSIZE);

    imshow(input_win, src);
    imshow(output_win, drawImg);

    cv::waitKey(0);
}

/******************************/

void OpencvOper2::fun_35()
{
    char input_win[] = "input image";
    char watershed_win[] = "watershed segmentation demo";
    cv::Mat src = cv::imread("D:/vcprojects/images/cards.png");
    // Mat src = imread("D:/kuaidi.jpg");
    if (src.empty()) {
        printf("could not load image...\n");
        return;
    }
    namedWindow(input_win, cv::WINDOW_AUTOSIZE);
    imshow(input_win, src);
    // 1. change background
    for (int row = 0; row < src.rows; row++) {
        for (int col = 0; col < src.cols; col++) {
            if (src.at<cv::Vec3b>(row, col) == cv::Vec3b(255, 255, 255)) {
                src.at<cv::Vec3b>(row, col)[0] = 0;
                src.at<cv::Vec3b>(row, col)[1] = 0;
                src.at<cv::Vec3b>(row, col)[2] = 0;
            }
        }
    }
    namedWindow("black background", cv::WINDOW_AUTOSIZE);
    imshow("black background", src);

    // sharpen
    cv::Mat kernel = (cv::Mat_<float>(3, 3) << 1, 1, 1, 1, -8, 1, 1, 1, 1);
    cv::Mat imgLaplance;
    cv::Mat sharpenImg = src;
    filter2D(src, imgLaplance, CV_32F, kernel, cv::Point(-1, -1), 0, cv::BORDER_DEFAULT);
    src.convertTo(sharpenImg, CV_32F);
    cv::Mat resultImg = sharpenImg - imgLaplance;

    resultImg.convertTo(resultImg, CV_8UC3);
    imgLaplance.convertTo(imgLaplance, CV_8UC3);
    imshow("sharpen image", resultImg);
    // src = resultImg; // copy back

    // convert to binary
    cv::Mat binaryImg;
    cvtColor(src, resultImg, cv::COLOR_BGR2GRAY);
    threshold(resultImg, binaryImg, 40, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
    imshow("binary image", binaryImg);

    cv::Mat distImg;
    distanceTransform(binaryImg, distImg, cv::DIST_L1, 3, 5);
    normalize(distImg, distImg, 0, 1, cv::NORM_MINMAX);
    imshow("distance result", distImg);

    // binary again
    threshold(distImg, distImg, .4, 1, cv::THRESH_BINARY);
    cv::Mat k1 = cv::Mat::ones(13, 13, CV_8UC1);
    erode(distImg, distImg, k1, cv::Point(-1, -1));
    imshow("distance binary image", distImg);

    // markers
    cv::Mat dist_8u;
    distImg.convertTo(dist_8u, CV_8U);
    vector<vector<cv::Point>> contours;
    findContours(dist_8u, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

    // create makers
    cv::Mat markers = cv::Mat::zeros(src.size(), CV_32SC1);
    for (size_t i = 0; i < contours.size(); i++) {
        drawContours(markers, contours, static_cast<int>(i), cv::Scalar::all(static_cast<int>(i) + 1), -1);
    }
    circle(markers, cv::Point(5, 5), 3, cv::Scalar(255, 255, 255), -1);
    imshow("my markers", markers*1000);

    // perform watershed
    watershed(src, markers);
    cv::Mat mark = cv::Mat::zeros(markers.size(), CV_8UC1);
    markers.convertTo(mark, CV_8UC1);
    bitwise_not(mark, mark, cv::Mat());
    imshow("watershed image", mark);

    // generate random color
    vector<cv::Vec3b> colors;
    for (size_t i = 0; i < contours.size(); i++) {
        int r = cv::theRNG().uniform(0, 255);
        int g = cv::theRNG().uniform(0, 255);
        int b = cv::theRNG().uniform(0, 255);
        colors.push_back(cv::Vec3b((uchar)b, (uchar)g, (uchar)r));
    }

    // fill with color and display final result
    cv::Mat dst =cv:: Mat::zeros(markers.size(), CV_8UC3);
    for (int row = 0; row < markers.rows; row++) {
        for (int col = 0; col < markers.cols; col++) {
            int index = markers.at<int>(row, col);
            if (index > 0 && index <= static_cast<int>(contours.size())) {
                dst.at<cv::Vec3b>(row, col) = colors[index - 1];
            }
            else {
                dst.at<cv::Vec3b>(row, col) = cv::Vec3b(0, 0, 0);
            }
        }
    }
    imshow("Final Result", dst);

    cv::waitKey(0);
}
