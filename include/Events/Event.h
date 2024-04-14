#ifndef INC_2DSPARK_EVENT_H
#define INC_2DSPARK_EVENT_H

#include <functional>

enum class EventType
{
    None = 0,
    KeyPressed,
    MouseMoved
};

class Event
{
public:
    Event() = default;
    virtual ~Event() = default;
    virtual const EventType GetType() const = 0;
};

#endif //INC_2DSPARK_EVENT_H
