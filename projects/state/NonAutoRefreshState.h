#pragma once
#include "State.h"

class TableView;

class NonAutoRefreshState : public State {
 public:
  virtual void update(TableView* view) override;
};
