#ifndef WORKSPACEWIDGET_H
#define WORKSPACEWIDGET_H

#include <QWidget>
#include "ComPluginManager.h"
#include <QStackedWidget>
#include <QTabWidget>


class WorkSpaceWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WorkSpaceWidget(QWidget *parent = nullptr);

signals:

public slots:


private:
    /**
     * @brief m_pComPluginManager 插件管理器
     */
    ComPluginManager* m_pComPluginManager;

    /**
     * @brief m_pWorkStackWidget 右侧工作窗口
     */
    QTabWidget* m_pWorkTabWidget;

private:
    /**
     * @brief InitWorkSpaceWidget 初始化窗口
     */
    void InitWorkSpaceWidget();

    /**
     * @brief LoadPluginAndFillWidget 加载插件并填充窗口
     */
    void LoadPluginAndFillWidget();
};

#endif // WORKSPACEWIDGET_H
