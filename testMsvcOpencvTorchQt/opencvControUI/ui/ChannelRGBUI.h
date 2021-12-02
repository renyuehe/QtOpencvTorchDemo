#ifndef CHANNELRGBUI_H
#define CHANNELRGBUI_H

#include <QDragEnterEvent>
#include <QMimeData>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <QVector>
#include <QFileDialog>

#include "Cv2Qt.h"
#include <QWidget>

namespace Ui {
class ChannelRGBUI;
}

class ChannelRGBUI : public QWidget
{
    Q_OBJECT

public:
    explicit ChannelRGBUI(QWidget *parent = nullptr);
    ~ChannelRGBUI();

    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);
private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::ChannelRGBUI *ui;

    cv::Mat m_img;
};

#endif // CHANNELRGBUI_H
