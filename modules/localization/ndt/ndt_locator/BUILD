load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "ndt_lidar_locator",
    srcs = [
        "lidar_locator_ndt.cc",
    ],
    hdrs = [
        "lidar_locator_ndt.h",
        "ndt_solver.h",
        "ndt_solver.hpp",
        "ndt_voxel_grid_covariance.h",
        "ndt_voxel_grid_covariance.hpp",
    ],
    deps = [
        "//cyber",
        "//modules/common/math",
        "//modules/common/monitor_log",
        "//modules/common/time",
        "//modules/localization/common:localization_common",
        "//modules/localization/msf/common/util:localization_msf_common_util",
        "//modules/localization/msf/local_map/ndt_map:localization_msf_ndt_map",
        "@eigen",
        "@glog",
        "@pcl",
        "@yaml_cpp//:yaml",
    ],
)

filegroup(
    name = "ndt_lidar_locator_test_data",
    srcs = glob([
        "ndt/test_data/**",
    ]),
)

cc_test(
    name = "ndt_lidar_locator_test",
    size = "small",
    timeout = "short",
    srcs = ["lidar_locator_ndt_test.cc"],
    data = [":ndt_lidar_locator_test_data"],
    deps = [
        "//cyber",
        "//modules/localization/msf/common/io:localization_msf_common_io",
        "//modules/localization/ndt/ndt_locator:ndt_lidar_locator",
        "@gtest//:main",
    ],
)

cc_test(
    name = "ndt_solver_test",
    size = "small",
    timeout = "short",
    srcs = ["ndt_solver_test.cc"],
    data = [":ndt_lidar_locator_test_data"],
    linkopts = [
        "-llz4",
    ],
    deps = [
        "//cyber",
        "//modules/localization/msf/common/io:localization_msf_common_io",
        "//modules/localization/ndt/ndt_locator:ndt_lidar_locator",
        "@gtest//:main",
    ],
)

cpplint()
