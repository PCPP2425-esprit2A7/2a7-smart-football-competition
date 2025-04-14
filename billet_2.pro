QT += core gui printsupport
QT       += core gui sql
QT       += core gui

QT += core gui widgets charts
QT += core gui multimedia
CONFIG += c++11
SOURCES += qrcodegen.cpp \
    dialog.cpp
HEADERS += qrcodegen.hpp \
    dialog.h


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
    mainwindow.cpp

HEADERS += \
    connection.h \
    dialog_billet.h \
    generate_tickets.h \
    gestion_billet.h \
    mainwindow.h

FORMS += \
    dialog.ui \
    dialog_billet.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES +=
