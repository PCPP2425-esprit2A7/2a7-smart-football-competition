QT += core gui printsupport
QT       += core gui sql
QT       += core gui
QT += serialport
QT += network
QT += core gui widgets charts
QT += core gui multimedia
CONFIG += c++11
SOURCES += qrcodegen.cpp \
    arduino.cpp \
    dialog_stat_billet.cpp \
    welcom_page.cpp
HEADERS += qrcodegen.hpp \
    arduino.h \
    dialog_stat_billet.h \
    welcom_page.h


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
    dialog_supporteur.cpp\
    arbitre.cpp \
    dialog_arbitre.cpp \
    emaildialog_arbitre.cpp \
    historiquedialog.cpp \
    mainwindow_arbitre.cpp\
    dialog_stat_joueur.cpp \
    joueur.cpp \
    mainwindow_joueur.cpp \
    openaiclient.cpp \
    playersubstitutiondialog.cpp\
    calendrierwidget.cpp \
    mainwindow_match.cpp \
    match.cpp \
    superviser.cpp\
    equipe.cpp \
    mainwindow_equipe.cpp
HEADERS += \
    connection.h \
    dialog_billet.h \
    generate_tickets.h \
    gestion_billet.h \
    mainwindow_billet.h \
    dialog_supporteur.h \
    mainwindow_supporteur.h \
    supporteur.h\
    arbitre.h \
    dialog_arbitre.h \
    emaildialog_arbitre.h \
    historiquedialog.h \
    mainwindow_arbitre.h \
    dialog_stat_joueur.h \
    joueur.h \
    mainwindow_joueur.h \
    openaiclient.h \
    playersubstitutiondialog.h\
    calendrierwidget.h \
    mainwindow_match.h \
    match.h \
    superviser.h\
    equipe.h \
    mainwindow_equipe.h

FORMS += \
    dialog_billet.ui \
    dialog_stat_billet.ui \
    mainwindow_billet.ui \
    dialog_supporteur.ui \
    mainwindow_supporteur.ui \
    dialog_arbitre.ui \
    emaildialog_arbitre.ui \
    historiquedialog.ui \
    mainwindow_arbitre.ui\
    dialog_stat_joueur.ui \
    mainwindow_joueur.ui \
    playersubstitutiondialog.ui\
    mainwindow_match.ui \
    superviser.ui \
    welcom_page.ui\
    mainwindow_equipe.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES +=
