package(default_visibility = ["//:__subpackages__"])

load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "model_item",
    hdrs = ["model_item.h"],
)

cc_library(
    name = "model",
    hdrs = ["model.h"],
    deps = [
        ":model_item",
        "//src/storage:storage_interface",
    ],
)
