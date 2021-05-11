QT       += core gui\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#TARGET = StartWindow.ui
#TEMPLATE = app

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Button.cpp \
    Enemy1.cpp \
    Enemy2.cpp \
    Game.cpp \
    Goal.cpp \
    Player.cpp \
    Score.cpp \
    Warrants.cpp \
    coinScore.cpp \
    main.cpp \
    titlewindow.cpp

HEADERS += \
    Button.h \
    Button.h \
    Enemy1.h \
    Enemy2.h \
    Game.h \
    Goal.h \
    Player.h \
    Score.h \
    Warrants.h \
    coinScore.h \
    titlewindow.h

FORMS += \
    titlewindow.ui
    # TitleWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    media.qrc

#DISTFILES +=
