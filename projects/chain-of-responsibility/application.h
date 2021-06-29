#pragma once
#include "event_handler.h"

class Application : public EventHandler {
public:
    Application(Event t);
    virtual void HandleEvent(Event) override;
};
