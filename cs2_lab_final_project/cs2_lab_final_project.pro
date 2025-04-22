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
<<<<<<< HEAD
    record.cpp \
    role.cpp \
    ui_adduserdialog.cpp \
    ui_adminform.cpp \
    ui_edituserdialog.cpp \
=======
    signupform.cpp \
>>>>>>> 45d8d739672ecad24dea7d9414b3ae5fcda1f962
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
<<<<<<< HEAD
    record.h \
    role.h \
    ui_adduserdialog.h \
    ui_adminform.h \
    ui_edituserdialog.h \
=======
    signupform.h \
>>>>>>> 45d8d739672ecad24dea7d9414b3ae5fcda1f962
    user.h

FORMS += \
    dashboard.ui \
    inventoryform.ui \
    loginform.ui \
    mainwindow.ui \
<<<<<<< HEAD
    ui_adduserdialog.ui \
    ui_adminform.ui \
    ui_edituserdialog.ui
=======
    signupform.ui
>>>>>>> 45d8d739672ecad24dea7d9414b3ae5fcda1f962

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    db.qrc
