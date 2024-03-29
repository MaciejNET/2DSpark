#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <GLFW/glfw3.h>

class InputManager {
public:
    InputManager();
    void Update(GLFWwindow* window);
    bool KeyPressed(int key);
    bool KeyReleased(int key);
    bool MouseButtonPressed(int button);
    bool MouseButtonReleased(int button);
    double GetMouseX() const;
    double GetMouseY() const;

private:
    bool _keys[512];
    bool _prevKeys[512];
    bool _mouseButtons[8];
    bool _prevMouseButtons[8];
    double _mouseX, _mouseY;
};

#endif // INPUTMANAGER_H
