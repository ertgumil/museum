# -------------------------------------------------
# Project created by QtCreator 2012-02-21T16:47:41
# -------------------------------------------------
unix:LIBS += -lGLEW
QT += core \
    gui \
    opengl
TARGET = EntornQTGC2
TEMPLATE = app
SOURCES += main.cpp \
    uigc2.cpp \
    GLWidget.cpp \
    Model.cpp \
    cameracontrol.cpp \
    objectloader.cpp \
    classobject.cpp
HEADERS += uigc2.h \
    GLWidget.h \
    Model.h \
    Util.h \
    cameracontrol.h \
    objectloader.h \
    classobject.h
FORMS += uigc2.ui
OTHER_FILES += simple.frag \
    simple.vert
