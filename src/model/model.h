#ifndef RMBR_MODEL_MODEL_H_
#define RMBR_MODEL_MODEL_H_

#include <map>
#include <string>

#include "model/model_item.h"
#include "model/storage.h"

namespace rmbr {

class Model {
 public:
  Model() = delete;
  Model(Storage& storage) : storage_(storage) {}

 private:
  // TODO: Potentially implement caching. Either here or at storage
  Storage storage_;
};

}  // namespace rmbr

#endif  // RMBR_MODEL_MODEL_H_