#pragma once
#include <string>
#include <memory>

class TableView {
 public:
  TableView(bool auto_refresh);

  void update();
  void refresh();
  void auto_refresh(bool on);
  void show();

 private:
  friend class State;
  friend class AutoRefreshState;
  friend class NonAutoRefreshState;

  std::unique_ptr<State> state;
  std::string value;
};
