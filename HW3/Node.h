#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

/**
 * The Node class represents a node in the binary search tree.
 * Each node stores a key, data, and pointers to its left and right children.
 */
class Node {
private:
    string key;    // Key used for sorting and searching
    int data;      // Data associated with the key
    Node* left;    // Pointer to the left child
    Node* right;   // Pointer to the right child

public:
    // Constructor to initialize a Node with a key and data
    Node(const string& key, int data);

    // Destructor
    ~Node();

    // Getters and Setters
    string getKey() const;
    int getData() const;
    Node* getLeft() const;
    Node* getRight() const;
    void setData(int data);
    void setLeft(Node* leftNode);
    void setRight(Node* rightNode);
};

#endif
