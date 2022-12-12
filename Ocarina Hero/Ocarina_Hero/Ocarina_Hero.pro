QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ocarina_Hero
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17

SOURCES += \
    Notes.cpp \
    health.cpp \
    main.cpp \
    ocarinahero.cpp \
    player.cpp \
    score.cpp \
    streak.cpp

HEADERS += \
    Notes.h \
    health.h \
    ocarinahero.h \
    player.h \
    score.h \
    streak.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    sounds.qrc
