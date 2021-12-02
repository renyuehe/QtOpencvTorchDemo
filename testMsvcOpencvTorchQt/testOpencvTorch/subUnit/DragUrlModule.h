#ifndef DRAGURLMODULE_H
#define DRAGURLMODULE_H

#include <QWidget>

namespace Ui {
class DragUrlModule;
}

class DragUrlModule : public QWidget
{
    Q_OBJECT

public:
    explicit DragUrlModule(QWidget *parent = nullptr);
    ~DragUrlModule();

protected:
    void dragEnterEvent(QDragEnterEvent* e);
    void dropEvent(QDropEvent* e);

public:
    QString getCurrentFile();

private:
    Ui::DragUrlModule *ui;

    QString m_currentFileName;
};

#endif // DRAGURLMODULE_H
