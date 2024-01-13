#ifndef ITERATOR_H__
#define ITERATOR_H__
#include "../stack/s21_stack.h"

template <class T>
struct Node;

template <class Key>
class BinaryTree;

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
    if (currentNode != nullptr) {
      if (currentNode->right != nullptr) {
        currentNode = findMin(currentNode->right);
      } else {
        while (currentNode->parent != nullptr &&
               currentNode == currentNode->parent->right) {
          currentNode = currentNode->parent;
        }
        currentNode = currentNode->parent;
      }
    }
    return *this;
  }

 private:
  Node<T> *currentNode;
};

#endif
