INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(include)

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/include/config.h.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/include/cml/config.h
)

SET(CML_MAIN_HEADERS
		include/cml.h
)

SET(CML_CML_HEADERS
	include/cml/config.h
	include/cml/structures.h
	include/cml/math.h
	include/cml/easings.h
)

SET(CML_MATH_HEADERS
	include/cml/math/consts.h
	include/cml/math/functions.h
	include/cml/math/types.h
)

SET(CML_MATH_TYPES_HEADERS
	include/cml/math/types/real.h
	include/cml/math/types/complex.h
	include/cml/math/types/bool.h
)

SET(CML_MATH_FUNC_HEADERS
	include/cml/math/functions/real.h
	include/cml/math/functions/complex.h
	include/cml/math/functions/generic.h
)

SET(CML_MATH_COMPLEX_HEADERS
	include/cml/math/functions/complex/basic.h
	include/cml/math/functions/complex/hyperbolic.h
	include/cml/math/functions/complex/error.h
	include/cml/math/functions/complex/exponentiation.h
	include/cml/math/functions/complex/trigonometric.h
)

SET(CML_MATH_REAL_HEADERS
	include/cml/math/functions/real/basic.h
	include/cml/math/functions/real/classification.h
	include/cml/math/functions/real/hyperbolic.h
	include/cml/math/functions/real/power.h
	include/cml/math/functions/real/exponential.h
	include/cml/math/functions/real/nearest-integer.h
	include/cml/math/functions/real/trigonometric.h
	include/cml/math/functions/real/error-gamma.h
)

SET(CML_EASINGS_HEADERS
	include/cml/easings/linear.h
	include/cml/easings/bounce.h
	include/cml/easings/quartic.h
	include/cml/easings/quintic.h
	include/cml/easings/circular.h
	include/cml/easings/back.h
	include/cml/easings/exponential.h
	include/cml/easings/sine.h
	include/cml/easings/cubic.h
	include/cml/easings/elastic.h
	include/cml/easings/quadratic.h
)

SET( CML_SRCS
		src/math/complex/trigonometric.c
		src/math/complex/hyperbolic.c
		src/math/complex/basic.c
		src/math/complex/exponentiation.c
		src/math/complex.c
		src/math/real/nearest-integer.c
		src/math/real/trigonometric.c
		src/math/real/power.c
		src/math/real/exponential.c
		src/math/real/hyperbolic.c
		src/math/real/basic.c
		src/math/real/classification.c
		src/math/real.c
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
)
SOURCE_GROUP(cml FILES ${CML_SRCS})

SET( CML_TESTS_SRCS
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
		LIBRARY DESTINATION lib${LIB_SUFFIX}
		ARCHIVE DESTINATION lib${LIB_SUFFIX}
		)
INSTALL(FILES ${CML_MAIN_HEADERS} DESTINATION include)
INSTALL(FILES ${CML_CML_HEADERS} DESTINATION include/cml)
INSTALL(FILES ${CML_MATH_HEADERS} DESTINATION include/cml/math)
INSTALL(FILES ${CML_MATH_TYPES_HEADERS} DESTINATION include/cml/math/types)
INSTALL(FILES ${CML_MATH_FUNC_HEADERS} DESTINATION include/cml/math/functions)
INSTALL(FILES ${CML_MATH_COMPLEX_HEADERS} DESTINATION include/cml/math/functions/complex)
INSTALL(FILES ${CML_MATH_REAL_HEADERS} DESTINATION include/cml/math/functions/real)
INSTALL(FILES ${CML_EASINGS_HEADERS} DESTINATION include/cml/easings)

#IF(CMAKE_COMPILER_IS_WINDOWS AND "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
#	INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/Debug/cml.pdb DESTINATION bin)
#ENDIF()
