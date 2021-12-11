#ifndef FILTERFORM
#define FILTERFORM

#include <QWidget>
#include <QPixmap>
#include <QRadioButton>


namespace Ui {
class FilterForm;
}

class FilterForm : public QWidget
{
    Q_OBJECT

public:
    explicit FilterForm(QWidget *parent = nullptr);
    ~FilterForm();


    void initUI();

private slots:

    void on_comboBox_weight_activated(const QString &arg1);

    void on_comboBox_height_activated(const QString &arg1);

    void on_comboBox_height_GaussianBlur_activated(const QString &arg1);

    void on_comboBox_weight_GaussianBlur_activated(const QString &arg1);

    void on_comboBox_wh_medianBlur_activated(const QString &arg1);


    void on_pushButton_bilateralFilter_clicked();

    void on_comboBox_height_boxFilter_activated(const QString &arg1);

    void on_comboBox_weight_boxFilter_activated(const QString &arg1);

private:
    Ui::FilterForm *ui;
};

#endif // FILTERFORM
