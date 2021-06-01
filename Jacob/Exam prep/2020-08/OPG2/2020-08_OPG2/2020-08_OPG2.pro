TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Material.cpp \
        TimeAndMaterials.cpp \
        TimeSheet.cpp \
        WorkHours.cpp \
        main.cpp

HEADERS += \
    Material.h \
    TimeAndMaterials.h \
    TimeSheet.h \
    WorkHours.h
