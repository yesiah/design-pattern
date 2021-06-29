#include <iostream>
#include "dialog.h"

Dialog::Dialog(EventHandler* h, Event t) : Widget(nullptr) {
    SetHandler(h, t);
}

void Dialog::HandleEvent(Event evt) {
    if (CanHandle(evt)) {
        std::cout << "Handled by Dialog" << std::endl;
    } else {
        EventHandler::HandleEvent(evt);
    }
}
