#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ComPluginManager.h"

#include <QPixmap>
#include <QSharedPointer>
//#include <stdlib.h>

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
    void initSignalSlot();

    void loadAllPlugin();

private:
    /**
     * @brief m_pComPluginManager 插件管理器
     */
    ComPluginManager* m_pComPluginManager;

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
