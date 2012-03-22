#############################################################################
# Makefile for building: EntornQTGC2
# Generated by qmake (2.01a) (Qt 4.6.2) on: mi� mar 21 19:54:38 2012
# Project:  EntornQTGC2.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger -o Makefile EntornQTGC2.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtOpenGL -I/usr/include/qt4 -I/usr/X11R6/include -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib -L/usr/X11R6/lib -lGLEW -lQtOpenGL -lQtGui -lQtCore -lGLU -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		uigc2.cpp \
		Model.cpp \
		GLWidget.cpp \
		objectloader.cpp \
		lib3ds/viewport.c \
		lib3ds/vector.c \
		lib3ds/tracks.c \
		lib3ds/tcb.c \
		lib3ds/shadow.c \
		lib3ds/quat.c \
		lib3ds/node.c \
		lib3ds/mesh.c \
		lib3ds/matrix.c \
		lib3ds/material.c \
		lib3ds/light.c \
		lib3ds/io.c \
		lib3ds/file.c \
		lib3ds/ease.c \
		lib3ds/chunk.c \
		lib3ds/camera.c \
		lib3ds/background.c \
		lib3ds/atmosphere.c \
		cameracontrol.cpp \
		collisionmanager.cpp \
		coldet/src/box.cpp \
		coldet/src/box_bld.cpp \
		coldet/src/coldet.cpp \
		coldet/src/coldet_bld.cpp \
		coldet/src/math3d.cpp \
		coldet/src/mytritri.cpp \
		coldet/src/sysdep.cpp \
		coldet/src/tritri.c moc_uigc2.cpp \
		moc_GLWidget.cpp
OBJECTS       = main.o \
		uigc2.o \
		Model.o \
		GLWidget.o \
		objectloader.o \
		viewport.o \
		vector.o \
		tracks.o \
		tcb.o \
		shadow.o \
		quat.o \
		node.o \
		mesh.o \
		matrix.o \
		material.o \
		light.o \
		io.o \
		file.o \
		ease.o \
		chunk.o \
		camera.o \
		background.o \
		atmosphere.o \
		cameracontrol.o \
		collisionmanager.o \
		box.o \
		box_bld.o \
		coldet.o \
		coldet_bld.o \
		math3d.o \
		mytritri.o \
		sysdep.o \
		tritri.o \
		moc_uigc2.o \
		moc_GLWidget.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		EntornQTGC2.pro
