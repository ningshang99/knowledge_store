cmake_minimum_required(VERSION 3.5)
project(logTest)

set (CMAKE_INSTALL_PREFIX ../../lib)

find_package( Boost COMPONENTS system thread REQUIRED )

set (Boost_NO_SYSTEM_PATHS  FALSE)

include_directories(
	include
	${Boost_INCLUDE_DIRS}
)
link_directories(
	${Boost_LIBRARY_DIRS}
	)

add_library( ${PROJECT_NAME}  SHARED
	source/logTest.cc
	source/logTest_Internal.cc
)

target_link_libraries(${PROJECT_NAME}
		${Boost_LIBRARIES}
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

message(STATUS "************************************")
message(STATUS "${CMAKE_BINARY_DIR}/lib${PROJECT_NAME}.so")
message(STATUS "************************************")
message(STATUS "${CMAKE_BINARY_DIR}/../../include")
message(STATUS "************************************")
message(STATUS "${CMAKE_BINARY_DIR}/../../lib")
message(STATUS "************************************")

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
	set (CMAKE_CXX_FLAGS "-fPIC --std=c++11 ")
	MESSAGE(STSTUS "###################################")
	MESSAGE(STSTUS "current platform: Linux ")
	ADD_DEFINITIONS(-DLINUX)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
	set (CMAKE_CXX_FLAGS "-fPIC --std=c++11 /EHsc ${CMAKE_CXX_FLAGS}")
	MESSAGE(STATUS "current platform: Windows")
	ADD_DEFINITIONS(-DBOOST_ALL_DYN_LINK -DWIN32)
ENDIF()

install(FILES  ${CMAKE_BINARY_DIR}/lib${PROJECT_NAME}.so
        DESTINATION ${CMAKE_BINARY_DIR}/../../lib)

install(FILES  ${CMAKE_BINARY_DIR}/../include/${PROJECT_NAME}.h
        DESTINATION ${CMAKE_BINARY_DIR}/../../include)
