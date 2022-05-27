DIR_GUARD=mkdir -p build
BUILD_PATH := build
PROJECT_DIR := source

CXXFILES := $(shell find $(PROJECT_DIR) -name "*.cpp")
TESTFILE := test.cpp
OBJFILES := $(patsubst $(PROJECT_DIR)/%.cpp, $(BUILD_PATH)/%.o, $(CXXFILES))
OUTPUT := libminivector.so

SANITIZER := \
	-fsanitize=address \
	-fsanitize=undefined 

CXX = clang++

CXXFLAGS := \
	-std=c++17 \
	-Wall \
	-Werror

$(BUILD_PATH)/%.o: $(CXXFILES)
	@$(DIR_GUARD)
	@echo "CXX $< $@"
	@$(CXX) -c $(CXXFLAGS) -o $@ $<

$(OUTPUT): $(OBJFILES)
	@$(DIR_GUARD)
	@echo "AR $(OUTPUT)"
	@#$(CXX) $(OBJFILES) $(SANITIZER) -o $(OUTPUT)
	@ar ru $(OUTPUT) $(OBJFILES)

test: $(TESTFILE) $(OUTPUT)
	@echo "TEST $<"
	@$(CXX) $(SANITIZER) $(OUTPUT) $(TESTFILE)
	@./a.out

clean: 
	rm $(OBJFILES)
	rm $(OUTPUT)

all: $(OUTPUT)
