cmake_minimum_required(VERSION 3.15)
project(First)

find_package(OpenGL)

set(CMAKE_CXX_STANDARD 14)

add_executable(First main.cpp)

file(COPY
        ${CMAKE_SOURCE_DIR}/freeglut.dll
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(First ${CMAKE_SOURCE_DIR}/freeglut.lib ${OPENGL_gl_LIBRARY})