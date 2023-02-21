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
#include "BITree.h"
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

int main() {
    using cppint = boost::multiprecision::cpp_int;
    std::random_device rd;

    cppint one = 10;
    for(int i = 0; i < 13; i++)
        one *= one;
    
    cppint two = one * 2;
    cppint four = two * 2;

    cppint fct = 1;
    cppint f_16 = 1;

    std::vector<cppint> copy;
    for (int i = 0; ; i++) {
        cppint val = (four/(8*i+1) - two/(8*i+4) - one/(8*i+5) - one/(8*i+6))/f_16;
        f_16 <<= 4U;
        fct *= i;
        if (val == 0) break;
        copy.push_back(val);
    }

    init(copy);

    // for (int64_t i = 0; i < copy.size(); i++) {
    // }
    std::cout << prefix_sum(copy, copy.size() - 1);
    std::cout << std::endl;

    return 0;
}
