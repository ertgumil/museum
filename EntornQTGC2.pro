# -------------------------------------------------
# Project created by QtCreator 2012-02-23T13:11:34
# -------------------------------------------------
unix:LIBS += -lGLEW -lGLU

# Llibreria OpenGl
QT += core \
    gui \
    opengl
TARGET = EntornQTGC2
TEMPLATE = app
SOURCES += main.cpp \
    uigc2.cpp \
    Model.cpp \
    GLWidget.cpp \
    cameracontrol.cpp \
    collisionmanager.cpp \
    coldet/src/box.cpp \
    coldet/src/box_bld.cpp \
    coldet/src/coldet.cpp \
    coldet/src/coldet_bld.cpp \
    coldet/src/math3d.cpp \
    coldet/src/mytritri.cpp \
    coldet/src/sysdep.cpp \
    coldet/src/tritri.c \
    lightmanager.cpp \
    object.cpp \
    objectmanager.cpp \
    sg/sgPerlinNoise.cxx \
    sg/sgIsect.cxx \
    sg/sgdIsect.cxx \
    sg/sgd.cxx \
    sg/sg.cxx \
    sg/ulError.cxx \
    lights.cpp \
    expat/xmltok_ns.c \
    expat/xmltok_impl.c \
    expat/xmltok.c \
    expat/xmlrole.c \
    expat/xmlparse.c \
    expat/XMLParser.cpp \
    xmlmanager.cpp \
    glwidgetmap.cpp \
    pointer.cpp \
    glm/glmimg_sim.c \
    glm/glmimg_sdl.c \
    glm/glmimg_png.c \
    glm/glmimg_jpg.c \
    glm/glmimg_devil.c \
    glm/glm.cpp \
    glm/glm_util.cpp \
    glm/glmimg.cpp
HEADERS += uigc2.h \
    Util.h \
    Model.h \
    GLWidget.h \
    cameracontrol.h \
    collisionmanager.h \
    coldet/src/box.h \
    coldet/src/coldet.h \
    coldet/src/coldetimpl.h \
    coldet/src/math3d.h \
    coldet/src/mytritri.h \
    coldet/src/sysdep.h \
    lightmanager.h \
    object.h \
    objectmanager.h \
    sg/sg.h \
    sg/ul.h \
    lights.h \
    expat/xmltok_impl.h \
    expat/xmltok.h \
    expat/xmlrole.h \
    expat/winconfig.h \
    expat/utf8tab.h \
    expat/nametab.h \
    expat/macconfig.h \
    expat/latin1tab.h \
    expat/internal.h \
    expat/iasciitab.h \
    expat/expat_external.h \
    expat/expat.h \
    expat/asciitab.h \
    expat/ascii.h \
    expat/amigaconfig.h \
    expat/XMLParser.h \
    xmlmanager.h \
    glwidgetmap.h \
    pointer.h \
    glm/glmint.h \
    glm/glm.h
FORMS += uigc2.ui
OTHER_FILES += simple.vert \
    simple.frag \
    lib3ds/types.txt \
    lib3ds/Makefile.in \
    lib3ds/Makefile.am \
    coldet/src/coldet.dsp \
    coldet/src/makefile.g++ \
    sg/sg.dsp \
    sg/Makefile.in \
    sg/Makefile.am \
    expat/Makefile.MPW \
    expat/libexpatw.def \
    expat/libexpat.def \
    expat/expatw_static.dsp \
    expat/expatw.dsp \
    expat/expat_static.dsp \
    expat/expat.dsp \
    glm/Makefile.in \
    glm/Makefile.am
