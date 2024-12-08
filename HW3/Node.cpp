/**
 * @file Node.cpp
 * @author Sam Emison
 * @date 2024-12-08
 * @brief .cpp file for node class
 * 
 * Gives node class functionality
 */

#include "Node.h"

// Constructor to initialize a Node with a given key and data

/**
 * Constructor
 *
 * @param const string& key 
 * @param int data 
 * @pre 
 * @post 
 * 
 */
Node::Node(const string& key, int data) {
    this->key = key;
    this->data = data;
    left = nullptr;
    right = nullptr;
}

// Destructor

/**
 * Destructor
 *
 * @pre 
 * @post 
 * 
 */
Node::~Node() {}

// Getter for the key

/**
 * Gets the key
 *
 * @pre 
 * @return string 
 * @post 
 * 
 */
string Node::getKey() const {
    return key;
}

// Getter for the data

/**
 * Gets the data
 *
 * @pre 
 * @return int 
 * @post 
 * 
 */
int Node::getData() const {
    return data;
}

// Getter for the left child node

/**
 * Finds whats to the left of the node
 *
 * @pre 
 * @return Node* 
 * @post 
 * 
 */
Node* Node::getLeft() const {
    return left;
}

// Getter for the right child node

/**
 * Finds whats to the right of the node
 *
 * @pre 
 * @return Node* 
 * @post 
 * 
 */
Node* Node::getRight() const {
    return right;
}

// Setter for data

/**
 * Sets the data
 *
 * @param int data 
 * @pre 
 * @return void 
 * @post 
 * 
 */
void Node::setData(int data) {
    this->data = data;
}

// Setter for left child node

/**
 * Sets the data for the left node
 *
 * @param Node* leftNode 
 * @pre 
 * @return void 
 * @post 
 * 
 */
void Node::setLeft(Node* leftNode) {
    left = leftNode;
}

// Setter for right child node

/**
 * Sets the data for the right node
 *
 * @param Node* rightNode 
 * @pre 
 * @return void 
 * @post 
 * 
 */
void Node::setRight(Node* rightNode) {
    right = rightNode;
}
