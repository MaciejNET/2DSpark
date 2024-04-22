#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <memory>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

struct Resolution 
{
    int width;
    int height;
};

class WindowManager {
public:
    static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
    void UpdateViewport(int width, int height);
    WindowManager(int width, int height, const char* title);
    ~WindowManager();

    void Init(int width, int height, const char* title);
    void Cleanup();
    GLFWwindow* GetWindow() const;
    void SetResolution(int width, int height);
    void ToggleFullscreen();
    void ToggleWindowed();
    void ClearScreen();
    void SetClearColor(float r, float g, float b, float a);

private:
    std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> _window;
    std::vector<Resolution> resolutions;
    int currentResolutionIndex;
    bool _isFullscreen;
    float _clearColor[4];
};

#endif
