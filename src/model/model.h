#ifndef RMBR_MODEL_MODEL_H_
#define RMBR_MODEL_MODEL_H_

#include <map>
#include <string>

#include "src/model/model_item.h"
#include "src/storage/storage_interface.h"

namespace rmbr {

struct ModelV1 {
  double version;
  std::map<uint64_t, ModelItemV1> items;
};

class Model {
 public:
  Model() = delete;
  Model(Storage& storage) : storage_(storage) {}

  uint64_t Store(std::string what) {
    ModelItemV1 item{what, {"a", "b"}};
    return storage_.Store(item);
  }

  bool Initialize() { return storage_.LoadModel(); }

  ModelItemV1 Retrieve(uint64_t) { return storage_.Retrieve(0); }

  double Version() { return version_; }

 private:
  // TODO: Potentially implement caching. Either here or at storage
  Storage& storage_;
  static constexpr double version_ = 1.0;
};

}  // namespace rmbr

#endif  // RMBR_MODEL_MODEL_H_