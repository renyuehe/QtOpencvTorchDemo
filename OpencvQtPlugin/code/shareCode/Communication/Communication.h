#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QVariant>
#include <QDebug>

#include <QtCore/qglobal.h>
#include <QPixmap>

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
    QPixmap mSrcPixmap;
    QPixmap mDstPixmap;

public:
    Communication();

public:
    /**
     * @brief SendMsg 消息发布接口
     * @param code
     * @param msg
     */
    void SendMsg(int code, const QVariant& msg);

signals:
    /**
     * @brief SendMsg 消息发布信号
     * @param code
     * @param msg
     */
    void SendMsgToManager(int code,const QVariant& msg);
};

#define SEND_MSG(code,msg)\
{\
    Communication* instance = Communication::GetInstance();\
    instance->SendMsg(code,msg);\
};

#define SRC_IMG  Communication::GetInstance()->mSrcPixmap
#define DST_IMG  Communication::GetInstance()->mDstPixmap

#endif // COMMUNICATION_H
