#include <iostream>
#include <string>
#include "Data.h"
#include "State.h"
#include "AutoRefreshState.h"
#include "NonAutoRefreshState.h"
#include "TableView.h"

TableView::TableView(bool on) {
  value = "string " + std::to_string(data);
  auto_refresh(on);
}

void TableView::update() { state->update(this); }

void TableView::refresh() { value = "string " + std::to_string(data); }

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
