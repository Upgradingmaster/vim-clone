# Flags
CC = gcc
WARNINGS = -Wall -Wextra -Werror
# Supports multiple dirs
INCDIRS = src 
OPT = -O0
DEBUG = -g
ASAN =
# ASAN = -fsanitize=address 
DPEN = -MMD 
CFLAGS = $(WARNINGS) $(foreach i, $(INCDIRS), -I$(i) )$(OPT) $(DEBUG) $(ASAN) 
LDFLAGS =  


# Directories
SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

# Files
BIN = $(BUILD_DIR)/main
SRCS = $(wildcard $(SRC_DIR)/*.c)
# OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, SRCS)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


.PHONY = all clean rebuild
all: $(BIN)

# Linking the .o files
$(BIN): $(OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

# Compile src files -> .o and .d files 
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DPEN) -c $< -o $@ 

# Directories
$(BUILD_DIR) $(OBJ_DIR):
	mkdir -p $@

clean: 
	rm -rf $(BUILD_DIR)

rebuild: clean all

# Watch the preprocessor generated dependencies for .o files
# `-` : we don't fail since the first build won't have dependencies
-include $(OBJS:.o=.d) 
