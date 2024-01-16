#include "BinaryTree.h"

template <class Key>
void BinaryTree<Key>::insert(const_reference value) {
  root = insertRec(root, value, nullptr);
  size_++;
}

template <class Key>
Node<Key>* BinaryTree<Key>::insertRec(Node<Key>* node, const_reference value,
                                      Node<Key>* parent) {
  if (node == nullptr) {
    node = new Node<Key>(value, parent);
  } else if (value < node->value) {
    node->left = insertRec(node->left, value, node);
  } else if (value > node->value) {
    node->right = insertRec(node->right, value, node);
  }
  return node;
}

// template <class key>
// BinaryTree<key>::find(Node<key>* current) {
//   if (root != nullptr) {
//     inOrderTraversal(root->left);  // вывод
//     if () {
//       return
//     }
//     inOrderTraversal(root->right);
//   }
// }

// bool check(Node<key>* value1, Node<key>* value1) {}

template <typename Key>
typename BinaryTree<Key>::iterator BinaryTree<Key>::find(const_reference key) {
  return searchRecursive(iterator(root), key);
}

template <class Key>
typename BinaryTree<Key>::iterator BinaryTree<Key>::searchRecursive(
    iterator current, const_reference key) {
  if (current == nullptr || (*current) == key) {
    return current;
  }
  if (key < *current) {
    return searchRecursive(current->left, key);
  } else {
    return searchRecursive(current->right, key);
  }
}

template <class Key>
typename BinaryTree<Key>::iterator BinaryTree<Key>::begin(iterator node) {
  while (node.getNode() != nullptr && node.getNode()->left != nullptr) {
    node.setNode(node.getNode()->left);
  }
  return node;
}

template <class Key>
typename BinaryTree<Key>::iterator BinaryTree<Key>::begin() {
  Node<Key>* node = root;
  while (node != nullptr && node->left != nullptr) {
    node = node->left;
  }
  return node;
}