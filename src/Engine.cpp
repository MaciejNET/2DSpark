#include "../include/Engine.h"
#include "../include/Events/EventBus.h"

Engine::Engine(int width, int height, const char *title) : _width(width), _height(height), _title(title)
{
    Init();
}

Engine::Engine(int width, int height, const char *title, float targetFps) : _width(width), _height(height), _title(title), _targetFps(targetFps)
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
    float frameTimeTarget = 0.0f;
    float nextFrameTime = 0.0f;

    while (!glfwWindowShouldClose(_window))
    {
        auto currentTime = (float)glfwGetTime();

        if (_targetFps > 0.0f)
        {
            frameTimeTarget = 1.0f / _targetFps;
            while (currentTime < nextFrameTime)
            {
                currentTime = (float)glfwGetTime();
            }
        }

        _deltaTime = currentTime - _lastFrame;
        _lastFrame = currentTime;
        nextFrameTime = currentTime + frameTimeTarget;

        _fps = 1.0f / _deltaTime;

        std::cout << "FPS: " << _fps << std::endl;

        _inputManager->Update(_window);

        if (_inputManager->KeyPressed(GLFW_KEY_ESCAPE))
            glfwSetWindowShouldClose(_window, true);

        ClearScreen();

        _renderer->Render();
        EventBus::GetInstance()->DispatchEvents();

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

void Engine::SetTargetFps(float targetFps)
{
    _targetFps = targetFps;
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
