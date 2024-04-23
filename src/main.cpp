#define GLFW_INCLUDE_NONE

#include <cstdlib>
#include "../include/Engine.h"
#include "../include/Primitives/LineObject.h"
#include "../include/Primitives/CircleObject.h"
#include "../include/Primitives/RectangleObject.h"
#include "../include/Primitives/PointObject.h"
#include "../include/Primitives/TriangleObject.h"
#include "../include/Primitives/AnimatedBitmapObject.h"
#include "../include/Primitives/BitmapObject.h"

int main(void)
{

    Engine engine(800, 600, "Test", 60.0f);
    LineObject line(Point(0.0f, 0.0f), Point(50.0f, 50.0f), 1.0f, 0.0f, 0.0f, false, 3.0f);
    CircleObject circle(Point(120.0f, 120.5f), Point(10.0f, 20.0f), 0.5f, 0.0f, 1.0f, 0.0f, true, 5.0f);
    RectangleObject rectangle(Point(200.0f, 30.0f), Point(10.5f, 300.5f), 0.0f, 0.0f, 1.0f, true, 5.0f);
    PointObject point(Point(10.5f, 10.5f), Point(0.5f, 0.5f), 1.0f, 0.0f, 0.0f, true, 0.0f);
    TriangleObject triangle(Point(40.0f, 10.0f), Point(60.5f, 100.5f), Point(200.5f, 600.0f), 1.0f, 0.0f, 0.0f, false, 5.0f);
    std::vector<std::string> imagesToAnimate;
    imagesToAnimate.emplace_back("../images/myImage1.jpg");
    imagesToAnimate.emplace_back("../images/myImage2.jpg");
    imagesToAnimate.emplace_back("../images/myImage3.jpg");
    AnimatedBitmapObject animatedObject(imagesToAnimate, 0.5f);
    //BitmapObject myImage("../images/myImage1.jpg");
    //triangle.Rotate(0.5f);
    //circle.SetFilled(false);
    //circle.SetFilled(1.0f);

    //engine.GetRenderer()->AddObject(&myImage);
    //engine.GetRenderer()->AddObject(&point);
    //engine.GetRenderer()->AddObject(&rectangle);
    //engine.GetRenderer()->AddObject(&circle);
    //engine.GetRenderer()->AddObject(&line);
    //engine.GetRenderer()->AddObject(&triangle);
    engine.GetRenderer()->AddObject(&animatedObject);
  
    engine.Run();
    glfwTerminate();
    exit(EXIT_SUCCESS);
}