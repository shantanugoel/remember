#ifndef RMBR_STORAGE_IMPL_MEMORY_H_
#define RMBR_STORAGE_IMPL_MEMORY_H_

#include <fstream>
#include <map>
#include <string>

#include "src/storage/storage_interface.h"

namespace rmbr {

// This implementation is not that useful without a server/client mode which can
// retain memory across client invocations
class StorageMemory : public Storage {
 public:
  // TODO: Implement. Generate new id
  uint64_t store(ModelItem& item) override {
    data_.emplace(0, item);
    return 0;
  }

  // TODO: Implement
  ModelItem* retrieve(uint64_t id) override {
    ModelItem* item = nullptr;
    auto item_iterator = data_.find(id);
    if (item_iterator != data_.end()) {
      item = &(item_iterator->second);
    }
    return item;
  }

 private:
  ::std::map<uint64_t, ModelItem> data_;
};

}  // namespace rmbr

#endif  // RMBR_STORAGE_IMPL_MEMORY_H_