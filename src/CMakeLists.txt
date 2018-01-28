INCLUDE_DIRECTORIES(.)

OPTION(CML_DOUBLE_PRECISION "Use double precision floating point values" BOOL:FALSE)
IF(CML_DOUBLE_PRECISION)
	MESSAGE(STATUS "Using double-precision floating point values")
ELSE()
	MESSAGE(STATUS "Using single-precision floating point values")
ENDIF()

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake
	${CMAKE_CURRENT_SOURCE_DIR}/config.h
)

SET( CML_HEADERS
		cml.h
		cml/include/structures.h
		cml/include/math.h
		cml/include/structures/functions/quaternion.h
		cml/include/structures/types.h
		cml/include/structures/types/matrix4.h
		cml/include/structures/types/quaternion.h
		cml/include/structures/types/matrix3.h
		cml/include/math/consts.h
		cml/include/math/functions/complex/basic.h
		cml/include/math/functions/complex/hyperbolic.h
		cml/include/math/functions/complex/error.h
		cml/include/math/functions/complex/exponentiation.h
		cml/include/math/functions/complex/trigonometric.h
		cml/include/math/functions/real.h
		cml/include/math/functions/complex.h
		cml/include/math/functions/generic.h
		cml/include/math/functions/real/basic.h
		cml/include/math/functions/real/classification.h
		cml/include/math/functions/real/hyperbolic.h
		cml/include/math/functions/real/power.h
		cml/include/math/functions/real/exponential.h
		cml/include/math/functions/real/nearest-integer.h
		cml/include/math/functions/real/trigonometric.h
		cml/include/math/functions/real/error-gamma.h
		cml/include/math/functions.h
		cml/include/math/types.h
		cml/include/math/types/real.h
		cml/include/math/types/complex.h
		cml/include/math/types/bool.h
		cml/include/easings.h
		cml/include/easings/quadratic.h
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
)

SET( Cml_SRCS
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
SOURCE_GROUP(cml FILES ${Cml_SRCS})

SET( Cml_Tests_SRCS
	test/main.c
)
SOURCE_GROUP(Tests FILES ${Cml_Tests_SRCS})

IF(NOT CMAKE_BUILD_TYPE)
	SET(CMAKE_BUILD_TYPE Release)
	MESSAGE(STATUS "No CMAKE_BUILD_TYPE specified, using default RELEASE")
ENDIF()
MESSAGE(STATUS "Built type is set to ${CMAKE_BUILD_TYPE}")

IF(CMAKE_COMPILER_IS_WINDOWS)
	SET(CMAKE_DEBUG_POSTFIX d)
ENDIF()

INCLUDE(../cmake/CMakeBuildFlags.cmake)

# unit tests do not use strict-prototypes, so this is here
IF(CMAKE_COMPILER_IS_GNUC OR CMAKE_COMPILER_IS_CLANG)
	SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
ENDIF()

SET(CMAKE_POSITION_INDEPENDENT_CODE ON)

OPTION(CML_BUILD_STATIC "Build static library" ON)
IF(CML_BUILD_STATIC)
	ADD_LIBRARY(cml_static STATIC ${Cml_SRCS})
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
	ADD_LIBRARY(cml SHARED ${Cml_SRCS})
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
INSTALL(FILES ${CML_HEADERS} DESTINATION include/cml)

#IF(CMAKE_COMPILER_IS_WINDOWS AND "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
#	INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/Debug/cml.pdb DESTINATION bin)
#ENDIF()
