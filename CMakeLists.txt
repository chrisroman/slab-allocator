cmake_minimum_required(VERSION 2.8.9)
project(slab_allocator)

include_directories(include)

SET(GCC_COVERAGE_COMPILE_FLAGS "-std=c++17 -Wall -O2")
SET(GCC_COVERAGE_LINK_FLAGS    "-lbenchmark -lpthread -latomic")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

SET(TEST_DIR "./tests")

add_executable(testST      "./tests/single-threaded.cpp")
add_executable(testMT	   "./tests/multi-threaded.cpp")
add_executable(benchmarkST "./tests/benchmark-single-threaded.cpp")
add_executable(benchmarkMT "./tests/benchmark-multi-threaded.cpp")

add_executable(lf_benchmarkMT "./tests/lf-bench-mth.cpp")
add_executable(lf_slist_test "./tests/lf-slist-test.cpp")
add_executable(lf_allocator_test "./tests/lf-allocator-test.cpp")
