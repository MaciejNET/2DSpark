#include "../../include/Events/EventBus.h"

std::mutex EventBus::_mutex;
EventBus* EventBus::_instance {nullptr};

EventBus* EventBus::GetInstance()
{
    std::lock_guard<std::mutex> lock(_mutex);
    if (_instance == nullptr)
        _instance = new EventBus();

    return _instance;
}

//template<typename T, typename>
//void EventBus::Subscribe(std::function<void(T&)> func)
//{
//    _handlers[T().GetType()].push_back([func](Event& event) { func(static_cast<T&>(event)); });
//}

template<typename T, typename>
void EventBus::Unsubscribe()
{
    auto eventType = T().GetType();
    auto it = _handlers.find(eventType);
    if (it != _handlers.end())
        it->second.clear();
}

void EventBus::Publish(const std::shared_ptr<Event>& event)
{
    _events.push_back(event);
}

void EventBus::DispatchEvents()
{
    for (auto& event : _events)
        DispatchEvent(*event);

    _events.clear();
}

void EventBus::DispatchEvent(Event& event)
{
    auto eventType = event.GetType();
    for (auto& subscriber : _handlers[event.GetType()])
        subscriber(event);
}