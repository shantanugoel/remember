#ifndef RMBR_MODEL_H_
#define RMBR_MODEL_H_

#include <string>

namespace rmbr {

class ModelItem {
 public:
  ModelItem() = delete;
  ModelItem(const std::string& input) : what_(std::move(input)) {}

 private:
  int id_;  // TODO: Replace with uuid
  std::string what_;
};

class Model {
 public:
  Model() : what_("") {}
  Model(const std::string& what) : what_(what) {}

 private:
  std::string what_;
};
}  // namespace rmbr

#endif  // RMBR_MODEL_H_