#ifndef INC_2DSPARK_EVENTBUS_H
#define INC_2DSPARK_EVENTBUS_H

#include <unordered_map>
#include <memory>
#include "Event.h"

class EventBus
{
public:
    static EventBus* GetInstance();

    EventBus(const EventBus&) = delete;
    EventBus& operator=(const EventBus&) = delete;

    template<typename T, typename = std::enable_if_t<std::is_base_of_v<Event, T>>>
    void Subscribe(std::function<void(T&)> func)
    {
        _handlers[T().GetType()].push_back([func](Event& event) { func(static_cast<T&>(event)); });
    }

    template<typename T, typename = std::enable_if_t<std::is_base_of_v<Event, T>>>
    void Unsubscribe();

    void Publish(const std::shared_ptr<Event>& event);
    void DispatchEvents();
private:
    EventBus() = default;
    ~EventBus() = default;
    void DispatchEvent(Event& event);

private:
    static EventBus* _instance;
    static std::mutex _mutex;

    std::unordered_map<EventType, std::vector<std::function<void(Event&)>>> _handlers;
    std::vector<std::shared_ptr<Event>> _events;
};

#endif //INC_2DSPARK_EVENTBUS_H
