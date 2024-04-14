#ifndef INC_2DSPARK_LINEOBJECT_H
#define INC_2DSPARK_LINEOBJECT_H

#include "ColorObject.h"
#include "Point.h"
#include "../Events/EventBus.h"
#include "../Events/KeyPressedEvent.h"
#include "../Events/MouseMovedEvent.h"

class LineObject : public ColorObject
{
public:
    LineObject(const Point& start, const Point& end) : _start(start), _end(end)
    {
    };

    LineObject(const Point& start, const Point& end, const float r, const float g, const float b) : ColorObject(r, g, b), _start(start), _end(end)
    {
    };
    void Draw() const override;

private:
    Point _start;
    Point _end;
};

#endif //INC_2DSPARK_LINEOBJECT_H
