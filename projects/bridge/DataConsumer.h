#include <memory>
#include "DataProvider.h"

///
/// For Client 1, support only GetIterator(GetFirst)
///
class DataConsumer {
public:
    using Iterator = DataProvider::Iterator;

    DataConsumer();
    virtual ~DataConsumer() = default;

    Iterator GetIterator() const;  // GetFirst

protected:
    std::unique_ptr<DataProvider> provider;
};

///
/// For Client2, support sequential access
/// 
class SequentialAccess : public DataConsumer {
public:
    SequentialAccess();
    virtual ~SequentialAccess() = default;

    Iterator GetFirst() const {
        return provider->GetFirst();
    }

    bool HasNext() const {
        return provider->HasMore();
    }

    Iterator GetNext() const {
        return provider->GetNext();
    }
};