cmake_minimum_required(VERSION 3.19)

project(Payment_System)

set(CMAKE_C_STANDARD 11)
set(CMAKE_DEBUG_POSTFIX "d")

include_directories(${CMAKE_BINARY_DIR})

add_library(tutorial_compiler_flags INTERFACE)

include_directories(./includes)

file(GLOB DEFINITIONS_SOURCES 
    ./src/definitions/*.c
    ./src/definitions/**/*.c 
)

add_executable(${PROJECT_NAME} ./src/main.c ${DEFINITIONS_SOURCES})

if (CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID MATCHES "Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -g)
elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /Zi)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

target_link_libraries(${PROJECT_NAME} -lncurses)

add_custom_target(run
    COMMAND ./${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
