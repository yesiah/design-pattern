#include <iostream>
#include <memory>
#include "event_handler.h"
#include "button.h"
#include "dialog.h"
#include "application.h"

int main() {
    auto app = std::make_unique<Application>(Event::kPrint);
    auto dialog = std::make_unique<Dialog>(app.get(), Event::kShowHelp);
    auto button = std::make_unique<Button>(dialog.get(), Event::kShowHelp);

    std::cout << std::endl << "==== Show help on Button ====" << std::endl;
    button->HandleEvent(Event::kShowHelp);

    std::cout << std::endl << "==== Show help on Dialog ====" << std::endl;
    dialog->HandleEvent(Event::kShowHelp);

    std::cout << std::endl << "==== Show help Application ====" << std::endl;
    app->HandleEvent(Event::kShowHelp);

    std::cout << std::endl;

    std::cout << std::endl << "==== Print on Button ====" << std::endl;
    button->HandleEvent(Event::kPrint);

    std::cout << std::endl << "==== Print on Dialog ====" << std::endl;
    dialog->HandleEvent(Event::kPrint);

    std::cout << std::endl << "==== Print on Application ====" << std::endl;
    app->HandleEvent(Event::kPrint);
}
