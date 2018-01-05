SOURCE_FOLDER := ./src
BIN_FOLDER := ./src/utils
MATH_FOLDER := $(SOURCE_FOLDER)/math
TEST_FOLDER := ./tests/src
BUILD_FOLDER := ./tests/.build
TEMPORAL_FOLDER := ./tests/.temp
TEST_OUTPUT_NAME := cmlMainTest.o

SRC_FILES := $(shell find src/ -name "*.c")


#################################
# Compilation options
#################################
# Optimization: -O0 baja, -O1 normal, -O2 optimizado, -O3 alta
# Show all warnings
# Compiles in gnu11 std
CFLAGS=-O3 -Wall -std=gnu11 -pthread -I./src

# Uncomment to debug
DEBUG=-g

##################################
# Rules

.PHONY:	all clean folders test
all:	folders c.o

c.o:
	gcc $(TEST_FOLDER)/main.c $(SRC_FILES) -o $(BUILD_FOLDER)/$(TEST_OUTPUT_NAME) $(CFLAGS) $(DEBUG)


clean:
	rm -rf $(TEMPORAL_FOLDER) $(BUILD_FOLDER)

folders:
	-mkdir $(TEMPORAL_FOLDER) $(BUILD_FOLDER)

test:
	$(BUILD_FOLDER)/$(TEST_OUTPUT_NAME)
