#include <iostream>
#include "button.h"

Button::Button(Widget* h, Event t) : Widget(h, t) {
}

void Button::HandleEvent(Event evt) {
    if (CanHandle(evt)) {
        std::cout << "Handled by Button" << std::endl;
    } else {
        EventHandler::HandleEvent(evt);
    }
}