QMAKE_TARGET  = EntornQTGC2
DESTDIR       = 
TARGET        = EntornQTGC2

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_uigc2.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: EntornQTGC2.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/opengl.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/libQtOpenGL.prl \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger -o Makefile EntornQTGC2.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/opengl.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/libQtOpenGL.prl:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger -o Makefile EntornQTGC2.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/EntornQTGC21.0.0 || $(MKDIR) .tmp/EntornQTGC21.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/EntornQTGC21.0.0/ && $(COPY_FILE) --parents uigc2.h Util.h Model.h GLWidget.h objectloader.h lib3ds/viewport.h lib3ds/vector.h lib3ds/types.h lib3ds/tracks.h lib3ds/tcb.h lib3ds/shadow.h lib3ds/quat.h lib3ds/node.h lib3ds/mesh.h lib3ds/matrix.h lib3ds/material.h lib3ds/light.h lib3ds/io.h lib3ds/file.h lib3ds/ease.h lib3ds/chunktable.sed lib3ds/chunktable.h lib3ds/chunk.h lib3ds/camera.h lib3ds/background.h lib3ds/atmosphere.h cameracontrol.h collisionmanager.h coldet/src/box.h coldet/src/coldet.h coldet/src/coldetimpl.h coldet/src/math3d.h coldet/src/mytritri.h coldet/src/sysdep.h .tmp/EntornQTGC21.0.0/ && $(COPY_FILE) --parents main.cpp uigc2.cpp Model.cpp GLWidget.cpp objectloader.cpp lib3ds/viewport.c lib3ds/vector.c lib3ds/tracks.c lib3ds/tcb.c lib3ds/shadow.c lib3ds/quat.c lib3ds/node.c lib3ds/mesh.c lib3ds/matrix.c lib3ds/material.c lib3ds/light.c lib3ds/io.c lib3ds/file.c lib3ds/ease.c lib3ds/chunk.c lib3ds/camera.c lib3ds/background.c lib3ds/atmosphere.c cameracontrol.cpp collisionmanager.cpp coldet/src/box.cpp coldet/src/box_bld.cpp coldet/src/coldet.cpp coldet/src/coldet_bld.cpp coldet/src/math3d.cpp coldet/src/mytritri.cpp coldet/src/sysdep.cpp coldet/src/tritri.c .tmp/EntornQTGC21.0.0/ && $(COPY_FILE) --parents uigc2.ui .tmp/EntornQTGC21.0.0/ && (cd `dirname .tmp/EntornQTGC21.0.0` && $(TAR) EntornQTGC21.0.0.tar EntornQTGC21.0.0 && $(COMPRESS) EntornQTGC21.0.0.tar) && $(MOVE) `dirname .tmp/EntornQTGC21.0.0`/EntornQTGC21.0.0.tar.gz . && $(DEL_FILE) -r .tmp/EntornQTGC21.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_uigc2.cpp moc_GLWidget.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_uigc2.cpp moc_GLWidget.cpp
moc_uigc2.cpp: uigc2.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) uigc2.h -o moc_uigc2.cpp

moc_GLWidget.cpp: Model.h \
		Util.h \
		cameracontrol.h \
		objectloader.h \
		lib3ds/file.h \
		lib3ds/background.h \
		lib3ds/types.h \
		lib3ds/atmosphere.h \
		lib3ds/shadow.h \
		lib3ds/viewport.h \
		lib3ds/camera.h \
		lib3ds/mesh.h \
		lib3ds/node.h \
		lib3ds/tracks.h \
		lib3ds/tcb.h \
		lib3ds/material.h \
		lib3ds/matrix.h \
		lib3ds/vector.h \
		lib3ds/light.h \
		GLWidget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) GLWidget.h -o moc_GLWidget.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_uigc2.h
compiler_uic_clean:
	-$(DEL_FILE) ui_uigc2.h
ui_uigc2.h: uigc2.ui \
		GLWidget.h \
		Model.h \
		Util.h \
		cameracontrol.h \
		objectloader.h \
		lib3ds/file.h \
		lib3ds/background.h \
		lib3ds/types.h \
		lib3ds/atmosphere.h \
		lib3ds/shadow.h \
		lib3ds/viewport.h \
		lib3ds/camera.h \
		lib3ds/mesh.h \
		lib3ds/node.h \
		lib3ds/tracks.h \
		lib3ds/tcb.h \
		lib3ds/material.h \
		lib3ds/matrix.h \
		lib3ds/vector.h \
		lib3ds/light.h
	/usr/bin/uic-qt4 uigc2.ui -o ui_uigc2.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp uigc2.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

uigc2.o: uigc2.cpp uigc2.h \
		ui_uigc2.h \
		GLWidget.h \
		Model.h \
		Util.h \
		cameracontrol.h \
		objectloader.h \
		lib3ds/file.h \
		lib3ds/background.h \
		lib3ds/types.h \
		lib3ds/atmosphere.h \
		lib3ds/shadow.h \
		lib3ds/viewport.h \
		lib3ds/camera.h \
		lib3ds/mesh.h \
		lib3ds/node.h \
		lib3ds/tracks.h \
		lib3ds/tcb.h \
		lib3ds/material.h \
		lib3ds/matrix.h \
		lib3ds/vector.h \
		lib3ds/light.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o uigc2.o uigc2.cpp

Model.o: Model.cpp Model.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Model.o Model.cpp

