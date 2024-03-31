#include "../include/ColorObject.h"

ColorObject::ColorObject(float r, float g, float b) : _r(r), _g(g), _b(b)
{
    CompileShaders();
}

ColorObject::ColorObject() : _r(1.0f), _g(1.0f), _b(1.0f)
{
    CompileShaders();
}

void ColorObject::SetColor(float r, float g, float b)
{
	_r = r;
	_g = g;
	_b = b;
    CompileShaders();
}

std::string ColorObject::GetVertexShaderSource() const
{
    return _vertexShaderSource;
}

std::string ColorObject::GetFragmentShaderSource() const
{
    return _fragmentShaderSource;
}

GLuint ColorObject::GetShaderProgram() const
{
    return _shaderProgram;
}

GLuint ColorObject::GetVertexShader() const
{
    return _vertexShader;
}

GLuint ColorObject::GetFragmentShader() const
{
    return _fragmentShader;
}

float ColorObject::GetR() const
{
    return _r;
}

float ColorObject::GetG() const
{
    return _g;
}

float ColorObject::GetB() const
{
    return _b;
}

void ColorObject::CompileShaders()
{
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
