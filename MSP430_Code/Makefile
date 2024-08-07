# Directories
MSPGCC_ROOT_DIR = ${TOOLS_PATH}
MSPGCC_BIN_DIR = $(MSPGCC_ROOT_DIR)/bin
MSPGCC_INCLUDE_DIR = $(MSPGCC_ROOT_DIR)/include
LIB_DIRS = $(MSPGCC_INCLUDE_DIR)
OBJ_DIR = obj
BIN_DIR = bin
SOURCE_DIR = src
SOURCE_DRIVERS_DIR = $(SOURCE_DIR)/drivers
HEADERS_DIR = include
HEADERS_DRIVERS_DIR = $(HEADERS_DIR)/drivers
INCLUDE_DIRS = $(MSPGCC_INCLUDE_DIR) $(HEADERS_DRIVERS_DIR) $(HEADERS_DIR)

# Define directories and tools
TI_CSS_DIR = /home/vietduc/ti/ccs1271/ccs/ccs_base/DebugServer
DEBUG_BIN_DIR = $(TI_CSS_DIR)/bin
DEBUG_DRIVERS_DIR = $(TI_CSS_DIR)/drivers
DEBUG = LD_LIBRARY_PATH=$(DEBUG_DRIVERS_DIR) $(DEBUG_BIN_DIR)/mspdebug

# Toolchain
CC = $(MSPGCC_BIN_DIR)/msp430-elf-gcc
GDB = $(MSPGCC_BIN_DIR)/msp430-elf-gdb
SIZE = $(MSPGCC_BIN_DIR)/msp430-elf-size

# Target
TARGET = $(BIN_DIR)/blink

# Source files
SRCS = $(SOURCE_DIR)/main.c \
	$(SOURCE_DRIVERS_DIR)/gpio.c \
	$(SOURCE_DRIVERS_DIR)/clock_init.c \
	$(SOURCE_DRIVERS_DIR)/lcd.c

# Object files
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

# Flags
MCU = msp430fr6989
WFLAGS = -Wall -Wextra -Werror -Wshadow
CFLAGS = -mmcu=$(MCU) $(WFLAGS) $(addprefix -I,$(INCLUDE_DIRS)) -Og -g
LDFLAGS = -mmcu=$(MCU) $(addprefix -L,$(LIB_DIRS)) 

# Build
## Linking
$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $^ -o $@

## Compiling
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $^ -o $@

## Debug
debug: $(TARGET)
	$(GDB) $(TARGET)

## Size
size: $(TARGET)
	$(SIZE) $(TARGET)

## Flash
flash: $(TARGET)
	$(DEBUG) tilib "prog $(TARGET)"

# Phony
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)