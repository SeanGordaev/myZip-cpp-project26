#pragma once
#include <vector>

template <typename T>
struct ZIP
{
    std::vector<bool> zip_data;
    std::vector<T> tree;
};

struct Node {
    std::vector<bool> value;
    int weight;
    Node* left;
    Node* right;

    Node(int w) : value(), weight(w), left(nullptr), right(nullptr) {}
};
