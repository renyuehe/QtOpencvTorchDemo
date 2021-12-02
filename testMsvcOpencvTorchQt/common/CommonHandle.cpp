#include "CommonHandle.h"


QPixmap CommonHandleSpace::GetFileIcon(QString path)
{
    QFileInfo fileInfo(path);
    QFileIconProvider icon;
    QPixmap pixmap = icon.icon(fileInfo).pixmap(32,32);
    return pixmap;
}

//QPixmap CommonHandleSpace::GetFileIconEx(QString path)
//{
//    Q_GUI_EXPORT QPixmap qt_pixmapFromWinHICON(HICON icon);
//    SHFILEINFOA psfi;
//    SHGetFileInfoA(path.toStdString().c_str(),NULL,&psfi,sizeof(SHFILEINFOA),SHGFI_ICON);
//    QPixmap pixmap = qt_pixmapFromWinHICON(psfi.hIcon);
//    DestroyIcon(psfi.hIcon);
//    return pixmap;
//}
