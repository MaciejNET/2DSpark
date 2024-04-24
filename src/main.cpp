#define GLFW_INCLUDE_NONE

#include <cstdlib>
#include "../include/Engine.h"
#include "../include/DemoGame/SnakeHead.h"

int main(void)
{
    Engine engine(800, 600, "Test", 60.0f);
    SnakeHead snakeHead(800, 600);
    engine.GetRenderer()->AddObject(&snakeHead);
    engine.Run();
    glfwTerminate();
    exit(EXIT_SUCCESS);
}