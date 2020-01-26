#ifndef RMBR_UI_UI_CLI_H_
#define RMBR_UI_UI_CLI_H_

#include "src/ui/ui_interface.h"

namespace rmbr {

class UiCli : public UiInterface {
 public:
  bool Start() override;

 private:
};

}  // namespace rmbr

#endif  // RMBR_UI_UI_CLI_H_