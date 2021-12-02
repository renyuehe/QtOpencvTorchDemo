#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

//音乐播放
#include <QMediaPlayer>

//视频播放
#include <QMediaPlayer>
#include <QVideoWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void videoPlayer();

    void mediaPlayer();

private:
    Ui::Widget *ui;

    QMediaPlayer *player;
    QVideoWidget * videoWidget;
};
#endif // WIDGET_H
