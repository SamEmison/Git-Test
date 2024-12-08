#ifndef BST_H
#define BST_H

#include "Node.h"
#include <string>
#include <utility>  // For std::pair

/**
 * The bst class represents a binary search tree where each node contains a key-value pair.
 */
class bst {
private:
    Node* root;  // Root of the binary search tree

    // Helper functions
    void clear(Node* node);
    Node* insert(Node* node, const string& key, int value);
    Node* findNode(Node* node, const string& key) const;
    Node* deleteNode(Node* node, const string& key);
    void printInOrder(Node* node) const;
    Node* minNode(Node* node) const;
    Node* maxNode(Node* node) const;
    void saveInOrder(Node* node, std::ofstream& file) const;

public:
    // Constructor and Destructor
    bst();
    ~bst();

    // Public methods for tree operations
    void set(const string& key, int value);
    int find(const string& key) const;
    void deleteKey(const string& key);
    void print() const;
    std::pair<string, int> min() const;
    std::pair<string, int> max() const;
    void saveFile(const string& filename) const;
};

#endif
