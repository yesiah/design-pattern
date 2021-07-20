#pragma once
#include "State.h"

class TableView;

class AutoRefreshState : public State {
 public:
  virtual void update(TableView* view) override;
};
