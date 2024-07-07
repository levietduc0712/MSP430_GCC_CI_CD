TOOLS_DIR = ${TOOLS_PATH}
BIN_DIR = ${TOOLS_PATH}/bin
INCLUDE_DIR = ${TOOLS_PATH}/include
CC = $(BIN_DIR)/msp430-elf-gcc
CFLAGS = -I$(INCLUDE_DIR) -mmcu=msp430g2553 -O2
LDFLAGS = -mmcu=msp430g2553 -L$(INCLUDE_DIR) -Tmsp430g2553.ld -Tmsp430g2553_symbols.ld

SRC_DIR = src
OBJ_DIR = obj
OUTPUT_DIR = bin

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
TARGET = $(OUTPUT_DIR)/main.elf

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(OUTPUT_DIR)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(OUTPUT_DIR)

.PHONY: all clean
