package(default_visibility = ["//:__subpackages__"])

load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "ui_interface",
    hdrs = ["ui_interface.h"],
    deps = [
        "//src/controller",
        "//src/model",
        "@cli11",
    ],
)

cc_library(
    name = "ui_cli",
    srcs = ["ui_cli.cc"],
    hdrs = ["ui_cli.h"],
    deps = [
        ":ui_interface",
        "@cli11",
    ],
)
