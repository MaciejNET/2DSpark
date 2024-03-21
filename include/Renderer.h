#ifndef INC_2DSPARK_RENDERER_H
#define INC_2DSPARK_RENDERER_H

#include <vector>
#include "Sprite.h"

class Renderer
{
public:
    void AddSprite(const Sprite* sprite);
    void RemoveSprite(const Sprite* sprite);
    void Render() const;
private:
    std::vector<const Sprite*> _sprites;
};

#endif //INC_2DSPARK_RENDERER_H
