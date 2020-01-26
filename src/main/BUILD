load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "rmbr",
    srcs = ["main.cc"],
    deps = [
        "//src/model",
        "//src/storage:storage_memory",
        "//src/ui:ui_cli",
    ],
)
