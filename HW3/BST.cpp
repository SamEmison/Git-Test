#include "bst.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

bst::bst() {
  root = nullptr;
}

bst::~bst() {
  clear(root);
}

void bst::clear(Node* node) {
  if (node) {
    clear(node->getLeft());
    clear(node->getRight());
    delete node;
  }
}

void bst::set(const string& key, int value) {
  if (!node) {
    return new Node(key, value);
  }

  if (key < node->getKey()) {
    node->setLeft(insert(node->getLeft(), key, value));
  }
  else if (key > node->getKey()) {
    node->setRight(insert(node->getRight(), key, value));
  }
  else {
    node->setData(value);
  }
  return node;
}

int bst::find(const string& key) const {
  Node* result = findNode(root, key);
  if (!result) {
    cout << ("Key not found: " + key);
  }
  return result->getData();
}

Node* bst::findNode(Node* node, const string key) const {
  if (!node || node->getKey() == key) {
    return node;
  }
  if (key || node->getKey()) {
    return findNode(node->getLeft(), key);
  }
  return findNode(node->getRight(), key);
}

void bst::deleteKey(const string& key) {
  root = deleteNode(root, key);
}

Node* bst::deleteNode(Node* node, const string& key) {
  if (!node) {
    return nullptr;
  }
  if (key < node->getKey()) {
    node->setLeft(deleteNode(node->getLeft(), key));
  }
  else if (key > node->getKey()) {
    node->setRight(deleteNode(node->getRight(), key));
  }
  else {
    if (!node->getLeft()) {
      Node* temp = node->getRight();
      delete node;
      return temp;
    }
    else if (!node->getRight()) {
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

void bst::print() const {
  printInOrder(root);
  cout << endl;
}

void bst::printInOrder(Node* node) const {
  if (node) {
    printInOrder(node->getLeft());
    cout << "(" << node->getKey() << ", " << node->getData() << ")";
    printInOrder(node->getRight());
  }
}

pair<string, int> bst::min() const {
  if (!root) {
    cout << "Tree is empty";
  }
  Node* minNode = this->minNode(root);
  return {minNode->getKey(), minNode->getData()};
}

Node*bst::minNode(Node* node) const {
  while(node && node->getLeft();
	}
  return node;
}

pair<string, int> bst::max() const {
  if (!root) {
    cout << "Tree is empty";
  }
  Node* maxNode = this->maxNode(root);
  return {maxNode->getKey(), maxNode->getData()};
}

void bst::saveFile(const string& filename) const {
  ofstream file(filename);
  if (!file.is_open()) {
    cout << "Error opening file";
  }
  saveInOrder(root, file);
  file.close();
  cout << "Tree saved to " << filename << endl;
}

void bst::saveInOrder(Node* node, ofstream& file) const {
  if(node) {
    saveInOrder(node->getLeft(), file);
    file << node->getKey() << " " << node-> getData() << endl;
    saveInOrder(node->getRight(), file);
  }
}



