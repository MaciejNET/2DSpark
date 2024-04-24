#ifndef INC_2DSPARK_SNAKEHEAD_H
#define INC_2DSPARK_SNAKEHEAD_H

#include "../Primitives/RectangleObject.h"
#include "../Events/KeyHeldEvent.h"
#include "../Events/KeyReleasedEvent.h"
#include "../Events/KeyPressedEvent.h"
#include "../Events/EventBus.h"

class SnakeHead : public RectangleObject
{
public:
    SnakeHead(const int screenWidth, const int screenHeight) : RectangleObject(Point((float)screenWidth / 2, (float)screenHeight / 2), Point((float)screenWidth / 2 + 10, (float)screenHeight / 2 + 10), 0.0f, 1.0f, 0.0f, 1.0f, 1.0f)
    {
        EventBus::GetInstance()->Subscribe<KeyHeldEvent>([this](const KeyHeldEvent& event)
        {
            _key = event.GetKey();
        });

        EventBus::GetInstance()->Subscribe<KeyPressedEvent>([this](const KeyPressedEvent& event)
        {
            _key = event.GetKey();
            Move();
            _key = -1;
        });

        EventBus::GetInstance()->Subscribe<KeyReleasedEvent>([this](const KeyReleasedEvent& event)
        {
            _key = -1;
        });
    };

    void Update(float deltaTime) override;
private:
    void Move();

private:
     int _key = -1;
};

#endif //INC_2DSPARK_SNAKEHEAD_H
