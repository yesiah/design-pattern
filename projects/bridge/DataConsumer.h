#include <memory>
#include "DataProvider.h"

class DataConsumer {
public:
    using Iterator = DataProvider::Iterator;

    DataConsumer();
    ~DataConsumer();

    Iterator GetIterator() const;  // GetFirst

private:
    std::unique_ptr<DataProvider> provider;
};