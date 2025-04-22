QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dashboard.cpp \
    inventory.cpp \
    inventoryform.cpp \
    inventorysystem.cpp \
    item.cpp \
    loginform.cpp \
    main.cpp \
    mainwindow.cpp \
    operationrecord.cpp \
    signupform.cpp \
    user.cpp

HEADERS += \
    dashboard.h \
    inventory.h \
    inventoryform.h \
    inventorysystem.h \
    item.h \
    loginform.h \
    mainwindow.h \
    operationrecord.h \
    signupform.h \
    user.h

FORMS += \
    dashboard.ui \
    inventoryform.ui \
    loginform.ui \
    mainwindow.ui \
    signupform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    db.qrc
