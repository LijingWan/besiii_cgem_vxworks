# Makefile generated by the project manager
#


## core information

PRJ_FILE       = Hello.wpj
PRJ_DIR        = C:/Tornado/target/proj/Hello
PRJ_TYPE       = vxApp
PRJ_OBJS       = Hello.o
BUILD_SPEC     = PPCEC603gnu
TGT_DIR        = $(WIND_BASE)/target




## build-configuration info

ifeq ($(BUILD_SPEC),PPCEC603gnu)
CPU              = PPCEC603
TOOL             = gnu
DEFAULT_RULE     = Hello.out
endif

include $(TGT_DIR)/h/make/defs.project

## build-configuration info

ifeq ($(BUILD_SPEC),PPCEC603gnu)
AR               = arppc
AS               = ccppc
CC               = ccppc
CFLAGS           = -g -mstrict-align -ansi -nostdinc -DRW_MULTI_THREAD -D_REENTRANT -fvolatile -fno-builtin -fno-for-scope -msoft-float -I. -IC:/Tornado/target/h -DCPU=PPCEC603
CFLAGS_AS        = -g -mstrict-align -ansi -nostdinc -fvolatile -fno-builtin -fno-for-scope -P -x assembler-with-cpp -I. -IC:/Tornado/target/h -DCPU=PPCEC603
CPP              = ccppc -E -P -xc
LD               = ldppc
LDFLAGS          = -X -N
LD_PARTIAL_FLAGS = -X -r
NM               = nmppc
OPTION_DEFINE_MACRO = -D
OPTION_INCLUDE_DIR = -I
SIZE             = sizeppc
POST_BUILD_RULE  = 
PRJ_LIBS         = 
endif

# override make definitions only below this line


# override make definitions only above this line
include $(TGT_DIR)/h/make/rules.project



## build-configuration info

ifeq ($(BUILD_SPEC),PPCEC603gnu)
Hello.o:
	$(CC) -g -mstrict-align -ansi -nostdinc -DRW_MULTI_THREAD -D_REENTRANT -fvolatile -fno-builtin -fno-for-scope -msoft-float -I. -I$(WIND_BASE)/target/h -DCPU=PPCEC603 -c $(PRJ_DIR)/Hello.c
endif


## dependencies

Hello.o: $(PRJ_DIR)/Hello.c


## user defined rules

