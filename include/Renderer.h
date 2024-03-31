#ifndef INC_2DSPARK_RENDERER_H
#define INC_2DSPARK_RENDERER_H

#include <vector>
#include "GameObject.h"

class Renderer
{
public:
    void AddObject(const GameObject* object);
    void RemoveObject(const GameObject* object);
    void Render() const;
    void ClearObjects();
private:
    std::vector<const GameObject*> _objects;
};

#endif //INC_2DSPARK_RENDERER_H
