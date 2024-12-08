#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class Node{
private:
  string key;
  int data;
  Node* left;
  Node* right;

public:
  Node(const string&key, int data);
  ~Node();
  string getKey();
  int getData();
  Node* getleft();
  Node* getRight();
  void setData(int data);
  void setLeft(Node* leftNode);
  void setRight(Node* rightNode);
};

#endif
