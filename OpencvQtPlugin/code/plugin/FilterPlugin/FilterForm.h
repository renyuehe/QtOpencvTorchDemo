#ifndef FILTERFORM
#define FILTERFORM

#include <QWidget>
#include <QPixmap>


namespace Ui {
class FilterForm;
}

class FilterForm : public QWidget
{
    Q_OBJECT

public:
    explicit FilterForm(QWidget *parent = nullptr);
    ~FilterForm();


private slots:
    void on_pushButton_clicked();

private:
    Ui::FilterForm *ui;
};

#endif // FILTERFORM
