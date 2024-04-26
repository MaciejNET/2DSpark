#define GLFW_INCLUDE_NONE

#include <cstdlib>
#include <ctime>
#include "../include/Engine.h"
#include "../include/DemoGame/SnakeHead.h"
#include "../include/DemoGame/FoodItem.h"

int main(void)
{
    srand(time(NULL));
    Engine engine(800, 600, "Test", 60.0f);
    SnakeHead snakeHead(800, 600);
    FoodItem foodItem(800, 600);
    engine.GetRenderer()->AddObject(&snakeHead);
    engine.GetRenderer()->AddObject(&foodItem);
    engine.Run();
    glfwTerminate();
    exit(EXIT_SUCCESS);
}