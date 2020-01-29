#include "CLI/CLI.hpp"
#include "src/controller/controller.h"
#include "src/model/model.h"
#include "src/storage/storage_impl_memory.h"
#include "src/storage/storage_impl_simple_file.h"
#include "src/ui/ui_cli.h"

int main(int argc, char** argv) {
  // TODO: Add argument processing. Assume sane defaults for now.
  CLI::App app{"Remember"};
  app.allow_extras();
  CLI11_PARSE(app, argc, argv);

  // TODO: Create separate interface to combine CLI arguments for all available
  // options, so -h can display those

  rmbr::StorageSimpleFile storage;
  // TODO: Graceful error handling
  assert(storage.Initialize(app));

  rmbr::Controller controller;
  rmbr::Model model(storage);
  rmbr::UiCli ui(controller, model);
  ui.Start(app);
  return 0;
}