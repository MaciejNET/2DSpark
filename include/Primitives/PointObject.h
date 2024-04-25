#ifndef INC_2DSPARK_POINTOBJECT_H
#define INC_2DSPARK_POINTOBJECT_H

#include "Point.h"
#include "ColorObject.h"

/**
 * Klasa reprezentująca punkt
 */
class PointObject : public ColorObject
{
public:
	PointObject(const Point& x, const Point& y) : _x(x), _y(y) {};
	PointObject(const Point& x, const Point& y, const float r, const float g, const float b, const float filled, const float thickness) : _x(x), _y(y), ColorObject(r, g, b, filled, thickness) {};
	void Draw() const override;
    void Update(float deltaTime) override {};
    void Translate(float x, float y) override;
    void Rotate(float angle) override;
    void Scale(float x, float y) override;
private:
	Point _x;
	Point _y;
};

#endif // !INC_2DSPARK_POINTOBJECT_H
