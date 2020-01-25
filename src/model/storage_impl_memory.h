#ifndef RMBR_STORAGE_IMPL_MEMORY_H_
#define RMBR_STORAGE_IMPL_MEMORY_H_

#include <fstream>
#include <string>

#include "model/storage.h"

namespace rmbr {

class StorageMemory : public Storage {
 public:
  // TODO: Implement
  uint64_t store(ModelItem& item) override { return 0; }
  // TODO: Implement
  ModelItem& retrieve(uint64_t) override {
    ModelItem test("test");
    return test;
  }

 private:
  std::map<uint64_t, ModelItem> data_;
};

}  // namespace rmbr

#endif  // RMBR_STORAGE_IMPL_MEMORY_H_