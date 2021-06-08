#include <iostream>
#include "DataConsumer.h"

int main(int argc, char const *argv[]) {
    DataConsumer consumer;
    auto iter = consumer.GetIterator();
    std::cout << iter.Value() << std::endl;
}
