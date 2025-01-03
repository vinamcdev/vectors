CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g
AR = ar
ARFLAGS = rcs

SRC_DIR = src
BIN_DIR = bin
TEST_DIR = tests
LIB_DIR = lib

TARGET_LIB = $(LIB_DIR)/libvectors.a
TEST_BIN = $(BIN_DIR)/test_vectors

LIB_SRCS = $(wildcard $(SRC_DIR)/*.c)
LIB_OBJS = $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(LIB_SRCS))

TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS = $(patsubst $(TEST_DIR)/%.c, $(BIN_DIR)/%.o, $(TEST_SRCS))

# Default rule
all: $(TARGET_LIB)

# Build the static library
$(TARGET_LIB): $(LIB_OBJS)
	@mkdir -p $(LIB_DIR)
	$(AR) $(ARFLAGS) $@ $^

# Compile library object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile test object files
$(BIN_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link the test executable with CUnit
$(TEST_BIN): $(TEST_OBJS) $(TARGET_LIB)
	$(CC) $(CFLAGS) $^ -o $@ -lm -lcunit

# Run tests
tests: $(TEST_BIN)
	./$(TEST_BIN)

# Clean all build artifacts
clean:
	rm -rf $(BIN_DIR) $(LIB_DIR)

.PHONY: all tests clean
