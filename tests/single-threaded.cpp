#include "../include/mutex_allocator/slab_allocator.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Test {
public:
    int num = 0;
    int arr[16];
    string str = "";

    Test() {}

    Test(int n, string s) : num(n), str(s) {}
};

void test1() {
    SlabAllocator<Test> test_sa;

    int n = 10000;
    vector<Test, SlabAllocator<Test>> vec(test_sa);
    for (int i = 0; i < n; ++i) {
        vec.push_back(Test(1, "aasdokfnaonfoneaognoeawnogboeiwbfiobe"));
    }
    
    SlabAllocator<int> int_sa;
    vector<int, SlabAllocator<int>> vec2(int_sa);
    for (int i = 0; i < n; ++i) {
        vec2.push_back(i);
    }

    //cout << std::boolalpha << (int_sa == test_sa) << endl;
    //test_sa.viewState();
    //int_sa.viewState();

    test_sa.clear();
}

void test2() {
    SlabAllocator<Test> test_sa;

    //int n = 770;
    int n = 10000;
    deque<Test, SlabAllocator<Test>> lst(test_sa);
    for (int i = 0; i < n; ++i) {
        lst.push_back(Test(1, "aasdokfnaonfoneaognoeawnogboeiwbfiobe"));
        std::cout << "Inserted element #" << i << std::endl;
    }
    std::cout << "Done allocating." << std::endl;
    //test_sa.viewState();

    //SlabAllocator<int> int_sa;
    //deque<int, SlabAllocator<int>> lst2(int_sa);
    //for (int i = 0; i < n; ++i) {
    //    lst2.push_back(i);
    //}

}

void test3() {
    SlabAllocator<Test> test_sa;

    {
        int n = 1000;
        deque<Test, SlabAllocator<Test>> lst(test_sa);
        int num_iters = 6;
        for (int i = 0; i < num_iters; ++i) {
            if (i % 3 == 2) {
                lst.clear();
                std::cout << "Cleared lst" << std::endl;
                //test_sa.viewState();
                continue;
            }

            for (int j = 0; j < n; ++j) {
                lst.push_back(Test(1, "aasdokfnaonfoneaognoeawnogboeiwbfiobe"));
                std::cout << "Inserted element #" << j << std::endl;
            }
            //test_sa.viewState();
        }
    }
    std::cout << "End of test3" << std::endl;
    //test_sa.viewState();
}

int main(void)
{
    test1();
    test2();
    test3();
    return 0;
}
