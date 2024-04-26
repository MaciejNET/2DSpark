#ifndef INC_2DSPARK_FOODITEM_H
#define INC_2DSPARK_FOODITEM_H

#include "../Primitives/RectangleObject.h"
#include <cstdlib>

class FoodItem : public RectangleObject 
{
public:
    FoodItem(float screenWidth, float screenHeight);
    void Respawn(float screenWidth, float screenHeight);
    void Update(float deltaTime) override;

private:
    float _screenWidth;
    float _screenHeight;
};

#endif // INC_2DSPARK_FOODITEM_H
