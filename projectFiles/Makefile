CC=g++
SRC_DIR=src
BUILD_DIR=build
BIN_DIR=bin

SOURCES=$(wildcard $(SRC_DIR)/*.cpp)
OBJECTS=$(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
EXECUTABLES=$(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%,$(SOURCES))

all: $(EXECUTABLES)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $< -o $@

$(BIN_DIR)/%: $(BUILD_DIR)/%.o
	$(CC) $< -o $@

clean:
	rm -f $(BUILD_DIR)/*.o $(EXECUTABLES)