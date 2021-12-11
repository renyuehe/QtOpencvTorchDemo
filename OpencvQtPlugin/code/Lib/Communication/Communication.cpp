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
