#ifndef INC_2DSPARK_TRIANGLEOBJECT_H
#define INC_2DSPARK_TRIANGLEOBJECT_H

#include "ColorObject.h"
#include "Point.h"

class TriangleObject : public ColorObject
{
public:
    TriangleObject(const Point& point1, const Point& point2, const Point& point3) : _point1(point1), _point2(point2), _point3(point3) {};
    TriangleObject(const Point& point1, const Point& point2, const Point& point3, const float r, const float g, const float b) : _point1(point1), _point2(point2), _point3(point3), ColorObject(r, g, b) {};
    void Draw() const override;
private:
    Point _point1;
    Point _point2;
    Point _point3;
};

#endif //INC_2DSPARK_TRIANGLEOBJECT_H
