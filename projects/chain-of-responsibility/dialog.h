#pragma once
#include "widget.h"

class Dialog : public Widget {
public:
    Dialog(EventHandler*, Event = Event::kNoEvent);
    virtual void HandleEvent(Event) override;
};
