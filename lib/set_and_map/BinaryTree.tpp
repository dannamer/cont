#include "BinaryTree.h"

template <class Key>
void BinaryTree<Key>::insert(const_reference value) {
  root = insertRec(root, value);
  size++;
}

template <class key>
Node<key>* BinaryTree<key>::insertRec(Node<key>* node, const_reference value) {
  if (node == nullptr) {
    return new Node<Key>(value);
  }
  if (value < node->value) {
    node->left = insertRec(node->left, value);
  } else if (value > node->value) {
    node->right = insertRec(node->right, value);
  }
  return node;
}

