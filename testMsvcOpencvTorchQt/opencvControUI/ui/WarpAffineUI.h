#ifndef WARPAFFINEUI_H
#define WARPAFFINEUI_H

#include <QDragEnterEvent>
#include <QMimeData>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "Cv2Qt.h"

#include <QWidget>

namespace Ui {
class WarpAffineUI;
}

class WarpAffineUI : public QWidget
{
    Q_OBJECT

public:
    explicit WarpAffineUI(QWidget *parent = nullptr);
    ~WarpAffineUI();


    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);

private slots:

    void on_pushButton_clicked();

    void on_verticalSlider_valueChanged(int value);

    void on_verticalSlider_2_valueChanged(int value);

    void on_horizontalSlider_00_valueChanged(int value);

    void on_horizontalSlider_01_valueChanged(int value);

    void on_horizontalSlider_02_valueChanged(int value);

    void on_horizontalSlider_10_valueChanged(int value);

    void on_horizontalSlider_11_valueChanged(int value);

    void on_horizontalSlider_12_valueChanged(int value);

private:
    Ui::WarpAffineUI *ui;

    cv::Mat m_img;

    double x00;
    double x01;
    double x02;
    double x10;
    double x11;
    double x12;

    double angle;
    double scale;
};

#endif // WARPAFFINEUI_H
