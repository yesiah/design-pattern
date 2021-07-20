#include "TableView.h"
#include "AutoRefreshState.h"

void AutoRefreshState::update(TableView* view) { view->refresh(); }
