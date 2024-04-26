#ifndef INC_2DSPARK_COLLISIONDETECTOR_H
#define INC_2DSPARK_COLLISIONDETECTOR_H

#include "../DemoGame/SnakeHead.h"
#include "../DemoGame/FoodItem.h"


class CollisionDetector {
public:
    CollisionDetector(SnakeHead *snakeHead, FoodItem *foodItem);
    ~CollisionDetector();

    void CheckCollision() const;

private:
    SnakeHead *_snakeHead;
    FoodItem *_foodItem;
};

#endif // COLLISION_DETECTOR_H
