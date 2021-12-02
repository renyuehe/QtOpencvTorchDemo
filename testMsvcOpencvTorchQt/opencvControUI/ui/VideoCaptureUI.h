#ifndef VIDEOCAPTUREUI_H
#define VIDEOCAPTUREUI_H
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
class VideoCaptureUI;
}

class VideoCaptureUI : public QWidget
{
    Q_OBJECT

public:
    explicit VideoCaptureUI(QWidget *parent = nullptr);
    ~VideoCaptureUI();

    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);
private slots:
    void on_pushButton_clicked();

private:
    Ui::VideoCaptureUI *ui;
};

#endif // VIDEOCAPTUREUI_H
