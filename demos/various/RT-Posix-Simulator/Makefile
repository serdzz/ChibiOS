<<<<<<< HEAD
#
#       !!!! Do NOT edit this makefile with an editor which replace tabs by spaces !!!!
#
##############################################################################################
#
# On command line:
#
# make all = Create project
#
# make clean = Clean project files.
#
# To rebuild project do "make clean" and "make all".
#

##############################################################################################
# Start of default section
#

TRGT = 
CC   = $(TRGT)gcc
AS   = $(TRGT)gcc -x assembler-with-cpp

# List all default C defines here, like -D_DEBUG=1
DDEFS = -DSIMULATOR

# List all default ASM defines here, like -D_DEBUG=1
DADEFS =

# List all default directories to look for include files here
DINCDIR =

# List the default directory to look for the libraries here
DLIBDIR =

# List all default libraries here
DLIBS = 

#
# End of default section
##############################################################################################

##############################################################################################
# Start of user section
#

# Define project name here
PROJECT = ch

# Define linker script file here
LDSCRIPT =

# List all user C define here, like -D_DEBUG=1
UDEFS =
=======
##############################################################################
# Build global options
# NOTE: Can be overridden externally.
#

# Compiler options here.
ifeq ($(USE_OPT),)
  USE_OPT = -O2 -ggdb -m32
endif

# C specific options here (added to USE_OPT).
ifeq ($(USE_COPT),)
  USE_COPT = 
endif

# C++ specific options here (added to USE_OPT).
ifeq ($(USE_CPPOPT),)
  USE_CPPOPT = -fno-rtti
endif

# Enable this if you want the linker to remove unused code and data.
ifeq ($(USE_LINK_GC),)
  USE_LINK_GC = yes
endif

# Linker extra options here.
ifeq ($(USE_LDOPT),)
  USE_LDOPT = 
endif

# Enable this if you want link time optimizations (LTO).
ifeq ($(USE_LTO),)
  USE_LTO = no
endif

# Enable this if you want to see the full log while compiling.
ifeq ($(USE_VERBOSE_COMPILE),)
  USE_VERBOSE_COMPILE = no
endif

# If enabled, this option makes the build process faster by not compiling
# modules not used in the current configuration.
ifeq ($(USE_SMART_BUILD),)
  USE_SMART_BUILD = yes
endif

#
# Build global options
##############################################################################

##############################################################################
# Architecture or project specific options
#

#
# Architecture or project specific options
##############################################################################

##############################################################################
# Project, sources and paths
#

# Define project name here
PROJECT = ch

# Imported source files and paths
CHIBIOS = ../../..
CONFDIR  := ./cfg
BUILDDIR := ./build
DEPDIR   := ./.dep

# Licensing files.
include $(CHIBIOS)/os/license/license.mk
# Startup files.
# HAL-OSAL files (optional).
include $(CHIBIOS)/os/hal/hal.mk
include $(CHIBIOS)/os/hal/boards/simulator/board.mk
include $(CHIBIOS)/os/hal/ports/simulator/posix/platform.mk
include $(CHIBIOS)/os/hal/osal/rt/osal.mk
# RTOS files (optional).
include $(CHIBIOS)/os/rt/rt.mk
include $(CHIBIOS)/os/common/ports/SIMIA32/compilers/GCC/port.mk
# Other files (optional).
include $(CHIBIOS)/test/lib/test.mk
include $(CHIBIOS)/test/rt/rt_test.mk
include $(CHIBIOS)/test/oslib/oslib_test.mk
include $(CHIBIOS)/os/hal/lib/streams/streams.mk
include $(CHIBIOS)/os/various/shell/shell.mk

# C sources here.
CSRC = $(ALLCSRC) \
       $(TESTSRC) \
       main.c

# C++ sources here.
CPPSRC = $(ALLCPPSRC)

# List ASM source files here.
ASMSRC = $(ALLASMSRC)
ASMXSRC = $(ALLXASMSRC)

INCDIR = $(CONFDIR) $(ALLINC) $(TESTINC)

#
# Project, sources and paths
##############################################################################

##############################################################################
# Start of user section
#

# List all user C define here, like -D_DEBUG=1
UDEFS = -DSIMULATOR
>>>>>>> upstream/master

# Define ASM defines here
UADEFS =

