#include "src/ui/ui_cli.h"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "CLI/CLI.hpp"
#include "src/model/model_item.h"

namespace rmbr {

bool UiCli::Start(std::vector<std::string> passthrough_options) {
  CLI::App app{"Remember CLI"};
  app.require_subcommand(1);
  // TODO: Is "stash" better than "store"?
  auto store = app.add_subcommand("store", "Store this");
  auto recall = app.add_subcommand("recall", "Recall");

  std::string what;
  store->add_option("what", what, "what to store");
  store->callback([&]() { model_.store(what); });
  app.parse(passthrough_options);
  return true;
}

}  // namespace rmbr