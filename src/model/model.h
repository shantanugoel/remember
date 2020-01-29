#ifndef RMBR_MODEL_MODEL_H_
#define RMBR_MODEL_MODEL_H_

#include <map>
#include <string>

#include "src/model/model_item.h"
#include "src/storage/storage_interface.h"

namespace rmbr {

class Model {
 public:
  Model() = delete;
  Model(Storage& storage) : storage_(storage) {}

  uint64_t Store(std::string what) {
    ModelItem* item = new ModelItem(what);
    return storage_.Store(*item);
  }

  ModelItem* Retrieve(uint64_t) { return storage_.Retrieve(0); }

 private:
  // TODO: Potentially implement caching. Either here or at storage
  Storage& storage_;
  // uint64_t version_;  // TODO
};

}  // namespace rmbr

#endif  // RMBR_MODEL_MODEL_H_