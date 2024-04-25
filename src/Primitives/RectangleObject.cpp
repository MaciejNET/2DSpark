#include "../../include/Primitives/RectangleObject.h"

void RectangleObject::Draw() const
{
	float vertices[] =
	{
		_top.GetX(), _top.GetY(),
		_bottom.GetX(), _top.GetY(),
		_bottom.GetX(), _bottom.GetY(),
		_top.GetX(), _bottom.GetY(),
        _top.GetX(), _top.GetY()
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

void RectangleObject::Translate(float x, float y)
{
    _top.SetX(_top.GetXPixels() + x);
    _top.SetY(_top.GetYPixels() + y);
    _bottom.SetX(_bottom.GetXPixels() + x);
    _bottom.SetY(_bottom.GetYPixels() + y);
}

void RectangleObject::Rotate(float angle)
{
    float x1 = _top.GetXPixels();
    float y1 = _top.GetYPixels();
    float x2 = _bottom.GetXPixels();
    float y2 = _bottom.GetYPixels();

    float x1Prime = x1 * cos(angle) - y1 * sin(angle);
    float y1Prime = x1 * sin(angle) + y1 * cos(angle);
    float x2Prime = x2 * cos(angle) - y2 * sin(angle);
    float y2Prime = x2 * sin(angle) + y2 * cos(angle);

    _top.SetX(x1Prime);
    _top.SetY(y1Prime);
    _bottom.SetX(x2Prime);
    _bottom.SetY(y2Prime);
}

void RectangleObject::Scale(float x, float y)
{
    _top.SetX(_top.GetXPixels() * x);
    _top.SetY(_top.GetYPixels() * y);
    _bottom.SetX(_bottom.GetXPixels() * x);
    _bottom.SetY(_bottom.GetYPixels() * y);
}
