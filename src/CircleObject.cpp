#include "../include/CircleObject.h"
#include <cmath>

void CircleObject::Draw() const {
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

    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_LOOP, 0, num_segments);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
