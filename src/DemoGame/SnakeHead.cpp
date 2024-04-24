#include "../../include/DemoGame/SnakeHead.h"

void SnakeHead::Update(float deltaTime)
{
    Move();
}

void SnakeHead::Move()
{
    if (_key == GLFW_KEY_W)
    {
        Translate(0.0f, -1.0f);
    }
    else if (_key == GLFW_KEY_S)
    {
        Translate(0.0f, 1.0f);
    }
    else if (_key == GLFW_KEY_A)
    {
        Translate(-1.0f, 0.0f);
    }
    else if (_key == GLFW_KEY_D)
    {
        Translate(1.0f, 0.0f);
    }
}
