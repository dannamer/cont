#ifndef S21_MAP_H_
#define S21_MAP_H_
#include "BinaryTree.h"
namespace s21 {
template <class Key, class T>
class map : public BinaryTree<std::pair<const Key, T>> {
 public:
  using value_type = std::pair<const Key, T>;
  using typename BinaryTree<value_type>::key_type;
  using typename BinaryTree<value_type>::reference;
  using typename BinaryTree<value_type>::const_reference;
  using typename BinaryTree<value_type>::iterator;
  using typename BinaryTree<value_type>::const_iterator;
  using typename BinaryTree<value_type>::size_type;
  using typename BinaryTree<value_type>::Node;
  using typename BinaryTree<value_type>::insert;

  map() {}
  ~map() {}
  map(std::initializer_list<value_type> const &items)
      : BinaryTree<value_type>(items) {}
  map(const map &m) : BinaryTree<value_type>(m) {}
  map(map &&m) : BinaryTree<value_type>(std::move(m)) {}
  T &at(const Key &key) {
    auto it = search(key);
    if (it != this->end()) {
      return it->second;
    } else {
      throw std::out_of_range("Нету такого ключа");
    }
  }
  T &operator[](const Key &key) {
    auto it = search(key);
    if (it != this->end()) {
      return it->second;
    } else {
      auto pair = insert(std::make_pair(key, T()));
      return pair.first->second;
    }
  }
  std::pair<iterator, bool> insert(const Key &key, const T &obj) {
    return insert(std::make_pair(key, obj));
  }
  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj) {
    auto it = insert(std::make_pair(key, obj));
    if (!it.second) {
      it.first->second = obj;
    }
    return it;
  }

  bool contains(const Key &key) {
    return search(key) != this->end() ? true : false;
  }

 private:
  iterator search(const Key &key) {
    return iterator(searchRec(this->root, key), this);
  }
  Node *searchRec(Node *node, const Key &key) {
    if (node == nullptr || node->key_.first == key) {
      return node;
    }
    if (key < node->key_.first) {
      return searchRec(node->left, key);
    } else {
      return searchRec(node->right, key);
    }
  }
  // bool operator<(const std::pair<Key, T> &lhs,
  //                const std::pair<Key, T> &rhs) const {
  //   return lhs.first < rhs.first;
  // }
};
}  // namespace s21
#endif