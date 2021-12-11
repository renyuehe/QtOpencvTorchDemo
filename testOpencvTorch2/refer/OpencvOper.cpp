#include "OpencvOper.h"


void OpencvOper::openImgOper(){
    QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                    ("文件对话框！"),
                                                    "F:",
                                                    ("图片文件(*png *jpg);;"));

    cv::Mat image=cv::imread(fileName.toStdString(),1);//一定要使用绝对路径，其他可以回报错

    cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
    cv::imshow( "Display window", image );

}


void OpencvOper::saveImgOper()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                    ("文件对话框！"),
                                                    "F:",
                                                    ("图片文件(*png *jpg);;"));

    cv::Mat image=cv::imread(fileName.toStdString(),1);//一定要使用绝对路径，其他可以回报错

    //保存图像
    cv::imwrite("images/write_pic.jpg",image);
}

void OpencvOper::VideoCaptureOper()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                    ("文件对话框！"),
                                                    "F:",
                                                    ("视频文件(*mp4)"));

    cv::VideoCapture cap = cv::VideoCapture(fileName.toStdString());

    while (true){
        cv::Mat frame;
        cap >> frame;
        if(frame.empty())
            break;

        cv::imshow("frame", frame);
        cv::waitKey(42);
    }

    cap.release();
    cv::destroyAllWindows();
}

void OpencvOper::cvtColorOper()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                    ("文件对话框！"),
                                                    "F:",
                                                    ("图片文件(*png *jpg);;"));
    cv::Mat dst;

    cv::Mat img=cv::imread(fileName.toStdString(),1);//一定要使用绝对路径，其他可以回报错
    cv::cvtColor(img, dst, cv::COLOR_BGR2GRAY);

    cv::imshow("pic", img);
    cv::imshow("dst", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper::drawShapeOper()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                    ("文件对话框！"),
                                                    "F:",
                                                    ("图片文件(*png *jpg);;"));

    cv::Mat img=cv::imread(fileName.toStdString(),1);//一定要使用绝对路径，其他可以回报错

    cv::line(img,cv::Point(100,30),cv::Point(210,180),cv::Scalar(0,0,255),2);
    cv::circle(img,cv::Point(50,50),30,cv::Scalar(0,0,255),2);
    cv::ellipse(img,cv::Point(100,100),cv::Point(100,50),0,0,360,cv::Scalar(0,0,255),2);
    cv::rectangle(img,cv::Point(100,30),cv::Point(210,180),cv::Scalar(0,0,255),2);
    //polylines
    vector<cv::Point> contor;
    contor.push_back(cv::Point(10,5));
    contor.push_back(cv::Point(20,50));
    contor.push_back(cv::Point(70,130));
    contor.push_back(cv::Point(130,150));
    cv::polylines(img,contor, true,cv::Scalar(255,0,0),2,cv::LINE_AA);
    //putText
    cv::putText(img,"hello world",cv::Point(10,300),cv::FONT_HERSHEY_SIMPLEX,1,cv::Scalar(0,0,255),3);

    cv::imshow("img",img);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper::thresholdOper()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                    ("文件对话框！"),
                                                    "F:",
                                                    ("图片文件(*png *jpg);;"));

    cv::Mat img=cv::imread(fileName.toStdString(), 0);
    cv::Mat bin_img;
    cv::threshold(img, bin_img, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

    cv::imshow("bin_img", bin_img);
    cv::imshow("src", img);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper::adapterThresholdOper()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                    ("文件对话框！"),
                                                    "F:",
                                                    ("图片文件(*png *jpg);;"));

    cv::Mat img=cv::imread(fileName.toStdString(), 0);
    cv::Mat dst1, dst2, dst3;

    cv::threshold(img, dst1, 50, 255, cv::ADAPTIVE_THRESH_MEAN_C | cv::THRESH_OTSU);
    cv::adaptiveThreshold(img, dst2, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 11, 2);
    cv::adaptiveThreshold(img, dst3, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 11, 2);

    cv::imshow("src", img);
    cv::imshow("dst1", dst1);
    cv::imshow("dst2", dst2);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper::imgMathOperation()
{
    cv::Mat x = (cv::Mat_<unsigned char>(2, 1)<<255, 34);
    cv::Mat y = (cv::Mat_<unsigned char>(2, 1) << 10, 100);

    cv::Mat add, sub;
    cv::add(x, y, add);
    cv::subtract(x, y, sub);

    cout << add << endl;
    cout << sub << endl;
}

