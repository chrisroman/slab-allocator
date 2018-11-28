# Slab Allocator

## Prerequisites
- g++-8
- cmake
- https://github.com/google/benchmark
    - Make sure to use g++-8 when doing the `cmake` commands. Once you've
    generated the Makefile for this, run `make install` to install it onto your
    system

## Compile and Run
Clone this directory. Then run `compile.sh`. This will use cmake to generate
a makefile to build any tests and benchmarks. Navigate to the `build` directory
and run `make`. You should be able to run the executables.

## TODO
1. Problem: Should we call `malloc/free` if the size of the object allocated in
the `SlabAllocator.allocate()` should `SingleAllocator`s allowed to be
arbitrarily large?
2. Lock free stack
