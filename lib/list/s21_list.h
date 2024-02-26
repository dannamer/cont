#pragma once
#include <initializer_list>
#include <limits>
#include <stdexcept>

#include "../ContainerBase/ContainerBase.h"

namespace s21 {
template <typename T>
class list {
 private:
  struct Node {
    T value;
    Node *prev;
    Node *next;
    Node(T val) : value(val), prev(nullptr), next(nullptr) {}
  };

  class Iterator {
   public:
    Iterator() {}
    Iterator(Node *node) : node_(node) {}
    T &operator*() const { return node_->value; }

    Iterator &operator++();
    Iterator operator++(int);

    Iterator &operator--();
    Iterator operator--(int);

    Node *get_node() { return node_; }
    bool operator==(const Iterator &other) const {
      return node_ == other.node_;
    }
    bool operator!=(const Iterator &other) const {
      return node_ != other.node_;
    }

   private:
    Node *node_ = nullptr;
  };

  class const_Iterator : public Iterator {
   public:
    const_Iterator(){};
    const_Iterator(const Iterator &node_) : Iterator(node_){};
    T &operator*() const { return Iterator::operator*(); };
  };

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = Iterator;
  using const_iterator = const_Iterator;
  using size_type = std::size_t;

 private:
  Node *head_ = nullptr;
  Node *tail_ = nullptr;
  size_type size_ = 0;
  Node *findNode(iterator pos);
  void checkSize() const;
  void split(list<T> &source, list<T> &left, list<T> &right);

 public:
  list() {}
  ~list() { clear(); }
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);

  list<T> &operator=(list &&l);
  list<T> &operator=(const list &l);

  const_reference front() const;
  const_reference back() const;

  iterator begin() { return iterator(head_); }
  iterator end() { return iterator(nullptr); }

  bool empty() const { return !size_; }
  size_type size() const { return size_; }
  size_type max_size() const { return std::numeric_limits<size_type>::max(); }

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);

  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void sort();

  void swap(list &other);
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();

  template <typename... Args>
  void emplace_front(Args &&...args);
  template <typename... Args>
  void emplace_back(Args &&...args);
  template <typename... Args>
  iterator emplace(iterator pos, Args &&...args);
};
}  // namespace s21
#include "s21_list.tpp"
