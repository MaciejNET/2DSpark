#include "../include/Engine.h"
#include "../include/Events/EventBus.h"

Engine::Engine(int width, int height, const char* title)
    : _width(width), _height(height), _title(title), _windowManager(std::make_unique<WindowManager>(width, height, title)) 
{
    Init();
}

Engine::Engine(int width, int height, const char* title, float targetFps)
    : _width(width), _height(height), _title(title), _targetFps(targetFps), _windowManager(std::make_unique<WindowManager>(width, height, title)) 
{
    Init();
}

Engine::~Engine() 
{
    CleanUp();
}

void Engine::Init() 
{
    _window = _windowManager->GetWindow();
    if (!_window) {
        std::cerr << "Failed to retrieve window from WindowManager\n";
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(_window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
    {
        std::cerr << "Failed to initialize GLAD\n";
        exit(EXIT_FAILURE);
    }

    glfwSetWindowUserPointer(_window, _windowManager.get());
    glfwSetFramebufferSizeCallback(_window, WindowManager::FramebufferSizeCallback);

    _renderer = std::make_unique<Renderer>();
    _inputManager = std::make_unique<InputManager>();

    SetClearColor(0.0f, 0.0f, 0.0f);
}

void Engine::Run() 
{
    float frameTimeTarget = 0.0f;
    float nextFrameTime = 0.0f;

    while (!glfwWindowShouldClose(_window)) 
    {
        try {
            auto currentTime = static_cast<float>(glfwGetTime());

            if (_targetFps > 0.0f) {
                frameTimeTarget = 1.0f / _targetFps;
                while (currentTime < nextFrameTime) {
                    currentTime = static_cast<float>(glfwGetTime());
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

            _windowManager->ClearScreen();
            _renderer->Render(_deltaTime);
            EventBus::GetInstance()->DispatchEvents();

            glfwSwapBuffers(_window);
            glfwPollEvents();
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            exit(EXIT_FAILURE);
        }
    }
}

void Engine::SetClearColor(float r, float g, float b, float alpha) 
{
    _clearColor[0] = r;
    _clearColor[1] = g;
    _clearColor[2] = b;
    _clearColor[3] = alpha;
}

Renderer* Engine::GetRenderer() const 
{
    return _renderer.get();
}

InputManager* Engine::GetInputManager() const 
{
    return _inputManager.get();
}

WindowManager* Engine::GetWindowManager() const 
{
    return _windowManager.get();
}

void Engine::SetTargetFps(float targetFps) 
{
    _targetFps = targetFps;
}

void Engine::CleanUp() 
{
    glfwTerminate();
}
