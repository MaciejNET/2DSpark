#ifndef INC_2DSPARK_POINTOBJECT_H
#define INC_2DSPARK_POINTOBJECT_H

#include "Point.h"
#include "ColorObject.h"

class PointObject : public ColorObject
{
public:
	PointObject(const Point& x, const Point& y) : _x(x), _y(y) {};
	PointObject(const Point& x, const Point& y, const float r, const float g, const float b) : _x(x), _y(y), ColorObject(r, g, b) {};
	void Draw() const override;
private:
	Point _x;
	Point _y;
};

#endif // !INC_2DSPARK_POINTOBJECT_H
