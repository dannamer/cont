#ifndef ITERATOR_H__
#define ITERATOR_H__

template <class Key, class T>
struct Node;

template <class Key, class T>
class BinaryTree;

namespace it {
template <class Key, class T>
class iterator {
 public:
  using value_type = std::pair<const Key, T>;
  using reference = value_type&;
  using pointer = value_type*;

  iterator(Node<Key, T>* node) : CNode(node) {}
  reference operator*() const { return CNode->key_; }
  Node<Key, T>* operator*() { return CNode; }
  pointer operator->() const { return &(CNode->key_); }
  iterator operator+(const std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
      ++(*this);
    }
    return *this;
  }
  iterator operator++() {
    if (CNode->right != nullptr) {
      CNode = CNode->right;
      while (CNode->left != nullptr) {
        CNode = CNode->left;
      }
    } else {
      Node<Key, T>* tempNode = CNode->parent;
      Node<Key, T>* last = CNode->last;
      while (tempNode != nullptr && CNode == tempNode->right) {
        CNode = tempNode;
        tempNode = tempNode->parent;
      }
      CNode = tempNode;
      if (!CNode) {
        CNode = last;
      }
    }
    return *this;
  }
  iterator operator++(int) {
    iterator temp = *this;
    ++(*this);
    return temp;
  }
  bool operator==(const iterator& other) const { return CNode == other.CNode; }

  bool operator!=(const iterator& other) const { return !(*this == other); }

 private:
  Node<Key, T>* CNode = nullptr;
};

template <class Key, class T>
class const_iterator {
 public:
  using value_type = std::pair<const Key, T>;
  using reference = const value_type&;
  using pointer = const value_type*;

  const_iterator(const Node<Key, T>* node) : CNode(node) {}
  reference operator*() const { return CNode->value_; }
  // const Node<Key, T>* operator*() const { return CNode; }
  pointer operator->() const { return &(CNode->value_); }
  const_iterator& operator+(const std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
      ++(*this);
    }
    return *this;
  }
  const_iterator& operator++() {
    if (CNode->right != nullptr) {
      CNode = CNode->right;
      while (CNode->left != nullptr) {
        CNode = CNode->left;
      }
    } else {
      const Node<Key, T>* tempNode = CNode->parent;
      const Node<Key, T>* last = CNode;
      while (tempNode != nullptr && CNode == tempNode->right) {
        CNode = tempNode;
        tempNode = tempNode->parent;
      }
      CNode = tempNode;
      if (!CNode) {
        CNode = last;
      }
    }
    return *this;
  }
  const_iterator operator++(int) {
    const_iterator temp = *this;
    ++(*this);
    return temp;
  }

 private:
  const Node<Key, T>* CNode = nullptr;
};
}  // namespace it
#endif