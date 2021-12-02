#ifndef BinaryThresholdUI_H
#define BinaryThresholdUI_H

#include <QDragEnterEvent>
#include <QMimeData>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "Cv2Qt.h"

#include <iostream>
#include <QDebug>
#include <QWidget>

namespace Ui {
class BinaryThresholdUI;
}

class BinaryThresholdUI : public QWidget
{
    Q_OBJECT

public:
    explicit BinaryThresholdUI(QWidget *parent = nullptr);
    ~BinaryThresholdUI();

    static void onChangeTrackBar(int pos, void *usrdata);

    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);
private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::BinaryThresholdUI *ui;

    cv::Mat m_img;
};

#endif // BinaryThresholdUI_H
