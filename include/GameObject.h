#ifndef INC_2DSPARK_GAMEOBJECT_H
#define INC_2DSPARK_GAMEOBJECT_H

#include "Point.h"

class GameObject
{
public:
    GameObject(const Point& position) : _position(position) {};
    virtual void Draw() const = 0;
    virtual ~GameObject() = default;
private:
    Point _position;
};

#endif //INC_2DSPARK_GAMEOBJECT_H
