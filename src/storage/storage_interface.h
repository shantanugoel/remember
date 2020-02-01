#ifndef RMBR_MODEL_STORAGE_INTERFACE_H_
#define RMBR_MODEL_STORAGE_INTERFACE_H_

#include "CLI/CLI.hpp"
#include "src/model/model_item.h"

namespace rmbr {
class Storage {
 public:
  virtual uint64_t Store(const ModelItemV1& item) = 0;
  virtual ModelItemV1 Retrieve(uint64_t) = 0;
  virtual bool Initialize(CLI::App& app) = 0;
  virtual bool LoadModel() = 0;

  // TODO: Add other search/retrieve mechanisms

 protected:
  bool initialized_ = false;
  bool model_loaded_ = false;
};

}  // namespace rmbr

#endif  // RMBR_MODEL_STORAGE_INTERFACE_H_