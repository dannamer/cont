#ifndef ITERATOR_H__
#define ITERATOR_H__
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
  iterator &operator--() {
    if (currentNode->left != nullptr) {
      currentNode = currentNode->left;
      while (currentNode->right != nullptr) {
        currentNode = currentNode->right;
      }
    } else {
      Node<T> *tempNode = currentNode->parent;
      while (tempNode != nullptr && currentNode == tempNode->left) {
        currentNode = tempNode;
        tempNode = tempNode->parent;
      }
      currentNode = tempNode;
    }
    return *this;
  }
  iterator<T> operator--(int) {
    iterator<T> temp = *this;
    --(*this);
    return temp;
  }
  iterator &operator++() {
    if (currentNode->right != nullptr) {
      currentNode = currentNode->right;
      while (currentNode->left != nullptr) {
        currentNode = currentNode->left;
      }
    } else {
      Node<T> *tempNode = currentNode->parent;
      while (tempNode != nullptr && currentNode == tempNode->right) {
        currentNode = tempNode;
        tempNode = tempNode->parent;
      }
      currentNode = tempNode;
    }
    return *this;
  }

  iterator<T> operator++(int) {
    iterator<T> temp = *this;
    ++(*this);
    return temp;
  }
  bool operator==(const iterator<T> &other) const {
    return currentNode == other.currentNode;
  }
  bool operator!=(const iterator<T> &other) const {
    return currentNode != other.currentNode;
  }

 private:
  Node<T> *currentNode = nullptr;
};
#endif
