#ifndef RMBR_MODEL_MODEL_H_
#define RMBR_MODEL_MODEL_H_

#include <map>
#include <string>

#include "src/model/model_item.h"
#include "src/storage/storage_interface.h"

namespace rmbr {

struct ModelV1 {
  uint32_t version;
  ModelItemV1 item;
};

class Model {
 public:
  Model() = delete;
  Model(Storage& storage) : storage_(storage) {}

  uint64_t Store(std::string what) {
    ModelItem* item = new ModelItem(what);
    return storage_.Store(*item);
  }

  // TODO: Add initialize func to load model data from storage

  ModelItem* Retrieve(uint64_t) { return storage_.Retrieve(0); }

 private:
  // TODO: Potentially implement caching. Either here or at storage
  Storage& storage_;
  ModelV1 data_;
};

}  // namespace rmbr

#endif  // RMBR_MODEL_MODEL_H_