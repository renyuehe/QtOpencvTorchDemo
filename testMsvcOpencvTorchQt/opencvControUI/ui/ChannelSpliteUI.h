#ifndef CHANNELSPLITEUI_H
#define CHANNELSPLITEUI_H

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
class ChannelSpliteUI;
}

class ChannelSpliteUI : public QWidget
{
    Q_OBJECT

public:
    explicit ChannelSpliteUI(QWidget *parent = nullptr);
    ~ChannelSpliteUI();

protected:
    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::ChannelSpliteUI *ui;

    cv::Mat m_img;
};

#endif // CHANNELSPLITEUI_H
