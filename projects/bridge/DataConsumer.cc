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