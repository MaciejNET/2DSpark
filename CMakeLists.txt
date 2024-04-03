cmake_minimum_required(VERSION 3.25)
project(2DSpark)

set(CMAKE_CXX_STANDARD 17)

find_library(GLFW_LIBRARY NAMES glfw3 PATHS "${CMAKE_SOURCE_DIR}/dependencies/lib")
include_directories("${CMAKE_SOURCE_DIR}/dependencies/include")

if(APPLE)
    find_library(COREFOUNDATION_LIBRARY CoreFoundation)
    find_library(COREGRAPHICS_LIBRARY CoreGraphics)
    find_library(IOKIT_LIBRARY IOKit)
    find_library(COCOA_LIBRARY Cocoa)
endif()

add_executable(2DSpark src/main.cpp src/glad.c
        src/Point.cpp src/Renderer.cpp src/InputManager.cpp
        src/Engine.cpp src/ColorObject.cpp
        src/LineObject.cpp "include/CircleObject.h" "src/CircleObject.cpp" "include/RectangleObject.h" "src/RectangleObject.cpp")

if(APPLE)
    target_link_libraries(2DSpark ${GLFW_LIBRARY} ${COREFOUNDATION_LIBRARY} ${COREGRAPHICS_LIBRARY} ${IOKIT_LIBRARY} ${COCOA_LIBRARY})
else()
    target_link_libraries(2DSpark ${GLFW_LIBRARY})
endif()
