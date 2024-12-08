#ifndef BST_H
#define BST_H

#include "Node.h"
#include <string>
#include <utility>

class bst {
  private:
  Node* root; // Root of the binary search tree
  void clear(Node* node);
  Node* insert(Node* node, const std::string& key, int value);
  Node* findNode(Node* node, const std::string& key) const;
  Node* deleteNode(Node* node, const std::string& key);
  void printInOrder(Node* node) const;
  Node* minNode(Node* node) const;
  Node* maxNode(Node* node) const;
  void saveInOrder(Node* node, std::ofstream& file) const;

 public:
  bst();
  ~bst();
  void set(const std::string& key, int value);
  int find(const std:;string& key) const;
  void deleteKey(const std::string& key);
  void print() const;
  std::pair<std::string, int> min() const;
  std::pair<std::string, int> max() const;
  void saveFile(const std::string& filename) const;
};

#endif
