QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++11 debug link_pkgconfig

INCLUDEPATH += \

SOURCES += \
    animationdemo.cpp \
    main.cpp \
    rotatedemo.cpp

HEADERS += \
    animationdemo.h \
    rotatedemo.h

RESOURCES += \
    res.qrc
