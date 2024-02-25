#ifndef ITERATOR_H__
#define ITERATOR_H__

template <class Key>
struct Node;

template <class Key>
class BinaryTree;

namespace it {
template <class Key>
class iterator {
 public:
  using value_type = Key;
  using reference = value_type&;
  using pointer = value_type*;

  iterator(Node<Key>* node) : CNode(node) {}
  reference operator*() const { return CNode->key_; }
  Node* operator*() { return CNode; }
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
      Node<Key>* tempNode = CNode->parent;
      Node<Key>* last = CNode->last;
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
  Node<Key>* CNode = nullptr;
};

template <class Key>
class const_iterator {
 public:
  using value_type = Key;
  using reference = const value_type&;
  using pointer = const value_type*;

  const_iterator(const Node<Key>* node) : CNode(node) {}
  reference operator*() const { return CNode->value_; }
  // const Node<Key>* operator*() const { return CNode; }
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
      const Node<Key>* tempNode = CNode->parent;
      const Node<Key>* last = CNode;
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
  const Node<Key>* CNode = nullptr;
};
}  // namespace it
#endif