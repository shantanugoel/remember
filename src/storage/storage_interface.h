#ifndef RMBR_MODEL_STORAGE_INTERFACE_H_
#define RMBR_MODEL_STORAGE_INTERFACE_H_

#include "CLI/CLI.hpp"
#include "src/model/model_item.h"

namespace rmbr {
class Storage {
 public:
  virtual uint64_t Store(ModelItem& item) = 0;
  virtual ModelItem* Retrieve(uint64_t) = 0;
  virtual bool Initialize(CLI::App& app) = 0;
  // TODO: Add other search/retrieve mechanisms

 private:
};

}  // namespace rmbr

#endif  // RMBR_MODEL_STORAGE_INTERFACE_H_