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

template <typename T>
void update(std::vector<T>& tree, int64_t index, T value) {
    while (index < tree.size()) {
        tree[index] += value;
        index += index & (-index);
    }
}

template <typename T> T sum(std::vector<T>& tree, int64_t index) {
    T result = 0;
    while (index > 0) {
        result += tree[index];
        index -= index & (-index);
    }
    return result;
}

template <typename T>
T query(std::vector<T>& tree, int64_t begin, int64_t end) {
    if (end >= tree.size() || begin > tree.size()) return 0;
    return sum<T>(tree, end) - sum<T>(tree, begin);
}

template <typename T> T valOf(std::vector<T>& tree, int64_t index) {
    if (index > tree.size()) return 0;
    return query<T>(tree, index - 1, index);
}

template <typename T> void set(std::vector<T>& tree, int64_t index, T val) {
    if (index > tree.size()) return;
    update<T>(tree, index, val - valOf<T>(tree, index));
}

template <typename T> std::vector<T> createTree(std::vector<T>& data) {
    std::vector<T> BITree(data.size() + 1);
    for (int i = 0; i < data.size(); i++) {
        update<T>(BITree, i + 1, data[i]);
    }
    return BITree;
}

#endif // BITREE_H
