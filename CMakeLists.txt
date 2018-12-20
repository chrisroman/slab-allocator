cmake_minimum_required(VERSION 2.8.9)
project(slab_allocator)

add_subdirectory(lib/Catch2)

set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)
add_subdirectory(lib/benchmark)
include_directories(include lib/benchmark/include)

add_subdirectory(benchmark_tests)

add_subdirectory(unit_tests)
enable_testing()

#add_executable(single-threaded      "./tests/single-threaded.cpp")
#add_executable(multi-threaded	   "./tests/multi-threaded.cpp")
#
#add_executable(lf-allocator-test "./tests/lf-allocator-test.cpp")
#add_executable(lf-stack "./tests/lf-stack.cpp")
#
#add_executable(pseudo-serialization "./tests/pseudo-serialization.cpp")
