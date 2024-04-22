#ifndef INC_2DSPARK_CIRCLEOBJECT_H
#define INC_2DSPARK_CIRCLEOBJECT_H

#include "ColorObject.h"
#include "Point.h"

class CircleObject : public ColorObject
{
public:
	CircleObject(const Point& x, const Point& y, const float& radius) : _x(x), _y(y), _radius(radius) {};
	CircleObject(const Point& x, const Point& y, const float& radius, const float r, const float g, const float b, const float filled, const float thickness) : ColorObject(r, g, b, filled, thickness), _x(x), _y(y), _radius(radius) {};
	void Draw() const override;
    void Translate(float x, float y) override;
    void Rotate(float angle) override;
    void Scale(float x, float y) override;
private:
	Point _x;
	Point _y;
	float _radius;
};

#endif // !INC_2DSPARK_CIRCLEOBJECT_H
