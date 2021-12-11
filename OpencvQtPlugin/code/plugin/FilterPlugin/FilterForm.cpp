#include "FilterForm.h"
#include "ui_FilterForm.h"
#include <QDebug>
#include "Communication.h"
#include "Cv2Qt.h"


FilterForm::FilterForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilterForm)
{
    ui->setupUi(this);
    initUI();
}

FilterForm::~FilterForm()
{
    delete ui;
}

#include "opencv2/highgui.hpp"
#include "opencv2/world.hpp"
#include "opencv2/core.hpp"
using namespace cv;

void FilterForm::initUI(){
    ui->tabWidget->setTabText(0, QString("blur"));
    ui->tabWidget->setTabText(1, QString("GaussianBlur"));
    ui->tabWidget->setTabText(2, QString("medianBlur"));
    ui->tabWidget->setTabText(3, QString("bilateralFilter"));
    ui->tabWidget->setTabText(4, QString("boxFilter"));
}


void FilterForm::on_comboBox_weight_activated(const QString &arg1)
{
    COM_BEGIN

    int kernelweight = ui->comboBox_weight->currentText().toInt();
    int kernelheight = ui->comboBox_height->currentText().toInt();

    //均值滤波
    cv::blur(SRC_MAT, DST_MAT, cv::Size(kernelweight,kernelheight));

    UPDATE_DST
}

void FilterForm::on_comboBox_height_activated(const QString &arg1)
{
    COM_BEGIN

    int kernelweight = ui->comboBox_weight->currentText().toInt();
    int kernelheight = ui->comboBox_height->currentText().toInt();

    //均值滤波
    cv::blur(SRC_MAT, DST_MAT, cv::Size(kernelweight,kernelheight));

    UPDATE_DST
}

void FilterForm::on_comboBox_height_GaussianBlur_activated(const QString &arg1)
{
    COM_BEGIN

    int kernelweight = ui->comboBox_weight_GaussianBlur->currentText().toInt();
    int kernelheight = ui->comboBox_weight_GaussianBlur->currentText().toInt();
    double sigmaX = ui->doubleSpinBox->value();
    double sigmaY = ui->doubleSpinBox->value();

    //高斯滤波
    cv::GaussianBlur(SRC_MAT, DST_MAT, cv::Size(kernelweight,kernelheight), sigmaX, sigmaY);

    UPDATE_DST
}

void FilterForm::on_comboBox_weight_GaussianBlur_activated(const QString &arg1)
{
    COM_BEGIN

    int kernelweight = ui->comboBox_weight_GaussianBlur->currentText().toInt();
    int kernelheight = ui->comboBox_weight_GaussianBlur->currentText().toInt();
    double sigmaX = ui->doubleSpinBox->value();
    double sigmaY = ui->doubleSpinBox->value();

    //高斯滤波
    cv::GaussianBlur(SRC_MAT, DST_MAT, cv::Size(kernelweight,kernelheight), sigmaX, sigmaY);

    UPDATE_DST
}


void FilterForm::on_comboBox_wh_medianBlur_activated(const QString &arg1)
{
    COM_BEGIN

    int kernelwh = ui->comboBox_wh_medianBlur->currentText().toInt();

    //种值滤波
    cv::medianBlur(SRC_MAT, DST_MAT, kernelwh);

    UPDATE_DST
}


void FilterForm::on_pushButton_bilateralFilter_clicked()
{
    COM_BEGIN

    int colorDis = ui->horizontalSlider_color->value();
    int spaceDis = ui->horizontalSlider_space->value();

    //双边滤波
    cv::bilateralFilter(SRC_MAT, DST_MAT, 9, colorDis, spaceDis);

    UPDATE_DST
}

void FilterForm::on_comboBox_height_boxFilter_activated(const QString &arg1)
{
    COM_BEGIN

    int w = ui->comboBox_weight_boxFilter->currentText().toInt();
    int h = ui->comboBox_height_boxFilter->currentText().toInt();
    int ddepth = -1; //-1代表原图的深度,即src.depth()
    bool isNormalize = ui->checkBox_boxFilter->isChecked();
    //方框滤波
    cv::boxFilter(SRC_MAT, DST_MAT, ddepth, cv::Size(w, h), cv::Point(-1,-1), isNormalize);

    UPDATE_DST
}

void FilterForm::on_comboBox_weight_boxFilter_activated(const QString &arg1)
{
    COM_BEGIN

    int w = ui->comboBox_weight_boxFilter->currentText().toInt();
    int h = ui->comboBox_height_boxFilter->currentText().toInt();
    int ddepth = -1;
    bool isNormalize = ui->checkBox_boxFilter->isChecked();
    //方框滤波
    cv::boxFilter(SRC_MAT, DST_MAT, ddepth, cv::Size(w, h), cv::Point(-1,-1), isNormalize);

    UPDATE_DST
}
