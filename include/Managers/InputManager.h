#ifndef INC_2DSPARK_INPUTMANAGER_H
#define INC_2DSPARK_INPUTMANAGER_H

#include "GLFW/glfw3.h"
#include "../Events/KeyHeldEvent.h"
#include <memory>

/**
 * Klasa zarządzająca wejściem
 */
class InputManager
{
public:
    /**
     * Konstruktor
     */
    InputManager();

    /**
     * Metoda aktualizująca stan wejścia
     * @param window
     */
    void Update(GLFWwindow* window);

    /**
     * Metoda zwracająca czy klawisz został wciśnięty
     * @param key - klawisz
     * @return czy klawisz został wciśnięty
     */
    bool KeyPressed(int key);

    /**
     * Metoda zwracająca czy klawisz jest wciśnięty
     * @param key - klawisz
     * @return czy klawisz jest wciśnięty
     */
    bool KeyHeld(int key);

    /**
     * Metoda zwracjąca czy klawisz został puszczony
     * @param key - klawisz
     * @return czy klawisz został puszczony
     */
    bool KeyReleased(int key);

    /**
     * Metoda zwracająca czy przycisk myszy został wciśnięty
     * @param button - przycisk myszy
     * @return czy przycisk myszy został wciśnięty
     */
    bool MouseButtonPressed(int button);

    /**
     * Metoda zwracająca czy przycisk myszy został puszczony
     * @param button - przycisk myszy
     * @return czy przycisk myszy został puszczony
     */
    bool MouseButtonReleased(int button);

    /**
     * Metoda zwraca współrzędną x myszy
     * @return współrzędna x myszy
     */
    double GetMouseX() const;

    /**
     * Metoda zwraca współrzędną y myszy
     * @return współrzędna y myszy
     */
    double GetMouseY() const;

private:
    bool _keys[512];
    bool _prevKeys[512];
    bool _mouseButtons[8];
    bool _prevMouseButtons[8];
    double _mouseX, _mouseY;
    double _keyPressTime[512];
    bool _isKeyHeld = false;
};

#endif // INC_2DSPARK_INPUTMANAGER_H
