##############################################################################
#
#	Copyright:		© 3S - Smart Software Solutions GmbH, Kempten
#	Module: 		generic makefile for building of runtime cmps
#	Description:
#				Follow the steps below to build your component
#
# 	Required tools:
#				make
#				cross-toolchain (compiler/linker)
# 				gnu m4  (-> apt-get install m4)
# 				fromdos (-> apt-get install tofrodos)
#
##############################################################################


# 1. set name of component
TARGET=$(strip $(shell basename $(realpath ../)))
#TARGET= CmpTemplate

# 2. set name of shared object
SONAME= lib${TARGET}.so

# 2. set version of component (so version)
MAJORVER?=0
MINORVER?=1

# 3. set sources of component
# from m4:
SRC = $(foreach f,$(shell sed -n '/SOURCES/ {s/COMPONENT_SOURCES(`//g; s/[,`)]/ /g; s/\([[:alnum:]]*\.c\)./\1/g;  p}' ../*Dep.m4), ../$f)
# or
#SRC = ../${TARGET}.c

# objects:
OBJ = $(SRC:.c=.o)

# 4. set runtime sdk path (e.g. relative)
CDSDIR=../../../
BUILDUTILS= ${CDSDIR}/BuildUtils

# 5. set Dependency and Interface headers
DEP = ../${TARGET}Dep

# 
ITF = ../${TARGET}Itf

# 6. set default includes for the runtime
CFLAGS +=  -I../ -I${CDSDIR}/Components -I${CDSDIR}/Platforms/Linux

# 7. set runtime cpu type: TRG_X86 | TRG_PPC | TRG_ARM | TRG_CORTEX | TRG_SH | TRG_MIPS
CFLAGS += -DTRG_CORTEX
# 64bit X86/ARM -> also set TRG_64BIT
#CFLAGS += -DTRG_64BIT

# 8. set compiler
#CC=arm-poky-linux-gnueabi-gcc

# 9. additional includes
CFLAGS += -DLINUX -DCDECL= -DDLL_DECL= -DHUGEPTR= 
CFLAGS += -g -O0 -Wall -Wextra -Wno-unused

# 10. additional libraries
#LDFLAGS+=


vpath+=${CDSDIR}/Components/
#
# RULES
#

all: checkpaths $(SONAME) 


.PHONY=checkpaths
checkpaths:
	@echo "**********************"
	@echo "Target: ${TARGET}"
	@echo "Soname: ${SONAME}"
	@echo "Src:    ${SRC}"
	@echo "Obj:    ${OBJ}"
	@echo "Dep:    ${DEP}"
	@echo "Itf:    ${ITF}"
	@echo "**********************"
	@echo ""


all: $(SONAME) checkpaths

%.o: %.c
	@echo "**********************"
	@echo "compile: $@ from $<"
	$(CC) -fPIC -c $(CFLAGS) -o $@  $<
	@echo "**********************"
	@echo ""

${SONAME}: $(DEP).h $(ITF).h $(OBJ)
	@echo "**********************"
	@echo "link: $@"
	$(CC) -shared $(OBJ) -Wl,-soname,$(SONAME) -o $(SONAME) $(LDFLAGS)
	@echo "**********************"
	@echo ""

$(DEP).h: $(DEP).m4 $(ITF).m4
	@echo "**********************"
	@echo "build: $@ from $<"
	rm -f $(OBJ)
	fromdos $(DEP).m4
	m4 -I$(BUILDUTILS)/M4Defs -I$(CDSDIR)/Components -I../ Implementation.m4 - < $(DEP).m4 > $(DEP).h
	@echo "**********************"
	@echo ""

$(ITF).h: $(ITF).m4
	@echo "**********************"
	@echo "build: $@ from $<"
	rm -f $(OBJ)
	fromdos $(ITF).m4
	m4 -I$(BUILDUTILS)/M4Defs Exports.m4 - < $(ITF).m4 > $(ITF).h
	@echo "**********************"
	@echo ""

clean:
	@echo ""
	@echo "**********************"
	@echo "clean up"
	rm -f $(OBJ);
	rm -f $(SONAME);
	rm -f $(ITF).h;
	rm -f $(DEP).h;
	@echo "**********************"
	@echo ""

