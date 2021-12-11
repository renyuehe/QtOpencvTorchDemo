#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QVariant>
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>

#include <QtCore/qglobal.h>

#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/world.hpp"

#if defined(COMMON_LIBRARY)
#  define D_COMMONSHARED_EXPORT Q_DECL_EXPORT
#else
#  define D_COMMONSHARED_EXPORT Q_DECL_IMPORT
#endif

class D_COMMONSHARED_EXPORT Communication : public QObject
{
    Q_OBJECT
private:
    static Communication* m_ComInstance;
    QString m_CurrentPluginName;

public:
    static Communication *GetInstance();

    cv::Mat mBaseMat;//绝对原图
    cv::Mat mSrcMat;//相对原图(连续处理时会被破坏)
    cv::Mat mDstMat;//相对目标图(连续处理时就是mSrcMat)

    bool canBegin(){
        if(Communication::GetInstance()->mSrcMat.empty()){
            QMessageBox::warning(nullptr, QString("warning"), QString("no src img"));
            return false;
        }
        else
            return true;
    }


private:
    Communication();    

signals:

    /**
     * @brief 更新主框架 dstPixmap 信号
     */
    void signalUpdateDstimg();
};

#define COM_BEGIN \
    if(!Communication::GetInstance()->canBegin()) \
    return;

#define SEND_MSG(code,msg)\
{\
    Communication* instance = Communication::GetInstance();\
    instance->SendMsg(code,msg);\
};

#define BASE_MAT  Communication::GetInstance()->mBaseMat
#define SRC_MAT  Communication::GetInstance()->mSrcMat
#define DST_MAT  Communication::GetInstance()->mDstMat
#define UPDATE_DST (emit Communication::GetInstance()->signalUpdateDstimg());

#endif // COMMUNICATION_H
