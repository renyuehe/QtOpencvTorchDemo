#include "Communication.h"

Communication* Communication::m_ComInstance = Q_NULLPTR;
Communication *Communication::GetInstance()
{
    if(!m_ComInstance){
        m_ComInstance = new Communication();
    }
    return m_ComInstance;
}

Communication::Communication()
{
}

/**
 * @brief SendMsg 消息发布接口
 * @param code
 * @param msg
 */
void Communication::SendMsg(int code, const QVariant& msg)
{
    if(code == 10000)
        m_CurrentPluginName = msg.toString();

    emit SendMsgToManager(code,msg);
}
