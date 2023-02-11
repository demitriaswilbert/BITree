/**
 * @file Binary Indexed Tree.cpp
 * @author Demitrias Wilbert (demitriaswilbert@gmail.com)
 * @brief Binary Indexed Tree aka Fenwick Tree
 *
 * Data structure used to compute the sum of
 * varible amount elements in an array.
 * does not work well on non-integral data types
 *
 * @version 0.1
 * @date 2023-02-11
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <bits/stdc++.h>
#include "BITree.h"

int main() {
    bool run = true;

    using datatype = int64_t;
    const size_t N = (1UL << 20U);
    std::random_device rd;
    std::uniform_int_distribution<datatype> dist(INT64_MIN / N,
                                                INT64_MAX / N);

    std::cout << "Creating Data" << std::endl;
    std::vector<datatype> data(N);
    for (auto& i : data) {
        i = dist(rd);
    }

    std::cout << "Indexing Tree" << std::endl;
    std::vector<datatype> tree = createTree<datatype>(data);

    std::cout << "Randomizing" << std::endl;

    size_t i = 0;
    for (; i < N; i++) {
        datatype val = dist(rd);
        data[i] = val;
        set(tree, i+1, val);
    }

    std::cout << "Comparing" << std::endl;

    i = 0;
    for (; i < N; i++) {
        if (data[i] != valOf(tree, i+1)) {
            std::cout << "Test Failed! " << std::endl
                      << "Difference found on " << i << std::endl;
            break;
        }
    }
    if (i == N) 
        std::cout << "Tested Successfully" << std::endl;

    return 0;
}
