QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Case.cpp \
    aide.cpp \
    caserail.cpp \
    casevide.cpp \
    config.cpp \
    continuer.cpp \
    dialog.cpp \
    feu.cpp \
    grille.cpp \
    jouerpartie.cpp \
    main.cpp \
    mainwindow.cpp \
    partie.cpp \
    train.cpp

HEADERS += \
    Case.h \
    aide.h \
    caserail.h \
    casevide.h \
    config.h \
    continuer.h \
    dialog.h \
    feu.h \
    grille.h \
    jouerpartie.h \
    mainwindow.h \
    partie.h \
    train.h

FORMS += \
    aide.ui \
    config.ui \
    continuer.ui \
    dialog.ui \
    jouerpartie.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES +=
