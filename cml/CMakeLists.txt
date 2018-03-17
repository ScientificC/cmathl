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

add_subdirectory(src)

INSTALL(FILES ${CML_MAIN_HEADERS} DESTINATION include)
INSTALL(DIRECTORY include/cml DESTINATION include/cml)


#IF(CMAKE_COMPILER_IS_WINDOWS AND "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
#	INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/Debug/cml.pdb DESTINATION bin)
#ENDIF()
