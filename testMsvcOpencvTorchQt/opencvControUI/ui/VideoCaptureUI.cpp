#include "VideoCaptureUI.h"
#include "ui_VideoCaptureUI.h"

VideoCaptureUI::VideoCaptureUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoCaptureUI)
{
    ui->setupUi(this);

    //拖拽
    this->setAcceptDrops(true);

    //新建窗口
    cv::namedWindow("videoCaptureUI", cv::WINDOW_NORMAL);
    Cv2Qt::namedWindowToWidget("videoCaptureUI", ui->frame);
}

VideoCaptureUI::~VideoCaptureUI()
{
    delete ui;
}


void VideoCaptureUI::dragEnterEvent(QDragEnterEvent* e)
{
    //dragEnterEvent 进入即相应，dropEvent 鼠标释放相应
    //filter 放行
    if (true)
    {
        e->acceptProposedAction();
    }
}
void VideoCaptureUI::dropEvent(QDropEvent* e)
{
    //filepath
    QList<QUrl> urls = e->mimeData()->urls();
    if (urls.isEmpty()) return;
    QString filename = urls.first().toLocalFile();

    //根据文件类型来做出对应的表达
    QString suffix = filename.split(".").last();
    if(suffix == "wvm" || suffix == "mp4" ){

        cv::VideoCapture cap = cv::VideoCapture(filename.toStdString());

        while (true){
            cv::Mat frame;
            cap >> frame;
            if(frame.empty())
                break;

            cv::imshow("videoCaptureUI", frame);
            cv::waitKey(42);
        }

        cap.release();
    }
    else{
    }
}

void VideoCaptureUI::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                    ("文件对话框！"),
                                                    "F:",
                                                    ("视频文件(*mp4)"));

    cv::VideoCapture cap = cv::VideoCapture(fileName.toStdString());

    while (true){
        cv::Mat frame;
        cap >> frame;
        if(frame.empty())
            break;

        cv::imshow("videoCaptureUI", frame);
        cv::waitKey(42);
    }

    cap.release();
}
