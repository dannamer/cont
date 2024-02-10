template <class Key, class T = void>
std::pair<typename BinaryTree<Key, T>::iterator, bool>
BinaryTree<Key, T>::insert(const_reference value) {
  bool isset = true;
  N tmp = insertRec(root, value, nullptr, isset);
  if (isset) ++size_;
  setNewEnd();
  return std::make_pair(iterator(tmp), isset);
}

template <class Key, class T = void>
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