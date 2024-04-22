#include "../../include/Primitives/ColorObject.h"


std::string ColorObject::ReadFile(const std::string& filePath)
{
    std::ifstream fileStream(filePath);
    if (!fileStream.is_open())
    {
        return "Error file reading";
    }

    std::stringstream buffer;
    buffer << fileStream.rdbuf();
    return buffer.str();
}
ColorObject::ColorObject(float r, float g, float b, bool filled, float thickness) : _r(r), _g(g), _b(b), _filled(filled), _thickness(thickness)
{
    CompileShaders();
}

ColorObject::ColorObject() : _r(1.0f), _g(1.0f), _b(1.0f), _filled(true), _thickness(1.0f)
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
void ColorObject::SetFilled(bool filled)
{
    _filled = filled;
    CompileShaders();
}

void ColorObject::SetThickness(float thickness)
{
    _thickness = thickness;
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
    glShaderSource(_vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(_vertexShader);

    _fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragmentShaderSource = _fragmentShaderSource.c_str();
    glShaderSource(_fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(_fragmentShader);

    _shaderProgram = glCreateProgram();
    glAttachShader(_shaderProgram, _vertexShader);
    glAttachShader(_shaderProgram, _fragmentShader);
    glLinkProgram(_shaderProgram);
    glUseProgram(_shaderProgram);

}