#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "WorkSpaceWidget.h"
#include "WorkSpaceWidget.h"
#include <QPixmap>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initUI();
    void initMenuBar();

    WorkSpaceWidget * m_pWorkSpaceWidget;
    void initWorkSpace();


private:
    Ui::MainWindow *ui;
    QPixmap mSrcPixmap;
};

#endif // MAINWINDOW_H
