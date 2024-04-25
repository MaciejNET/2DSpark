#ifndef INC_2DSPARK_EVENTBUS_H
#define INC_2DSPARK_EVENTBUS_H

#include <unordered_map>
#include <memory>
#include <mutex>
#include "Event.h"

/**
 * Klasa reprezentująca event bus
 */
class EventBus
{
public:
    /**
     * Metoda zwracająca instancję klasy EventBus
     */
    static EventBus* GetInstance();

    EventBus(const EventBus&) = delete;
    EventBus& operator=(const EventBus&) = delete;

    /**
     * Metoda subskrybująca zdarzenie
     * @tparam T - typ zdarzenia
     * @param func - funkcja obsługująca zdarzenie
     */
    template<typename T, typename = std::enable_if_t<std::is_base_of_v<Event, T>>>
    void Subscribe(std::function<void(T&)> func)
    {
        _handlers[T().GetType()].push_back([func](Event& event) { func(static_cast<T&>(event)); });
    }

    /**
     * Metoda służąca do odsubskrybowania zdarzenia
     * @tparam T - typ zdarzenia
     */
    template<typename T, typename = std::enable_if_t<std::is_base_of_v<Event, T>>>
    void Unsubscribe();

    /**
     * Metoda do publikacja zdarzenia
     * @param event - zdarzenie
     */
    void Publish(const std::shared_ptr<Event>& event);

    /**
     * Metoda do wywoływania funkcji obsługującyh zdarzenia
     */
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
