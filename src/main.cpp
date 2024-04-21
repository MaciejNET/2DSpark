#include <iostream>
#include <GLFW/glfw3.h>
#include "../include/Managers/InputManager.h"
#include "../include/Events/EventBus.h"
#include "../include/Events/KeyPressedEvent.h"
#include "../include/Events/MouseMovedEvent.h"

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        std::cout << "Key pressed: " << key << std::endl;
    }
    else if (action == GLFW_RELEASE)
    {
        std::cout << "Key released: " << key << std::endl;
    }
}

void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        std::cout << "Mouse button pressed: " << button << std::endl;
    }
    else if (action == GLFW_RELEASE)
    {
        std::cout << "Mouse button released: " << button << std::endl;
    }
}

void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
    std::cout << "Mouse moved to: (" << xpos << ", " << ypos << ")" << std::endl;
}

int main()
{
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "InputManager Test", NULL, NULL);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, KeyCallback);
    glfwSetMouseButtonCallback(window, MouseButtonCallback);
    glfwSetCursorPosCallback(window, CursorPositionCallback);

    InputManager inputManager;

    while (!glfwWindowShouldClose(window))
    {
        inputManager.Update(window);

        if (inputManager.KeyTriggered(GLFW_KEY_SPACE))
        {
            std::cout << "Space key triggered!" << std::endl;
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
