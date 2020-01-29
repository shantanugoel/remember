#ifndef RMBR_STORAGE_IMPL_SIMPLE_FILE_H_
#define RMBR_STORAGE_IMPL_SIMPLE_FILE_H_

#include <fstream>
#include <string>
#include <vector>

#include "CLI/CLI.hpp"
#include "src/model/model_item.h"
#include "src/storage/storage_interface.h"

namespace rmbr {

class StorageSimpleFile : public Storage {
 public:
  ~StorageSimpleFile() { file_.close(); }
  // TODO: Implement
  uint64_t Store(ModelItem& item) override {
    (void)item;
    return 0;
  }
  // TODO: Implement
  ModelItem* Retrieve(uint64_t id) override {
    (void)id;
    return nullptr;
  }

  bool Initialize(CLI::App& app) override;

 private:
  std::fstream file_;
};

}  // namespace rmbr

#endif  // RMBR_STORAGE_IMPL_SIMPLE_FILE_H_