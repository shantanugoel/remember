#include "controller/controller.h"
#include "model/model.h"
#include "model/storage_impl_memory.h"
#include "view/view.h"

int main() {
  rmbr::StorageMemory storage;
  rmbr::Model model(storage);
  return 0;
}