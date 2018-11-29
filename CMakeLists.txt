cmake_minimum_required(VERSION 2.8.9)
project(slab_allocator)

include_directories(include)

string(CONCAT GCC_WARNINGS
    " -Wall -Wextra"
	" -Wshadow"
	" -Wnon-virtual-dtor"
	" -Wcast-align"
	" -Wunused"
	" -Woverloaded-virtual"
	" -Wpedantic"
	" -Wmisleading-indentation"
	" -Wduplicated-cond"
	" -Wduplicated-branches"
	" -Wlogical-op"
	" -Wnull-dereference"
	" -Wuseless-cast"
	" -Wdouble-promotion"
	" -Wformat=2"
    )

SET(GCC_COVERAGE_COMPILE_FLAGS "-std=c++17 -O2 ${GCC_WARNINGS}")
SET(GCC_COVERAGE_LINK_FLAGS    "-lbenchmark -lpthread -latomic")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

SET(TEST_DIR "./tests")

add_executable(single-threaded      "./tests/single-threaded.cpp")
add_executable(multi-threaded	   "./tests/multi-threaded.cpp")
add_executable(benchmark-single-threaded "./tests/benchmark-single-threaded.cpp")
add_executable(benchmark-multi-threaded "./tests/benchmark-multi-threaded.cpp")

add_executable(lf-bench-mth "./tests/lf-bench-mth.cpp")
add_executable(lf-slist-test "./tests/lf-slist-test.cpp")
add_executable(lf-allocator-test "./tests/lf-allocator-test.cpp")
add_executable(lf-stack "./tests/lf-stack.cpp")
