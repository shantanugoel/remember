#include "CLI/CLI.hpp"
#include "src/controller/controller.h"
#include "src/model/model.h"
#include "src/storage/storage_impl_memory.h"
#include "src/ui/ui_cli.h"

int main(int argc, char** argv) {
  // TODO: Add argument processing. Assume sane defaults for now.
  rmbr::StorageMemory storage;
  rmbr::Controller controller;
  rmbr::Model model(storage);
  rmbr::UiCli ui(controller, model);
  ui.Start();
  return 0;
}