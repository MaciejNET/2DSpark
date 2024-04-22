#include "../../include/Managers/WindowManager.h"
#include <iostream>

WindowManager::WindowManager(int width, int height, const char* title)
    : _isFullscreen(false), _window(nullptr, glfwDestroyWindow) 
{
    resolutions = { {1024, 768}, {1280, 960}, {1920, 1080} };
    currentResolutionIndex = 0;
    std::fill_n(_clearColor, 4, 0.0f);
    Init(width, height, title);
}

GLFWwindow* WindowManager::GetWindow() const 
{
    return _window.get();
}

void WindowManager::UpdateViewport(int width, int height) 
{
    float targetAspectRatio = 800.0f / 600.0f;
    int viewWidth = width;
    int viewHeight = static_cast<int>((float)width / targetAspectRatio);

    if (viewHeight > height) 
    {
        viewHeight = height;
        viewWidth = static_cast<int>((float)height * targetAspectRatio);
    }

    int xOffset = (width - viewWidth) / 2;
    int yOffset = (height - viewHeight) / 2;

    glViewport(xOffset, yOffset, viewWidth, viewHeight);
}

WindowManager::~WindowManager()
{
    Cleanup();
}

void WindowManager::Init(int width, int height, const char* title) 
{
    if (!glfwInit()) 
    {
        std::cerr << "Failed to initialize GLFW\n";
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) 
    {
        glfwTerminate();
        std::cerr << "Failed to create GLFW window\n";
        exit(EXIT_FAILURE);
    }
    _window.reset(window);

    glfwMakeContextCurrent(_window.get());
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
    {
        std::cerr << "Failed to initialize GLAD\n";
        exit(EXIT_FAILURE);
    }

    glfwSetFramebufferSizeCallback(_window.get(), FramebufferSizeCallback);
}

void WindowManager::FramebufferSizeCallback(GLFWwindow* window, int width, int height) 
{
    glViewport(0, 0, width, height);
    auto* manager = static_cast<WindowManager*>(glfwGetWindowUserPointer(window));
    if (manager) 
    {
        manager->UpdateViewport(width, height);
    }
}

void WindowManager::Cleanup() 
{
    glfwTerminate();
}

void WindowManager::SetResolution(int width, int height) 
{
    if (_window) 
    {
        glfwSetWindowSize(_window.get(), width, height);
    }
}

void WindowManager::ToggleFullscreen() 
{
    _isFullscreen = !_isFullscreen;
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    if (_isFullscreen) 
    {
        glfwSetWindowMonitor(_window.get(), monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
        UpdateViewport(mode->width, mode->height);
    }
    else 
    {
        auto res = resolutions[currentResolutionIndex];
        glfwSetWindowMonitor(_window.get(), nullptr, 100, 100, res.width, res.height, GLFW_DONT_CARE);
        UpdateViewport(res.width, res.height);
    }
}

void WindowManager::ToggleWindowed() 
{
    if (!_isFullscreen) return;
    _isFullscreen = false;
    auto res = resolutions[currentResolutionIndex];
    glfwSetWindowMonitor(_window.get(), nullptr, 100, 100, res.width, res.height, GLFW_DONT_CARE);
}

void WindowManager::ClearScreen() 
{
    glClearColor(_clearColor[0], _clearColor[1], _clearColor[2], _clearColor[3]);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
