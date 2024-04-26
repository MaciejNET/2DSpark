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
        src/Primitives/Point.cpp src/Renderer.cpp src/Managers/InputManager.cpp
        src/Engine.cpp src/Primitives/ColorObject.cpp src/Managers/WindowManager.cpp
        src/Primitives/LineObject.cpp "include/Primitives/CircleObject.h" "src/Primitives/CircleObject.cpp" "include/Primitives/RectangleObject.h" "src/Primitives/RectangleObject.cpp" "include/Primitives/PointObject.h" "src/Primitives/PointObject.cpp" "dependencies/include/stb_image.h" "include/Primitives/BitmapObject.h" "src/Primitives/BitmapObject.cpp" src/Primitives/TriangleObject.cpp "include/Primitives/TriangleObject.h"
        src/Events/EventBus.cpp "include/Events/KeyHeldEvent.h"
        src/Primitives/AnimatedBitmapObject.cpp
        src/DemoGame/SnakeHead.cpp src/DemoGame/FoodItem.cpp "include/DemoGame/FoodItem.h"   "include/DemoGame/CollisionDetector.h" "src/DemoGame/CollisionDetector.cpp"  )

if(APPLE)
    target_link_libraries(2DSpark ${GLFW_LIBRARY} ${COREFOUNDATION_LIBRARY} ${COREGRAPHICS_LIBRARY} ${IOKIT_LIBRARY} ${COCOA_LIBRARY})
else()
    target_link_libraries(2DSpark ${GLFW_LIBRARY})
endif()
