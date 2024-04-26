
#include "../../include/DemoGame/CollisionDetector.h"
#include "../../include/DemoGame/SnakeHead.h"
#include <iostream>

CollisionDetector::CollisionDetector() {}

CollisionDetector::~CollisionDetector() {}

bool CollisionDetector::CheckCollision(const SnakeHead& snakeHead, const FoodItem& foodItem) const {
    Point snakeHeadPos = snakeHead.GetTop();
    Point foodItemPos = foodItem.GetTop();

    float distance = sqrt(pow(snakeHeadPos.GetX() - foodItemPos.GetX(), 2) + pow(snakeHeadPos.GetY() - foodItemPos.GetY(), 2));

    float collisionThreshold = 10.0f;

    return distance < collisionThreshold;
}
