#include <iostream>
#include <memory>

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

class Widget : public EventHandler {
protected:
    Widget(Widget*, Event = Event::kNoEvent);
};

Widget::Widget(Widget* parent, Event t) : EventHandler(parent, t) {
}

class Button : public Widget {
public:
    Button(Widget*, Event = Event::kNoEvent);
    virtual void HandleEvent(Event) override;
};

Button::Button(Widget* h, Event t) : Widget(h, t) {
}

void Button::HandleEvent(Event evt) {
    if (CanHandle(evt)) {
        std::cout << "Handled by Button" << std::endl;
    } else {
        EventHandler::HandleEvent(evt);
    }
}

class Dialog : public Widget {
public:
    Dialog(EventHandler*, Event = Event::kNoEvent);
    virtual void HandleEvent(Event) override;
};

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

class Application : public EventHandler {
public:
    Application(Event t);
    virtual void HandleEvent(Event) override;
};

Application::Application(Event t) : EventHandler(nullptr, t) {
}

void Application::HandleEvent(Event evt) {
    if (CanHandle(evt)) {
        std::cout << "Handled by Application" << std::endl;
    } else {
        EventHandler::HandleEvent(evt);
    }
}

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
