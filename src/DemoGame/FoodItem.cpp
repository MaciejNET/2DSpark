#include "../../include/DemoGame/FoodItem.h"
#include <cstdlib>

#include "../../include/Events/EventBus.h"
#include "../../include/DemoGame/CollisionDetectedEvent.h"

FoodItem::FoodItem(float screenWidth, float screenHeight)
    : RectangleObject(
        Point(rand() % (int)(screenWidth - 10), rand() % (int)(screenHeight - 10)),
        Point(0, 0),
        1.0f, 0.0f, 0.0f, true, 1.0f) 
{
    _screenWidth = screenWidth;
    _screenHeight = screenHeight;
    Respawn(_screenWidth, _screenHeight);
    EventBus::GetInstance()->Subscribe<CollisionDetectedEvent>([this](const CollisionDetectedEvent& event)
    {
        Respawn(_screenWidth, _screenHeight);
    });
}

void FoodItem::Respawn(float screenWidth, float screenHeight) 
{
    int newX = rand() % (int)(screenWidth - 10);
    int newY = rand() % (int)(screenHeight - 10);
    Point newTop(newX, newY);
    Point newBottom(newX + 10, newY + 10);
    SetTop(newTop);
    SetBottom(newBottom);
}

void FoodItem::Update(float deltaTime) 
{
}