<<<<<<< HEAD
# Imported source files
CHIBIOS = ../../..
include $(CHIBIOS)/os/hal/boards/simulator/board.mk
include $(CHIBIOS)/os/hal/hal.mk
include $(CHIBIOS)/os/hal/ports/simulator/posix/platform.mk
include $(CHIBIOS)/os/hal/osal/rt/osal.mk
include $(CHIBIOS)/os/rt/ports/SIMIA32/compilers/GCC/port.mk
include $(CHIBIOS)/os/rt/rt.mk
include $(CHIBIOS)/test/rt/test.mk

# List C source files here
SRC =  $(PORTSRC) \
       $(KERNSRC) \
       $(TESTSRC) \
       $(HALSRC) \
       $(OSALSRC) \
       $(PLATFORMSRC) \
       $(BOARDSRC) \
       $(CHIBIOS)/os/various/shell.c \
       $(CHIBIOS)/os/hal/lib/streams/memstreams.c \
       $(CHIBIOS)/os/hal/lib/streams/chprintf.c \
       main.c

# List ASM source files here
ASRC =

# List all user directories here
UINCDIR = $(PORTINC) $(KERNINC) $(TESTINC) \
          $(HALINC) $(OSALINC) $(PLATFORMINC) $(BOARDINC) \
          $(CHIBIOS)/os/hal/lib/streams $(CHIBIOS)/os/various
=======
# List all user directories here
UINCDIR =
>>>>>>> upstream/master

# List the user directory to look for the libraries here
ULIBDIR =

# List all user libraries here
ULIBS =

<<<<<<< HEAD
# Define optimisation level here
OPT = -ggdb -O2

#
# End of user defines
##############################################################################################

INCDIR  = $(patsubst %,-I%,$(DINCDIR) $(UINCDIR))
LIBDIR  = $(patsubst %,-L%,$(DLIBDIR) $(ULIBDIR))
DEFS    = $(DDEFS) $(UDEFS)
ADEFS   = $(DADEFS) $(UADEFS)
OBJS    = $(ASRC:.s=.o) $(SRC:.c=.o)
LIBS    = $(DLIBS) $(ULIBS)

LDFLAGS = -m32 -Wl,-Map=$(PROJECT).map,--cref,--no-warn-mismatch $(LIBDIR)
ASFLAGS = -m32 -Wa,-amhls=$(<:.s=.lst) $(ADEFS)
CPFLAGS = -m32 -Wall -Wextra -Wundef -Wstrict-prototypes -fverbose-asm -Wa,-alms=$(<:.c=.lst) $(DEFS)

# Generate dependency information
CPFLAGS += -MD -MP -MF .dep/$(@F).d

#
# makefile rules
#

all: $(OBJS) $(PROJECT).exe

%.o : %.c
	$(CC) -c $(OPT) $(CPFLAGS) -I . $(INCDIR) $< -o $@

%.o : %.s
	$(AS) -c $(OPT) $(ASFLAGS) $< -o $@

%exe: $(OBJS)
	$(CC) $(OPT) $(OBJS) $(LDFLAGS) $(LIBS) -o $@

gcov:
	-mkdir gcov
	$(COV) -u $(subst /,\,$(SRC))
	-mv *.gcov ./gcov

clean:
	-rm -f $(OBJS)
	-rm -f $(PROJECT).exe
	-rm -f $(PROJECT).map
	-rm -f $(SRC:.c=.c.bak)
	-rm -f $(SRC:.c=.lst)
	-rm -f $(ASRC:.s=.s.bak)
	-rm -f $(ASRC:.s=.lst)
	-rm -fR .dep

#
# Include the dependency files, should be the last of the makefile
#
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)

# *** EOF ***
=======
#
# End of user defines
##############################################################################

##############################################################################
# Compiler settings
#

TRGT = 
CC   = $(TRGT)gcc
CPPC = $(TRGT)g++
# Enable loading with g++ only if you need C++ runtime support.
# NOTE: You can use C++ even without C++ support if you are careful. C++
#       runtime support makes code size explode.
LD   = $(TRGT)gcc
#LD   = $(TRGT)g++
CP   = $(TRGT)objcopy
AS   = $(TRGT)gcc -x assembler-with-cpp
AR   = $(TRGT)ar
OD   = $(TRGT)objdump
SZ   = $(TRGT)size
HEX  = $(CP) -O ihex
BIN  = $(CP) -O binary
COV  = gcov

# Define C warning options here
CWARN = -Wall -Wextra -Wundef -Wstrict-prototypes

# Define C++ warning options here
CPPWARN = -Wall -Wextra -Wundef

#
# Compiler settings
##############################################################################

RULESPATH = $(CHIBIOS)/os/common/startup/SIMIA32/compilers/GCC
include $(RULESPATH)/rules.mk
>>>>>>> upstream/master
