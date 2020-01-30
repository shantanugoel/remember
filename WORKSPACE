load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

new_git_repository(
    name = "cli11",
    build_file = "cli11.BUILD",
    remote = "https://github.com/CLIUtils/CLI11.git",
    tag = "v1.9.0",
)

http_archive(
    name = "json",
    build_file = "json.BUILD",
    sha256 = "87b5884741427220d3a33df1363ae0e8b898099fbc59f1c451113f6732891014",
    strip_prefix = "single_include/nlohmann",
    url = "https://github.com/nlohmann/json/releases/download/v3.7.3/include.zip",
)
