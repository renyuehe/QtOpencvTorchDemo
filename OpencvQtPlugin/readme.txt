打包命令: windeployqt  

插件方式  实现 Opencv 的管理版本

MainForm 是主框架

Plugin 里面是插件

LIb 里面存放一些库，比如 communication（插件和主框架通讯的库，相互之间只包含头文件声明，编译的时候连接库）

thirdLib 是第三方库，比如opencv、libtorch

common/common.pri 负责整个项目的控制,比如库路径,插件路径,sharecode路径

