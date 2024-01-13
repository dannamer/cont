#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include "iterator.h"

template <class T>
struct Node {
  T value;
  Node *left = nullptr, *right = nullptr, *parent = nullptr;
  Node(T val) : value(val) {}
  Node(T val, Node<T>* parent) : value(val), parent(parent) {}
};

template <class Key>
class BinaryTree {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = std::size_t;

 public:
  BinaryTree() {}
  void insert(const_reference value);
  size_type size() const { return size; }
  bool empty() const { return size == 0 }

 protected:
  Node<Key>* root = nullptr;
  size_type size = 0;
  Node<Key>* insertRec(Node<Key>* node, const_reference value);
};

#endif