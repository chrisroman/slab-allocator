#ifndef SLAB_ALLOCATOR_H
#define SLAB_ALLOCATOR_H

#include "single_allocator.h"
#include <memory>
#include <vector>
#include <cmath>

// Allows for slots of size 2 << MAX_ALLOCATORS
static int const MAX_ALLOCATORS = 13;
SingleAllocator* allocators[MAX_ALLOCATORS] = {0};

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
        std::cout << "----- Start SlabAllocator() -----" << std::endl;
        std::cout << "allocators array = " << (void*) allocators << std::endl;
        std::cout << "----- End SlabAllocator() -----\n\n\n" << std::endl;
    }

    ~SlabAllocator()
    {
        std::cout << "----- Begin Destroy SlabAllocator = " << (void*)this << " -----" << std::endl;
        std::cout << "----- End Destroy SlabAllocator -----\n\n\n" << std::endl;
    }

    template <class U>
    constexpr SlabAllocator(const SlabAllocator<U>& rhs) noexcept
    {
        std::cout << "----- Start SlabAllocator(const SlabAllocator<U>&) -----" << std::endl;
        std::cout << "----- End SlabAllocator(const SlabAllocator<U>&) -----\n\n\n" << std::endl;
    }


    T* allocate(std::size_t n)
    {
        std::cout << "----- Start allocate(" << n << ") -----" << std::endl;

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
            std::cout << "Allocating via malloc" << std::endl;
            return static_cast<T*>(malloc(n * sizeof(T)));
        }

        // Find the correct allocator for this size and use it do allocation
        SingleAllocator*& salloc = allocators[exponent];
        if (salloc == nullptr) {
            salloc = new SingleAllocator(rounded_size);
        }

        std::cout << "Allocating for size " << pow(2, exponent) << std::endl;
        T* p = static_cast<T*>(salloc->allocate());

        std::cout << "----- End allocate: (return " << p << ")  -----\n\n\n" << std::endl;
        return p;
    }

    void deallocate(T* p, std::size_t n) noexcept
    {
        //std::cout << "----- Start deallocate(" << p << ", " << n << ") -----" << std::endl;

        // Find the nearest power of 2 >= (n*sizeof(T))
        size_t rounded_size = 1;
        int exponent = 0;
        while (rounded_size < n * sizeof(T)) {
            rounded_size <<= 1;
            ++exponent;
        }

        if (exponent >= MAX_ALLOCATORS) {
            std::cout << "Deallocating via free" << std::endl;
            free(p);
        }

        // Find the correct allocator for this size and use it do allocation
        SingleAllocator*& salloc = allocators[exponent];
        if (salloc == nullptr) {
            return;
        }
        salloc->deallocate(p);

        //std::cout << "----- End deallocate -----\n\n\n" << std::endl;
    }

};

template <class T, class U>
bool operator==(const SlabAllocator<T>& lhs, const SlabAllocator<U>& rhs)
{
    std::cout << "----- Start operator==(const SlabAllocator<T>& lhs, const SlabAllocator<U>& rhs) -----" << std::endl;
    return true;
    std::cout << "----- End operator==(const SlabAllocator<T>& lhs, const SlabAllocator<U>& rhs) -----\n\n\n" << std::endl;
}

template <class T, class U>
bool operator!=(const SlabAllocator<T>& lhs, const SlabAllocator<U>& rhs)
{
    std::cout << "----- Start operator!=(const SlabAllocator<T>& lhs, const SlabAllocator<U>& rhs) -----" << std::endl;
    return false;
    std::cout << "----- End operator!=(const SlabAllocator<T>& lhs, const SlabAllocator<U>& rhs) -----\n\n\n" << std::endl;
}


#endif /* ifndef SLAB_ALLOCATOR_H */
