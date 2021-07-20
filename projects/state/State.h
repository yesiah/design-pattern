#pragma once

class TableView;

class State {
 public:
  virtual void update(TableView* view);
};
