CC = msp430-gcc
CFLAGS = -mmcu=msp430g2553 -O2
LDFLAGS = -mmcu=msp430g2553

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
TARGET = $(BIN_DIR)/main.elf

all: $(TARGET)

$(TARGET): $(OBJECTS)
    @mkdir -p $(BIN_DIR)
    $(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
    @mkdir -p $(OBJ_DIR)
    $(CC) $(CFLAGS) -c -o $@ $<

clean:
    rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean