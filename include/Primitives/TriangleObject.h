#ifndef INC_2DSPARK_TRIANGLEOBJECT_H
#define INC_2DSPARK_TRIANGLEOBJECT_H

#include "ColorObject.h"
#include "Point.h"

class TriangleObject : public ColorObject
{
public:
    TriangleObject(const Point& x1, const Point& x2, const Point& x3) : _x1(x1), _x2(x2), _x3(x3) {};
    TriangleObject(const Point& x1, const Point& x2, const Point& x3, const float r, const float g, const float b, const float filled, const float thickness) : _x1(x1), _x2(x2), _x3(x3), ColorObject(r, g, b, filled, thickness) {};
    void Draw() const override;
    void Translate(float x, float y) override;
    void Rotate(float angle) override;
    void Scale(float x, float y) override;
private:
    Point _x1;
    Point _x2;
    Point _x3;
};

#endif //INC_2DSPARK_TRIANGLEOBJECT_H
