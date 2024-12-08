/**
 * @file Node.cpp
 * @author Sam Emison
 * @date 2024-12-07
 * @brief Node functionality 
 * 
 * Provides functionality for the Node class
 */

#include "Node.h";
#include <iostream>

using namespace std;

Node::Node(const string& key, int data) {
  this->key = key;
  this->data = data;
  left = nullptr;
  right = nullptr;
}

Node::~Node() {}

string Node::getKey() {
  return key;
}

int Node::getData() {
  return data;
}

Node* Node::getLeft() {
  return left;
}

Node* Node::getRight() {
  return right;
}

void Node::setData(int data) {
  this->data = data;
}

void Node::setLeft(Node* leftNode) {
  left = leftNode;
}

void Node::setRight(Node* rightNode) {
  right = rightNode;
}
