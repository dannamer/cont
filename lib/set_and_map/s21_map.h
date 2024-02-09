#ifndef S21_MAP_H_
#define S21_MAP_H_
#include "BinaryTree.h"
namespace s21 {
template <class Key, class T>
class map : public BinaryTree<Key, T> {
 public:
  using typename BinaryTree<Key, T>::key_type;
  using typename BinaryTree<Key, T>::mapped_type;
  using typename BinaryTree<Key, T>::value_type;
  using typename BinaryTree<Key, T>::reference;
  using typename BinaryTree<Key, T>::const_reference;
  using typename BinaryTree<Key, T>::iterator;
  using typename BinaryTree<Key, T>::const_iterator;
  using typename BinaryTree<Key, T>::size_type;

  using typename BinaryTree<Key, T>::insert;

  map() {}
  ~map() {}
  map(std::initializer_list<value_type> const &items)
      : BinaryTree<Key, T>(items) {}
  map(const map &m) : BinaryTree<Key, T>(m) {}
  map(map &&m) : BinaryTree<Key, T>(std::move(m)) {}
  T &at(const Key &key) {
    auto it = find(key);
    if (it != this->end()) {
      return it->second;
    } else {
      throw std::out_of_range("Нету такого ключа");
    }
  }
  T &operator[](const Key &key) {
    auto it = find(key);
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

 private:
  using typename BinaryTree<Key, T>::find;
};
}  // namespace s21
#endif