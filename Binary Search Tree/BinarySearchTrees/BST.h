#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* lchild;
  Node* rchild;
  Node(int value) {
    data = value;
    lchild = nullptr;
    rchild = nullptr;
  }
};

class BST {
  Node* Root;

 public:
  BST() { Root = nullptr; }

  void insert(int key);
  Node* deleteNode(Node* p, int key);
  void inorder(Node* p);
  void preorder(Node* p);
  Node* search(int key);
  Node* getRoot() { return Root; }  // Getter for Root
};
#endif
