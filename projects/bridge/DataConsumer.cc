#include "DataConsumer.h"

DataConsumer::DataConsumer() {
    // Select actual implementor based on actual conditions
    provider = std::make_unique<LevelDb>();
}

DataConsumer::~DataConsumer() {
}

DataConsumer::Iterator DataConsumer::GetIterator() const {
    return provider->GetFirst();
}