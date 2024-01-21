#include "BinaryTree.h"
template <class Key, class T>
std::pair<typename BinaryTree<Key, T>::iterator, bool>
BinaryTree<Key, T>::insert(const_reference value) {
  bool isset = true;
  N tmp = insertRec(root, value, nullptr, isset);
  
  if(isset) ++size_;
  return std::make_pair(iterator(tmp), isset);
}

template <class Key, class T>
typename BinaryTree<Key, T>::N BinaryTree<Key, T>::insertRec(
    N node, const_reference value, N parent, bool &isset) {
  if (node == nullptr) {
    node = new Node<Key, T>(value, parent);
    return node;
  } else if (value.first < node->key_.first) {
    N insertedNode = insertRec(node->left, value, node, isset);
    if(node->left == nullptr) node->left = insertedNode;
    return insertedNode;
  } else if (value.first > node->key_.first) {
    N insertedNode = insertRec(node->right, value, node, isset);
    if(node->right == nullptr)
      node->right = insertedNode;
    return insertedNode;
  } else {
    isset = false;
    return node;
  }
}

template<class Key, class T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::begin() {
  Node<Key, T>* node = root;
  while (node != nullptr && node->left != nullptr) {
    node = node->left;
  }
  return iterator(node);
}


template<class Key, class T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::end() {
  return begin() + size();
}


/////////////////////////////////////////////

// template <class Key>
// void BinaryTree<Key>::insert(const_reference value, ) {
//   root = insertRec(root, value, nullptr);
//   size_++;
// }

// template <class Key>
// Node<Key>* BinaryTree<Key>::insertRec(Node<Key>* node, const_reference value,
//                                       Node<Key>* parent) {
//   if (node == nullptr) {
//     node = new Node<Key>(value, parent);
//   } else if (value < node->value) {
//     node->left = insertRec(node->left, value, node);
//   } else if (value > node->value) {
//     node->right = insertRec(node->right, value, node);
//   }
//   return node;
// }

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

// template <typename Key>
// typename BinaryTree<Key>::iterator BinaryTree<Key>::find(const_reference key)
// {
//   return searchRecursive(iterator(root), key);
// }

// template <class Key>
// typename BinaryTree<Key>::iterator Bin//   Node<Key>* node = root;
//   while (node != nullptr && node->left != nullptr) {
//     node = node->left;
//   }
//   return node;
// }
//   if (current == endit || *current == key) {
//     return current;
//   }
//   if (key < *current) {
//     return searchRecursive(current->left, key);
//   } else {
//     return searchRecursive(current->right, key);
//   }
// }

// template <class Key>
// typename BinaryTree<Key>::iterator BinaryTree<Key>::begin(iterator node) {
//   while (node.getNode() != nullptr && node.getNode()->left != nullptr) {
//     node.setNode(node.getNode()->left);
//   }
//   return node;
// }

// template <class Key>
// typename BinaryTree<Key>::iterator BinaryTree<Key>::begin() {
//   Node<Key>* node = root;
//   while (node != nullptr && node->left != nullptr) {
//     node = node->left;
//   }
//   return node;
// }

// template <typename Key>
// typename BinaryTree<Key>::iterator BinaryTree<Key>::end() {
//   Node<Key>* current = root;
//   while (current->right != nullptr) {
//     current = current->right;
//   }
//   return iterator(current);
// }