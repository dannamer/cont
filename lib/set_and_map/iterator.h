#ifndef ITERATOR_H__
#define ITERATOR_H__
#include "../stack/s21_stack.h"
template <class T>
struct Node;

template <class T>
class iterator {
 public:
  using value_type = T;
  using pointer = T *;
  using reference = T &;
  iterator() {}
  iterator(Node<T> *node) : currentNode(node) {}
  reference operator*() const { return currentNode->value; }
  pointer operator->() const { return &currentNode->value; }
  iterator &operator++() {
    currentNode = currentNode->next;
    return *this;
  }

 private:
  s21::stack<Node<T> *> stack;
};

#endif
