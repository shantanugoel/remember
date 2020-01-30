#include "src/storage/storage_impl_simple_file.h"

#include <fstream>
#include <iostream>

#include "CLI/CLI.hpp"
#include "json/json.hpp"

namespace rmbr {

bool StorageSimpleFile::Initialize(CLI::App& app) {
  std::string storage_file;
  app.add_option("--storage-file", storage_file, "File to store data");
  app.parse(app.remaining_for_passthrough());
  std::cout << storage_file << "\n";
  file_.open(storage_file, file_.in | file_.out);
  // If File doesn't exist, try to create it
  if (!file_.is_open()) {
    file_.open(storage_file, file_.in | file_.out | file_.trunc);
  }
  return file_.is_open();
}

}  // namespace rmbr