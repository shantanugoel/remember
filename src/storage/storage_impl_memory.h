#ifndef RMBR_STORAGE_IMPL_MEMORY_H_
#define RMBR_STORAGE_IMPL_MEMORY_H_

#include <fstream>
#include <map>
#include <string>

#include "CLI/CLI.hpp"
#include "src/storage/storage_interface.h"

namespace rmbr {

// This implementation is not that useful without a server/client mode which can
// retain memory across client invocations
class StorageMemory : public Storage {
 public:
  // TODO: Implement. Generate new id
  uint64_t Store(const ModelItemV1& item) override {
    data_.emplace(0, item);
    return 0;
  }

  // TODO: Fix not existing scenario
  ModelItemV1 Retrieve(uint64_t id) override {
    ModelItemV1 item;
    auto item_iterator = data_.find(id);
    if (item_iterator != data_.end()) {
      item = item_iterator->second;
    }
    return item;
  }

  bool Initialize(CLI::App& app) override {
    (void)app;
    return true;
  }

 private:
  std::map<uint64_t, ModelItemV1> data_;
};

}  // namespace rmbr

#endif  // RMBR_STORAGE_IMPL_MEMORY_H_