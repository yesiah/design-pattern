#include "Data.h"
#include "TableView.h"
#include "NonAutoRefreshState.h"

void NonAutoRefreshState::update(TableView* view) {
  if (!view->value.empty() && view->value[0] == '*') {
    return;
  }

  if (view->value != std::string{"string " + std::to_string(data)}) {
    view->value.insert(view->value.begin(), '*');
  }
}
