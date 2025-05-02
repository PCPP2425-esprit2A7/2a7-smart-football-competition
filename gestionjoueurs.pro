QT  += core gui sql
QT += core gui widgets charts
QT += network
QT+= core gui printsupport
QT += serialport



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connection.cpp \
    dialog_stat_joueur.cpp \
    joueur.cpp \
    main.cpp \
    mainwindow_joueur.cpp \
    openaiclient.cpp \
    playersubstitutiondialog.cpp

HEADERS += \
    arduino.h \
    connection.h \
    dialog_stat_joueur.h \
    joueur.h \
    mainwindow_joueur.h \
    openaiclient.h \
    playersubstitutiondialog.h

FORMS += \
    dialog_stat_joueur.ui \
    mainwindow_joueur.ui \
    playersubstitutiondialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

QT += network



