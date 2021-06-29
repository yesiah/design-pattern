#pragma once
enum class Event {
    kNoEvent,
    kPrint,
    kShowHelp,
};

class EventHandler {
private:
    EventHandler* successor;
    Event event;

public:
    EventHandler(EventHandler* = nullptr, Event = Event::kNoEvent);

    virtual bool CanHandle(Event);
    virtual void SetHandler(EventHandler*, Event);
    virtual void HandleEvent(Event);
};
