# Flags
CC = gcc
WARNINGS = -Wall -Wextra -Werror
# Supports multiple dirs
INCDIRS = src src/model $(HOME)/.local/include
OPT = -O0
DEBUG = -g
ASAN =
ASAN = -fsanitize=address 
# DPEN = -MMD 
CFLAGS = $(WARNINGS) $(foreach i, $(INCDIRS), -I$(i)) $(OPT) $(DEBUG) $(ASAN) 
LDFLAGS = -llogger -L$(HOME)/.local/lib/  
RTP = -Wl,-rpath=$(HOME)/.local/lib/

# Directories
SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

# Files
BIN = $(BUILD_DIR)/main

# Find all .c files recursively in src directory
SRCS = $(shell find $(SRC_DIR) -name '*.c')

# Create object file paths while maintaining directory structure
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Get directory paths for object files
OBJ_DIRS = $(sort $(dir $(OBJS)))

.PHONY = all clean rebuild

all: $(BIN)

# Linking the .o files
$(BIN): $(OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS) $(RTP)

# Compile src files -> .o and .d files 
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIRS)
	$(CC) $(CFLAGS) $(DPEN) -c $< -o $@ $(LDFLAGS)

# Create all necessary subdirectories
$(OBJ_DIRS):
	mkdir -p $@

$(BUILD_DIR):
	mkdir -p $@

clean: 
	rm -rf $(BUILD_DIR)

rebuild: clean all

# Watch the preprocessor generated dependencies for .o files
# `-` : we don't fail since the first build won't have dependencies
-include $(OBJS:.o=.d)
