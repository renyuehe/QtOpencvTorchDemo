#ifndef DRAGURLWIDGET_H
#define DRAGURLWIDGET_H

#include <QWidget>

//视频播放
#include <QMediaPlayer>
#include <QVideoWidget>

namespace Ui {
class DragUrlWidget;
}

class DragUrlWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DragUrlWidget(QWidget *parent = nullptr);
    ~DragUrlWidget();


protected:
    void dragEnterEvent(QDragEnterEvent* e);
    void dropEvent(QDropEvent* e);

public:
    QString getCurrentFile();

private:
    QString m_currentFileName;

private:
    Ui::DragUrlWidget *ui;

    //
    QMediaPlayer *player;
    QVideoWidget * videoWidget;
};

#endif // DRAGURLWIDGET_H
