#ifndef _ITERATOR_H_
#define _ITERATOR_H_

namespace s21 {
template <typename T>
struct Node {
  T value;
  Node* prev;
  Node* next;
  Node(T val) : value(val), prev(nullptr), next(nullptr) {}
};

template <typename T>
class iterator {
 public:
  iterator() {}
  iterator(Node<T>* node) : node_(node) {}
  T& operator*() const { return node_->value; }
  iterator& operator++() {
    node_ = node_->next;
    return *this;
  }
  iterator operator++(int) {
    iterator temp = *this;
    ++(*this);
    return temp;
  }
  iterator& operator--() {
    if (node_ != nullptr) {
      node_ = node_->prev;
    }
    return *this;
  }
  iterator operator--(int) {
    iterator temp = *this;
    --(*this);
    return temp;
  }
  Node<T>* get_node() { return node_; }
  bool operator==(const iterator& other) const { return node_ == other.node_; }
  bool operator!=(const iterator& other) const { return node_ != other.node_; }

 private:
  Node<T>* node_ = nullptr;
}; 

template <typename T>
class const_iterator {
 public:
  const_iterator(const Node<T>* node) : node_(node) {}
  const T& operator*() const { return node_->value; }
  const_iterator& operator++() {
    if (node_ != nullptr) node_ = node_->next;
    return *this;
  }
  const_iterator operator++(int) {
    const_iterator temp = *this;
    ++(*this);
    return temp;
  }
  const_iterator& operator--() {
    if (node_ != nullptr) {
      node_ = node_->prev;
    }
    return *this;
  }
  const_iterator operator--(int) {
    const_iterator temp = *this;
    --(*this);
    return temp;
  }
  const Node<T>* get_node() const { return node_; }
  bool operator==(const const_iterator& other) const {
    return node_ == other.node_;
  }
  bool operator!=(const const_iterator& other) const {
    return node_ != other.node_;
  }

 private:
  const Node<T>* node_;
};
}  // namespace s21

#endif