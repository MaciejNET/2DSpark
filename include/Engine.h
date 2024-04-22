#ifndef INC_2DSPARK_ENGINE_H
#define INC_2DSPARK_ENGINE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Managers/InputManager.h"
#include "Renderer.h"
#include <thread>
#include "../include/Managers/WindowManager.h"
#include <memory>

class Engine 
{
public:
    Engine(int width, int height, const char* title);
    Engine(int width, int height, const char* title, float targetFps);
    ~Engine();
    void Run();
    void SetClearColor(float r, float g, float b, float alpha = 1.0f);
    Renderer* GetRenderer() const;
    InputManager* GetInputManager() const;
    WindowManager* GetWindowManager() const;
    void SetTargetFps(float targetFps);
private:
    void Init();
    void CleanUp();

    int _width, _height;
    const char* _title;
    GLFWwindow* _window;
    std::unique_ptr<InputManager> _inputManager;
    std::unique_ptr<Renderer> _renderer;
    float _deltaTime = 0.0f;
    float _lastFrame = 0.0f;
    float _fps;
    float _clearColor[4];
    float _targetFps = 0.0f;
    std::unique_ptr<WindowManager> _windowManager;
};

#endif //INC_2DSPARK_ENGINE_H
