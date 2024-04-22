#include "../../include/Primitives/Point.h"
#include "glad/glad.h"

Point::Point(float x, float y)
{
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    float screenWidth = static_cast<float>(viewport[2]);
    float screenHeight = static_cast<float>(viewport[3]);

    _x = (x / screenWidth) * 2.0f - 1.0f;
    _y = 1.0f - (y / screenHeight) * 2.0f;
}

float Point::GetX() const
{
    return _x;
}

float Point::GetXPixels() const
{
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    float screenWidth = static_cast<float>(viewport[2]);

    return (1.0f + _x) * screenWidth / 2.0f;
}

float Point::GetY() const
{
    return _y;
}

float Point::GetYPixels() const
{
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    float screenHeight = static_cast<float>(viewport[3]);

    return (1.0f - _y) * screenHeight / 2.0f;
}

std::pair<float, float> Point::GetXY() const
{
    return std::make_pair(_x, _y);
}

std::pair<float, float> Point::GetXYPixels() const
{
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    float screenWidth = static_cast<float>(viewport[2]);
    float screenHeight = static_cast<float>(viewport[3]);

    return std::make_pair((1.0f + _x) * screenWidth / 2.0f, (1.0f - _y) * screenHeight / 2.0f);
}

void Point::SetX(float x)
{
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    float screenWidth = static_cast<float>(viewport[2]);

    _x = (x / screenWidth) * 2.0f - 1.0f;
}

void Point::SetY(float y)
{
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    float screenHeight = static_cast<float>(viewport[3]);

    _y = 1.0f - (y / screenHeight) * 2.0f;
}

void Point::SetXY(float x, float y)
{
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    float screenWidth = static_cast<float>(viewport[2]);
    float screenHeight = static_cast<float>(viewport[3]);

    _x = (x / screenWidth) * 2.0f - 1.0f;
    _y = 1.0f - (y / screenHeight) * 2.0f;
}