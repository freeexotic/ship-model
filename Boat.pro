QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 warn_on debug
QMAKE_CXXFLAGS += -std=c++17 -fdiagnostics-show-option

INCLUDEPATH += \
    $$PWD/map \
    $$PWD/objects \
    $$PWD/functions \
    $$PWD/objects/boat

DEPENDPATH += $$PWD/map $$PWD/objects $$PWD/functions $$PWD/objects/boat

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
    objects/boat/boat_model.cpp \
    objects/boat/boat_obj.cpp \
    objects/boat/controller_boat.cpp \
    objects/map_grid.cpp \
    objects/pool_object.cpp

HEADERS += \
    functions/global_2d.h \
    functions/local_2d.h \
    functions/math.h \
    functions/polar_2d.h \
    mainwindow.h \
    map/map_interface.h \
    map/orentation.h \
    map/scene_object.h \
    objects/boat/boat_model.h \
    objects/boat/boat_obj.h \
    objects/boat/controller_boat.h \
    objects/map_grid.h \
    objects/pool_object.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    anotation.md \
    my_thoughts.md

LIBS += -lGeographicLib
INCLUDEPATH += /usr/local/include/GeographicLib
