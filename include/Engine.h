#ifndef INC_2DSPARK_ENGINE_H
#define INC_2DSPARK_ENGINE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "InputManager.h"
#include "Renderer.h"

class Engine {
public:
    Engine(int width, int height, const char* title);
    ~Engine();
    void Run();
    void ClearScreen();
    void SetClearColor(float r, float g, float b, float alpha = 1.0f);
    void ToggleFullscreen();
    void ToggleWindowed();
    static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

private:
    void Init();
    void CleanUp();

private:
    int _width, _height;
    const char* _title;
    GLFWwindow* _window;
    InputManager* _inputManager;
    Renderer* _renderer;
    float _deltaTime = 0.0f;
    float _lastFrame = 0.0f;
    float _fps;
    float _clearColor[4];
};

#endif //INC_2DSPARK_ENGINE_H
