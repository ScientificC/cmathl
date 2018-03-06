INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/cml/include)

ADD_EXECUTABLE(test_cml main.c complex.c deriv.c diff.c easings.c quaternion.c real.c)
TARGET_LINK_LIBRARIES(test_cml cml)
ADD_TEST(NAME test_cml COMMAND test_cml)
