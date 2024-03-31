#include "../include/Engine.h"

Engine::Engine(int width, int height, const char *title) : _width(width), _height(height), _title(title)
{
    Init();
}

Engine::~Engine()
{
    CleanUp();
}

void Engine::Init()
{
    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(_width, _height, _title, nullptr, nullptr);
    if (!_window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(_window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        exit(EXIT_FAILURE);

    glViewport(0, 0, _width, _height);
    _renderer = new Renderer();
    _inputManager = new InputManager();

    glfwSetFramebufferSizeCallback(_window, FramebufferSizeCallback);
    SetClearColor(0.0f, 0.0f, 0.0f);
}

void Engine::Run()
{
    while (!glfwWindowShouldClose(_window))
    {
        auto currentTime = (float)glfwGetTime();
        _deltaTime = currentTime - _lastFrame;
        _lastFrame = currentTime;

        _fps = 1.0f / _deltaTime;

        std::cout << "FPS: " << _fps << std::endl;

        _inputManager->Update(_window);

        if (_inputManager->KeyPressed(GLFW_KEY_ESCAPE))
            glfwSetWindowShouldClose(_window, true);

        ClearScreen();

        _renderer->Render();

        glfwSwapBuffers(_window);
        glfwPollEvents();
    }
}

void Engine::ClearScreen()
{
    glClearColor(_clearColor[0], _clearColor[1], _clearColor[2], _clearColor[3]);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Engine::SetClearColor(float r, float g, float b, float alpha)
{
    _clearColor[0] = r;
    _clearColor[1] = g;
    _clearColor[2] = b;
    _clearColor[3] = alpha;
}

void Engine::ToggleFullscreen()
{
    auto monitor = glfwGetPrimaryMonitor();
    auto mode = glfwGetVideoMode(monitor);
    glfwSetWindowMonitor(_window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
}

void Engine::ToggleWindowed()
{
    auto mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowMonitor(_window, nullptr, 0, 0, _width, _height, mode->refreshRate);
}

Renderer *Engine::GetRenderer() const
{
    return _renderer;
}

InputManager *Engine::GetInputManager() const
{
    return _inputManager;
}

void Engine::FramebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Engine::CleanUp()
{
    delete _renderer;
    delete _inputManager;
    glfwTerminate();
}
