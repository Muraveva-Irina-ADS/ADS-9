// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
template<typename T>
class BST {
 private:
    struct Node {
        T value;
        int count;
        Node* left, * right;
        explicit Node(T value) : value(value), count(1), left(nullptr), right(nullptr) {}
    };

 public:
    Node* root;
    BST() : root(nullptr) {}
    int search(T value) {
        return searchNode(root, value);
    }
    int searchNode(Node* root, T value) {
        if (!root)
            return 0;
        if (root->value == value)
            return root;
        if (value < root->value)
            return searchNode(root->left, value);
        else
            return searchNode(root->right, value);
    }
    int depth() {
        return getDepth(root) - 1;
    }
    int getDepth(Node* root) {
        if (root)
            return std::max(getDepth(root->left), getDepth(root->right)) + 1;
        else
            return 0;
    }
    void add(T value) {
        root = insertWord(root, value);
    }
    Node* insertWord(Node* ptr, T word) {
        if (ptr == nullptr) {
            ptr = new Node(word);
        } else if (ptr->value == word) {
            ptr->count++;
        } else if (ptr->value > word) {
            ptr->left = insertWord(ptr->left, word);
        } else if (ptr->value < word) {
            ptr->right = insertWord(ptr->right, word);
        }
        return ptr;
    }
};
#endif  // INCLUDE_BST_H_
