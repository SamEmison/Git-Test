#include "BST.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

// Constructor: Initialize the tree as empty
bst::bst() {
    root = nullptr;
}

// Destructor: Clear all nodes in the tree
bst::~bst() {
    clear(root);
}

// Clear the tree (delete all nodes)
void bst::clear(Node* node) {
    if (node) {
        clear(node->getLeft());
        clear(node->getRight());
        delete node;
    }
}

// Insert or update a key-value pair
void bst::set(const string& key, int value) {
    root = insert(root, key, value);
}

// Recursive function to insert a node into the tree
Node* bst::insert(Node* node, const string& key, int value) {
    if (!node) {
        return new Node(key, value);
    }
    if (key < node->getKey()) {
        node->setLeft(insert(node->getLeft(), key, value));
    } else if (key > node->getKey()) {
        node->setRight(insert(node->getRight(), key, value));
    } else {
        node->setData(value);  // Update data if the key already exists
    }
    return node;
}

// Find a value by its key
int bst::find(const string& key) const {
    Node* result = findNode(root, key);
    if (!result) {
        throw runtime_error("Key not found: " + key);
    }
    return result->getData();
}

// Helper function to find a node by its key
Node* bst::findNode(Node* node, const string& key) const {
    if (!node || node->getKey() == key) {
        return node;
    }
    if (key < node->getKey()) {
        return findNode(node->getLeft(), key);
    }
    return findNode(node->getRight(), key);
}

// Delete a node by its key
void bst::deleteKey(const string& key) {
    root = deleteNode(root, key);
}

// Recursive function to delete a node
Node* bst::deleteNode(Node* node, const string& key) {
    if (!node) {
        return nullptr;
    }
    if (key < node->getKey()) {
        node->setLeft(deleteNode(node->getLeft(), key));
    } else if (key > node->getKey()) {
        node->setRight(deleteNode(node->getRight(), key));
    } else {
        if (!node->getLeft()) {
            Node* temp = node->getRight();
            delete node;
            return temp;
        } else if (!node->getRight()) {
            Node* temp = node->getLeft();
            delete node;
            return temp;
        }

        Node* temp = minNode(node->getRight());
        node->setData(temp->getData());
        node->setRight(deleteNode(node->getRight(), temp->getKey()));
    }
    return node;
}

// Print the tree in-order
void bst::print() const {
    printInOrder(root);
    cout << endl;
}

// Helper function to print nodes in-order
void bst::printInOrder(Node* node) const {
    if (node) {
        printInOrder(node->getLeft());
        cout << "(" << node->getKey() << ", " << node->getData() << ") ";
        printInOrder(node->getRight());
    }
}

// Find the minimum key-value pair
pair<string, int> bst::min() const {
    if (!root) {
        throw runtime_error("Tree is empty");
    }
    Node* minNode = this->minNode(root);
    return {minNode->getKey(), minNode->getData()};
}

// Find the node with the minimum value
Node* bst::minNode(Node* node) const {
    while (node && node->getLeft()) {
        node = node->getLeft();
    }
    return node;
}

// Find the maximum key-value pair
pair<string, int> bst::max() const {
    if (!root) {
        throw runtime_error("Tree is empty");
    }
    Node* maxNode = this->maxNode(root);
    return {maxNode->getKey(), maxNode->getData()};
}

// Find the node with the maximum value
Node* bst::maxNode(Node* node) const {
    while (node && node->getRight()) {
        node = node->getRight();
    }
    return node;
}

// Save the tree to a file
void bst::saveFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Could not open file: " + filename);
    }

    saveInOrder(root, file);
    file.close();
    cout << "Tree saved to " << filename << endl;
}

// Helper function to save tree data in-order to a file
void bst::saveInOrder(Node* node, ofstream& file) const {
    if (node) {
        saveInOrder(node->getLeft(), file);
        file << node->getKey() << " " << node->getData() << endl;
        saveInOrder(node->getRight(), file);
    }
}
