#include "src/model/model.h"
#include "src/storage/storage_impl_memory.h"
#include "src/ui/ui_cli.h"

int main(int argc, char** argv) {
  rmbr::UiCli ui;
  ui.Start();
  return 0;
}