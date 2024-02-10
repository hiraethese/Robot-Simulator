CXX=g++
CXXFLAGS=-std=c++17
BUILD_DIR=build

all: $(BUILD_DIR)/main

$(BUILD_DIR)/main: $(BUILD_DIR) src/main.cpp
	$(CXX) $(CXXFLAGS) src/main.cpp -o $(BUILD_DIR)/main

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

.PHONY: run clean

run: $(BUILD_DIR)/main
	./$(BUILD_DIR)/main

clean:
	rmdir /s /q $(BUILD_DIR)
