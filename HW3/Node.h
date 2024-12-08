#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class Node {
public:
    Node(string key, int data);
    string getKey() const;
    int getData() const;
    void setData(int data);
    Node* getLeft() const;
    Node* getRight() const;
    void setLeft(Node* left);
    void setRight(Node* right);
    Node* left;
    Node* right;

  
private:
    string key;
    int data;
};

#endif
