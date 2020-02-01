package(default_visibility = ["//:__subpackages__"])

load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "storage_interface",
    hdrs = ["storage_interface.h"],
    deps = [
        "//src/model:model_item",
        "@cli11",
    ],
)

cc_library(
    name = "storage_memory",
    hdrs = ["storage_impl_memory.h"],
    deps = [
        ":storage_interface",
        "@cli11",
    ],
)

cc_library(
    name = "storage_simple_file",
    srcs = ["storage_impl_simple_file.cc"],
    hdrs = ["storage_impl_simple_file.h"],
    deps = [
        ":storage_interface",
        "//src/model",
        "//src/model:model_item",
        "@cli11",
        "@json",
    ],
)
