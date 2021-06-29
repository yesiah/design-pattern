#include <iostream>
#include <memory>

typedef int Topic;
constexpr Topic NO_HELP_TOPIC = -1;
constexpr Topic PRINT_TOPIC = 1;
constexpr Topic PAPER_ORIENTATION_TOPIC = 2;
constexpr Topic APPLICATION_TOPIC = 3;

class HelpHandler {
private:
    HelpHandler* successor;
    Topic topic;
public:
    HelpHandler(HelpHandler* = nullptr, Topic = NO_HELP_TOPIC);

    virtual bool HasHelp();
    virtual void SetHandler(HelpHandler*, Topic);
    virtual void HandleHelp();
};

HelpHandler::HelpHandler(HelpHandler* h, Topic t) : successor(h), topic(t) {
}

void HelpHandler::SetHandler(HelpHandler* h, Topic t) {
    successor = h;
    topic = t;
}

bool HelpHandler::HasHelp() {
    return topic != NO_HELP_TOPIC;
}

void HelpHandler::HandleHelp() {
    if (successor != nullptr) {
        successor->HandleHelp();
    }
}

class Widget : public HelpHandler {
private:
    Widget* parent;
protected:
    Widget(Widget*, Topic = NO_HELP_TOPIC);
};

Widget::Widget(Widget* parent, Topic t) : HelpHandler(parent, t) {
    this->parent = parent;
}

class Button : public Widget {
public:
    Button(Widget*, Topic = NO_HELP_TOPIC);
    virtual void HandleHelp() override;
};

Button::Button(Widget* h, Topic t) : Widget(h, t) {
}

void Button::HandleHelp() {
    if (HasHelp()) {
        std::cout << "Help on Button" << std::endl;
    } else {
        HelpHandler::HandleHelp();
    }
}

class Dialog : public Widget {
public:
    Dialog(HelpHandler*, Topic = NO_HELP_TOPIC);
    virtual void HandleHelp() override;
};

Dialog::Dialog(HelpHandler* h, Topic t) : Widget(nullptr) {
    SetHandler(h, t);
}

void Dialog::HandleHelp() {
    if (HasHelp()) {
        std::cout << "Help on the Dialog" << std::endl;
    } else {
        HelpHandler::HandleHelp();
    }
}

class Application : public HelpHandler {
public:
    Application(Topic t);
    virtual void HandleHelp() override;
};

Application::Application(Topic t) : HelpHandler(nullptr, t) {
}

void Application::HandleHelp() {
    std::cout << "Help on the Application" << std::endl;
}

int main() {
    auto app = std::make_unique<Application>(APPLICATION_TOPIC);
    auto dialog = std::make_unique<Dialog>(app.get(), PRINT_TOPIC);
    auto button = std::make_unique<Button>(dialog.get(), PAPER_ORIENTATION_TOPIC);

    std::cout << std::endl << "==== Invoke Button ====" << std::endl;
    button->HandleHelp();

    std::cout << std::endl << "==== Invoke Dialog ====" << std::endl;
    dialog->HandleHelp();

    std::cout << std::endl << "==== Invoke Application ====" << std::endl;
    app->HandleHelp();
}
