#ifndef S21_LIST_H_
#define S21_LIST_H_
#include <limits>

#include "../ContainerBase/ContainerBase.h"
#include "../iterator/iterator.h"
// #include "ContainerBase.h"
namespace s21 {

template <typename T>
class list {
 public:
  using iterator = s21::iterator<T>;
  using const_iterator = s21::const_iterator<T>;
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = std::size_t;
  list() {}
  ~list() { clear(); }
  list(size_type n);
  list(std::initializer_list<value_type> const& items);
  list(const list& l);
  list(list&& l);
  list<T>& operator=(list&& l);
  list<T>& operator=(list& l);
  iterator begin() { return iterator(head_); }
  iterator end() { return iterator(tail_->next); }
  const_reference front() const;
  const_reference back() const;
  bool empty() const { return !size_; }
  size_type size() const { return size_; }
  size_type max_size() const { return std::numeric_limits<size_type>::max(); }
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void pop_back();
  void pop_front();
  void push_back(const_reference value);
  void push_front(const_reference value);
  void swap(list& other);
  void splice(const_iterator pos, list& other);
 private:
  Node<T>* head_ = nullptr;
  Node<T>* tail_ = nullptr;
  size_type size_ = 0;
  void checkSize() {
    if (!size_) {
      throw std::runtime_error("Список пуст");
    }
  }
  void split(list<T>& source, list<T>& left, list<T>& right);
};
#include "list.tpp"
}  // namespace s21

#endif