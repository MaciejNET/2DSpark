#ifndef INC_2DSPARK_COLLISIONDETECTED_H
#define INC_2DSPARK_COLLISIONDETECTED_H

#include "../Events/Event.h"

class CollisionDetectedEvent : public Event
{
public:
    CollisionDetectedEvent() = default;
    ~CollisionDetectedEvent() = default;

    const EventType GetType() const override { return EventType::CollisionDetected; };
};

#endif //INC_2DSPARK_COLLISIONDETECTED_H
