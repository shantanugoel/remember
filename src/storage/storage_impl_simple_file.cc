#include "src/storage/storage_impl_simple_file.h"

#include <fstream>
#include <iostream>

#include "CLI/CLI.hpp"

namespace rmbr {

bool StorageSimpleFile::Initialize(std::vector<std::string> input_args,
                                   std::vector<std::string>& remaining_args) {
  CLI::App app{"Remember Storage Simple File"};
  app.allow_extras();
  std::string storage_file;
  app.add_option("--storage-file", storage_file, "File to store data");
  app.parse(input_args);
  std::cout << storage_file;
  // file_.open(filePath, file_.in | file_.out);
  // TODO: better graceful failure
  // assert(file_.is_open());
  remaining_args = app.remaining_for_passthrough();
  return true;
}

}  // namespace rmbr