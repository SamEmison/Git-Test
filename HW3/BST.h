#ifndef BST_H
#define BST_H

#include "Node.h"
#include <fstream>
#include <string>
using namespace std;

class BST {
public:
    BST();
    ~BST();
    void set(const string& key, int data);         // Insert or overwrite key-value pair
    int find(const string& key);                   // Find the value of a given key
    void print() const;                            // Print the tree in-order (key, value)
    void min() const;                             // Print the smallest key
    void max() const;                             // Print the largest key
    void saveFile(const string& filename);        // Save the tree to a file
    void loadFile(const string& filename);        // Load the tree from a file
    void deleteNode(const string& key);           // Delete a key from the tree

private:
    Node* root;
    void insertHelper(Node*& node, const string& key, int data);
    Node* findNode(Node* node, const string& key) const;
    void printHelper(Node* node) const;
    void saveHelper(Node* node, ofstream& outFile) const;
    Node* deleteHelper(Node* node, const string& key);
    Node* findMin(Node* node) const;
    void clear(Node* node);
};

#endif
