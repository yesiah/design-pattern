#pragma once
#include "widget.h"

class Button : public Widget {
public:
    Button(Widget*, Event = Event::kNoEvent);
    virtual void HandleEvent(Event) override;
};
