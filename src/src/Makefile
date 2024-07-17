CXX = g++
CXXFLAGS = -ffreestanding -O2 -Wall -Wextra
LDFLAGS = -T linker.ld -nostdlib -lgcc
NASM = nasm
NASMFLAGS = -f elf32

SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

CPP_SRC = $(wildcard $(SRC_DIR)/**/*.cpp)
ASM_SRC = $(wildcard $(SRC_DIR)/**/*.asm)-
SRC_FILES = $(CPP_SRC) $(ASM_SRC)

OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(CPP_SRC)) \
            $(patsubst $(SRC_DIR)/%.asm, $(BUILD_DIR)/%.o, $(ASM_SRC))

all: $(BUILD_DIR)/kernel.bin

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.asm
	mkdir -p $(dir $@)
	$(NASM) $(NASMFLAGS) $< -o $@

$(BUILD_DIR)/kernel.bin: $(OBJ_FILES)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ_FILES)

clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: all clean
