#define GLFW_INCLUDE_NONE

#include <cstdlib>
#include "../include/Engine.h"
#include "../include/LineObject.h"
#include "../include/CircleObject.h"
#include "../include/RectangleObject.h"
#include "../include/PointObject.h"
#include "../include/TriangleObject.h"
#include "../include/BitmapObject.h"

int main(void)
{
    Engine engine(800, 600, "Test");
    LineObject line(Point(0.0f, 0.0f), Point(0.5f, 0.5f), 1.0f, 0.0f, 0.0f);
    CircleObject circle(Point(0.5f, 0.5f), Point(0.0f, 0.0f), 0.5f, 0.0f, 1.0f, 0.0f);
    RectangleObject rectangle(Point(0.0f, -0.0f), Point(0.5f, 0.5f), 0.0f, 0.0f, 1.0f);
    PointObject point(Point(0.5f, 0.5f), Point(0.5f, 0.5f), 1.0f, 0.0f, 0.0f);
    TriangleObject triangle(Point(0.0f, 0.0f), Point(0.5f, 0.5f), Point(0.5f, 0.0f), 1.0f, 1.0f, 1.0f);

#ifdef __unix__
    BitmapObject myImage("../images/myImage.jpg");
#elif __aarch64__
    BitmapObject myImage("../images/myImage.jpg");
#elif defined(_WIN32) || defined(_WIN64)
    BitmapObject myImage("../../../images/myImage.jpg");
#endif
    
    engine.GetRenderer()->AddObject(&myImage);
    engine.GetRenderer()->AddObject(&point);
    engine.GetRenderer()->AddObject(&rectangle);
    engine.GetRenderer()->AddObject(&circle);
    engine.GetRenderer()->AddObject(&line);
    engine.GetRenderer()->AddObject(&triangle);
  
    engine.Run();
    glfwTerminate();
    exit(EXIT_SUCCESS);
}