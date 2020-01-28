#ifndef RMBR_UI_UI_CLI_H_
#define RMBR_UI_UI_CLI_H_

#include <iostream>

#include "src/controller/controller.h"
#include "src/model/model.h"
#include "src/ui/ui_interface.h"

namespace rmbr {

class UiCli : public UiInterface {
 public:
  UiCli(Controller& controller, Model& model)
      : controller_(controller), model_(model) {}
  ~UiCli() {}
  bool Start() override;

 private:
  Controller& controller_;
  Model& model_;
};

}  // namespace rmbr

#endif  // RMBR_UI_UI_CLI_H_