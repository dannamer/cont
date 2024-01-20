#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include "iterator.h"
// template <class Key, class T>
// struct MapNode {
//   Key kye;
//   T значение;
//   MapNode()
// };

template <class Key, class T>
struct Node {
  Key key_;
  T value_;
  Node *left = nullptr, *right = nullptr, *parent = nullptr;

  Node(Key key, T value) : key_(key), value_(value) {}

  Node(Key key, T value, Node<Key, T>* parent)
      : key_(key), value_(value), parent(parent) {}
};

namespace s21 {
template <class Key, class T>
class BinaryTree {
 public:
};
}  // namespace s21
namespace s21 {
template <class Key, class T>
class BinaryTree {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = it::iterator<Key>;
  using const_iterator = it::const_iterator<Key>;
  using size_type = std::size_t;

 public:
  BinaryTree() {}
  void insert(const_reference value);
  size_type size() const { return size_; }
  bool empty() const { return size_ == 0; }
  iterator find(const_reference key);
  iterator begin(iterator node);
  iterator begin();
  iterator end();

 protected:
  Node<Key, T>* root = nullptr;

  size_type size_ = 0;
  Node<Key>* insertRec(Node<Key>* node, const_reference value,
                       Node<Key>* parent);
  void inOrderTraversal(Node<Key>* current);
  iterator searchRecursive(iterator current, const_reference key);
  // Node<Key> *findMin(Node<Key>* node);
};
#include "BinaryTree.tpp"
}  // namespace s21
#endif