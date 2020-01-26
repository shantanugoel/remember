#ifndef RMBR_MODEL_STORAGE_INTERFACE_H_
#define RMBR_MODEL_STORAGE_INTERFACE_H_

#include "model/model_item.h"

namespace rmbr {
class Storage {
 public:
  virtual uint64_t store(ModelItem& item) = 0;
  virtual ModelItem& retrieve(uint64_t) = 0;
  // TODO: Add other search/retrieve mechanisms

 private:
};

}  // namespace rmbr

#endif  // RMBR_MODEL_STORAGE_INTERFACE_H_