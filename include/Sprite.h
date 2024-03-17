#ifndef INC_2DSPARK_SPRITE_H
#define INC_2DSPARK_SPRITE_H

#include "Point.h"

class Sprite
{
public:
    Sprite(const Point& position) : _position(position) {};
    virtual void Draw() const = 0;
    virtual ~Sprite() = default;
private:
    Point _position;
};

#endif //INC_2DSPARK_SPRITE_H
