#include "src/storage/storage_impl_simple_file.h"

#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>

#include "CLI/CLI.hpp"
#include "json/json.hpp"
#include "src/model/model.h"

namespace rmbr {

void to_json(nlohmann::json& j, const ModelItemV1& item) {
  j = nlohmann::json{{"what", item.what}, {"tags", item.tags}};
}

void from_json(const nlohmann::json& j, ModelItemV1& item) {
  j.at("what").get_to(item.what);
  j.at("tags").get_to(item.tags);
}

bool StorageSimpleFile::Initialize(CLI::App& app) {
  app.add_option("--storage-file", file_path_, "File to store data");
  app.parse(app.remaining_for_passthrough());
  file_.open(file_path_, file_.in);
  // If File doesn't exist, try to create it
  if (!file_.is_open()) {
    file_.open(file_path_, file_.out | file_.trunc);
    // TODO: Error handling
  }
  initialized_ = file_.is_open();
  file_.close();
  return initialized_;
}

bool StorageSimpleFile::LoadModel() {
  // TODO: Prevent loading model again if already loaded?
  if (initialized_) {
    try {
      file_.open(file_path_, file_.in);
      file_ >> model_json_;
      model_loaded_ = true;
    } catch (nlohmann::json::exception& e) {
      // TODO: Warn about malformed file & conditionally abort?
      model_json_.clear();
    }
  }
  file_.close();
  model_loaded_ = true;
  return model_loaded_;
}

uint64_t StorageSimpleFile::Store(const ModelItemV1& item) {
  model_json_.emplace_back(item);
  std::filesystem::path from(file_path_);
  std::string to_filename =
      "." + from.filename().string() + "." + std::to_string(std::time(nullptr));
  std::filesystem::path to(file_path_);
  to.replace_filename(to_filename);
  std::filesystem::copy_file(from, to,
                             std::filesystem::copy_options::overwrite_existing);
  file_.open(file_path_, file_.out | file_.trunc);
  if (file_.is_open()) {
    file_ << model_json_;
  }
  file_.close();
  return 0;
}

// TODO: Allow "reload" to re-read data from filesystem in case files were
// modified externally
ModelItemV1 StorageSimpleFile::Retrieve(uint64_t id) {
  auto data = model_json_.find(std::to_string(id));
  ModelItemV1 item;
  if (data != model_json_.end()) {
    item = *data;
  }
  return item;
}

}  // namespace rmbr