#include "../../include/Primitives/PointObject.h"

void PointObject::Draw() const
{
    float vertex[] = 
    { 
        _x.GetX(), _y.GetY()
    };

    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

    glBindVertexArray(VAO);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glUseProgram(GetShaderProgram());

    glUniform4f(glGetUniformLocation(GetShaderProgram(), "color"), GetR(), GetG(), GetB(), 1.0f);
    glBindVertexArray(VAO);
    glDrawArrays(GL_POINTS, 0, 1);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void PointObject::Translate(float x, float y)
{
    _x.SetX(_x.GetX() + x);
    _y.SetY(_y.GetY() + y);
}

void PointObject::Rotate(float angle)
{
    // Do nothing
}

void PointObject::Scale(float x, float y)
{
    // Do nothing
}