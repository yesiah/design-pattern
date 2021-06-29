#include <iostream>
#include "application.h"

Application::Application(Event t) : EventHandler(nullptr, t) {
}

void Application::HandleEvent(Event evt) {
    if (CanHandle(evt)) {
        std::cout << "Handled by Application" << std::endl;
    } else {
        EventHandler::HandleEvent(evt);
    }
}
