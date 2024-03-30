#include "../include/Renderer.h"

void Renderer::AddObject(const GameObject *sprite)
{
    _objects.push_back(sprite);
}

void Renderer::RemoveObject(const GameObject *sprite)
{
    std::remove(_objects.begin(), _objects.end(), sprite);
}

void Renderer::Render() const
{
    for (const auto& object : _objects)
        object->Draw();
}