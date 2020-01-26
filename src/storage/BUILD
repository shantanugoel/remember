package(default_visibility = ["//:__subpackages__"])

load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "storage_interface",
    hdrs = ["storage_interface.h"],
)

cc_library(
    name = "storage_memory",
    hdrs = ["storage_impl_memory.h"],
    deps = [
        ":storage_interface",
    ],
)
