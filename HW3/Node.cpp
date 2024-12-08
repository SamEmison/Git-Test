#include "Node.h"

// Constructor to initialize a Node with a given key and data
Node::Node(const string& key, int data) {
    this->key = key;
    this->data = data;
    left = nullptr;
    right = nullptr;
}

// Destructor
Node::~Node() {}

// Getter for the key
string Node::getKey() const {
    return key;
}

// Getter for the data
int Node::getData() const {
    return data;
}

// Getter for the left child node
Node* Node::getLeft() const {
    return left;
}

// Getter for the right child node
Node* Node::getRight() const {
    return right;
}

// Setter for data
void Node::setData(int data) {
    this->data = data;
}

// Setter for left child node
void Node::setLeft(Node* leftNode) {
    left = leftNode;
}

// Setter for right child node
void Node::setRight(Node* rightNode) {
    right = rightNode;
}
