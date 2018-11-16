#ifndef SLAB_H
#define SLAB_H

#include <bitset>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <atomic>
#include <sstream>

#include <strings.h>

struct Slab {
    // TODO: use atomic 
    static constexpr int MAX_SLOTS = 63;

    std::atomic<int> num_free{MAX_SLOTS};
        // Current number of free slots

    size_t sz;
        // Size of each individual slot

    std::atomic<uint64_t> free_slots{-1ULL};
        // 1 represent slot is in free, 0 represents in use.

    char *data;
        // Data layout: [ Ptr to this slab | Slot1 | Slot2 | ... | Slot63 ]

    // Constructs a Slab where each slot has a size of 's'
    Slab(size_t s) : sz(s)
    {
        // We need sizeof(void*) + 63*sz < alignment, since the max
        // possible slot number is 63
        size_t alignment = sz * 2 * (MAX_SLOTS+1);

        size_t data_sz = sz * MAX_SLOTS + sizeof(void*);

        posix_memalign((void**)&data, alignment, data_sz);
        //data = static_cast<char*>(aligned_alloc(alignment, data_sz));

        *((Slab**)data) = this;
    }

    std::pair<void*, int> insert() {
        int free_slot = 0;

        // Find a free slot and mark it as in use
        uint64_t desired_free_slots;
        uint64_t expected_free_slots = free_slots.load();
        do {
            free_slot = ffsll(expected_free_slots) - 1;
            if (free_slot == -1) {
                return {nullptr, -1};
            }
            desired_free_slots = expected_free_slots & (~(1ULL << free_slot));
        } while (!free_slots.compare_exchange_weak(expected_free_slots, desired_free_slots));

        //int new_num_free = num_free.fetch_sub(1) - 1;
        //std::cout << std::to_string(new_num_free) + "\n";
        
        void *p = data + (free_slot * sz) + sizeof(void*);
        return {p, -1};
    }

    int erase(int slot_num) {
        // Mark the slot_num as free now
        uint64_t desired_free_slots;
        uint64_t expected_free_slots = free_slots.load();
        do {
            desired_free_slots = expected_free_slots | (1ULL << slot_num);
        } while (!free_slots.compare_exchange_weak(expected_free_slots, desired_free_slots));
        return num_free.fetch_add(1);
    }

    ~Slab()
    {
        free(data);
    }

};

#endif /* ifndef SLAB_H */
