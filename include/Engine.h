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

/**
 * Klasa odpowiedzialna za tworzenie silnika i zarządzaniem nim
 */
class Engine 
{
public:
    /**
     * Konstruktor tworzący silnik bez ograniczenia w generowanej liczbie fps
     * @param width - szerokość okna
     * @param height - wysokość okna
     * @param title - nazwa okna
     */
    Engine(int width, int height, const char* title);

    /**
     * Konstruktor tworzący klasę z ograniczeniem w generowanej liczbie fps
     * @param width - szerokość okna
     * @param height - wysokość okna
     * @param title - nazwa okna
     * @param targetFps - maksymalna liczba fps
     */
    Engine(int width, int height, const char* title, float targetFps);
    ~Engine();

    /**
     * Metoda do uruchamiania silnika
     */
    void Run();

    /**
     * Ustawia kolor czyszczenia obrazu
     * @param r
     * @param g
     * @param b
     * @param alpha
     */
    void SetClearColor(float r, float g, float b, float alpha = 1.0f);

    /**
     * Metoda pobierająca renderer
     * @return rederer
     */
    Renderer* GetRenderer() const;

    /**
     * Metoda pobierająca manager wejść
     * @return manager wejść
     */
    InputManager* GetInputManager() const;

    /**
     * Metoda pobierająca manager okien
     * @return manager okien
     */
    WindowManager* GetWindowManager() const;

    /**
     * Metoda ustawia maksymalną liczbę renderowanych klatek na sekundę
     * @param targetFps
     */
    void SetTargetFps(float targetFps);
private:
    /**
     * Metoda służąca do inicjalizacji silnika
     */
    void Init();

    /**
     * Metoda służąca do czyszczenia silnika
     */
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
