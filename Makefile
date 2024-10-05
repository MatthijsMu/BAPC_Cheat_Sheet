# Directories
SRC_DIR := src
BIN_DIR := bin

# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -g

# Get all .cpp files in SRC_DIR
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)

# Create a list of corresponding output files in BIN_DIR
BIN_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%, $(SRC_FILES))

# Default target: build all binaries
all: $(BIN_FILES)

# Rule for building each binary
$(BIN_DIR)/%: $(SRC_DIR)/%.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

# Ensure BIN_DIR exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean target to remove binaries
clean:
	rm -rf $(BIN_DIR)/*

# Phony targets
.PHONY: all clean
