#include <iostream>
#include <thread>

#include "Data.h"
#include "State.h"
#include "TableView.h"

void update_data() {
  while (data < 8) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    ++data;
  }
}

int main() {
  std::thread background_updater(update_data);

  TableView view1(true);
  TableView view2(false);
  std::cout << "==== Initial ====" << std::endl;
  view1.update();
  view2.update();
  view1.show();
  view2.show();

  std::this_thread::sleep_for(std::chrono::milliseconds(1100));
  std::cout << "==== Update Table ====" << std::endl;
  view1.update();
  view2.update();
  view1.show();
  view2.show();

  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  std::cout << "==== Exchange Auto Refresh Flag ====" << std::endl;
  std::cout << std::endl;
  view1.auto_refresh(false);
  view2.auto_refresh(true);

  std::this_thread::sleep_for(std::chrono::milliseconds(1100));
  std::cout << "==== Update Table ====" << std::endl;
  view1.update();
  view2.update();
  view1.show();
  view2.show();

  std::this_thread::sleep_for(std::chrono::milliseconds(1100));
  std::cout << "==== Manually Refresh ====" << std::endl;
  view1.refresh();
  view2.refresh();
  view1.show();
  view2.show();

  std::this_thread::sleep_for(std::chrono::milliseconds(1100));
  std::cout << "==== Update Table ====" << std::endl;
  view1.update();
  view2.update();
  view1.show();
  view2.show();
  
  background_updater.join();
}
