#include "../../include/Primitives/LineObject.h"

void LineObject::Draw() const
{
    float vertices[] = 
    {
            _start.GetX(), _start.GetY(),
            _end.GetX(), _end.GetY()
    };

    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(VAO);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glUseProgram(GetShaderProgram());

    glUniform4f(glGetUniformLocation(GetShaderProgram(), "color"), GetR(), GetG(), GetB(), 1.0f);
    glLineWidth(_thickness);
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINES, 0, 2);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void LineObject::Translate(float x, float y)
{
    _start.SetX(_start.GetXPixels() + x);
    _start.SetY(_start.GetYPixels() + y);
    _end.SetX(_end.GetXPixels() + x);
    _end.SetY(_end.GetYPixels() + y);
}

void LineObject::Rotate(float angle)
{
    float x1 = _start.GetXPixels();
    float y1 = _start.GetYPixels();
    float x2 = _end.GetXPixels();
    float y2 = _end.GetYPixels();

    float x1Prime = x1 * cos(angle) - y1 * sin(angle);
    float y1Prime = x1 * sin(angle) + y1 * cos(angle);
    float x2Prime = x2 * cos(angle) - y2 * sin(angle);
    float y2Prime = x2 * sin(angle) + y2 * cos(angle);

    _start.SetX(x1Prime);
    _start.SetY(y1Prime);
    _end.SetX(x2Prime);
    _end.SetY(y2Prime);
}

void LineObject::Scale(float x, float y)
{
    _start.SetX(_start.GetXPixels() * x);
    _start.SetY(_start.GetYPixels() * y);
    _end.SetX(_end.GetXPixels() * x);
    _end.SetY(_end.GetYPixels() * y);
}