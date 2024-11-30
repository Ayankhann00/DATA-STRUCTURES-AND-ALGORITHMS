#include <iostream>

#include "BST.h"
using namespace std;

int main() {
  BST bst;

  // Insert elements
  bst.insert(10);
  bst.insert(5);
  bst.insert(20);
  bst.insert(8);
  bst.insert(30);

  // Inorder traversal
  cout << "Inorder Traversal Before Deletion: ";
  bst.inorder(bst.getRoot());
  cout << endl;

  // Delete a node
  bst.deleteNode(bst.getRoot(), 20);

  // Inorder traversal after deletion
  cout << "Inorder Traversal After Deletion: ";
  bst.inorder(bst.getRoot());
  cout << endl;

  cout << "preorder traversal after deletion:";
  bst.preorder(bst.getRoot());
  cout << endl;

  return 0;
}
