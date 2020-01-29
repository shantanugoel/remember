#ifndef RMBR_UI_UI_CLI_H_
#define RMBR_UI_UI_CLI_H_

#include <iostream>
#include <string>
#include <vector>

#include "src/controller/controller.h"
#include "src/model/model.h"
#include "src/ui/ui_interface.h"

namespace rmbr {

class UiCli : public UiInterface {
 public:
  UiCli(Controller& controller, Model& model)
      : controller_(controller), model_(model) {
    (void)controller_;
  }

  ~UiCli() {}
  bool Start(std::vector<std::string>& input_args) override;

 private:
  Controller& controller_;
  Model& model_;
};

}  // namespace rmbr

#endif  // RMBR_UI_UI_CLI_H_