#include "../include/ColorObject.h"
#include <iostream>

ColorObject::ColorObject(float r, float g, float b) : _r(r), _g(g), _b(b) {}
ColorObject::ColorObject() : _r(1.0f), _g(1.0f), _b(1.0f) {}
void ColorObject::SetColor(float r, float g, float b)
{
	_r = r;
	_g = g;
	_b = b;
}

void ColorObject::CompileShaders() {
    _vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char* vertexShaderSource = _vertexShaderSource.c_str();
    glShaderSource(_vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(_vertexShader);

    _fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragmentShaderSource = _fragmentShaderSource.c_str();
    glShaderSource(_fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(_fragmentShader);

    _shaderProgram = glCreateProgram();
    glAttachShader(_shaderProgram, _vertexShader);
    glAttachShader(_shaderProgram, _fragmentShader);
    glLinkProgram(_shaderProgram);
    glUseProgram(_shaderProgram);
}
