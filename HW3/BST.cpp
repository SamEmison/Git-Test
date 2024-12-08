#include "BST.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

BST::BST() {
    root = nullptr;
}

BST::~BST() {
    clear(root);
}

void BST::clear(Node* node) {
    if (node != nullptr) {
        clear(node->getLeft());
        clear(node->getRight());
        delete node;
    }
}

// Set a key-value pair (insert or update)
void BST::set(const string& key, int data) {
    insertHelper(root, key, data);
}

void BST::insertHelper(Node*& node, const string& key, int data) {
    if (node == nullptr) {
        node = new Node(key, data);
    } else if (key < node->getKey()) {
        insertHelper(node->left, key, data);
    } else if (key > node->getKey()) {
        insertHelper(node->right, key, data);
    } else {
        node->setData(data);  // Update the value if the key already exists
    }
}

// Find the value associated with the key
int BST::find(const string& key) {
    Node* node = findNode(root, key);
    if (node != nullptr) {
        return node->getData();
    }
    throw out_of_range("Key not found");
}

Node* BST::findNode(Node* node, const string& key) const {
    if (node == nullptr) return nullptr;
    if (key == node->getKey()) return node;
    if (key < node->getKey()) return findNode(node->getLeft(), key);
    return findNode(node->getRight(), key);
}

// Print the tree in-order (key, value) pairs
void BST::print() const {
    printHelper(root);
}

void BST::printHelper(Node* node) const {
    if (node != nullptr) {
        printHelper(node->getLeft());
        cout << "(" << node->getKey() << ", " << node->getData() << ")" << endl;
        printHelper(node->getRight());
    }
}

// Find and print the smallest key
void BST::min() const {
    Node* minNode = findMin(root);
    if (minNode != nullptr) {
        cout << "Min key: " << minNode->getKey() << endl;
    } else {
        cout << "Tree is empty." << endl;
    }
}

Node* BST::findMin(Node* node) const {
    while (node && node->getLeft() != nullptr) {
        node = node->getLeft();
    }
    return node;
}

// Find and print the largest key
void BST::max() const {
    Node* maxNode = root;
    while (maxNode && maxNode->getRight() != nullptr) {
        maxNode = maxNode->getRight();
    }
    if (maxNode != nullptr) {
        cout << "Max key: " << maxNode->getKey() << endl;
    } else {
        cout << "Tree is empty." << endl;
    }
}

// Save the tree to a file
void BST::saveFile(const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw runtime_error("Could not open file for saving.");
    }
    saveHelper(root, outFile);
    outFile.close();
}

void BST::saveHelper(Node* node, ofstream& outFile) const {
    if (node != nullptr) {
        saveHelper(node->getLeft(), outFile);  // Traverse left subtree
        outFile << node->getKey() << ", " << node->getData() << endl;  // Save current node
        saveHelper(node->getRight(), outFile);  // Traverse right subtree
    }
}

// Load the tree from a file (simple load)
void BST::loadFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        throw runtime_error("Could not open file for loading.");
    }

    string key;
    int data;
    while (inFile >> key >> data) {
        set(key, data);  // Reuse set() method to insert nodes
    }
    inFile.close();
}

// Delete a key from the tree
void BST::deleteNode(const string& key) {
    root = deleteHelper(root, key);
}

Node* BST::deleteHelper(Node* node, const string& key) {
    if (node == nullptr) return node;

    if (key < node->getKey()) {
        node->setLeft(deleteHelper(node->getLeft(), key));
    } else if (key > node->getKey()) {
        node->setRight(deleteHelper(node->getRight(), key));
    } else {
        if (node->getLeft() == nullptr) {
            Node* temp = node->getRight();
            delete node;
            return temp;
        } else if (node->getRight() == nullptr) {
            Node* temp = node->getLeft();
            delete node;
            return temp;
        }

        Node* temp = findMin(node->getRight());  // Get the in-order successor
        node->setData(temp->getData());
        node->setRight(deleteHelper(node->getRight(), temp->getKey()));
    }
    return node;
}
