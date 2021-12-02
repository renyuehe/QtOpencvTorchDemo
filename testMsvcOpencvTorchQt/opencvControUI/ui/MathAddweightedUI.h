#ifndef MATHADDWEIGHTEDUI_H
#define MATHADDWEIGHTEDUI_H

#include <QDragEnterEvent>
#include <QMimeData>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "Cv2Qt.h"

#include <QWidget>

namespace Ui {
class MathAddweightedUI;
}

class MathAddweightedUI : public QWidget
{
    Q_OBJECT

public:
    explicit MathAddweightedUI(QWidget *parent = nullptr);
    ~MathAddweightedUI();


    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);
private slots:
    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_pushButton_clicked();

private:
    Ui::MathAddweightedUI *ui;

    cv::Mat m_img;
    double m_iWeight1;
    double m_iWeight2;
};

#endif // MATHADDWEIGHTEDUI_H
