#ifndef RMBR_STORAGE_IMPL_SIMPLE_FILE_H_
#define RMBR_STORAGE_IMPL_SIMPLE_FILE_H_

#include <fstream>
#include <string>
#include <vector>

#include "CLI/CLI.hpp"
#include "json/json.hpp"
#include "src/model/model.h"
#include "src/model/model_item.h"
#include "src/storage/storage_interface.h"

namespace rmbr {

class StorageSimpleFile : public Storage {
 public:
  ~StorageSimpleFile() { file_.close(); }

  uint64_t Store(const ModelItemV1& item) override;

  ModelItemV1* Retrieve(uint64_t id) override;

  bool Initialize(CLI::App& app) override;
  bool LoadModel() override;

 private:
  std::fstream file_;
  std::string file_path_;
  nlohmann::json model_json_;
};

}  // namespace rmbr

#endif  // RMBR_STORAGE_IMPL_SIMPLE_FILE_H_