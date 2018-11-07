#ifndef SLAB_ALLOCATOR_H
#define SLAB_ALLOCATOR_H

#include "single_allocator.h"
#include <memory>
#include <vector>
#include <cmath>
#include <thread>

// Allows for slots of size 2 << MAX_ALLOCATORS
static int const MAX_ALLOCATORS = 13;
SingleAllocator* allocators[MAX_ALLOCATORS] = {0};
std::mutex mux_allocators;

template <typename T>
struct SlabAllocator {
    typedef T value_type;

    // used for debugging
    void viewState() {
        for (auto& salloc : allocators) {
            if (salloc != nullptr) {
                salloc->viewState();
            }
        }
    }

    SlabAllocator()
    {
        // TODO: Review "Double Checked Locking" by Herb Stutter not have to
        // do all the allocations during construction, but rather do them
        // on the first access (when it is nullptr)
        std::lock_guard<std::mutex> lock(mux_allocators);
        if (allocators[0] == nullptr) {
            for (int i = 0, sz = 1; i < MAX_ALLOCATORS; ++i, sz *= 2) {
                allocators[i] = new SingleAllocator(sz);
            }
        }
    }

    ~SlabAllocator()
    {
    }

    template <class U>
    constexpr SlabAllocator(const SlabAllocator<U>& rhs) noexcept
    {
    }


    T* allocate(std::size_t n)
    {

        // Find the nearest power of 2 >= (n*sizeof(T))
        size_t rounded_size = 1;
        int exponent = 0;
        while (rounded_size < n * sizeof(T)) {
            rounded_size <<= 1;
            ++exponent;
        }

        // If size of object to be allocated is larger than what we have
        // SingleAllocators for, just malloc it
        if (exponent >= MAX_ALLOCATORS) {
            return static_cast<T*>(malloc(n * sizeof(T)));
        }

        // Find the correct allocator for this size and use it do allocation
        SingleAllocator* salloc = allocators[exponent];

        T* p = static_cast<T*>(salloc->allocate());

        return p;
    }

    void deallocate(T* p, std::size_t n) noexcept
    {
        // Find the nearest power of 2 >= (n*sizeof(T))
        size_t rounded_size = 1;
        int exponent = 0;
        while (rounded_size < n * sizeof(T)) {
            rounded_size <<= 1;
            ++exponent;
        }

        if (exponent >= MAX_ALLOCATORS) {
            free(p);
        } else {
            // Find the correct allocator for this size and use it do allocation
            SingleAllocator*& salloc = allocators[exponent];
            salloc->deallocate(p);
        }
    }

};

template <class T, class U>
bool operator==(const SlabAllocator<T>& lhs, const SlabAllocator<U>& rhs)
{
    return true;
}

template <class T, class U>
bool operator!=(const SlabAllocator<T>& lhs, const SlabAllocator<U>& rhs)
{
    return false;
}


#endif /* ifndef SLAB_ALLOCATOR_H */
