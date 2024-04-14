#ifndef INC_2DSPARK_GAMEOBJECT_H
#define INC_2DSPARK_GAMEOBJECT_H

class GameObject
{
public:
    GameObject() = default;
    virtual ~GameObject() = default;
    virtual void Draw() const = 0;
};

#endif //INC_2DSPARK_GAMEOBJECT_H
