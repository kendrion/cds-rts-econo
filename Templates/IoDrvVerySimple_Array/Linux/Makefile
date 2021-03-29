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
ifeq ("$(wildcard ../*Itf.m4)", "")
ITF_M4=""
ITF_H=""
else
ITF_M4 = $(wildcard ../*Itf.m4)
ITF_H = $(patsubst %Itf.m4, %Itf.h, ${ITF_M4})
endif


# 6. set default includes for the runtime
CFLAGS +=  -I../ -I${CDSDIR}/Components -I${CDSDIR}/Platforms/Linux

# 7. set runtime cpu type: TRG_X86 | TRG_PPC | TRG_ARM | TRG_CORTEX | TRG_SH | TRG_MIPS
CFLAGS += -DTRG_X86
# 64bit X86/ARM -> also set TRG_64BIT
#CFLAGS += -DTRG_64BIT

# 8. set compiler
CC = gcc

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
	@echo "Itf:    ${ITF_M4}"
	@echo "**********************"
	@echo ""

all: $(SONAME) checkpaths

%.o: %.c
	@echo "**********************"
	@echo "compile: $@ from $<"
	$(CC) -fPIC -c $(CFLAGS) -o $@  $<
	@echo "**********************"
	@echo ""

${SONAME}: $(DEP).h $(OBJ)
	@echo "**********************"
	@echo "link: $@"
	$(CC) -g -shared $(OBJ) -Wl,-soname,$(SONAME) -o $(SONAME) $(LDFLAGS)
	@echo "**********************"
	@echo ""

$(DEP).h: $(DEP).m4
	@echo "**********************"
	@echo "build: $@ from $<"
	rm -f $(OBJ)
	fromdos $(DEP).m4
	m4 -I$(BUILDUTILS)/M4Defs -I$(CDSDIR)/Components -I../ Implementation.m4 - < $(DEP).m4 > $(DEP).h
	@echo "**********************"
	@echo ""



.PHONY:createcmp
createcmp:
	@echo "**********************"
	@echo "create new component: "
	@read -p "Enter name for component and press enter: " CMPNAME; \
	read -p "Enter Vendor ID for component and press enter:  e.g. 0x0001  " CMPVENDORID; \
	read -p "Enter Component ID for component and press enter:  e.g. 0x2000  " CMPID; \
	cp -r ../ ../../$$CMPNAME && \
	cd ../../$$CMPNAME && \
	rm *.bat *.cpp *Dep.h *Itf.h && \
	mv ${TARGET}.c $$CMPNAME.c && \
	mv ${TARGET}Dep.m4 $${CMPNAME}Dep.m4 && \
	mv ${TARGET}Itf.m4 $${CMPNAME}Itf.m4 && \
	sed -i "s/${TARGET}/$$CMPNAME/g" $${CMPNAME}Itf.m4 && \
	sed -i "s/${TARGET}/$$CMPNAME/g" $${CMPNAME}Dep.m4 && \
	sed -i "s/${TARGET}/$$CMPNAME/g" $${CMPNAME}Dep.m4 && \
	sed -i "/COMPONENT_VENDORID/ s/\(COMPONENT_VENDORID.*\)0x[0-9a-fA-F]*\(.*\)/\1$${CMPVENDORID}\2/g" $${CMPNAME}Dep.m4 && \
	sed -i "/CMPID_/ s/^#define CMPID_.*/#define CMPID_$${CMPNAME} $${CMPID}/g" $${CMPNAME}Dep.m4 && \
	sed -i "/CLASSID_/ s/^#define CLASSID_.*/#define CLASSID_C$${CMPNAME} ADDVENDORID(CMP_VENDORID, $${CMPID})/g" $${CMPNAME}Dep.m4 && \
	sed -i "/ITFID_/ s/^#define ITFID_.*/#define ITFID_I$${CMPNAME} ADDVENDORID(CMP_VENDORID, $${CMPID})/g" $${CMPNAME}Dep.m4 && \
	echo "Component $$CMPNAME created successfully here: ../../$${CMPNAME}" && \
	echo "Renaming done. Please set your IDs in Dep.m4"
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

.PHONY:help
help:
	@echo ""
	@echo "**********************"
	@echo "possible targets"
	@echo "all          - component as shared object lib<CmpName>.so"
	@echo "checkpaths   - check and output all paths configured"
	@echo "createcmp    - create (copy and rename) a new component based on this one"
	@echo "clean        - clean up"
	@echo "**********************"
	@echo ""


