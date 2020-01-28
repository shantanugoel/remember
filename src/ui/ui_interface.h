#ifndef RMBR_UI_UI_INTERFACE_H_
#define RMBR_UI_UI_INTERFACE_H_

#include <string>
#include <vector>

namespace rmbr {

// TODO: Singleton?
class UiInterface {
 public:
  virtual bool Start(std::vector<std::string> passthrough_options) = 0;

 private:
};

}  // namespace rmbr
#endif  // RMBR_UI_UI_INTERFACE_H_