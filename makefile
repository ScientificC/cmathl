SOURCE_FOLDER := src
TEST_FOLDER := test
BUILD_FOLDER := .build
TEMPORAL_FOLDER := .tmp
TEST_OUTPUT_NAME := test
INSTALL_FOLDER=/usr/bin

SRC_UTILS_FILES := series_resolver

SRC_MATH_FILES := real_acos \
complex_tanh \
real_equals \
real_log_b \
real_floor \
real_exp \
real_asinh \
real_sqrt \
real_isinteger \
real_isnatural \
complex_cos \
complex_log_b \
complex_csc \
real_ceil \
real_cosh \
complex_add \
real_cos \
real_root \
complex_tan \
real_pow \
complex_arg \
real_div_e \
real_coth \
real_ismult \
complex_sec \
real_isgreater_or_equals \
real_sgn \
real_abs \
real_sinh \
complex_log \
complex_exp \
real_csch \
real_asin \
real_opposite \
real_ared \
real_mod \
complex_scalar_prod \
rational \
real_acosh \
real_sin \
complex_div \
real_add \
complex_cot \
real_sech \
real_ln \
real_isless \
real_isnull \
real_prod \
complex_conjugate \
real_atan2 \
complex_cosh \
real_csc \
real_isgreater \
complex_prod \
real_tan \
complex \
real_tanh \
complex_sin \
complex_sinh \
complex_inverse \
real_cot \
real_sec \
real_isless_or_equals \
real_atan \
real_inverse \
real \
complex_abs \
real_div \
real_sub \
real_atanh \
complex_sub

CML_TEST_FILES := main

CFLAG=-Ofast -Wall -std=c11 -pthread -I$(SOURCE_FOLDER) -Dmfloat_t=double -DCML_DOUBLE_PRECISION=ON
DEBUG=-g -ggdb

.PHONY:	all clean folders test test-run cml.o test.o
.IGNORE: clean

all: clean folders cml.o

test: clean folders test.o $(TEMPORAL_FOLDER) $(BUILD_FOLDER)
	    gcc $(TEMPORAL_FOLDER)/** -o $(BUILD_FOLDER)/$(TEST_OUTPUT_NAME) $(CFLAG) $(DEBUG)

cml.o:
		for file in $(SRC_MATH_FILES); do \
				gcc -c $(SOURCE_FOLDER)/math/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG) $(DEBUG); \
		done

		for file in $(SRC_UTILS_FILES); do \
				gcc -c $(SOURCE_FOLDER)/utils/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG) $(DEBUG); \
		done

test.o: cml.o
		for file in $(CML_TEST_FILES); do \
				gcc -c $(TEST_FOLDER)/$$file.c -o $(TEMPORAL_FOLDER)/$$file.o $(CFLAG) $(DEBUG); \
		done

clean: ; -rm -rf $(TEMPORAL_FOLDER) $(BUILD_FOLDER)

folders: ; -mkdir $(TEMPORAL_FOLDER) $(BUILD_FOLDER)

lines:
		@ printf "	.c files              "
		@ find $(SOURCE_FOLDER)/ -name '*.c' | xargs wc -l | grep total
		@ printf "	.h files      	       "
		@ find $(SOURCE_FOLDER)/ -name '*.h' | xargs wc -l | grep total

test-run: test ; @ ./$(BUILD_FOLDER)/test
