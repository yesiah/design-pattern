#include <random>
#include "DataConsumer.h"

DataConsumer::DataConsumer() {
    ///
    /// Select actual implementor based on context
    ///
    provider = std::make_unique<SQLServer>();
}

DataConsumer::Iterator DataConsumer::GetIterator() const {
    return provider->GetFirst();
}

///
/// Sequential Access
///
SequentialAccess::SequentialAccess() {
    ///
    /// Select actual implementor based on context
    ///
    provider = std::make_unique<LevelDb>();
}

SequentialAccess::Iterator SequentialAccess::GetFirst() const {
    return provider->GetFirst();
}

bool SequentialAccess::HasNext() const {
    return provider->HasMore();
}

SequentialAccess::Iterator SequentialAccess::GetNext() const {
    return provider->GetNext();
}

///
/// Random Access
///
RandomAccess::RandomAccess() {
    ///
    /// Select actual implementor based on context
    ///
    provider = std::make_unique<Csv>();
}

RandomAccess::Iterator RandomAccess::GetRandom() const {
    static std::random_device rd;
    static std::mt19937_64 randomGenerator(rd());
    static std::uniform_int_distribution uniformInt(0, 9);
    int i = uniformInt(randomGenerator);
    return provider->GetNth(i);
}