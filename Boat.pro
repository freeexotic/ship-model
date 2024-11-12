QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


INCLUDEPATH += \
    $$PWD/map \
    $$PWD/objects \
    $$PWD/functions



SOURCES += \
    functions/global_2d.cpp \
    functions/local_2d.cpp \
    functions/math.cpp \
    functions/polar_2d.cpp \
    main.cpp \
    mainwindow.cpp \
    map/map_interface.cpp \
    map/orentation.cpp \
    map/scene_object.cpp \
    objects/map_grid.cpp

HEADERS += \
    functions/global_2d.h \
    functions/local_2d.h \
    functions/math.h \
    functions/polar_2d.h \
    mainwindow.h \
    map/map_interface.h \
    map/orentation.h \
    map/scene_object.h \
    objects/map_grid.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    anotation.md \
    my_thoughts.md

LIBS += \
    -lGeographicLib
INCLUDEPATH += \
    /usr/local/include/GeographicLib
