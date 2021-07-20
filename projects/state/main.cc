#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>

std::atomic<int> data;

void update_data() {
  while (data < 8) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    ++data;
  }
}

class TableView;

class State {
 public:
  State();
  ~State();

  virtual void update(TableView* view);
};

class AutoRefreshState : public State {
 public:
  AutoRefreshState();
  ~AutoRefreshState();

  virtual void update(TableView* view) override;
};

class NonAutoRefreshState : public State {
 public:
  NonAutoRefreshState();
  ~NonAutoRefreshState();

  virtual void update(TableView* view) override;
};

class TableView {
 public:
  TableView(bool auto_refresh);
  ~TableView();

  void update();
  void refresh();
  void auto_refresh(bool on);
  void show();

 private:
  friend class State;
  friend class AutoRefreshState;
  friend class NonAutoRefreshState;
  void change_state(State* state);

  std::unique_ptr<State> state;
  std::string value;
};

State::State() {}

State::~State() {}

void State::update(TableView* view) {}


AutoRefreshState::AutoRefreshState() {}

AutoRefreshState::~AutoRefreshState() {}

void AutoRefreshState::update(TableView* view) { view->refresh(); }

NonAutoRefreshState::NonAutoRefreshState() {}

NonAutoRefreshState::~NonAutoRefreshState() {}

void NonAutoRefreshState::update(TableView* view) {
  if (!view->value.empty() && view->value[0] == '*') {
    return;
  }

  if (view->value != std::string{"string " + std::to_string(data)}) {
    view->value.insert(view->value.begin(), '*');
  }
}


TableView::TableView(bool on) {
  value = "string " + std::to_string(data);
  auto_refresh(on);
}

TableView::~TableView() {}

void TableView::update() { state->update(this); }

void TableView::refresh() {
  value = "string " + std::to_string(data);
}

void TableView::auto_refresh(bool on) {
  state.reset(on ? static_cast<State*>(new AutoRefreshState())
                 : static_cast<State*>(new NonAutoRefreshState()));
}

void TableView::show() {
  std::cout.width(20);
  std::cout.fill('-');
  std::cout << "\r\n";
  std::cout << "   " << value << "\r\n";
  std::cout.fill('-');
  std::cout << std::endl;
}

void TableView::change_state(State* state) {}

int main() {
  std::thread background_updater(update_data);

  TableView auto_refresh(true);
  TableView no_auto_refresh(false);
  std::cout << "==== Initial ====" << std::endl;
  auto_refresh.update();
  no_auto_refresh.update();
  auto_refresh.show();
  no_auto_refresh.show();

  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::cout << "==== Updated Table ====" << std::endl;
  auto_refresh.update();
  no_auto_refresh.update();
  auto_refresh.show();
  no_auto_refresh.show();

  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "==== Switch Auto Refresh ====" << std::endl;
  std::cout << std::endl;
  auto_refresh.auto_refresh(false);
  no_auto_refresh.auto_refresh(true);

  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "==== Update Table ====" << std::endl;
  auto_refresh.update();
  no_auto_refresh.update();
  auto_refresh.show();
  no_auto_refresh.show();

  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::cout << "==== Manually Refresh ====" << std::endl;
  auto_refresh.refresh();
  no_auto_refresh.refresh();
  auto_refresh.show();
  no_auto_refresh.show();

  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::cout << "==== Update Table ====" << std::endl;
  auto_refresh.update();
  no_auto_refresh.update();
  auto_refresh.show();
  no_auto_refresh.show();
  
  background_updater.join();
}
