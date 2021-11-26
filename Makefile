#
# A simple makefile for compiling a c++ project
#
# http://www.gnu.org/software/make/manual/make.html

##########################################################################################
# Paths SECTION
##########################################################################################
SRC=./source
OUTPUT_DIR = source/build

##########################################################################################
# Target SECTION
##########################################################################################
TARGET  = $(OUTPUT_DIR)/main

##########################################################################################
# GCC compiler program SECTION
##########################################################################################
GCC = gcc
OBJCOPY=objcopy
OBJDUMP=objdump
SIZE=size
NM=nm

##########################################################################################
# Programs and shortcuts SECTION
##########################################################################################
ARGS = 101
RM = rm -rf
COPY = cp
ECHO = echo
SED = sed
CRC = srec_cat
MKDIR = mkdir -p
NULL = /dev/null
PD = /
QUOTE = '

##########################################################################################
# Define Messages SECTION
##########################################################################################
MSG_ERRORS_NONE = Errors: none
MSG_BEGIN = "-------- begin --------"
MSG_END = --------  end  --------
MSG_SIZE_BEFORE = Size before:
MSG_SIZE_AFTER = Size after:
MSG_FLASH = Creating load file for Flash:
MSG_EXTENDED_LISTING = Creating Extended Listing:
MSG_SYMBOL_TABLE = Creating Symbol Table:
MSG_LINKING = Linking:
MSG_COMPILING = Compiling C:
MSG_COMPILING_ARM = "Compiling C (ARM-only):"
MSG_COMPILINGCPP = Compiling C++:
MSG_COMPILINGCPP_ARM = "Compiling C++ (ARM-only):"
MSG_ASSEMBLING = Assembling:
MSG_ASSEMBLING_ARM = "Assembling (ARM-only):"
MSG_CLEANING = Cleaning project:
MSG_FORMATERROR = Can not handle output-format
MSG_LPC21_RESETREMINDER = You may have to bring the target in bootloader-mode now.

##########################################################################################
# Building variables SECTION
##########################################################################################
# Optimization level, can be [0, 1, 2, 3, s].
# 0 = turn off optimization. s = optimize for size.
# (Note: 3 is not always the best optimization level. See avr-libc FAQ.)
OPT = 0

# Compiler flag to set the C Standard level.
# c89   - "ANSI" C
# gnu89 - c89 plus GCC extensions
# c99   - ISO C99 standard (not yet fully implemented)
# gnu99 - c99 plus GCC extensions
CSTANDARD = -std=c++11

# Debug build
DEBUG = 1

##########################################################################################
# CFLAGS SECTION
##########################################################################################
# #  -g*:          generate debugging information
# #  -O*:          optimization level
# #  -f...:        tuning, see GCC manual and avr-libc documentation
# #  -Wall...:     warning level
# #  -Wa,...:      tell GCC to pass this to the assembler.
# #    -adhlns...: create assembler listing
# #
# # Flags for C and C++ (arm-elf-gcc/arm-elf-g++)

CFLAGS = -O$(OPT)
CFLAGS += -Wall
CFLAGS += -MMD -MP

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif

##########################################################################################
# Source SECTION
# TODO: Add all file to path
##########################################################################################
INCLUDE =	-I./source \
			-I./source/header \
			-I./source/task

SOURCES = 	$(SRC)/main.c  \
	    	$(SRC)/task/chapter1.c \
			$(SRC)/task/chapter2.c \
			$(SRC)/task/chapter3.c \
			$(SRC)/task/chapter4.c \
			$(SRC)/task/chapter5.c \
			$(SRC)/task/chapter6.c \
            $(SRC)/task/chapter7.c

DEP = $(patsubst %.c, %.d, $(SOURCES))

##########################################################################################
# Define all object files. SECTION
##########################################################################################
COBJ      = $(SOURCES:.c=.o)


all: begin gccversion build finished end
	@$(ECHO) ------------------------------
	@$(ECHO) 	Used memory:
	@$(SIZE) -B  $(TARGET).exe
	@$(ECHO) ------------------------------

build: $(TARGET).exe

##########################################################################################
# Clean SECTION
##########################################################################################
clean:
	@echo
	@echo ----------------------------------------
	@echo $(MSG_CLEANING)
# $(RM) $(TARGET).exe;
# $(RM) $(SOURCES:.c=.o);
# $(RM) $(SOURCES:.c=.d);
	-find . -name '*.o'     -exec $(RM) {} \;
	-find . -name '*.d'     -exec $(RM) {} \;
	-find . -name '*.exe'   -exec $(RM) {} \;
	@echo $(QUOTE)Clean done!!! $(QUOTE)
	@echo ----------------------------------------

begin:
	@echo
	@echo $(MSG_BEGIN)

finished:
	@echo $(MSG_ERRORS_NONE)

end:
	@echo $(MSG_END)
	@echo

##########################################################################################
# Display compiler version information. SECTION
##########################################################################################
gccversion:
	@$(GCC) --version

##########################################################################################
# List of objects SECTION
##########################################################################################
$(TARGET).exe: $(COBJ)
	@echo
	@echo ----------------------------------------
	@echo $(MSG_LINKING) $@
	@$(GCC) $(CFLAGS) -Wl,-o$(TARGET).exe,$(COBJ)

##########################################################################################
# Compile: create object files from C source files. ARM/Thumb SECTION
##########################################################################################
$(COBJ) : %.o : %.c
	@echo
	@echo ----------------------------------------
	@echo $(MSG_COMPILING) $<
	@$(GCC) -c $(INCLUDE) $(CFLAGS) $(CONLYFLAGS) $< -o $*.o

##########################################################################################
# Include the dependency files. SECTION
##########################################################################################
# -include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)
-include $(DEP)

##########################################################################################
# Listing of phony targets. SECTION
##########################################################################################
.PHONY : all build clean begin finish end gccversion
# ----------------------------------------------------------------------------------------
