#include "../../include/Primitives/TriangleObject.h"
#include <cmath>

void TriangleObject::Draw() const {
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

    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_LOOP, 0, num_vertices);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}