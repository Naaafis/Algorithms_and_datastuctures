#include <iostream>
#include <vector>
#include "hw5.h"

int main() {
    std::vector<int> small_min_heap;// = {0, 1, 2, 3, 4, 5, 6};
    //
    small_min_heap.push_back(-2074469549);
    small_min_heap.push_back(-1991056672);
    small_min_heap.push_back(-1659939278);
    small_min_heap.push_back(-1827455201);
    small_min_heap.push_back(857903436);
    small_min_heap.push_back(-250315153);
    small_min_heap.push_back(1680957094);
    small_min_heap.push_back(49880895);
    small_min_heap.push_back(466790725);
    small_min_heap.push_back(1948819314);
    std::vector<int> smallest_3 = findMinK(2, small_min_heap);
    std::cout << "smallest 3 elements are: ";
    // should print 0, 1, 2, in any order.
    for (auto it = smallest_3.begin(); it != smallest_3.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    BloomFilter bf = BloomFilter();
    bf.insert("Hello, World!");
    bf.insert("Lorem ipsum");

    std::cout << (bf.member("foo bar") ?
            "'foo bar' is in our bloom filter" :
            "'foo bar' is not in our bloom filter")
        << std::endl;

    return 0;
}