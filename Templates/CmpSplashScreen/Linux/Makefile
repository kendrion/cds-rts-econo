TARGET = CmpSplashScreen

INCLUDE = -I../ -I../../../Components -I../../../Platforms/Linux
INCLUDE += -I/opt/qt5/include -I/opt/qt5/include/QtCore -I/opt/qt5/include/QtWidgets
BUILDUTILS = ../../../BuildUtils

CXX = g++
MOC = moc
CXXFLAGS = -DTRG_X86

DEBFLAGS = -g
LDLIBS = -lpthread
CXXFLAGS += -DALIGNATTRIB= -DCDECL= -DHANDLE_WIN32_PRAGMA -DDLL_DECL= -D_REENTRANT= -DHUGEPTR=
CXXFLAGS += -O0 -Wall -Wno-unused
CXXFLAGS += $(INCLUDE)
CXXFLAGS += -DLINUX
CXXFLAGS += $(DEBFLAGS)
CXXFLAGS += -fPIC
CXXFLAGS += -std=c++11
CXXFLAGS += -Wno-write-strings
LDFLAGS += $(LDLIBS)

MAJORVER = 0
MINORVER = 1
SONAME = lib$(TARGET).so

SRC =  ../$(TARGET).cpp
OBJ = $(TARGET).o $(TARGET)_moc.o

all: $(SONAME)

$(SONAME): ../$(TARGET)Dep.h ../$(TARGET)Itf.h $(OBJ)
	$(CXX) -shared $(CXXFLAGS) $(LDFLAGS) $(OBJ) -lc -Wl,-soname,$(SONAME) -o $(SONAME)

%_moc.cpp: ../%_qt.h
	$(MOC) $< -o $@

%.o : ../%.c
	$(CC) -fPIC -c $(CXXFLAGS) -o $*.o $<

%.o : ../%.cpp
	$(CXX) -fPIC -c $(CXXFLAGS) -o $*.o $<

$(TARGET).o: $(OBJ)

../$(TARGET)Dep.h: ../$(TARGET)Dep.m4 ../$(TARGET)Itf.m4
	rm -f $(OBJ)
	fromdos ../$(TARGET)Dep.m4
	m4 -I$(BUILDUTILS)/M4Defs -I../../../Components -I../ Implementation.m4 - < ../$(TARGET)Dep.m4 > ../$(TARGET)Dep.h

../$(TARGET)Itf.h: ../$(TARGET)Itf.m4
	rm -f $(OBJ)
	fromdos ../$(TARGET)Itf.m4
	m4 -I$(BUILDUTILS)/M4Defs Exports.m4 - < ../$(TARGET)Itf.m4 > ../$(TARGET)Itf.h

clean:
	rm -f $(OBJ) *~ core .depend $(SONAME)

cleanall: clean
	rm -f ../$(TARGET)Dep.h ../$(TARGET)Itf.h

.depend:
	$(CXX) $(CXXFLAGS) -M $(SRC) > $@

ifeq (.depend,$(wildcard .depend))
include .depend
endif
