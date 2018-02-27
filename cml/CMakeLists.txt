INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(include)

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/include/config.h.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/include/cml/config.h
)

SET(CML_MAIN_HEADERS
		include/cml.h
		include/cml.hpp
)

SET(CML_SRCS
		src/errno/error.c
		src/errno/message.c
		src/errno/stream.c
		src/errno/strerrno.c
		src/complex/trigonometric.c
		src/complex/hyperbolic.c
		src/complex/basic.c
		src/complex/exponentiation.c
		src/complex/init.c
		src/math/nearest-integer.c
		src/math/trigonometric.c
		src/math/power.c
		src/math/exponential.c
		src/math/hyperbolic.c
		src/math/basic.c
		src/math/classification.c
		src/math/init.c
		src/easings/exponential.c
		src/easings/quadratic.c
		src/easings/quartic.c
		src/easings/linear.c
		src/easings/cubic.c
		src/easings/back.c
		src/easings/bounce.c
		src/easings/quintic.c
		src/easings/sine.c
		src/easings/elastic.c
		src/easings/circular.c
		src/quaternion/basic.c
		src/quaternion/classification.c
		src/quaternion/exponentiation.c
		src/quaternion/parity.c
		src/quaternion/init.c
		src/ieee/endian.c
		src/ieee/make_rep.c
		src/ieee/print.c
		src/ieee/standardize.c
		src/deriv/deriv.c
		src/diff/diff.c
		src/block/source.c
)
SOURCE_GROUP(cml FILES ${CML_SRCS})

SET(CML_TESTS_SRCS
	test/main.c
)
SOURCE_GROUP(Tests FILES ${CML_TESTS_SRCS})

IF(NOT CMAKE_BUILD_TYPE)
	SET(CMAKE_BUILD_TYPE Release)
	MESSAGE(STATUS "No CMAKE_BUILD_TYPE specified, using default RELEASE")
ENDIF()
MESSAGE(STATUS "Built type is set to ${CMAKE_BUILD_TYPE}")

IF(CMAKE_COMPILER_IS_WINDOWS)
	SET(CMAKE_DEBUG_POSTFIX d)
ENDIF()

INCLUDE(../cmake/CMakeBuildFlags.cmake)

SET(CMAKE_POSITION_INDEPENDENT_CODE ON)

OPTION(CML_BUILD_STATIC "Build static library" ON)
IF(CML_BUILD_STATIC)
	ADD_LIBRARY(cml_static STATIC ${CML_SRCS})
	SET_TARGET_PROPERTIES(cml_static PROPERTIES LINKER_LANGUAGE C)
	if(CMAKE_COMPILER_IS_GNUC)
		SET_TARGET_PROPERTIES(cml_static PROPERTIES OUTPUT_NAME "cml")
	endif()
	list(APPEND CML_LIB_TARGET cml_static)
	SET_TARGET_PROPERTIES(cml_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
	IF(APPLE)
		SET_TARGET_PROPERTIES(cml_static PROPERTIES MACOSX_RPATH ON)
	ENDIF()
ENDIF()


OPTION(CML_BUILD_SHARED "Build shared library" ON)
IF(CML_BUILD_SHARED)
	ADD_LIBRARY(cml SHARED ${CML_SRCS})
	SET_TARGET_PROPERTIES(cml PROPERTIES LINKER_LANGUAGE C)
	SET_TARGET_PROPERTIES(cml PROPERTIES VERSION ${PROJECT_VERSION})
	#SET_TARGET_PROPERTIES(cml PROPERTIES SOVERSION 1)
	list(APPEND CML_LIB_TARGET cml)
	SET_TARGET_PROPERTIES(cml PROPERTIES CLEAN_DIRECT_OUTPUT 1)
	IF(LINUX)
		# shared library should link to libm
		FIND_LIBRARY(M_LIB m)
		TARGET_LINK_LIBRARIES(cml ${M_LIB})
	ENDIF()
	IF(APPLE)
		SET_TARGET_PROPERTIES(cml PROPERTIES MACOSX_RPATH ON)
	ENDIF()
	#IF(CMAKE_COMPILER_IS_WINDOWS)
	#	SET_TARGET_PROPERTIES(cml PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
	#ENDIF()
ENDIF()


IF(NOT CML_BUILD_STATIC AND NOT CML_BUILD_SHARED)
	MESSAGE(FATAL_ERROR "Both shared and static libraries are disabled. Please specify one or the other or both.")
ENDIF(NOT CML_BUILD_STATIC AND NOT CML_BUILD_SHARED)

IF(CMAKE_SIZEOF_VOID_P EQUAL 8)
	SET(LIB_SUFFIX "64")
ENDIF()

INSTALL(TARGETS ${CML_LIB_TARGET}
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib
		)
INSTALL(FILES ${CML_MAIN_HEADERS} DESTINATION include)
INSTALL(DIRECTORY include/cml/ DESTINATION include/cml)


#IF(CMAKE_COMPILER_IS_WINDOWS AND "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
#	INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/Debug/cml.pdb DESTINATION bin)
#ENDIF()