GLWidget.o: GLWidget.cpp GLWidget.h \
		Model.h \
		Util.h \
		cameracontrol.h \
		objectloader.h \
		lib3ds/file.h \
		lib3ds/background.h \
		lib3ds/types.h \
		lib3ds/atmosphere.h \
		lib3ds/shadow.h \
		lib3ds/viewport.h \
		lib3ds/camera.h \
		lib3ds/mesh.h \
		lib3ds/node.h \
		lib3ds/tracks.h \
		lib3ds/tcb.h \
		lib3ds/material.h \
		lib3ds/matrix.h \
		lib3ds/vector.h \
		lib3ds/light.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o GLWidget.o GLWidget.cpp

objectloader.o: objectloader.cpp objectloader.h \
		lib3ds/file.h \
		lib3ds/background.h \
		lib3ds/types.h \
		lib3ds/atmosphere.h \
		lib3ds/shadow.h \
		lib3ds/viewport.h \
		lib3ds/camera.h \
		lib3ds/mesh.h \
		lib3ds/node.h \
		lib3ds/tracks.h \
		lib3ds/tcb.h \
		lib3ds/material.h \
		lib3ds/matrix.h \
		lib3ds/vector.h \
		lib3ds/light.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o objectloader.o objectloader.cpp

viewport.o: lib3ds/viewport.c lib3ds/viewport.h \
		lib3ds/types.h \
		lib3ds/chunk.h \
		lib3ds/io.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o viewport.o lib3ds/viewport.c

vector.o: lib3ds/vector.c lib3ds/vector.h \
		lib3ds/types.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o vector.o lib3ds/vector.c

tracks.o: lib3ds/tracks.c lib3ds/tracks.h \
		lib3ds/tcb.h \
		lib3ds/types.h \
		lib3ds/io.h \
		lib3ds/chunk.h \
		lib3ds/vector.h \
		lib3ds/quat.h \
		lib3ds/node.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o tracks.o lib3ds/tracks.c

tcb.o: lib3ds/tcb.c lib3ds/tcb.h \
		lib3ds/types.h \
		lib3ds/io.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o tcb.o lib3ds/tcb.c

shadow.o: lib3ds/shadow.c lib3ds/shadow.h \
		lib3ds/types.h \
		lib3ds/chunk.h \
		lib3ds/io.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o shadow.o lib3ds/shadow.c

quat.o: lib3ds/quat.c lib3ds/quat.h \
		lib3ds/types.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o quat.o lib3ds/quat.c

node.o: lib3ds/node.c lib3ds/node.h \
		lib3ds/tracks.h \
		lib3ds/tcb.h \
		lib3ds/types.h \
		lib3ds/file.h \
		lib3ds/background.h \
		lib3ds/atmosphere.h \
		lib3ds/shadow.h \
		lib3ds/viewport.h \
		lib3ds/io.h \
		lib3ds/chunk.h \
		lib3ds/matrix.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o node.o lib3ds/node.c

mesh.o: lib3ds/mesh.c lib3ds/mesh.h \
		lib3ds/types.h \
		lib3ds/io.h \
		lib3ds/chunk.h \
		lib3ds/vector.h \
		lib3ds/matrix.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o mesh.o lib3ds/mesh.c

matrix.o: lib3ds/matrix.c lib3ds/matrix.h \
		lib3ds/types.h \
		lib3ds/quat.h \
		lib3ds/vector.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o matrix.o lib3ds/matrix.c

material.o: lib3ds/material.c lib3ds/material.h \
		lib3ds/types.h \
		lib3ds/chunk.h \
		lib3ds/io.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o material.o lib3ds/material.c

light.o: lib3ds/light.c lib3ds/light.h \
		lib3ds/types.h \
		lib3ds/chunk.h \
		lib3ds/io.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o light.o lib3ds/light.c

