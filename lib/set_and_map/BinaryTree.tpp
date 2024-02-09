// #include "BinaryTree.h"

template <class Key, class T>
BinaryTree<Key, T>::~BinaryTree() {
  clear();
}

template <class Key, class T>
BinaryTree<Key, T>::BinaryTree(std::initializer_list<value_type> const& items) {
  for (auto it = items.begin(); it != items.end(); ++it) {
    insert(*it);
  }
}

template <class Key, class T>
BinaryTree<Key, T>::BinaryTree(const BinaryTree& m) {
  size_ = m.size_;
  root = copyBinaryTree(m.root);
  setNewEnd();
}

template <class Key, class T>
BinaryTree<Key, T>::BinaryTree(BinaryTree&& m) {
  *this = std::move(m);
}

template <class Key, class T>
void BinaryTree<Key, T>::merge(BinaryTree& other) {
  for (auto it = other.begin(); it != other.end; ++it) {
    insert(*it);
  }
  other.clear();
}

template <class Key, class T>
BinaryTree<Key, T>& BinaryTree<Key, T>::operator=(BinaryTree&& m) {
  if (this != &m) {
    delete root;
    delete rootEnd;
    size_ = m.size_;
    root = m.root;
    rootEnd = m.rootEnd;
    m.size_ = 0;
    m.root = nullptr;
    m.rootEnd = nullptr;
  }
  return *this;
}

template <class Key, class T>
void BinaryTree<Key, T>::swap(BinaryTree& other) {
  BinaryTree<Key, T> tmp = std::move(other);
  other = std::move(*this);
  *this = std::move(tmp);
}

// копирование
template <class Key, class T>
typename BinaryTree<Key, T>::N BinaryTree<Key, T>::copyBinaryTree(N CRoot) {
  if (CRoot == nullptr) {
    return nullptr;
  }
  N newNode = new Node<Key, T>(CRoot->key_.first, CRoot->key_.second);
  newNode->left = copyBinaryTree(root->left);
  newNode->right = copyBinaryTree(root->right);
  return newNode;
}

template <class Key, class T>
std::pair<typename BinaryTree<Key, T>::iterator, bool>
BinaryTree<Key, T>::insert(const_reference value) {
  bool isset = true;
  N tmp = insertRec(root, value, nullptr, isset);
  if (isset) ++size_;
  setNewEnd();
  return std::make_pair(iterator(tmp), isset);
}

template <class Key, class T>
void BinaryTree<Key, T>::setNewEnd() {
  clearEnd();
  rootEnd =
      new Node<Key, T>(std::make_pair(size(), 0), *(begin() + (size() - 1)));
  N last = rootEnd->parent;
  if (last->left == nullptr)
    last->last = rootEnd;
  else if (last != root && last->left != nullptr &&
           last->left->right == nullptr && last->left->left == nullptr) {
    last->last = rootEnd;
    last->left->last = rootEnd;
    rootEnd->parent = last->left;
  }
}

template <class Key, class T>
typename BinaryTree<Key, T>::N BinaryTree<Key, T>::insertRec(
    N node, const_reference value, N parent, bool& isset) {
  if (node == nullptr) {
    node = new Node<Key, T>(value, parent);
    if (root == nullptr) root = node;
    return node;
  } else if (value.first < node->key_.first) {
    N insertedNode = insertRec(node->left, value, node, isset);
    if (node->left == nullptr) node->left = insertedNode;
    return insertedNode;
  } else if (value.first > node->key_.first) {
    N insertedNode = insertRec(node->right, value, node, isset);
    if (node->right == nullptr) node->right = insertedNode;
    return insertedNode;
  } else {
    isset = false;
    return node;
  }
}

template <class Key, class T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::begin() {
  Node<Key, T>* node = root;
  while (node != nullptr && node->left != nullptr) {
    node = node->left;
  }
  return iterator(node);
}

template <class Key, class T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::end() {
  return iterator(rootEnd);
}

template <class Key, class T>
void BinaryTree<Key, T>::clearEnd() {
  if (rootEnd) {
    rootEnd->parent->last = nullptr;
    delete rootEnd;
    rootEnd = nullptr;
  }
}

template <class Key, class T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::find(const Key& key) {
  N current = root;
  while (current != nullptr) {
    if (key < current->key_.first) {
      current = current->left;
    } else if (key > current->key_.first) {
      current = current->right;
    } else {
      return iterator(current);
    }
  }
  return end();
}

// template <class Key, class T>
// void BinaryTree<Key, T>::searchNode(const Key& key, Node<Key, T>*& node) {
//   while (node && node->key_.first != key) {
//     if (node->key_.first < key)
//       node = node->right;
//     else
//       node = node->left;
//   }
// }
template <class Key, class T>
bool BinaryTree<Key, T>::contains(const Key& key) {
  return find(key) != end() ? true : false;
}
template <class Key, class T>
void BinaryTree<Key, T>::erase(iterator pos) {
  Node<Key, T> tmpRoot = root;
  root = nullptr;
  auto itBegin = this->begin();
  while (itBegin != this->end()) {
    if (pos != itBegin) insert(*itBegin);
    itBegin++;
  }
}

template <class Key, class T>
void BinaryTree<Key, T>::clear() {
  clearRec(root);
  clearEnd();
  root = nullptr;
  size_ = 0;
}

template <class Key, class T>
void BinaryTree<Key, T>::clearRec(N node) {
  if (node != nullptr) {
    clearRec(node->left);
    clearRec(node->right);
    delete node;
  }
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