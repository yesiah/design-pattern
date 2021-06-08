#include <iostream>
#include "DataConsumer.h"

///
/// Client 1 uses the base DataConsumer
///
void RunClient1() {
    DataConsumer consumer;
    auto iter = consumer.GetIterator();
    std::cout << iter.Value() << std::endl;
}

///
/// Client 2 would like to have sequential access to data
///
void RunClient2() {
    SequentialAccess sequential;
    auto iter = sequential.GetFirst();
    std::cout << iter.Value() << std::endl;
    while (sequential.HasNext()) {
        iter = sequential.GetNext();
        std::cout << iter.Value() << std::endl;
    }
}

///
/// Client 3 access randomly
///
void RunClient3() {
    RandomAccess random;
    for (int i = 0; i < 10; ++i) {
        auto iter = random.GetRandom();
        std::cout << iter.Value() << std::endl;
    }
}


int main() {
    std::cout << "==== Run Client 1 ====" << std::endl;
    RunClient1();

    std::cout << std::endl;
    std::cout << "==== Run Client 2 ====" << std::endl;
    RunClient2();

    std::cout << std::endl;
    std::cout << "==== Run Client 3 ====" << std::endl;
    RunClient3();
}
