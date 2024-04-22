#include "../../include/Managers/InputManager.h"
#include "../../include/Events/EventBus.h"
#include "../../include/Events/KeyPressedEvent.h"
#include "../../include/Events/MouseMovedEvent.h"
#include "GLFW/glfw3.h"

InputManager::InputManager() {
    for (int i = 0; i < 512; i++) {
        _keys[i] = false;
        _prevKeys[i] = false;
        _keyPressTime[i] = 0.0;
    }
    for (int i = 0; i < 8; i++) {
        _mouseButtons[i] = false;
        _prevMouseButtons[i] = false;
    }
    _mouseX = 0.0;
    _mouseY = 0.0;
}

bool InputManager::KeyPressed(int key) {
    return _keys[key] && !_prevKeys[key];
}

bool InputManager::KeyReleased(int key) {
    return !_keys[key] && _prevKeys[key];
}

bool InputManager::MouseButtonPressed(int button) {
    return _mouseButtons[button] && !_prevMouseButtons[button];
}

bool InputManager::MouseButtonReleased(int button) {
    return !_mouseButtons[button] && _prevMouseButtons[button];
}

double InputManager::GetMouseX() const {
    return _mouseX;
}

double InputManager::GetMouseY() const {
    return _mouseY;
}

bool InputManager::KeyHeld(int key, double holdTimeThreshold) {
    // Check if the key is pressed
    if (!_keys[key])
        return false;

    // Check if the key has been pressed for long enough
    double currentTime = glfwGetTime();
    double holdDuration = currentTime - _keyPressTime[key];
    if (holdDuration >= holdTimeThreshold) {
        // If the key has been pressed for long enough, return true
        return true;
    }

    return false;
}

void InputManager::Update(GLFWwindow* window) {
    for (int i = 0; i < 512; i++) {
        _prevKeys[i] = _keys[i];
        _keys[i] = glfwGetKey(window, i);

        if (_keys[i] && !_prevKeys[i]) {
            _keyPressTime[i] = glfwGetTime();
        }

        // Check for KeyHeld event
        if (KeyHeld(i, 0.5)) { // Example hold time threshold (0.5 seconds)
            std::shared_ptr<Event> event = std::make_shared<KeyHeldEvent>(i);
            EventBus::GetInstance()->Publish(event);
        }
    }

    for (int i = 0; i < 8; i++) {
        _prevMouseButtons[i] = _mouseButtons[i];
        _mouseButtons[i] = glfwGetMouseButton(window, i);
    }

    double x, y;
    glfwGetCursorPos(window, &x, &y);
    _mouseX = x;
    _mouseY = y;

    std::shared_ptr<Event> event = std::make_shared<MouseMovedEvent>(_mouseX, _mouseY);
    EventBus::GetInstance()->Publish(event);
}