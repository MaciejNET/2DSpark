#ifndef INC_2DSPARK_EVENT_H
#define INC_2DSPARK_EVENT_H

#include <functional>

enum class EventType
{
    None = 0
};

class Event
{
public:
    Event();
    virtual ~Event() = default;
    virtual EventType GetType() const = 0;
public:
    bool Handled = false;
};

template<typename T>
using EventHandler = std::function<bool(T&)>;

class EventDispatcher
{
public:
    EventDispatcher(Event& event) : _event(event) {};
    template<typename T>
    void Dispatch(EventHandler<T> handler)
    {
        if (_event.GetType() == T::GetStaticType())
        {
            _event.Handled = handler(*(T*)&_event);
        }
    }
private:
    Event& _event;
};

#endif //INC_2DSPARK_EVENT_H
