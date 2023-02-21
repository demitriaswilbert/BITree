/**
 * @file BITree.h
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
#ifndef BITREE_H
#define BITREE_H

#include <bits/stdc++.h>

#define BIT_LSB(i) ((i) & -(i))

template <typename T> T prefix_sum(std::vector<T>& tree, int64_t index) {
    if (index < 0) return 0;
    T sum = tree[0];
    for (; index > 0; index -= BIT_LSB(index))
        sum += tree[index];
    return sum;
}

template <typename T>
void add(std::vector<T>& tree, int64_t index, T value) {
    if (index == 0) {
        tree[0] += value;
        return;
    }
    for (; index < tree.size(); index += BIT_LSB(index))
        tree[index] += value;
}

// convert array to fenwick tree form
template <typename T> void init(std::vector<T>& tree) {
    for (int64_t i = 1; i < tree.size(); i++) {
        int64_t j = i + BIT_LSB(i);
        if (j < tree.size())
            tree[j] += tree[i];
    }
}

// convert fenwick tree array back to array of per element counts
template <typename T> void fini(std::vector<T>& tree) {
    for (int64_t i = tree.size() - 1; i > 0; i--) {
        int64_t j = i + BIT_LSB(i);
        if (j < tree.size())
            tree[j] -= tree[i];
    }
}

template <typename T> T get(std::vector<T>& tree, int64_t index) {
    return prefix_sum(tree, index) - prefix_sum(tree, index - 1);
    // return range_sum(tree, index - 1, index);
}

template <typename T> void set(std::vector<T>& tree, int64_t index, T value) {
    add(tree, index, value - get(tree, index));
}





#endif // BITREE_H
