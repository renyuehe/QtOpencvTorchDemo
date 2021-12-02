#ifndef DRAGURL_H
#define DRAGURL_H

#include <QWidget>


namespace Ui {
class DragUrl;
}

class DragUrl : public QWidget
{
    Q_OBJECT

public:
    explicit DragUrl(QWidget *parent = nullptr);
    ~DragUrl();

protected:
    void dragEnterEvent(QDragEnterEvent* e);
    void dropEvent(QDropEvent* e);
private:
    Ui::DragUrl *ui;
};

#endif // DRAGURL_H
