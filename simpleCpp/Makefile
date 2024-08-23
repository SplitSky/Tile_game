
# Makefile for compiling main.cpp with g++

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++14 -Wall -Wextra -I/opt/homebrew/opt/googletest/include

# Linker flags
LDFLAGS = -L/opt/homebrew/opt/googletest/lib -lgtest -lgtest_main -pthread

# Target executables
TARGET = a.out
TEST_TARGET = runTests

# Source files
SRCS = main.cpp
TEST_SRCS = main_test.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Default rule to build the target
all: $(TARGET) test

# Rule to link the object files and create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile the test object files and create the test executable
$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)

# Rule to compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Clean up the build files
clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)

.PHONY: all clean test

