#ifndef INC_2DSPARK_RENDERER_H
#define INC_2DSPARK_RENDERER_H

#include <vector>
#include "GameObject.h"

class Renderer
{
public:
    void AddObject(const GameObject* sprite);
    void RemoveObject(const GameObject* sprite);
    void Render() const;
private:
    std::vector<const GameObject*> _objects;
};

#endif //INC_2DSPARK_RENDERER_H