io.o: lib3ds/io.c lib3ds/io.h \
		lib3ds/types.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o io.o lib3ds/io.c

file.o: lib3ds/file.c lib3ds/file.h \
		lib3ds/background.h \
		lib3ds/types.h \
		lib3ds/atmosphere.h \
		lib3ds/shadow.h \
		lib3ds/viewport.h \
		lib3ds/chunk.h \
		lib3ds/io.h \
		lib3ds/material.h \
		lib3ds/mesh.h \
		lib3ds/camera.h \
		lib3ds/light.h \
		lib3ds/node.h \
		lib3ds/tracks.h \
		lib3ds/tcb.h \
		lib3ds/matrix.h \
		lib3ds/vector.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o file.o lib3ds/file.c

ease.o: lib3ds/ease.c lib3ds/ease.h \
		lib3ds/types.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o ease.o lib3ds/ease.c

chunk.o: lib3ds/chunk.c lib3ds/chunk.h \
		lib3ds/types.h \
		lib3ds/io.h \
		lib3ds/chunktable.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o chunk.o lib3ds/chunk.c

camera.o: lib3ds/camera.c lib3ds/camera.h \
		lib3ds/types.h \
		lib3ds/chunk.h \
		lib3ds/io.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o camera.o lib3ds/camera.c

background.o: lib3ds/background.c lib3ds/background.h \
		lib3ds/types.h \
		lib3ds/chunk.h \
		lib3ds/io.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o background.o lib3ds/background.c

atmosphere.o: lib3ds/atmosphere.c lib3ds/atmosphere.h \
		lib3ds/types.h \
		lib3ds/chunk.h \
		lib3ds/io.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o atmosphere.o lib3ds/atmosphere.c

cameracontrol.o: cameracontrol.cpp cameracontrol.h \
		collisionmanager.h \
		coldet/src/coldet.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cameracontrol.o cameracontrol.cpp

collisionmanager.o: collisionmanager.cpp collisionmanager.h \
		coldet/src/coldet.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o collisionmanager.o collisionmanager.cpp

box.o: coldet/src/box.cpp coldet/src/sysdep.h \
		coldet/src/box.h \
		coldet/src/math3d.h \
		coldet/src/mytritri.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o box.o coldet/src/box.cpp

box_bld.o: coldet/src/box_bld.cpp coldet/src/sysdep.h \
		coldet/src/box.h \
		coldet/src/math3d.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o box_bld.o coldet/src/box_bld.cpp

coldet.o: coldet/src/coldet.cpp coldet/src/sysdep.h \
		coldet/src/coldetimpl.h \
		coldet/src/coldet.h \
		coldet/src/box.h \
		coldet/src/math3d.h \
		coldet/src/mytritri.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o coldet.o coldet/src/coldet.cpp

coldet_bld.o: coldet/src/coldet_bld.cpp coldet/src/sysdep.h \
		coldet/src/coldetimpl.h \
		coldet/src/coldet.h \
		coldet/src/box.h \
		coldet/src/math3d.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o coldet_bld.o coldet/src/coldet_bld.cpp

math3d.o: coldet/src/math3d.cpp coldet/src/sysdep.h \
		coldet/src/math3d.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o math3d.o coldet/src/math3d.cpp

mytritri.o: coldet/src/mytritri.cpp coldet/src/sysdep.h \
		coldet/src/mytritri.h \
		coldet/src/box.h \
		coldet/src/math3d.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mytritri.o coldet/src/mytritri.cpp

sysdep.o: coldet/src/sysdep.cpp coldet/src/sysdep.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sysdep.o coldet/src/sysdep.cpp

tritri.o: coldet/src/tritri.c 
	$(CC) -c $(CFLAGS) $(INCPATH) -o tritri.o coldet/src/tritri.c

moc_uigc2.o: moc_uigc2.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_uigc2.o moc_uigc2.cpp

moc_GLWidget.o: moc_GLWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_GLWidget.o moc_GLWidget.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

