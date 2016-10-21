#############################################################################
# Makefile for building: out/target/GWNDiscoveryTool
# Generated by qmake (2.01a) (Qt 4.8.4) on: ?? 10? 13 14:29:14 2016
# Project:  GWNDiscoveryTool.pro
# Template: app
# Command: /usr/local/Trolltech/Qt-4.8.4/bin/qmake -o Makefile GWNDiscoveryTool.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/local/Trolltech/Qt-4.8.4/mkspecs/linux-g++-64 -I. -I/usr/local/Trolltech/Qt-4.8.4/include/QtCore -I/usr/local/Trolltech/Qt-4.8.4/include/QtNetwork -I/usr/local/Trolltech/Qt-4.8.4/include/QtGui -I/usr/local/Trolltech/Qt-4.8.4/include -I. -Iinclude -Isrc -Iout/moc
LINK          = g++
LFLAGS        = -m64 -Wl,-O1 -Wl,-rpath,/usr/local/Trolltech/Qt-4.8.4/lib
LIBS          = $(SUBLIBS)  -L/usr/local/Trolltech/Qt-4.8.4/lib -lQtGui -L/usr/local/Trolltech/Qt-4.8.4/lib -L/usr/X11R6/lib64 -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/local/Trolltech/Qt-4.8.4/bin/qmake
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

OBJECTS_DIR   = out/obj/

####### Files

SOURCES       = include/GLabel.cpp \
		include/GSeparator.cpp \
		include/SingleApp.cpp \
		include/Loading.cpp \
		src/DeviceItem.cpp \
		src/DeviceTab.cpp \
		src/main.cpp \
		src/MainWidget.cpp \
		src/netCardSelectDialog.cpp \
		src/qMDNS.cpp out/moc/moc_DeviceItem.cpp \
		out/moc/moc_DeviceTab.cpp \
		out/moc/moc_GLabel.cpp \
		out/moc/moc_MainWidget.cpp \
		out/moc/moc_Loading.cpp \
		out/moc/moc_SingleApp.cpp \
		out/moc/moc_netCardSelectDialog.cpp \
		out/moc/moc_qMDNS.cpp
OBJECTS       = out/obj/GLabel.o \
		out/obj/GSeparator.o \
		out/obj/SingleApp.o \
		out/obj/Loading.o \
		out/obj/DeviceItem.o \
		out/obj/DeviceTab.o \
		out/obj/main.o \
		out/obj/MainWidget.o \
		out/obj/netCardSelectDialog.o \
		out/obj/qMDNS.o \
		out/obj/moc_DeviceItem.o \
		out/obj/moc_DeviceTab.o \
		out/obj/moc_GLabel.o \
		out/obj/moc_MainWidget.o \
		out/obj/moc_Loading.o \
		out/obj/moc_SingleApp.o \
		out/obj/moc_netCardSelectDialog.o \
		out/obj/moc_qMDNS.o
DIST          = /usr/local/Trolltech/Qt-4.8.4/mkspecs/common/unix.conf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/common/linux.conf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/common/gcc-base.conf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/common/gcc-base-unix.conf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/common/g++-base.conf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/common/g++-unix.conf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/qconfig.pri \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/release.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/qt.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/moc.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/resources.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/uic.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/lex.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/include_source_dir.prf \
		GWNDiscoveryTool.pro
QMAKE_TARGET  = GWNDiscoveryTool
DESTDIR       = out/target/
TARGET        = out/target/GWNDiscoveryTool

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

$(TARGET):  $(OBJECTS)  
	@$(CHK_DIR_EXISTS) out/target/ || $(MKDIR) out/target/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: GWNDiscoveryTool.pro  /usr/local/Trolltech/Qt-4.8.4/mkspecs/linux-g++-64/qmake.conf /usr/local/Trolltech/Qt-4.8.4/mkspecs/common/unix.conf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/common/linux.conf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/common/gcc-base.conf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/common/gcc-base-unix.conf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/common/g++-base.conf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/common/g++-unix.conf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/qconfig.pri \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/release.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/qt.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/moc.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/resources.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/uic.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/lex.prf \
		/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/include_source_dir.prf \
		/usr/local/Trolltech/Qt-4.8.4/lib/libQtGui.prl \
		/usr/local/Trolltech/Qt-4.8.4/lib/libQtCore.prl \
		/usr/local/Trolltech/Qt-4.8.4/lib/libQtNetwork.prl
	$(QMAKE) -o Makefile GWNDiscoveryTool.pro
