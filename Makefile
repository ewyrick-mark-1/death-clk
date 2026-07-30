CC = gcc
CFLAGS = -Wall -g
LIB_FLAGS = -llgpio
BUILD_DIR = build
SRC_DIR = src

all: $(BUILD_DIR)/meow

$(BUILD_DIR)/meow: $(SRC_DIR)/main.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/meow $(SRC_DIR)/main.c $(LIB_FLAGS)

#clean is a command
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
