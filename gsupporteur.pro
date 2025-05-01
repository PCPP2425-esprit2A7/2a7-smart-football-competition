QT += core gui printsupport
QT       += core gui sql
QT       += core gui
QT += serialport

QT += core gui widgets charts
QT += core gui multimedia
CONFIG += c++11
SOURCES += qrcodegen.cpp \
    arduino.cpp \
    dialog_stat_billet.cpp
HEADERS += qrcodegen.hpp \
    arduino.h \
    dialog_stat_billet.h


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    dialog_billet.cpp \
    generate_tickets.cpp \
    gestion_billet.cpp \
    main.cpp \
    mainwindow_billet.cpp \
    mainwindow_supporteur.cpp \
    supporteur.cpp \
    dialog_supporteur.cpp

HEADERS += \
    connection.h \
    dialog_billet.h \
    generate_tickets.h \
    gestion_billet.h \
    mainwindow_billet.h \
    dialog_supporteur.h \
    mainwindow_supporteur.h \
    supporteur.h


FORMS += \
    dialog_billet.ui \
    dialog_stat_billet.ui \
    mainwindow_billet.ui \
    dialog_supporteur.ui \
    mainwindow_supporteur.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES +=