/usr/local/Trolltech/Qt-4.8.4/mkspecs/common/unix.conf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/common/linux.conf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/common/gcc-base.conf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/common/gcc-base-unix.conf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/common/g++-base.conf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/common/g++-unix.conf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/qconfig.pri:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/qt_functions.prf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/qt_config.prf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/exclusive_builds.prf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/default_pre.prf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/release.prf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/default_post.prf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/warn_on.prf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/qt.prf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/unix/thread.prf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/moc.prf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/resources.prf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/uic.prf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/yacc.prf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/lex.prf:
/usr/local/Trolltech/Qt-4.8.4/mkspecs/features/include_source_dir.prf:
/usr/local/Trolltech/Qt-4.8.4/lib/libQtGui.prl:
/usr/local/Trolltech/Qt-4.8.4/lib/libQtCore.prl:
/usr/local/Trolltech/Qt-4.8.4/lib/libQtNetwork.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile GWNDiscoveryTool.pro

dist: 
	@$(CHK_DIR_EXISTS) out/obj/GWNDiscoveryTool1.0.0 || $(MKDIR) out/obj/GWNDiscoveryTool1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) out/obj/GWNDiscoveryTool1.0.0/ && $(COPY_FILE) --parents include/DeviceItem.h include/DeviceTab.h include/GLabel.h include/GSeparator.h include/MainWidget.h include/Loading.h include/SingleApp.h include/netCardSelectDialog.h include/qMDNS.h include/Common.h out/obj/GWNDiscoveryTool1.0.0/ && $(COPY_FILE) --parents include/GLabel.cpp include/GSeparator.cpp include/SingleApp.cpp include/Loading.cpp src/DeviceItem.cpp src/DeviceTab.cpp src/main.cpp src/MainWidget.cpp src/netCardSelectDialog.cpp src/qMDNS.cpp out/obj/GWNDiscoveryTool1.0.0/ && (cd `dirname out/obj/GWNDiscoveryTool1.0.0` && $(TAR) GWNDiscoveryTool1.0.0.tar GWNDiscoveryTool1.0.0 && $(COMPRESS) GWNDiscoveryTool1.0.0.tar) && $(MOVE) `dirname out/obj/GWNDiscoveryTool1.0.0`/GWNDiscoveryTool1.0.0.tar.gz . && $(DEL_FILE) -r out/obj/GWNDiscoveryTool1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: out/moc/moc_DeviceItem.cpp out/moc/moc_DeviceTab.cpp out/moc/moc_GLabel.cpp out/moc/moc_MainWidget.cpp out/moc/moc_Loading.cpp out/moc/moc_SingleApp.cpp out/moc/moc_netCardSelectDialog.cpp out/moc/moc_qMDNS.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) out/moc/moc_DeviceItem.cpp out/moc/moc_DeviceTab.cpp out/moc/moc_GLabel.cpp out/moc/moc_MainWidget.cpp out/moc/moc_Loading.cpp out/moc/moc_SingleApp.cpp out/moc/moc_netCardSelectDialog.cpp out/moc/moc_qMDNS.cpp
out/moc/moc_DeviceItem.cpp: include/Common.h \
		include/GSeparator.h \
		include/GLabel.h \
		include/DeviceItem.h
	/usr/local/Trolltech/Qt-4.8.4/bin/moc $(DEFINES) $(INCPATH) include/DeviceItem.h -o out/moc/moc_DeviceItem.cpp

out/moc/moc_DeviceTab.cpp: include/DeviceItem.h \
		include/Common.h \
		include/GSeparator.h \
		include/GLabel.h \
		include/qMDNS.h \
		include/netCardSelectDialog.h \
		include/DeviceTab.h
	/usr/local/Trolltech/Qt-4.8.4/bin/moc $(DEFINES) $(INCPATH) include/DeviceTab.h -o out/moc/moc_DeviceTab.cpp

out/moc/moc_GLabel.cpp: include/Common.h \
		include/GLabel.h
	/usr/local/Trolltech/Qt-4.8.4/bin/moc $(DEFINES) $(INCPATH) include/GLabel.h -o out/moc/moc_GLabel.cpp

