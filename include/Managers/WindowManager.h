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

/**
 * Klasa zarządzająca oknem
 */
class WindowManager
{
public:
    static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
    void UpdateViewport(int width, int height);
    WindowManager(int width, int height, const char* title);
    ~WindowManager();

    /**
     * Metoda inicjalizująca okno
     * @param width - szerokość okna
     * @param height - wysokość okna
     * @param title - tytuł okna
     */
    void Init(int width, int height, const char* title);

    /**
     * Metoda zamykająca okno
     */
    void Cleanup();

    /**
     * Metoda zwracająca wskaźnik na okno
     * @return wskaźnik na okno
     */
    GLFWwindow* GetWindow() const;

    /**
     * Metoda ustawiająca rozdzielczość
     * @param width
     * @param height
     */
    void SetResolution(int width, int height);

    /**
     * Metoda ustawia pełny ekran
     */
    void ToggleFullscreen();

    /**
     * Metoda ustawia okno na tryb okienkowy
     */
    void ToggleWindowed();

    /**
     * Metoda czyści ekran
     */
    void ClearScreen();

    /**
     * Metoda ustawia kolor czyszczenia ekranu
     * @param r - czerwony
     * @param g - zielony
     * @param b - niebieski
     * @param a - alfa
     */
    void SetClearColor(float r, float g, float b, float a);

private:
    std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> _window;
    std::vector<Resolution> resolutions;
    int currentResolutionIndex;
    bool _isFullscreen;
    float _clearColor[4];
};

#endif
