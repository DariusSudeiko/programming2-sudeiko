# This is an example of a Makefile that can be used in lab works
###############################################################################
# Options
###############################################################################
# You can use either gcc or clang
# CC = gcc
CC = clang
# CFLAGS
# Set a C standard version: -std=gnu17
# Add debug info: -O0 -g
# clang-specific debug options: -fno-limit-debug-info -fno-standalone-debug
# Include subdir: -I /src
# ASM
# Set options to generate asm output: -S compiler-specific-options
# Get the environment values
CFLAGS := ${CFLAGS}
# Add math lib for linker
LDFLAGS  := -lm
# Set compilier-specific options
C_STD = gnu17
# Create a destination folders
SOURCE_DIR = src
BIN_DIR = bin
ASM_DIR = asm
TARGET = myapp
# Source files
SRCS=$(wildcard $(SOURCE_DIR)/*.c)
OBJS=$(SRCS:.c=.o)
# Compilier options
ifeq ($(CC), gcc)
CFLAGS += -std=$(C_STD) -O0 -g -I $(SOURCE_DIR)
ASM = -S -masm=intel
else
CFLAGS += -std=$(C_STD) -O0 -g -I $(SOURCE_DIR) -fno-limit-debug-info -fno-standalone-debug
ASM = -S -mllvm --x86-asm-syntax=intel
endif
# Enables all the warnings and break compilation in case any warning
WARN = -Wall -Wextra -Wpedantic -Werror
# Check tools parameters, for clang-tydy '-' means 'disable'
CLANGTIDYFLAGS :="-*,\
clang-analyzer-*,cert-*,readability-*,\
-readability-uppercase-literal-suffix,\
-readability-magic-numbers,\
-clang-analyzer-deadcode.DeadStores,\
-clang-analyzer-security.insecureAPI.rand"
CPPCHECKFLAGS := --enable=style,warning,missingInclude
###############################################################################
# Targets
###############################################################################
# Perform all steps to compile and run debugger
all: clean build asm debug

# Clean a destination folder (remove all files)
clean:
	rm -rf $(BIN_DIR) $(ASM_DIR)
	rm -f $(SOURCE_DIR)/*.o

# Compile binary, it depends on the main.bin target
build: myapp

# make ./bin dir and compile files
myapp: $(OBJS)
	$(shell mkdir -p $(BIN_DIR))
	$(CC) -o $(BIN_DIR)/$@ $^ $(CFLAGS) $(LDFLAGS)

# run binary, it depends on 3 targets - clean, prep and compile
run: clean build
	$(BIN_DIR)/$(TARGET)

# build app and call debugger
debug: clean build
	lldb $(BIN_DIR)/$(TARGET)

# make the ./asm dir and generate assembler code
asm: $(SRCS)
	$(shell mkdir -p $(ASM_DIR))
	$(CC) $(ASM) $< -o $(ASM_DIR)/$(TARGET).asm

###############################################################################
# Static analysis
###############################################################################

check:
	clang-format --verbose -dry-run --Werror $(wildcard $(SOURCE_DIR)/*.c)
	clang-tidy $(SOURCE_DIR)/*.c --header-filter=.* --checks=$(CLANGTIDYFLAGS) -- -std=$(C_STD)
	rm -rf $(SOURCE_DIR)/*.dump

cppcheck:
	cppcheck $(CPPCHECKFLAGS) $(SOURCE_DIR)/*.c
