#ifndef RMBR_UI_UI_INTERFACE_H_
#define RMBR_UI_UI_INTERFACE_H_

#include <string>
#include <vector>

#include "CLI/CLI.hpp"

namespace rmbr {

// TODO: Singleton?
class UiInterface {
 public:
  // virtual bool Start(std::vector<std::string>& input_args) = 0;
  virtual bool Start(CLI::App& app) = 0;

 private:
};

}  // namespace rmbr
#endif  // RMBR_UI_UI_INTERFACE_H_