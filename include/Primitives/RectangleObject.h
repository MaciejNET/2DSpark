#ifndef INC_2DSPARK_RECTANGLEOBJECT_H
#define INC_2DSPARK_RECTANGLEOBJECT_H

#include "ColorObject.h"
#include "Point.h"

/**
 * Klasa reprezentująca prostokąt
 */
class RectangleObject : public ColorObject
{
public:
    RectangleObject(const Point& top, const Point& bottom, float r, float g, float b, bool filled, float thickness)
        : ColorObject(r, g, b, filled, thickness), _top(top), _bottom(bottom) {}

    void Draw() const override;
    void Update(float deltaTime) override {};
    void Translate(float x, float y) override;
    void Rotate(float angle) override;
    void Scale(float x, float y) override;

    const Point& GetTop() const { return _top; }
    void SetTop(const Point& top) { _top = top; }
    const Point& GetBottom() const { return _bottom; }
    void SetBottom(const Point& bottom) { _bottom = bottom; }

private:
    Point _top;
    Point _bottom;
};

#endif //INC_2DSPARK_RECTANGLEOBJECT_H
