#include "Node.h"

Node::Node(string key, int data) {
    this->key = key;
    this->data = data;
    left = nullptr;
    right = nullptr;
}

string Node::getKey() const {
    return key;
}

int Node::getData() const {
    return data;
}

void Node::setData(int data) {
    this->data = data;
}

Node* Node::getLeft() const {
    return left;
}

Node* Node::getRight() const {
    return right;
}

void Node::setLeft(Node* left) {
    this->left = left;
}

void Node::setRight(Node* right) {
    this->right = right;
}
