#include "../../include/Primitives/CircleObject.h"
#include <cmath>

void CircleObject::Draw() const
{
    const int num_segments = 100;
    const float theta = 2.0f * 3.1415926f / float(num_segments);
    float c = cosf(theta);
    float s = sinf(theta);
    float t;

    float x = _radius;
    float y = 0;

    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, 2 * num_segments * sizeof(float), NULL, GL_STATIC_DRAW);
    float* vertices = (float*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
    if (vertices) 
    {
        for (int i = 0; i < num_segments; i++) 
        {
            vertices[i * 2] = x + _x.GetX();
            vertices[i * 2 + 1] = y + _y.GetY();
            t = x;
            x = c * x - s * y;
            y = s * t + c * y;
        }
        glUnmapBuffer(GL_ARRAY_BUFFER);
    }

    glBindVertexArray(VAO);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glUseProgram(GetShaderProgram());

    glUniform4f(glGetUniformLocation(GetShaderProgram(), "color"), GetR(), GetG(), GetB(), 1.0f);

    if (_thickness > 1.0f)
    {
        glLineWidth(_thickness);
    }

    if (_filled)
    {
        glDrawArrays(GL_TRIANGLE_FAN, 0, num_segments);
    }
    else
    {
        glDrawArrays(GL_LINE_LOOP, 0, num_segments);
    }
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_LOOP, 0, num_segments);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void CircleObject::Translate(float x, float y)
{
    _x.SetX(_x.GetXPixels() + x);
    _y.SetY(_y.GetYPixels() + y);
}

void CircleObject::Rotate(float angle)
{
    float x = _x.GetXPixels();
    float y = _y.GetYPixels();

    float xPrime = x * cos(angle) - y * sin(angle);
    float yPrime = x * sin(angle) + y * cos(angle);

    _x.SetX(xPrime);
    _y.SetY(yPrime);
}

void CircleObject::Scale(float x, float y)
{
    _radius *= x;
}
