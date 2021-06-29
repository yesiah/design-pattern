#pragma once
#include "event_handler.h"

class Widget : public EventHandler {
protected:
    Widget(Widget*, Event = Event::kNoEvent);
};
