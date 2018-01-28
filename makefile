SOURCE_FOLDER := src
TEST_FOLDER := test
BUILD_FOLDER := build
TEMPORAL_FOLDER := tmp
TEST_OUTPUT_NAME := test
INSTALL_FOLDER=/usr/bin

SRC_UTILS_FILES :=

SRC_EASING_FILES := exponential \
										quadratic \
										quartic \
										linear \
										cubic \
										back \
										bounce \
										quintic \
										sine \
										elastic \
										circular

SRC_MATH_FILES := real \
									complex

SRC_MATH_REAL_FILES := basic \
										   classification \
											 exponential \
											 hyperbolic \
											 nearest-integer \
											 power \
											 trigonometric

SRC_MATH_COMPLEX_FILES := basic \
													exponentiation \
													hyperbolic \
													trigonometric

CML_TEST_FILES := main

CFLAG=-Ofast -Wall -pthread -I$(SOURCE_FOLDER) \
-Dmfloat_t=double -DCML_DOUBLE_PRECISION=ON

DEBUG=-g -ggdb

.PHONY:	all clean folders test test-run cml.o test.o
.IGNORE: clean

all: clean folders cml.o

test: clean folders test.o $(TEMPORAL_FOLDER) $(BUILD_FOLDER)
	    $(CC) $(TEMPORAL_FOLDER)/** -o $(BUILD_FOLDER)/$(TEST_OUTPUT_NAME) $(CFLAG) $(DEBUG)

cml.o:
		for file in $(SRC_MATH_FILES); do \
				$(CC) -c $(SOURCE_FOLDER)/cml/math/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG) $(DEBUG); \
		done

		for file in $(SRC_MATH_REAL_FILES); do \
				$(CC) -c $(SOURCE_FOLDER)/cml/math/real/$$file.c -o $(TEMPORAL_FOLDER)/real_$$file.o $(CFLAG) $(DEBUG); \
		done

		for file in $(SRC_MATH_COMPLEX_FILES); do \
				$(CC) -c $(SOURCE_FOLDER)/cml/math/complex/$$file.c -o $(TEMPORAL_FOLDER)/complex_$$file.o $(CFLAG) $(DEBUG); \
		done

		for file in $(SRC_EASING_FILES); do \
				$(CC) -c $(SOURCE_FOLDER)/cml/easings/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG) $(DEBUG); \
		done

		for file in $(SRC_UTILS_FILES); do \
				$(CC) -c $(SOURCE_FOLDER)/cml/utils/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG) $(DEBUG); \
		done

test.o: cml.o
		for file in $(CML_TEST_FILES); do \
				$(CC) -c $(TEST_FOLDER)/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG) $(DEBUG); \
		done

clean: ; -rm -rf $(TEMPORAL_FOLDER) $(BUILD_FOLDER)

folders: ; -mkdir $(TEMPORAL_FOLDER) $(BUILD_FOLDER)

lines:
		@ printf "	.c files              "
		@ find $(SOURCE_FOLDER)/ -name '*.c' | xargs wc -l | grep total
		@ printf "	.h files      	       "
		@ find $(SOURCE_FOLDER)/ -name '*.h' | xargs wc -l | grep total

test-run: test ; @ ./$(BUILD_FOLDER)/test
