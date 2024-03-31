#include "../include/Renderer.h"

void Renderer::AddObject(const GameObject *object)
{
    _objects.push_back(object);
}

void Renderer::RemoveObject(const GameObject *object)
{
    _objects.erase(std::remove(_objects.begin(), _objects.end(), object), _objects.end());
}

void Renderer::Render() const
{
    for (const auto& object : _objects)
        object->Draw();
}

void Renderer::ClearObjects()
{
    for (const auto& object : _objects)
        delete object;

    _objects.clear();
}