out/moc/moc_MainWidget.cpp: include/DeviceTab.h \
		include/DeviceItem.h \
		include/Common.h \
		include/GSeparator.h \
		include/GLabel.h \
		include/qMDNS.h \
		include/netCardSelectDialog.h \
		include/Loading.h \
		include/MainWidget.h
	/usr/local/Trolltech/Qt-4.8.4/bin/moc $(DEFINES) $(INCPATH) include/MainWidget.h -o out/moc/moc_MainWidget.cpp

out/moc/moc_Loading.cpp: include/Common.h \
		include/Loading.h
	/usr/local/Trolltech/Qt-4.8.4/bin/moc $(DEFINES) $(INCPATH) include/Loading.h -o out/moc/moc_Loading.cpp

out/moc/moc_SingleApp.cpp: include/Common.h \
		include/SingleApp.h
	/usr/local/Trolltech/Qt-4.8.4/bin/moc $(DEFINES) $(INCPATH) include/SingleApp.h -o out/moc/moc_SingleApp.cpp

out/moc/moc_netCardSelectDialog.cpp: include/netCardSelectDialog.h
	/usr/local/Trolltech/Qt-4.8.4/bin/moc $(DEFINES) $(INCPATH) include/netCardSelectDialog.h -o out/moc/moc_netCardSelectDialog.cpp

out/moc/moc_qMDNS.cpp: include/Common.h \
		include/netCardSelectDialog.h \
		include/qMDNS.h
	/usr/local/Trolltech/Qt-4.8.4/bin/moc $(DEFINES) $(INCPATH) include/qMDNS.h -o out/moc/moc_qMDNS.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

out/obj/GLabel.o: include/GLabel.cpp include/GLabel.h \
		include/Common.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o out/obj/GLabel.o include/GLabel.cpp

out/obj/GSeparator.o: include/GSeparator.cpp include/GSeparator.h \
		include/Common.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o out/obj/GSeparator.o include/GSeparator.cpp

out/obj/SingleApp.o: include/SingleApp.cpp include/SingleApp.h \
		include/Common.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o out/obj/SingleApp.o include/SingleApp.cpp

out/obj/Loading.o: include/Loading.cpp include/Loading.h \
		include/Common.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o out/obj/Loading.o include/Loading.cpp

out/obj/DeviceItem.o: src/DeviceItem.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o out/obj/DeviceItem.o src/DeviceItem.cpp

out/obj/DeviceTab.o: src/DeviceTab.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o out/obj/DeviceTab.o src/DeviceTab.cpp

out/obj/main.o: src/main.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o out/obj/main.o src/main.cpp

out/obj/MainWidget.o: src/MainWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o out/obj/MainWidget.o src/MainWidget.cpp

out/obj/netCardSelectDialog.o: src/netCardSelectDialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o out/obj/netCardSelectDialog.o src/netCardSelectDialog.cpp

out/obj/qMDNS.o: src/qMDNS.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o out/obj/qMDNS.o src/qMDNS.cpp

out/obj/moc_DeviceItem.o: out/moc/moc_DeviceItem.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o out/obj/moc_DeviceItem.o out/moc/moc_DeviceItem.cpp

out/obj/moc_DeviceTab.o: out/moc/moc_DeviceTab.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o out/obj/moc_DeviceTab.o out/moc/moc_DeviceTab.cpp

out/obj/moc_GLabel.o: out/moc/moc_GLabel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o out/obj/moc_GLabel.o out/moc/moc_GLabel.cpp

out/obj/moc_MainWidget.o: out/moc/moc_MainWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o out/obj/moc_MainWidget.o out/moc/moc_MainWidget.cpp

out/obj/moc_Loading.o: out/moc/moc_Loading.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o out/obj/moc_Loading.o out/moc/moc_Loading.cpp

out/obj/moc_SingleApp.o: out/moc/moc_SingleApp.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o out/obj/moc_SingleApp.o out/moc/moc_SingleApp.cpp

out/obj/moc_netCardSelectDialog.o: out/moc/moc_netCardSelectDialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o out/obj/moc_netCardSelectDialog.o out/moc/moc_netCardSelectDialog.cpp

out/obj/moc_qMDNS.o: out/moc/moc_qMDNS.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o out/obj/moc_qMDNS.o out/moc/moc_qMDNS.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

