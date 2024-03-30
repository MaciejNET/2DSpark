#define GLFW_INCLUDE_NONE

#include <cstdlib>
#include "../include/Engine.h"

int main(void)
{
    Engine engine(800, 600, "Test");
    engine.Run();
    exit(EXIT_SUCCESS);
}