void OpencvOper::imgMathOperation2()
{
    cv::Mat img1=cv::imread("C:\\Users\\60161\\Desktop\\small_girl.jpg", 1);
    cv::Mat img2=cv::imread("C:\\Users\\60161\\Desktop\\small_sea.jpg", 1);

    cv::Mat out;
    cv::addWeighted(img1, 0.5, img2, 0.3, 0, out);

    cv::imshow("img1", img1);
    cv::imshow("img2", img2);
    cv::imshow("out", out);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper::imgBitOperation()
{
    cv::Mat img1=cv::imread("C:\\Users\\60161\\Desktop\\small_girl.jpg", 1);
    cv::Mat img2=cv::imread("C:\\Users\\60161\\Desktop\\small_sea.jpg", 1);

    cv::Mat dst1, dst2, dst3, dst4;

    cv::bitwise_or(img1, img2, dst1);
    cv::bitwise_and(img1, img2, dst2);
    cv::bitwise_not(img1, dst3);
    cv::bitwise_xor(img1, img2, dst4);

    cv::imshow("dst1", dst1);
    cv::imshow("dst2", dst2);
    cv::imshow("dst3", dst3);
    cv::imshow("dst4", dst4);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper::transposeFlipOper()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                    ("文件对话框！"),
                                                    "F:",
                                                    ("图片文件(*png *jpg);;"));

    cv::Mat img = cv::imread(fileName.toStdString(), 0);
    cv::Mat dst1, dst2, dst3;

    cv::resize(img, dst1, cv::Size(300, 300));
    cv::transpose(img, dst2);
    cv::flip(img, dst3, 0);

    cv::imshow("img", img);
    cv::imshow("dst", dst1);
    cv::imshow("dst", dst2);
    cv::imshow("dst", dst3);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper::warpAffine()
{
    cv::Mat img = cv::imread("C:\\Users\\60161\\Desktop\\small_girl.jpg", 1);
    cv::Mat dst1, dst2;

    cv::Mat M1 = (cv::Mat_<double>(2,3) << 1,0,50,0,1,50);
    cv::Mat M2 = cv::getRotationMatrix2D(cv::Point(img.cols/2,img.rows/2), 45, 0.7);

    cv::warpAffine(img,dst1,M1,img.size());
    cv::warpAffine(img,dst2,M2,img.size());
    cv::imshow("src",img);
    cv::imshow("dst1",dst1);
    cv::imshow("dst2",dst2);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper::warpPerspective()
{
    cv::Mat img=cv::imread("C:\\Users\\60161\\Desktop\\small_girl.jpg", 1);
    cv::Mat dst;

    cv::Point2f pts1[] = {cv::Point2f(25,30), cv::Point2f(179, 25), cv::Point2f(12, 188),cv::Point2f(189, 190)};
    cv::Point2f pts2[] = {cv::Point2f(0,0), cv::Point2f(200, 0), cv::Point2f(200, 200),cv::Point2f(0, 200)};

    cv::Mat M = cv::getPerspectiveTransform(pts1, pts2);
    cv::warpPerspective(img, dst, M, img.size());

    cv::imshow("img", img);
    cv::imshow("dst", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper::morphologicalOper()
{
    cv::Mat img=cv::imread("C:\\Users\\60161\\Desktop\\small_girl.jpg", 1);
    cv::Mat dst;

    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5,5));

    cv::dilate(img, dst, kernel);//膨胀
    cv::erode(img, dst, kernel);//腐蚀

    cv::morphologyEx(img, dst, cv::MORPH_OPEN, kernel);//开操作
    cv::morphologyEx(img, dst, cv::MORPH_CLOSE, kernel);//闭操作
    cv::morphologyEx(img, dst, cv::MORPH_TOPHAT,kernel);//礼貌操作,获取噪声
    cv::morphologyEx(img, dst, cv::MORPH_BLACKHAT,kernel);//黑帽操作,
    cv::morphologyEx(img, dst, cv::MORPH_GRADIENT,kernel);//梯度操作

    cv::imshow("img", img);
    cv::imshow("dst", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper::channelSplite()
{
    cv::Mat img = cv::Mat(200,200,CV_8UC3,cv::Scalar(255,0,0));

    {//channel splite
        for (int i = 0;i<img.rows;++i){
            for(int j=0;j<img.cols;++j){
                img.at<cv::Vec3b>(i,j)[0] = 0;
                img.at<cv::Vec3b>(i,j)[1] = 0;
                img.at<cv::Vec3b>(i,j)[2] = 255;
            }
        }
    }

    {//Scalar(标量)
        //通道切割
        vector<cv::Mat> ms;
        cv::split(img,ms);
        ms[0] = cv::Scalar(0);
        ms[1] = cv::Scalar(255);
        ms[2] = cv::Scalar(0);
        //通道合并
        cv::merge(ms,img);
    }

    cv::imshow("src",img);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper::graphFilterOper()
{
    cv::Mat img = cv::imread("C:\\Users\\60161\\Desktop\\small_girl.jpg", 1);
    cv::Mat dst;

    //自定义滤波器
    cv::Mat M = (cv::Mat_<double>(3,3)<<1,1,0,1,0,-1,0,-1,-1);
    cv::filter2D(img, dst, -1, M);

    /************低通**************/
    //均值滤波
    cv::blur(img, dst, cv::Size(3,3));
    //高斯滤波
    cv::GaussianBlur(img, dst, cv::Size(3,3), 1);
    //中值滤波
    cv::medianBlur(img, dst, 5);
    //双边模糊
    cv::bilateralFilter(img, dst, 9, 75, 75);

    /************高通**************/
    //拉普拉斯
    cv::Laplacian(img, dst, -1);

    //Sobel x and y
    cv::Sobel(img, dst, -1, 1, 0);
    cv::Sobel(img, dst, -1, 0, 1);

    //Scharr x and y
    cv::Scharr(img, dst, -1, 1, 0);
    cv::Scharr(img, dst, -1, 0, 1);


    cv::imshow("src", img);
    cv::imshow("dst", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper::CannyOper()
{
    cv::Mat img = cv::imread("C:\\Users\\60161\\Desktop\\small_girl.jpg", 1);
    cv::Mat dst;

    cv::Canny(img, dst, 50, 150);
    cv::imshow("dst", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper::findContoursOper()
{
    cv::Mat img = cv::imread("C:\\Users\\60161\\Desktop\\small_girl.jpg", 0);
    cv::Mat dst, binary;

    cv::threshold(img, binary, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

    vector<vector<cv::Point>> contours;//存放点
    cv::findContours(binary, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
    cv::drawContours(img, contours, -1, cv::Scalar(0,0,255));

    cv::imshow("img", img);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper::approxPolyDPOper()
{
    cv::Mat img = cv::imread("C:\\Users\\60161\\Desktop\\img\\16.jpg");
    cv::Mat gray, bin;

    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::threshold(gray, bin, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

    vector<vector<cv::Point>> contours;
    cv::findContours(bin, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
    cv::approxPolyDP(contours.at(0), contours.at(0), 60, true);
    cv::drawContours(img, contours, -1, cv::Scalar(0, 255, 0), 5);

    cv::imshow("img", img);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper::convexOper()
{
    cv::Mat img = cv::imread("C:\\Users\\60161\\Desktop\\img\\16.jpg");
    cv::Mat gray, bin;

    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::threshold(gray, bin, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

    vector<vector<cv::Point>> contours;

    cv::findContours(bin, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
    vector<vector<cv::Point>> hull(contours.size());

    cv::convexHull(contours.at(0), hull.at(0));
    cout << cv::isContourConvex(contours.at(0)) << "" << cv::isContourConvex(hull.at(0)) << endl;

    cv::drawContours(img,hull,0,cv::Scalar(0,0,255),2);//绘制轮廓

    cv::imshow("img", img);
    cv::imshow("bin", bin);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper::boundaryDetection(){
    cv::Mat img = cv::imread("C:\\Users\\60161\\Desktop\\img\\16.jpg");
    cv::Mat gray, bin;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::threshold(gray, bin, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

    vector<vector<cv::Point>> contours;
    cv::findContours(bin, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    //边界矩形
    cv::Rect rect = cv::boundingRect(contours.at(0));
    cv::rectangle(img, cv::Point(rect.x , rect.y ), cv::Point(rect.x + rect.width, rect.y + rect.height), cv::Scalar(0,0,255));
    //最小矩形
    cv::RotatedRect minRect =  cv::minAreaRect(contours.at(0));
    cv::Point2f vs[4];
    minRect.points(vs);
    vector<cv::Point> contour;
    contour.push_back(vs[0]);
    contour.push_back(vs[1]);
    contour.push_back(vs[2]);
    contour.push_back(vs[3]);
    cv::polylines(img, contour, true, cv::Scalar(0,0,255), 2 );
    //最小外接圆
    cv::Point2f center;
    float radius;
    cv::minEnclosingCircle(contours.at(0), center, radius);
    cv::circle(img, center, radius, cv::Scalar(0,0,255), 2);

    cv::imshow("img", img);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper::contoursProperty()
{
    cv::Mat img = cv::imread("C:\\Users\\60161\\Desktop\\small_girl.jpg");
    cv::Mat gray, bin;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::threshold(gray, bin, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

    vector<vector<cv::Point>> contours;
    cv::findContours(bin, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    cv::Moments M = cv::moments(contours.at(0));
    int cx = M.m10/M.m00;
    int cy = M.m01/M.m00;
    cout << cx << "," << cy << endl;

    double area = cv::contourArea(contours.at(0));
    cout << "area" << area << endl;

    double area_len = cv::arcLength(contours.at(0), true);
    cout << "area " << area_len << endl;

    cv::imshow("img", img);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper::huofuOper()
{
    cv::Mat img = cv::imread("C:\\Users\\60161\\Desktop\\img\\32.jpg");
    cv::Mat gray, bin;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::threshold(gray, bin, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

    vector<vector<cv::Point>> contours;
    cv::findContours(bin, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    vector<cv::Vec4f> plines;
    cv::HoughLinesP(bin, plines, 1 , CV_PI/180, 130);
    for(size_t i = 0; i < plines.size(); i++)
    {
        cv::Vec4f hline = plines[i];
        cv::line(img, cv::Point(hline[0], hline[1]), cv::Point(hline[2], hline[3]), cv::Scalar(0,0,255));
    }

    cv::imshow("img", img);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper::hintDetact()
{
    cv::Mat img = cv::imread("C:\\Users\\60161\\Desktop\\img\\7.jpg", 0);
    cv::Mat dst;

    cv::equalizeHist(img, dst);

    cv::imshow("hist", dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void OpencvOper::test()
{
    cv::Mat img = cv::imread("C:\\Users\\60161\\Desktop\\small_girl.jpg", -1);
    cv::pyrDown(img, img, cv::Size(img.cols/2, img.rows/2), 4);
    cv::imshow("img", img);imwrite("img.jpg", img);

    //通过canny算法找轮廓，这样 findcontours 的结果会好些
    cv::Mat canny_out;
    cv::Canny(img, canny_out, 45, 127, 3, false);
    cv::imshow("canny_out", canny_out);imwrite("canny_out.jpg", canny_out);

    //寻找轮廓
    vector<vector<cv::Point>> contours;
    vector<cv::Vec4i> hierachy;
    findContours(canny_out, contours, hierachy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(-1,-1));
    drawContours(img, contours, -1, cv::Scalar(0,0,255), 1, 8, hierachy);

    //定义圆形、方形、旋转矩形、椭圆的存储容器
    vector<vector<cv::Point>> contours_ploy(contours.size());
    vector<cv::Rect> rects_ploy(contours.size());
    vector<cv::Point2f> circle_centers(contours.size());
    vector<float> circle_radius(contours.size());
    vector<cv::RotatedRect> RotatedRect_ploy;//注意：由于下面赋值的过程中有个点数大于5的条件，所以这里没有直接初始化，才有下面pushback的方法添加值。
    vector<cv::RotatedRect> ellipse_ploy;//注意，这里是画椭圆，但是容器类型是 RotatedRect

    //将结果放到各自的容器中
    for (size_t i = 0; i< contours.size(); i++)
    {
        cv::approxPolyDP(contours[i], contours_ploy[i], 5, true);
        rects_ploy[i] = boundingRect(contours_ploy[i]);
        cv::minEnclosingCircle(contours_ploy[i], circle_centers[i], circle_radius[i]);

        if (contours_ploy[i].size() >5)
        {
            cv::RotatedRect temp1 = cv::minAreaRect(contours_ploy[i]);
            RotatedRect_ploy.push_back(temp1);

            cv::RotatedRect temp2 = cv::fitEllipse(contours_ploy[i]);
            ellipse_ploy.push_back(temp2);
        }
    }

    //定义最终绘图的图片
    cv::Mat draw_rect(img.size(), img.type(), cv::Scalar::all(0)),
        draw_rotateRect(img.size(), img.type(), cv::Scalar::all(0)),
        draw_circle(img.size(), img.type(), cv::Scalar::all(0)),
        draw_ellipse(img.size(), img.type(), cv::Scalar::all(0));

    //绘图圆形、矩形
    cv::RNG rng(12345);
    for (size_t i = 0; i<contours.size(); i++)
    {
        cv::Scalar color = cv::Scalar(rng.uniform(0,255), rng.uniform(0,255), rng.uniform(0,255));
        cv::rectangle(draw_rect, rects_ploy[i], color, 1, 8);
        cv::circle(draw_circle, circle_centers[i], circle_radius[i], color, 1, 8);
    }
    cv::imshow("draw_rect", draw_rect);imwrite("draw_rect.jpg", draw_rect);
    cv::imshow("draw_circle", draw_circle);imwrite("draw_circle.jpg", draw_circle);

    //绘图椭圆形、旋转矩形
    cv::Point2f pot[4];
    for (size_t i = 0; i<ellipse_ploy.size(); i++)
    {
        cv::Scalar color = cv::Scalar(rng.uniform(0,255), rng.uniform(0,255), rng.uniform(0,255));
        cv::ellipse(draw_ellipse, ellipse_ploy[i], color, 1, 8);

        RotatedRect_ploy[i].points(pot);
        for(int j=0; j<4; j++)
        {
            cv::line(draw_rotateRect, pot[j], pot[(j+1)%4], color);
        }
    }
    cv::imshow("draw_ellipse", draw_ellipse);
    cv::imwrite("draw_ellipse.jpg", draw_ellipse);
    cv::imshow("draw_rotateRect", draw_rotateRect);
    cv::imwrite("draw_rotateRect.jpg", draw_rotateRect);


    cv::waitKey();
    cv::destroyAllWindows();
}


