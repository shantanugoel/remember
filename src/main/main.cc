#include "src/model/model.h"
#include "src/storage/storage_impl_memory.h"
#include "src/ui/ui_cli.h"

int main() {
  rmbr::StorageMemory storage;
  rmbr::Model model(storage);
  return 0;
}