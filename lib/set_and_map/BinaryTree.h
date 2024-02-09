#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <limits>

#include "iterator.h"

template <class Key, class T>
struct Node {
  using value_type = std::pair<const Key, T>;
  value_type key_;
  Node *left = nullptr, *right = nullptr, *parent = nullptr, *last = nullptr;
  Node(value_type key) : key_(key) {}
  Node(value_type key, Node* parent) : key_(key), parent(parent) {}
};
namespace s21 {
template <class Key, class T>
class BinaryTree {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = it::iterator<Key, T>;
  using const_iterator = it::const_iterator<Key, T>;
  using size_type = std::size_t;
  BinaryTree() {}
  ~BinaryTree();
  BinaryTree(std::initializer_list<value_type> const& items);
  BinaryTree(const BinaryTree& m);
  BinaryTree(BinaryTree&& m);
  BinaryTree<Key, T>& operator=(BinaryTree&& m);

  std::pair<iterator, bool> insert(const_reference value);
  bool empty() const { return !size_; }
  size_type size() const { return size_; }
  size_type max_size() { return std::numeric_limits<size_type>::max(); }  // ?
  iterator begin();
  iterator end();
  iterator find(const Key& key);
  void clear();
  void erase(iterator pos);
  bool contains(const Key& key);
  void swap(BinaryTree& other);
  void merge(BinaryTree& other);

 protected:
  using N = Node<Key, T>*;
  N insertRec(N node, const_reference value, N parrent, bool& isset);
  void clearRec(N node);
  void clearEnd();
  void setNewEnd();
  N copyBinaryTree(N CRoot);
  N root = nullptr;
  N rootEnd = nullptr;
  size_type size_ = 0;
};
#include "BinaryTree.tpp"
}  // namespace s21
#endif