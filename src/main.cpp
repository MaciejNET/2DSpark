#define GLFW_INCLUDE_NONE

#include <cstdlib>
#include "../include/Engine.h"
#include "../include/LineObject.h"
#include "../include/CircleObject.h"
#include "../include/RectangleObject.h"

int main(void)
{
    Engine engine(800, 600, "Test");
    LineObject line( Point(0.0f, 0.0f), Point(0.5f, 0.5f), 1.0f, 0.0f, 0.0f);
    CircleObject circle( Point(0.5f, 0.5f), Point(0.0f, 0.0f), 0.5f, 0.0f, 1.0f, 0.0f);
    RectangleObject rectangle(Point(0.0f, -0.0f), Point(0.5f, 0.5f), 0.0f, 0.0f, 1.0f);
    engine.GetRenderer()->AddObject(&rectangle);
    engine.GetRenderer()->AddObject(&circle);
    engine.GetRenderer()->AddObject(&line);
    engine.Run();
    exit(EXIT_SUCCESS);
}