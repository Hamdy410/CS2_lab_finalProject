
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG   += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminform.cpp \
    dashboard.cpp \
    inventory.cpp \
    inventoryform.cpp \
    inventorysystem.cpp \
    item.cpp \
    loginform.cpp \
    main.cpp \
    mainwindow.cpp \
    operationrecord.cpp \
    record.cpp \
    role.cpp \
    signupform.cpp \
    systemui.cpp \
    user.cpp \

HEADERS += \
    adminform.h \
    dashboard.h \
    inventory.h \
    inventoryform.h \
    inventorysystem.h \
    item.h \
    loginform.h \
    mainwindow.h \
    operationrecord.h \
    record.h \
    role.h \
    signupform.h \
    systemui.h \
    user.h

FORMS += \
    adminform.ui \
    dashboard.ui \
    inventoryform.ui \
    loginform.ui \
    mainwindow.ui \
    signupform.ui \
    systemui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
