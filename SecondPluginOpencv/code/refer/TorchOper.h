#ifndef TORCHOPER_H
#define TORCHOPER_H

#include <QString>

namespace TorchOper
{
    /**
     * @brief 打包预测
     * @return
     */
    int jitModulePredictNumber();
    /**
     * @brief 打包预测、绘制矩形框
     * @return
     */
    int jitPredictYellowArea(QString fileName);
}

#endif // TORCHOPER_H
