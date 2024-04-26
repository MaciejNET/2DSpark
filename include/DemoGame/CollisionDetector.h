#ifndef INC_2DSPARK_COLLISIONDETECTOR_H
#define INC_2DSPARK_COLLISIONDETECTOR_H

#include "../DemoGame/SnakeHead.h"
#include "../DemoGame/FoodItem.h"


class CollisionDetector {
public:
    CollisionDetector();
    ~CollisionDetector();

    bool CheckCollision(const SnakeHead& snakeHead, const FoodItem& foodItem) const;
};

#endif // COLLISION_DETECTOR_H
