#ifndef INC_2DSPARK_RECTANGLEOBJECT_H
#define INC_2DSPARK_RECTANGLEOBJECT_H

#include "ColorObject.h"
#include "Point.h"

class RectangleObject : public ColorObject
{
public:
	RectangleObject(const Point& top, const Point& bottom) : _top(top), _bottom(bottom) {};
	RectangleObject(const Point& top, const Point& bottom, const float r, const float g, const float b) : _top(top), _bottom(bottom), ColorObject(r, g, b) {};
	void Draw() const override;
private:
	Point _top;
	Point _bottom;
};

#endif //INC_2DSPARK_RECTANGLEOBJECT_H