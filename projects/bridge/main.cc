#include <iostream>
#include "DataConsumer.h"

int main() {
    DataConsumer consumer;
    auto iter = consumer.GetIterator();
    std::cout << iter.Value() << std::endl;
}
