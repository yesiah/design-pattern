#include <iostream>
#include "event_handler.h"

EventHandler::EventHandler(EventHandler* h, Event t) : successor(h), event(t) {
}

void EventHandler::SetHandler(EventHandler* h, Event t) {
    successor = h;
    event = t;
}

bool EventHandler::CanHandle(Event evt) {
    return event == evt;
}

void EventHandler::HandleEvent(Event evt) {
    if (successor != nullptr) {
        successor->HandleEvent(evt);
    } else {
        std::cout << "No more successor, event is left unhandled" << std::endl;
    }
}
