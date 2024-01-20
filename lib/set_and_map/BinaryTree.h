#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include "iterator.h"

template <class Key, class T>
struct Node {
  using value_type = std::pair<const Key, T>;
  value_type key_;
  Node *left = nullptr, *right = nullptr, *parent = nullptr;
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
  virtual std::pair<iterator, bool> insert(const value_type& value);

 protected:
  Node<Key, T>* insertRec(Node<Key, T>* node, const_reference value,
                          Node<Key, T>* parrent);

  Node<Key, T>* root = nullptr;
  bool isset = true;
};
#include "BinaryTree.tpp"
}  // namespace s21
#endif
// namespace s21 {
// template <class Key, class T>
// class BinaryTree {
//  public:
//   using key_type = Key;
//   using mapped_type = T;
//   using value_type = std::pair<const key_type, mapped_type>;
//   using reference = value_type&;
//   using const_reference = const value_type&;
//   using iterator = it::iterator<Key, T>;
//   using const_iterator = it::const_iterator<Keym T>;
//   using size_type = std::size_t;

//  public:
//   BinaryTree() {}
//   void insert(const_reference value);
//   size_type size() const { return size_; }
//   bool empty() const { return size_ == 0; }
//   iterator find(const_reference key);
//   iterator begin(iterator node);
//   iterator begin();
//   iterator end();
//   value_type lol.fert protected : Node<value_type>* root = nullptr;
//   Node<Key>* root

//       size_type size_ = 0;
//   Node<Key>* insertRec(Node<Key>* node, const_reference value,
//                        Node<Key>* parent);
//   void inOrderTraversal(Node<Key>* current);
//   iterator searchRecursive(iterator current, const_reference key);
//   // Node<Key> *findMin(Node<Key>* node);
// };
// #include "BinaryTree.tpp"
// }  // namespace s21