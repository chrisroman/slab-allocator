set(bench_cc ./benchmark-multi-threaded.cpp)

add_executable(bench ${bench_cc})

target_link_libraries(bench benchmark)
