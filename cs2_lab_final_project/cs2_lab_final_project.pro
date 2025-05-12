
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG   += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adduserform.cpp \
    adminform.cpp \
    dashboard.cpp \
    editroleform.cpp \
    helpers.cpp \
    inventory.cpp \
    inventoryform.cpp \
    inventorysystem.cpp \
    item.cpp \
    itemphotomanager.cpp \
    loginform.cpp \
    main.cpp \
    mainwindow.cpp \
    operationrecord.cpp \
    record.cpp \
    role.cpp \
    systemui.cpp \
    user.cpp \

HEADERS += \
    adduserform.h \
    adminform.h \
    dashboard.h \
    editroleform.h \
    helpers.h \
    inventory.h \
    inventoryform.h \
    inventorysystem.h \
    item.h \
    itemphotomanager.h \
    loginform.h \
    mainwindow.h \
    operationrecord.h \
    record.h \
    role.h \
    systemui.h \
    user.h

FORMS += \
    adduserform.ui \
    adminform.ui \
    dashboard.ui \
    editroleform.ui \
    inventoryform.ui \
    loginform.ui \
    mainwindow.ui \
    systemui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    db.qrc
