#ifndef S21_MAP_H_
#define S21_MAP_H_
#include "BinaryTree.h"

template <class Key, class T>
class map {
 private:
  using NodeType = std::pair<Key, Value>;
  BinaryTree<NodeType> tree;

 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
	using iterator = 
 private:
  BinaryTree<value_type> tree;
};

template <class Key>
class set : public BinaryTree<Node<key>> {};

#endif