INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/cml/include)

INCLUDE(../cmake/CMakeBuildFlags.cmake)

ADD_EXECUTABLE(test_cml main.c)
TARGET_LINK_LIBRARIES(test_cml cml ${LIBM})
ADD_TEST(NAME test_cml COMMAND test_cml)
