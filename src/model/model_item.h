#ifndef RMBR_MODEL_MODEL_ITEM_H_
#define RMBR_MODEL_MODEL_ITEM_H_

#include <map>
#include <string>

namespace rmbr {

// TODO: Connect insight engine that parses/analyzes model items to provide
// value adds, e.g., time of occurence
// TODO: Templatize ModelItem to take various types of items, not just strings
class ModelItem {
 public:
  ModelItem() = delete;
  ModelItem(const std::string& input) : what_(std::move(input)) {}

 private:
  int id_;  // TODO: Replace with uuid
  std::string what_;
};

}  // namespace rmbr

#endif  // RMBR_MODEL_MODEL_ITEM_H_