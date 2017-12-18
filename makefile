SOURCE_FOLDER=./src
BIN_FOLDER=./src/bin
MATH_FOLDER=$(SOURCE_FOLDER)/math
FUNC_FOLDER=$(MATH_FOLDER)/functions
TEST_FOLDER=./tests/src
BUILD_FOLDER=./tests/.build
TEMPORAL_FOLDER=./tests/.temp
TEST_OUTPUT_NAME=cmlMainTest.o


#################################
# Compilation options
#################################
# Optimization: -O0 baja, -O1 normal, -O2 optimizado, -O3 alta
# Show all warnings
# Compiles in gnu11 std
CFLAGS=-O3 -Wall -std=gnu11 -pthread

# Uncomment to debug
DEBUG=-g

##################################
# Rules

.PHONY:	all clean folders test
all:	folders c.o

c.o:
	gcc $(TEST_FOLDER)/main.c $(MATH_FOLDER)/types/* $(FUNC_FOLDER)/* $(BIN_FOLDER)/* -o $(BUILD_FOLDER)/$(TEST_OUTPUT_NAME) $(CFLAGS) $(DEBUG)


clean:
	rm -rf $(TEMPORAL_FOLDER) $(BUILD_FOLDER)

folders:
	-mkdir $(TEMPORAL_FOLDER) $(BUILD_FOLDER)

test:
	$(BUILD_FOLDER)/$(TEST_OUTPUT_NAME)
