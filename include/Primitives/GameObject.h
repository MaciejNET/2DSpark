#ifndef INC_2DSPARK_GAMEOBJECT_H
#define INC_2DSPARK_GAMEOBJECT_H

class GameObject
{
public:
    GameObject() = default;
    virtual ~GameObject() = default;
    virtual void Draw() const = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Translate(float x, float y) = 0;
    virtual void Rotate(float angle) = 0;
    virtual void Scale(float x, float y) = 0;
};

#endif //INC_2DSPARK_GAMEOBJECT_H
