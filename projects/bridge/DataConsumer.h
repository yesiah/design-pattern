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
/// For Client 2, support sequential access
/// 
class SequentialAccess : public DataConsumer {
public:
    SequentialAccess();
    virtual ~SequentialAccess() = default;

    Iterator GetFirst() const;
    bool HasNext() const;
    Iterator GetNext() const;
};

///
/// Client 3, random access
///
class RandomAccess : public DataConsumer {
public:
    RandomAccess();
    virtual ~RandomAccess() = default;

    Iterator GetRandom() const;
};
