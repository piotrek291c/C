#
# A simple makefile for compiling a c++ project
#
SRC=./source
OUTPUT_DIR = source/build
TARGET  = $(OUTPUT_DIR)/main


GCC = gcc
OBJCOPY=objcopy
OBJDUMP=objdump
SIZE=size
NM=nm

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

# ----------------------------------------------------------------------------------------
# ----------------------------------------------------------------------------------------
# Define Messages
# English
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

# ----------------------------------------------------------------------------------------

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

# ----------------------------------------------------------------------------------------
# ----------------------------------------------------------------------------------------
# #  -g*:          generate debugging information
# #  -O*:          optimization level
# #  -f...:        tuning, see GCC manual and avr-libc documentation
# #  -Wall...:     warning level
# #  -Wa,...:      tell GCC to pass this to the assembler.
# #    -adhlns...: create assembler listing
# #
# # Flags for C and C++ (arm-elf-gcc/arm-elf-g++)
CFLAGS = -g
CFLAGS += -O$(OPT)
CFLAGS += -Wall
CFLAGS += -MMD -MP

# ----------------------------------------------------------------------------------------
# ----------------------------------------------------------------------------------------
INCLUDE =	-I./source \
			-I./source/header \
			-I./source/task

SOURCE = 	$(SRC)/main.c
# 	./src/syscalls.c \

DEP = $(patsubst %.c, %.d, $(SOURCE))

# ----------------------------------------------------------------------------------------
# ----------------------------------------------------------------------------------------
# Define all object files.
COBJ      = $(SOURCE:.c=.o)


all: begin gccversion build finished end
	@$(ECHO) ------------------------------
	@$(ECHO) 	Used memory:
	@$(SIZE) -B  $(TARGET).exe
	@$(ECHO) ------------------------------

build: $(TARGET).exe

clean:
	@echo
	@echo ----------------------------------------
	@echo $(MSG_CLEANING)

	$(RM) $(TARGET).exe;
	$(RM) $(SOURCE:.c=.o);
	$(RM) $(SOURCE:.c=.d);

	@echo $(QUOTE)Clean done!!! $(QUOTE)
	@echo ----------------------------------------

begin:
	@echo --
	@echo $(MSG_BEGIN)

finished:
	@echo $(MSG_ERRORS_NONE)

end:
	@echo $(MSG_END)
	@echo

# Display compiler version information.
gccversion:
	@$(GCC) --version



main.c:
	@$(GCC) source/main.c -o source/build/main

$(TARGET).exe: $(COBJ)
	@echo
	@echo $(MSG_LINKING) $@
	@$(GCC) $(CFLAGS) -Wl,-o$(TARGET).exe,$(COBJ)

# ----------------------------------------------------------------------------------------
# ----------------------------------------------------------------------------------------
# Compile: create object files from C source files. ARM/Thumb
$(COBJ) : %.o : %.c
	@echo
	@echo $(MSG_COMPILING) $<
	@$(GCC) -c $(INCLUDE) $(CFLAGS) $(CONLYFLAGS) $< -o $*.o

# ----------------------------------------------------------------------------------------
# ----------------------------------------------------------------------------------------
# Include the dependency files.
# -include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)
-include $(DEP)


# Listing of phony targets.
.PHONY : all build clean begin finish end gccversion
# ----------------------------------------------------------------------------------------