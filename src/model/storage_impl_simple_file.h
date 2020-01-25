#ifndef RMBR_STORAGE_IMPL_SIMPLE_FILE_H_
#define RMBR_STORAGE_IMPL_SIMPLE_FILE_H_

#include <fstream>
#include <string>

#include "model/storage.h"

namespace rmbr {

class StorageSimpleFile : public Storage {
 public:
  StorageSimpleFile() = delete;
  StorageSimpleFile(const std::string& filePath) {
    file_.open(filePath, file_.in | file_.out);
    // TODO: better graceful failure
    assert(file_.is_open());
  }

  // TODO: Implement
  uint64_t store(ModelItem& item) override { return 0; }
  // TODO: Implement
  ModelItem& retrieve(uint64_t) override {
    ModelItem test("test");
    return test;
  }

 private:
  std::fstream file_;
};

}  // namespace rmbr

#endif  // RMBR_STORAGE_IMPL_SIMPLE_FILE_H_