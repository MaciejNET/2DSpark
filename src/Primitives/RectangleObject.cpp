#include "../../include/Primitives/RectangleObject.h"

void RectangleObject::Draw() const
{
	float vertices[] =
	{
		_top.GetX(), _top.GetY(), //gorny lewy naroznik
		_bottom.GetX(), _top.GetY(), //gorny prawy
		_bottom.GetX(), _bottom.GetY(), //dolny prawy
		_top.GetX(), _bottom.GetY(), //dolny lewy
        _top.GetX(), _top.GetY() //zamkniecie
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
    glDrawArrays(GL_LINE_LOOP, 0, 5);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}