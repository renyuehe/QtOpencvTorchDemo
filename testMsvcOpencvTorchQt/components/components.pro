TEMPLATE = lib

QT += core gui widgets
CONFIG += staticlib

include(../top.pri)

#生成路径
DESTDIR = $$DEST_LIBS


HEADERS += \
    HMdiArea.h \
    HYMdiArea.h \

HEADERS += \
    qtmaterialavatar_p.h \
    qtmaterialavatar.h \
    qtmaterialstyle_p.h \
    qtmaterialstyle.h \
    qtmaterialtheme_p.h \
    qtmaterialtheme.h \
    qtmaterialbadge_p.h \
    qtmaterialbadge.h \
    qtmaterialoverlaywidget.h \
    qtmaterialcheckbox_p.h \
    qtmaterialcheckbox.h \
    qtmaterialcheckable_internal.h \
    qtmaterialcheckable_p.h \
    qtmaterialripple.h \
    qtmaterialrippleoverlay.h \
    qtmaterialcheckable.h \
    qtmaterialfab_p.h \
    qtmaterialfab.h \
    qtmaterialraisedbutton_p.h \
    qtmaterialraisedbutton.h \
    qtmaterialflatbutton_internal.h \
    qtmaterialflatbutton_p.h \
    qtmaterialflatbutton.h \
    qtmaterialstatetransition.h \
    qtmaterialstatetransitionevent.h \
    qtmaterialiconbutton_p.h \
    qtmaterialiconbutton.h \
    qtmaterialprogress_internal.h \
    qtmaterialprogress_p.h \
    qtmaterialprogress.h \
    qtmaterialcircularprogress_internal.h \
    qtmaterialcircularprogress_p.h \
    qtmaterialcircularprogress.h \
    qtmaterialslider_internal.h \
    qtmaterialslider_p.h \
    qtmaterialslider.h \
    qtmaterialsnackbar_internal.h \
    qtmaterialsnackbar_p.h \
    qtmaterialsnackbar.h \
    qtmaterialradiobutton_p.h \
    qtmaterialradiobutton.h \
    qtmaterialtoggle_internal.h \
    qtmaterialtoggle_p.h \
    qtmaterialtoggle.h \
    qtmaterialtextfield_internal.h \
    qtmaterialtextfield_p.h \
    qtmaterialtextfield.h \
    qtmaterialtabs_internal.h \
    qtmaterialtabs_p.h \
    qtmaterialtabs.h \
    qtmaterialscrollbar_internal.h \
    qtmaterialscrollbar_p.h \
    qtmaterialscrollbar.h \
    qtmaterialdialog_internal.h \
    qtmaterialdialog_p.h \
    qtmaterialdialog.h \
    qtmaterialdrawer_internal.h \
    qtmaterialdrawer_p.h \
    qtmaterialdrawer.h \
    qtmaterialappbar.h \
    qtmaterialappbar_p.h \
    qtmaterialautocomplete.h \
    qtmaterialautocomplete_p.h \
    qtmaterialpaper.h \
    qtmaterialpaper_p.h \
    qtmaterialtable.h \
    qtmaterialtable_p.h \
    qtmaterialsnackbarlayout.h \
    qtmaterialsnackbarlayout_p.h \
    qtmaterialautocomplete_internal.h \
    qtmaterialmenu.h \
    qtmaterialmenu_p.h \
    qtmaterialmenu_internal.h \
    qtmateriallist.h \
    qtmateriallist_p.h \
    qtmateriallistitem.h \
    qtmateriallistitem_p.h

SOURCES += \
    complete/HMdiArea.cpp \
    complete/HYMdiarea.cpp \


SOURCES += \
    complete/qtmaterialavatar.cpp \
    complete/qtmaterialstyle.cpp \
    complete/qtmaterialtheme.cpp \
    complete/qtmaterialbadge.cpp \
    complete/qtmaterialoverlaywidget.cpp \
    complete/qtmaterialcheckbox.cpp \
    complete/qtmaterialcheckable_internal.cpp \
    complete/qtmaterialcheckable.cpp \
    complete/qtmaterialripple.cpp \
    complete/qtmaterialrippleoverlay.cpp \
    complete/qtmaterialfab.cpp \
    complete/qtmaterialraisedbutton.cpp \
    complete/qtmaterialflatbutton_internal.cpp \
    complete/qtmaterialflatbutton.cpp \
    complete/qtmaterialstatetransition.cpp \
    complete/qtmaterialiconbutton.cpp \
    complete/qtmaterialprogress_internal.cpp \
    complete/qtmaterialprogress.cpp \
    complete/qtmaterialcircularprogress_internal.cpp \
    complete/qtmaterialcircularprogress.cpp \
    complete/qtmaterialslider_internal.cpp \
    complete/qtmaterialslider.cpp \
    complete/qtmaterialsnackbar_internal.cpp \
    complete/qtmaterialsnackbar.cpp \
    complete/qtmaterialradiobutton.cpp \
    complete/qtmaterialtoggle_internal.cpp \
    complete/qtmaterialtoggle.cpp \
    complete/qtmaterialtextfield_internal.cpp \
    complete/qtmaterialtextfield.cpp \
    complete/qtmaterialtabs_internal.cpp \
    complete/qtmaterialtabs.cpp \
    complete/qtmaterialscrollbar_internal.cpp \
    complete/qtmaterialscrollbar.cpp \
    complete/qtmaterialdialog_internal.cpp \
    complete/qtmaterialdialog.cpp \
    complete/qtmaterialdrawer_internal.cpp \
    complete/qtmaterialdrawer.cpp \
    complete/qtmaterialappbar.cpp \
    complete/qtmaterialautocomplete.cpp \
    complete/qtmaterialpaper.cpp \
    complete/qtmaterialtable.cpp \
    complete/qtmaterialsnackbarlayout.cpp \
    complete/qtmaterialautocomplete_internal.cpp \
    complete/qtmaterialmenu.cpp \
    complete/qtmaterialmenu_internal.cpp \
    complete/qtmateriallist.cpp \
    complete/qtmateriallistitem.cpp

RESOURCES += \
    resources.qrc
