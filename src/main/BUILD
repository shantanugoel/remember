load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "rmbrlib",
    deps = [
        "//src/controller",
        "//src/model",
        "//src/storage:storage_memory",
        "//src/storage:storage_simple_file",
        "//src/ui:ui_cli",
        "@cli11",
    ],
)

cc_binary(
    name = "rmbr",
    srcs = ["main.cc"],
    deps = [
        ":rmbrlib",
    ],
)
