#Genetated by VisualGDB project wizard.
#Note: VisualGDB will automatically update this file when you add new sources to the project.

cmake_minimum_required(VERSION 2.7)
project(russia)

set(THIRD_PARTY_LIBRARIES mylog
)

set(LIBRARIES_FROM_REFERENCES pthread
)

set(RUNTIME_LIB ${LIBRARIES_FROM_REFERENCES} ${THIRD_PARTY_LIBRARIES}
)

SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_CXX_COMPILER g++)
SET(CMAKE_STRIP strip)

MESSAGE(STATUS "the PROJECT_SOURCE_DIR value is " ${PROJECT_SOURCE_DIR})

AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src SRC_LIST)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include )

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib )	

link_libraries(russia ${RUNTIME_LIB})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(russia ${SRC_LIST})

target_link_libraries(russia ${RUNTIME_LIB})