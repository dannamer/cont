#ifndef S21_SET_H_
#define S21_SET_H_

#include "BinaryTree.h"
namespace s21 {
template <class Key>
class set : public s21::BinaryTree<Key, Key> {
 public:
  using typename BinaryTree<Key, Key>::key_type;
  using typename BinaryTree<Key, Key>::value_type;
  using typename BinaryTree<Key, Key>::reference;
  using typename BinaryTree<Key, Key>::const_reference;
  using typename BinaryTree<Key, Key>::iterator;
  using typename BinaryTree<Key, Key>::const_iterator;
  using typename BinaryTree<Key, Key>::size_type;
  set() {}
  ~set() {}
  set(std::initializer_list<value_type> const &items)
      : BinaryTree<Key, Key>(items) {}
  set(const set &s) : BinaryTree<Key, Key>(s) {}
  set(set &&s) : BinaryTree<Key, Key>(std::move(s)) {}


 private:
};
}  // namespace s21
#endif