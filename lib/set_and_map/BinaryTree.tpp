template <class Key>
BinaryTree<Key>::~BinaryTree() {
  clear();
}

template <class Key>
BinaryTree<Key>::BinaryTree(std::initializer_list<Key> const& items) {
  for (auto it = items.begin(); it != items.end(); ++it) {
    insert(*it);
  }
}

template <class Key>
BinaryTree<Key>::BinaryTree(const BinaryTree& m) {
  size_ = m.size_;
  root = copyBinaryTree(m.root);
  // setNewEnd();
}

template <class Key>
BinaryTree<Key>::BinaryTree(BinaryTree&& m) {
  *this = std::move(m);
}

template <class Key>
void BinaryTree<Key>::merge(BinaryTree& other) {
  for (auto it = other.begin(); it != other.end(); ++it) {
    insert(*it);
  }
  other.clear();
}

template <class Key>
BinaryTree<Key>& BinaryTree<Key>::operator=(BinaryTree&& m) {
  if (this != &m) {
    delete root;
    // delete rootEnd;
    size_ = m.size_;
    root = m.root;
    // rootEnd = m.rootEnd;
    m.size_ = 0;
    m.root = nullptr;
    // m.rootEnd = nullptr;
  }
  return *this;
}

template <class Key>
void BinaryTree<Key>::swap(BinaryTree& other) {
  BinaryTree<Key> tmp = std::move(other);
  other = std::move(*this);
  *this = std::move(tmp);
}

// копирование
template <class Key>
typename BinaryTree<Key>::N BinaryTree<Key>::copyBinaryTree(N CRoot) {
  if (CRoot == nullptr) {
    return nullptr;
  }
  N newNode = new Node(CRoot->key_);
  newNode->left = copyBinaryTree(CRoot->left);
  newNode->right = copyBinaryTree(CRoot->right);
  return newNode;
}

template <class Key>
std::pair<typename BinaryTree<Key>::iterator, bool> BinaryTree<Key>::insert(
    const_reference value) {
  bool isset = true;
  N tmp = insertRec(root, value, nullptr, isset);
  if (isset) ++size_;
  // setNewEnd();
  return std::make_pair(iterator(tmp, this), isset);
}

// template <class Key>
// void BinaryTree<Key>::setNewEnd() {
//   clearEnd();
//   rootEnd = new Node(std::make_pair(size(), 0), (begin() + (size() -
//   1)).getNode()); N last = rootEnd->parent; if (last->left == nullptr)
//     last->last = rootEnd;
//   else if (last != root && last->left != nullptr &&
//            last->left->right == nullptr && last->left->left == nullptr) {
//     last->last = rootEnd;
//     last->left->last = rootEnd;
//     rootEnd->parent = last->left;
//   }
// }

template <class Key>
typename BinaryTree<Key>::N BinaryTree<Key>::insertRec(N node,
                                                       const_reference value,
                                                       N parent, bool& isset) {
  if (node == nullptr) {
    node = new Node(value, parent);
    if (root == nullptr) root = node;
    return node;
  } else if (value < node->key_) {
    N insertedNode = insertRec(node->left, value, node, isset);
    if (node->left == nullptr) node->left = insertedNode;
    return insertedNode;
  } else if (value > node->key_) {
    N insertedNode = insertRec(node->right, value, node, isset);
    if (node->right == nullptr) node->right = insertedNode;
    return insertedNode;
  } else {
    isset = false;
    return node;
  }
}

template <class Key>
typename BinaryTree<Key>::iterator BinaryTree<Key>::begin() {
  Node* node = root;
  while (node != nullptr && node->left != nullptr) {
    node = node->left;
  }
  return iterator(node, this);
}

template <class Key>
typename BinaryTree<Key>::iterator BinaryTree<Key>::end() {
  return iterator(nullptr, this);
}

// template <class Key>
// void BinaryTree<Key>::clearEnd() {
//   if (rootEnd) {
//     rootEnd->parent->last = nullptr;
//     delete rootEnd;
//     rootEnd = nullptr;
//   }
// }

template <class Key>
typename BinaryTree<Key>::iterator BinaryTree<Key>::find(const Key& key) {
  N current = root;
  while (current != nullptr) {
    if (key < current->key_) {
      current = current->left;
    } else if (key > current->key_) {
      current = current->right;
    } else {
      return iterator(current, this);
    }
  }
  return end();
}

// template <class Key>
// void BinaryTree<Key>::searchNode(const Key& key, Node*& node) {
//   while (node && node->key_.first != key) {
//     if (node->key_.first < key)
//       node = node->right;
//     else
//       node = node->left;
//   }
// }
template <class Key>
bool BinaryTree<Key>::contains(const Key& key) {
  return find(key) != end() ? true : false;
}
template <class Key>
void BinaryTree<Key>::erase(iterator pos) {
  deleteNode(root, *pos);
}

template <class Key>
typename BinaryTree<Key>::Node* BinaryTree<Key>::deleteNode(Node* node,
                                                            Key key) {
  if (node == nullptr) {
    return nullptr;
  } else if (key < node->key_) {
    node->left = deleteNode(node->left, key);
  } else if (key > node->key_) {
    node->right = deleteNode(node->right, key);
  } else {
    if (node->left == nullptr || node->right == nullptr) {
      Node* temp = (node->left == nullptr) ? node->right : node->left;
      if (temp != nullptr) {
        temp->parent = node->parent;
      }
      delete node;
      node = temp;
      size_--;
    } else {
      Node* maxLeft = findMax(node->left);
      node->key_ = maxLeft->key_;
      node->right = deleteNode(node->right, maxLeft->key_);
    }
    
  }
  return node;
}
template <class Key>
void BinaryTree<Key>::clear() {
  clearRec(root);
  // clearEnd();
  root = nullptr;
  size_ = 0;
}

template <class Key>
void BinaryTree<Key>::clearRec(N node) {
  if (node != nullptr) {
    clearRec(node->left);
    clearRec(node->right);
    delete node;
  }
}

template <class Key>
typename BinaryTree<Key>::iterator BinaryTree<Key>::iterator::operator--() {
  if (itNode == nullptr) {
    itNode = tree->findMax(tree->root);
  } else if (itNode->left != nullptr) {
    itNode = tree->findMax(itNode->left);
  } else {
    Node* temp = itNode->parent;
    while (temp != nullptr && itNode == temp->left) {
      itNode = temp;
      temp = temp->parent;
    }
    itNode = temp;
  }
  return *this;
}

template <class Key>
typename BinaryTree<Key>::Node* BinaryTree<Key>::findMax(Node* node) {
  if (node) {
    while (node->right != nullptr) {
      node = node->right;
    }
    return node;
  }
  return nullptr;
}