#ifndef INC_2DSPARK_RENDERER_H
#define INC_2DSPARK_RENDERER_H

#include <vector>
#include "GameObject.h"

class Renderer
{
public:
    void AddSprite(const GameObject* sprite);
    void RemoveSprite(const GameObject* sprite);
    void Render() const;
private:
    std::vector<const GameObject*> _objects;
};

#endif //INC_2DSPARK_RENDERER_H
