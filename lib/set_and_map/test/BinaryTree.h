#ifndef BINARYTREE_H_
#define BINARYTREE_H_
namespace s21 {
template <class Key>
struct Node {
  Key key_;
  Node *left = nullptr, *right = nullptr, *parent = nullptr, *last = nullptr;
  Node(value_type key, Node* parent = nullptr) : key_(key), parent(parent) {}
};

template <class Key, class T = void>
class BinaryTree {
 public:
  using key_type = Key;
  using mapped_type = T;
  using 
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = it::iterator<Key, T>;
  using const_iterator = it::const_iterator<Key, T>;
  using size_type = std::size_t;
	std::pair<iterator, bool> insert(const_reference value);
 protected:
  using N = Node<value_type>*;
  N root = nullptr;
  N rootEnd = nullptr;
  size_type size_ = 0;
};
#include "BinaryTree.cpp"
}  // namespace s21
#endif
