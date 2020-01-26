#ifndef RMBR_UI_UI_CLI_H_
#define RMBR_UI_UI_CLI_H_

#include <iostream>

#include "src/ui/ui_interface.h"

namespace rmbr {

class UiCli : public UiInterface {
 public:
  UiCli() {}
  ~UiCli() {}
  bool Start() override;

 private:
};

}  // namespace rmbr

#endif  // RMBR_UI_UI_CLI_H_