#ifndef SINGLE_ALLOCATOR_H
#define SINGLE_ALLOCATOR_H

#include "slab.h"
#include <deque>
#include <stack>

struct SingleAllocator {
    std::deque<Slab*> free_slabs;
    size_t sz;

    // used for debugging
    std::deque<Slab*> all_slabs;

    void viewState() {
        std::cout << "\t----- Viewing state for SingleAllocator(" << sz << ") -----" << std::endl;
        int slab_num = 0;
        for (Slab* slab : all_slabs) {
            std::cout << "\t----- Slab# " << slab_num << "-----\n"
                << "\tnum_free = " << slab->num_free << '\n'
                << "\tslots_used = " << slab->slots_used << '\n'
                << "\t----------\n" << std::endl;
            ++slab_num;
        }
        std::cout << "\t----- End viewState for SingleAllocator -----\n\n\n" << std::endl;
    }

    // Constructs a SingleAllocator that contains Slabs, where each slot
    // in the Slab is of size 's'
    SingleAllocator(size_t s) : sz(s)
    {
        free_slabs.emplace_back(new Slab(sz));
        all_slabs.emplace_back(free_slabs.front());
    }


    [[nodiscard]]
    void* allocate()
    {
        Slab *slab = free_slabs.front();
        void *p = slab->insert();

        std::cout << "slab->num_free = " << slab->num_free << std::endl;

        // Remove the top (active) slab if there's no more space
        if (slab->num_free == 0) {
            free_slabs.pop_front();
        }

        // Add a new slab if there's no more free space in the top (active) one
        if (free_slabs.size() == 0) {
            free_slabs.emplace_back(new Slab(sz));
            all_slabs.emplace_back(free_slabs.front());
        }

        return p;
    }

    void deallocate(void* p)
    {
        // Alignment for Slab::data
        size_t alignment = sz * (Slab::MAX_SLOTS + 1);
        // Offset (# of bytes) into Slab::data
        size_t offset = ((long long)p) % alignment;
        // The slot index for p
        int slot_num = (offset - sizeof(void*)) / sz;

        //std::cout << "\toffset = " << offset<< std::endl;
        //std::cout << "\tslot_num = " << slot_num << std::endl;

        //std::cout << "\tStart of data: " << (void*) (((char*)p) - offset) << std::endl;
        Slab *slab = *((Slab**) (((char*)p) - offset));
        //std::cout << "\tSlab start found at: " << (void*)slab << std::endl;
        
        // If the slab is empty, add it to the free list since it will
        // have a free slot once we finish 'deallocate'-ing
        if (slab->num_free == 0) {
            free_slabs.push_back(slab);
        }

        slab->erase(slot_num);

    }

};

#endif /* ifndef SINGLE_ALLOCATOR_H */
