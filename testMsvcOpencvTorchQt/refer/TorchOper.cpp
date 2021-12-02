#include "TorchOper.h"

//#undef slots
#include "torch/script.h"
//#define slots Q_SLOTS

#include "torch/torch.h"
#include "opencv2/opencv.hpp"

#include <vector>
#include <QFileDialog>
#include <QDebug>

/////////////////////////////////////////////////////////////////////////////////////////////
int TorchOper::jitModulePredictNumber()
{
    try {
        QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                        ("文件对话框！"),
                                                        "F:",
                                                        ("图片文件(*png *jpg);;"));

        cv::Mat img = cv::imread(fileName.toStdString(), 0);

        //转换形状, ==》 reshape(1,xxx),转 float32
        torch::Tensor tensor_img = torch::from_blob(img.data, {1, img.rows * img.cols}, torch::kByte).toType(torch::kFloat);
        tensor_img /= 255.;

        //jit 拿到训练好的模型
        //        auto module = torch::jit::load("holeModel.mm");

        QString moduleFilePath = QFileDialog::getOpenFileName(nullptr,
                                                              ("文件对话框！"),
                                                              "F:",
                                                              ("模型(*pt);;"));
        //jit 拿到手动选择的模型
        auto module = torch::jit::load(moduleFilePath.toStdString());

        //创建前向运算的 X ,因为有批次,所有有vector
        //这里很疑惑,torch::jit::IValue 和 torch::Tensor 有啥关系,为什么 inputs是IValue类型却可以装Tensor
        std::vector<torch::jit::IValue> inputs;
        inputs.push_back(tensor_img);


        //参数输入,得到结果预测结果
        //        module.to(at::DeviceType::CUDA);
        auto rst = module.forward(inputs).toTensor();


        std::cout << rst << std::endl;

//        std::cout << rst << std::endl;
                std::cout << torch::argmax(rst, 1) << std::endl;

    }
    catch (const c10::Error &e){
        std::cerr << e.what();
        return -1;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////
int TorchOper::jitPredictYellowArea(QString fileName)
{
    try {
        QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                        ("文件对话框！"),
                                                        "F:",
                                                        ("图片文件(*png *jpg);;"));

        cv::Mat img = cv::imread(fileName.toStdString());

        //转换形状, ==》 reshape(1,xxx),转 float32
        torch::Tensor tensor_img = torch::from_blob(img.data, {1, img.rows * img.cols * 3}, torch::kByte).toType(torch::kFloat);
        tensor_img /= 255.;

        //jit 拿到训练好的模型
        //        auto module = torch::jit::load("holeModel.mm");

        QString moduleFilePath = QFileDialog::getOpenFileName(nullptr,
                                                              ("文件对话框！"),
                                                              "F:",
                                                              ("模型(*pt);;"));
        //jit 拿到手动选择的模型
        auto module = torch::jit::load(moduleFilePath.toStdString());

        //创建前向运算的 X ,因为有批次,所有有vector
        //这里很疑惑,torch::jit::IValue 和 torch::Tensor 有啥关系,为什么 inputs是IValue类型却可以装Tensor
        std::vector<torch::jit::IValue> inputs;
        inputs.push_back(tensor_img);


        //参数输入,得到结果预测结果
        auto rst = module.forward(inputs);
        const at::Tensor tensor = rst.toTensor();

        std::cout << tensor << endl;
        std::cout << tensor[0] << endl;
        at::Tensor x1 = tensor[0][0].toType(torch::ScalarType::Int);
        at::Tensor y1 = tensor[0][1].toType(torch::ScalarType::Int);
        at::Tensor x2 = tensor[0][2].toType(torch::ScalarType::Int);
        at::Tensor y2 = tensor[0][3].toType(torch::ScalarType::Int);

        int ix1 = x1.item<int>();
        int iy1 = y1.item<int>();
        int ix2 = x2.item<int>();
        int iy2 = y2.item<int>();

        cv::_InputOutputArray inputOutPutArray;
        cv::Point point;
        cv::rectangle(img, cv::Rect(ix1, iy1, ix2-ix1, iy2-iy1), cv::Scalar(255,0,0), 3);

        cv::imshow("img", img);
        cv::waitKey(0);
        cv::destroyAllWindows();
    }
    catch (const c10::Error &e){
        std::cerr << e.what();
        return -1;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

