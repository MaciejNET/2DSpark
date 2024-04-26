
#include "../../include/DemoGame/CollisionDetector.h"
#include "../../include/DemoGame/SnakeHead.h"
#include "../../include/DemoGame/CollisionDetectedEvent.h"
#include "../../include/Events/EventBus.h"
#include <iostream>

CollisionDetector::CollisionDetector(SnakeHead* snakeHead, FoodItem* foodItem)
    : _snakeHead(snakeHead), _foodItem(foodItem)
{
}

CollisionDetector::~CollisionDetector()
{
    delete _snakeHead;
    delete _foodItem;
}

void CollisionDetector::CheckCollision() const
{
    Point snakeHeadPos = _snakeHead->GetTop();
    Point foodItemPos = _foodItem->GetTop();

    float distance = sqrt(pow(snakeHeadPos.GetXPixels() - foodItemPos.GetXPixels(), 2) + pow(snakeHeadPos.GetYPixels() - foodItemPos.GetYPixels(), 2));

    float collisionThreshold = 10.0f;

    if (distance < collisionThreshold)
    {
        std::shared_ptr<Event> event = std::make_shared<CollisionDetectedEvent>();
        EventBus::GetInstance()->Publish(event);
    }
}
