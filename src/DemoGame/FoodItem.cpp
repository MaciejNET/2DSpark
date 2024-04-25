#include "../../include/DemoGame/FoodItem.h"
#include <cstdlib>

FoodItem::FoodItem(float screenWidth, float screenHeight)
    : RectangleObject(
        Point(rand() % (int)(screenWidth - 10), rand() % (int)(screenHeight - 10)),
        Point(0, 0),
        1.0f, 0.0f, 0.0f, true, 1.0f) 
{
    this->Respawn(screenWidth, screenHeight);
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
    // przysz³a logika dla potrzeb gry
}