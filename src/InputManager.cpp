#include "../include/InputManager.h"
#include <GLFW/glfw3.h>

InputManager::InputManager() 
{
	for (int i = 0; i < 512; i++)
	{
		_keys[i] = false;
		_prevKeys[i] = false;
	}
	for (int i = 0; i < 8; i++)
	{
		_mouseButtons[i] = false;
		_prevMouseButtons[i] = false;
	}
	_mouseX = 0.0;
	_mouseY = 0.0;	
}

void InputManager::Update(GLFWwindow* window)
{
	for (int i = 0; i < 512; i++)
	{
		_prevKeys[i] = _keys[i];
		_keys[i] = glfwGetKey(window, i);
	}
	for (int i = 0; i < 8; i++)
	{
		_prevMouseButtons[i] = _mouseButtons[i];
		_mouseButtons[i] = glfwGetMouseButton(window, i);
	}
	
	double x, y;
	glfwGetCursorPos(window, &x, &y);
	_mouseX = x;
	_mouseY = y;
}

bool InputManager::KeyPressed(int key)
{
	return _keys[key] && !_prevKeys[key];
}
bool InputManager::KeyReleased(int key)
{
	return !_keys[key] && _prevKeys[key];
}
bool InputManager::MouseButtonPressed(int button)
{
	return _mouseButtons[button] && !_prevMouseButtons[button];
}
bool InputManager::MouseButtonReleased(int button)
{
	return !_mouseButtons[button] && _prevMouseButtons[button];
}
double InputManager::GetMouseX() const
{
	return _mouseX;
}
double InputManager::GetMouseY() const
{
	return _mouseY;
}