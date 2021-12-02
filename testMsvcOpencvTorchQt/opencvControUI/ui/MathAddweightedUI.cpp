#include "MathAddweightedUI.h"
#include "ui_MathAddweightedUI.h"

MathAddweightedUI::MathAddweightedUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MathAddweightedUI)
{
    ui->setupUi(this);
    this->m_iWeight1 = 0.5;
    this->m_iWeight2 = 0.5;

    //拖拽
    this->setAcceptDrops(true);

    //新建窗口
    cv::namedWindow("mathAddweightedUI", cv::WINDOW_NORMAL);
    Cv2Qt::namedWindowToWidget("mathAddweightedUI", ui->frame);
}

MathAddweightedUI::~MathAddweightedUI()
{
    delete ui;
}

void MathAddweightedUI::dragEnterEvent(QDragEnterEvent* e)
{
    //dragEnterEvent 进入即相应，dropEvent 鼠标释放相应
    //filter 放行
    if (true)
    {
        e->acceptProposedAction();
    }
}

void MathAddweightedUI::dropEvent(QDropEvent* e)
{
    //filepath
    QList<QUrl> urls = e->mimeData()->urls();
    if (urls.isEmpty()) return;
    QString filename = urls.first().toLocalFile();

    //根据文件类型来做出对应的表达
    QString suffix = filename.split(".").last();
    if(suffix == "jpg" || suffix == "png" ){
        if(m_img.empty())
        {
            //读入图像
            this->m_img = cv::imread(filename.toStdString() , cv::IMREAD_COLOR);
            imshow("mathAddweightedUI", m_img);
            ui->label->setText("success");
        }
        else
        {
            cv::Mat next = cv::imread(filename.toStdString() , cv::IMREAD_COLOR);
            if(next.size == m_img.size)
            {
                cv::addWeighted(m_img, m_iWeight1, next, m_iWeight2, 0, m_img);
                imshow("mathAddweightedUI", m_img);
                ui->label->setText("success");
            }
            else
            {
                ui->label->setText("waring: img1.size != img2.size");
            }
        }
    }
    else{
    }
}

void MathAddweightedUI::on_doubleSpinBox_valueChanged(double arg1)
{
    this->m_iWeight1 = arg1;
}

void MathAddweightedUI::on_doubleSpinBox_2_valueChanged(double arg1)
{
    this->m_iWeight2 = arg1;
}

void MathAddweightedUI::on_pushButton_clicked()
{
    if(this->m_img.empty())
        return;

    this->m_img * 0;
    imshow("mathAddweightedUI", m_img);
}
