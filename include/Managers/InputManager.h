#ifndef INC_2DSPARK_INPUTMANAGER_H
#define INC_2DSPARK_INPUTMANAGER_H

#include "SPARK/spark.h"
#include <chrono>
#include <iostream>

class InputManager {
public:
    InputManager();
    void Update(GLFWwindow* window);
    bool KeyPressed(int key);
    bool KeyReleased(int key);
    bool KeyHeld(int key);
    bool KeyTriggered(int key);
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

#endif // INC_2DSPARK_INPUTMANAGER_H