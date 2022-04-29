QT       += core gui sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    blackjack.cpp \
    crash.cpp \
    hilo.cpp \
    main.cpp \
    authorization.cpp \
    mainwindow.cpp \
    minesweeper.cpp \
    registrationwindow.cpp \
    roulette.cpp \
    slots.cpp

HEADERS += \
    authorization.h \
    blackjack.h \
    crash.h \
    hilo.h \
    mainwindow.h \
    minesweeper.h \
    registrationwindow.h \
    roulette.h \
    slots.h

FORMS += \
    authorization.ui \
    blackjack.ui \
    crash.ui \
    hilo.ui \
    mainwindow.ui \
    minesweeper.ui \
    registrationwindow.ui \
    roulette.ui \
    slots.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc \
    rosource.qrc
