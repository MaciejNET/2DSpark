#include "../../include/Primitives/TriangleObject.h"
#include <cmath>

void TriangleObject::Draw() const
{
    const int num_vertices = 3;

    // Wierzchołki trójkąta
    float vertices[num_vertices * 2] = {
        _x1.GetX(), _x1.GetY(),
        _x2.GetX(), _x2.GetY(),
        _x3.GetX(), _x3.GetY()
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
    if (_filled)
    {
        glDrawArrays(GL_TRIANGLE_FAN, 0, 5);
    }
    else
    {
        glLineWidth(_thickness);
        glDrawArrays(GL_LINE_LOOP, 0, 5);
    }
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_LOOP, 0, num_vertices);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void TriangleObject::Translate(float x, float y)
{
    _x1.SetX(_x1.GetXPixels() + x);
    _x1.SetY(_x1.GetYPixels() + y);
    _x2.SetX(_x2.GetXPixels() + x);
    _x2.SetY(_x2.GetYPixels() + y);
    _x3.SetX(_x3.GetXPixels() + x);
    _x3.SetY(_x3.GetYPixels() + y);
}

void TriangleObject::Rotate(float angle)
{
    float x1 = _x1.GetXPixels();
    float y1 = _x1.GetYPixels();
    float x2 = _x2.GetXPixels();
    float y2 = _x2.GetYPixels();
    float x3 = _x3.GetXPixels();
    float y3 = _x3.GetYPixels();

    float x1Prime = x1 * cos(angle) - y1 * sin(angle);
    float y1Prime = x1 * sin(angle) + y1 * cos(angle);
    float x2Prime = x2 * cos(angle) - y2 * sin(angle);
    float y2Prime = x2 * sin(angle) + y2 * cos(angle);
    float x3Prime = x3 * cos(angle) - y3 * sin(angle);
    float y3Prime = x3 * sin(angle) + y3 * cos(angle);

    _x1.SetX(x1Prime);
    _x1.SetY(y1Prime);
    _x2.SetX(x2Prime);
    _x2.SetY(y2Prime);
    _x3.SetX(x3Prime);
    _x3.SetY(y3Prime);
}

void TriangleObject::Scale(float x, float y)
{
    _x1.SetX(_x1.GetXPixels() * x);
    _x1.SetY(_x1.GetYPixels() * y);
    _x2.SetX(_x2.GetXPixels() * x);
    _x2.SetY(_x2.GetYPixels() * y);
    _x3.SetX(_x3.GetXPixels() * x);
    _x3.SetY(_x3.GetYPixels() * y);
}