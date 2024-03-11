cmake_minimum_required(VERSION 3.25)
project(2DSpark)

set(CMAKE_CXX_STANDARD 17)

add_executable(2DSpark main.cpp)

include_directories(libraries/glad)
target_sources(2DSpark PRIVATE libraries/glad/src/gl.c)

add_subdirectory(libraries/glfw-3.4)
target_link_libraries(2DSpark glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(2DSpark OpenGL::GL)
