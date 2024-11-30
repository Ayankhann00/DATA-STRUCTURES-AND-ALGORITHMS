#include "BST.h"

#include <iostream>
using namespace std;

void BST::insert(int key) {
  Node* t = Root;
  Node* p;
  Node* r = nullptr;

  if (Root == nullptr) {
    p = new Node(key);
    Root = p;
    return;
  }

  while (t != nullptr) {
    r = t;
    if (key < t->data) {
      t = t->lchild;
    } else if (key > t->data) {
      t = t->rchild;
    } else {
      cout << "Duplicate key not allowed" << endl;
      return;
    }
  }

  p = new Node(key);
  if (key < r->data) {
    r->lchild = p;
  } else {
    r->rchild = p;
  }
}
Node* BST::deleteNode(Node* p, int key) {
  if (p == nullptr) {
    return nullptr;
  }

  if (key < p->data) {
    p->lchild = deleteNode(p->lchild, key);
  } else if (key > p->data) {
    p->rchild = deleteNode(p->rchild, key);
  } else {
    if (p->lchild == nullptr && p->rchild == nullptr) {
      delete p;
      return nullptr;
    } else if (p->lchild == nullptr) {
      Node* temp = p->rchild;
      delete p;
      return temp;
    } else if (p->rchild == nullptr) {
      Node* temp = p->lchild;
      delete p;
      return temp;
    } else {
      Node* succ = p->rchild;
      while (succ->lchild != nullptr) {
        succ = succ->lchild;
      }
      p->data = succ->data;
      p->rchild = deleteNode(p->rchild, succ->data);
    }
  }

  return p;
}

void BST::inorder(Node* p) {
  if (p) {
    inorder(p->lchild);
    cout << p->data << ", ";
    inorder(p->rchild);
  }
}
void BST::preorder(Node* p) {
  if (p) {
    cout << p->data << ", ";
    preorder(p->lchild);
    preorder(p->rchild);
  }
}
Node* BST::search(int key) {
  Node* t = Root;
  while (t != nullptr) {
    if (key == t->data) {
      return t;
    } else if (key < t->data) {
      t = t->lchild;
    } else {
      t = t->rchild;
    }
  }
  return nullptr;
}
