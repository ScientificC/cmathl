INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/cml/include)

ADD_EXECUTABLE(test_cml main.c complex.c deriv.c diff.c easings.c quaternion.c real.c)

if(CMAKE_COMPILER_IS_GNUC OR CMAKE_COMPILER_IS_CLANG)
	FIND_LIBRARY(LIBM m)
  TARGET_LINK_LIBRARIES(test_cml cml LIBM)
else()
  TARGET_LINK_LIBRARIES(test_cml cml)
endif()

ADD_TEST(NAME test_cml COMMAND test_cml)
