INCLUDE_DIRECTORIES(.)

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/config.h
)

SET(CML_MAIN_HEADERS
		cml.h
		config.h
)

SET(CML_CML_HEADERS
	cml/include/structures.h
	cml/include/math.h
	cml/include/easings.h)

SET(CML_MATH_HEADERS
	cml/include/math/consts.h
	cml/include/math/functions.h
	cml/include/math/types.h
)

SET(CML_MATH_TYPES_HEADERS
	cml/include/math/types/real.h
	cml/include/math/types/complex.h
	cml/include/math/types/bool.h
)

SET(CML_MATH_FUNC_HEADERS
	cml/include/math/functions/real.h
	cml/include/math/functions/complex.h
	cml/include/math/functions/generic.h
)

SET(CML_MATH_COMPLEX_HEADERS
	cml/include/math/functions/complex/basic.h
	cml/include/math/functions/complex/hyperbolic.h
	cml/include/math/functions/complex/error.h
	cml/include/math/functions/complex/exponentiation.h
	cml/include/math/functions/complex/trigonometric.h
)

SET(CML_MATH_REAL_HEADERS
	cml/include/math/functions/real/basic.h
	cml/include/math/functions/real/classification.h
	cml/include/math/functions/real/hyperbolic.h
	cml/include/math/functions/real/power.h
	cml/include/math/functions/real/exponential.h
	cml/include/math/functions/real/nearest-integer.h
	cml/include/math/functions/real/trigonometric.h
	cml/include/math/functions/real/error-gamma.h
)

SET(CML_EASINGS_HEADERS
	cml/include/easings/linear.h
	cml/include/easings/bounce.h
	cml/include/easings/quartic.h
	cml/include/easings/quintic.h
	cml/include/easings/circular.h
	cml/include/easings/back.h
	cml/include/easings/exponential.h
	cml/include/easings/sine.h
	cml/include/easings/cubic.h
	cml/include/easings/elastic.h
	cml/include/easings/quadratic.h
)

SET( CML_SRCS
		cml/math/complex/trigonometric.c
		cml/math/complex/hyperbolic.c
		cml/math/complex/basic.c
		cml/math/complex/exponentiation.c
		cml/math/complex.c
		cml/math/real/nearest-integer.c
		cml/math/real/trigonometric.c
		cml/math/real/power.c
		cml/math/real/exponential.c
		cml/math/real/hyperbolic.c
		cml/math/real/basic.c
		cml/math/real/classification.c
		cml/math/real.c
		cml/easings/exponential.c
		cml/easings/quadratic.c
		cml/easings/quartic.c
		cml/easings/linear.c
		cml/easings/cubic.c
		cml/easings/back.c
		cml/easings/bounce.c
		cml/easings/quintic.c
		cml/easings/sine.c
		cml/easings/elastic.c
		cml/easings/circular.c
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
INSTALL(FILES ${CML_CML_HEADERS} DESTINATION include/cml/include)
INSTALL(FILES ${CML_MATH_HEADERS} DESTINATION include/cml/include/math)
INSTALL(FILES ${CML_MATH_TYPES_HEADERS} DESTINATION include/cml/include/math/types)
INSTALL(FILES ${CML_MATH_FUNC_HEADERS} DESTINATION include/cml/include/math/functions)
INSTALL(FILES ${CML_MATH_COMPLEX_HEADERS} DESTINATION include/cml/include/math/functions/complex)
INSTALL(FILES ${CML_MATH_REAL_HEADERS} DESTINATION include/cml/include/math/functions/real)
INSTALL(FILES ${CML_EASINGS_HEADERS} DESTINATION include/cml/include/easings)

#IF(CMAKE_COMPILER_IS_WINDOWS AND "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
#	INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/Debug/cml.pdb DESTINATION bin)
#ENDIF()
