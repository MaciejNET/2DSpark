#include "../include/Renderer.h"

void Renderer::AddSprite(const GameObject *sprite)
{
    _sprites.push_back(sprite);
}

void Renderer::RemoveSprite(const GameObject *sprite)
{
    std::remove(_sprites.begin(), _sprites.end(), sprite);
}

void Renderer::Render() const
{
    for (const auto& sprite : _sprites)
        sprite->Draw();
}