#include "src/ui/ui_cli.h"

#include <string>
#include <vector>

#include "CLI/CLI.hpp"

namespace rmbr {

bool UiCli::Start(std::vector<std::string> passthrough_options) {
  CLI::App app{"Remember CLI"};
  app.parse(passthrough_options);
  return true;
}

}  // namespace rmbr