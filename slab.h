#ifndef SLAB_H
#define SLAB_H

#include <bitset>
#include <cstdlib>
#include <iostream>

struct Slab {
    static constexpr int MAX_SLOTS = 63;

    int num_free = MAX_SLOTS;
        // Current number of free slots

    size_t sz;
        // Size of each individual slot

    std::bitset<MAX_SLOTS> slots_used;
        // 1 represent slot is in use, 0 represents free.

    char *data;
        // Data layout: [ Ptr to this slab | Slot1 | Slot2 | ... | Slot63 ]

    // Constructs a Slab where each slot has a size of 's'
    Slab(size_t s) : sz(s)
    {
        size_t alignment = sz * (MAX_SLOTS+1);
        size_t data_sz = sz * MAX_SLOTS + sizeof(void*);
        posix_memalign((void**)&data, alignment, data_sz);
        // data = static_cast<char*>(aligned_alloc(data_size, data_size));
        *((Slab**)data) = this;
        //std::cout << "\t\tSlab::this = " << (void*) this << std::endl;
        //std::cout << "\t\tStart of data = " << (void*) data << std::endl;
        //std::cout << "\t\tData at beginning of data = " << (void*) *((Slab**)data) << std::endl;
    }

    void* insert() {
        size_t free_slot = 0;
        for (; free_slot < slots_used.size(); ++free_slot) {
            if (slots_used[free_slot] == 0) {
                break;
            }
        }

        void *p = data + (free_slot * sz) + sizeof(void*);
        slots_used[free_slot] = 1;
        num_free -= 1;

        std::cout << "\t\t----- p at slot#" << free_slot << std::endl;

        return p;
    }

    void erase(int slot_num) {
        slots_used[slot_num] = 0;
        num_free += 1;
    }

    ~Slab()
    {
        std::cout << "\t\tFreeing data = " << (void*) data << "from this = " << (void*) this << "\n\n\n" << std::endl;
        free(data);
    }

};

#endif /* ifndef SLAB_H */
