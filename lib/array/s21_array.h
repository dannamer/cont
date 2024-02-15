#ifndef ARRAY_H
#define ARRAY_H
namespace s21 {
template <class T, std::size_t N>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

  array() {}
  array(std::initializer_list<value_type> const &items);
  array(const array &a);
  array(array &&a);
  ~array() {}
  array<T, N> &operator=(array &&a);
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  class iterator {
   public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T *;
    using reference = T &;
    iterator(pointer p = nullptr) : ptr(p) {}
    reference operator*() const { return *ptr; }
    iterator &operator++() {
      ++ptr;
      return *this;
    }
    iterator operator++(int) {
      iterator tmp = *this;
      ++(*this);
      return tmp;
    }
    iterator &operator++() {
      --ptr;
      return *this;
    }
    iterator operator++(int) {
      iterator tmp = *this;
      --(*this);
      return tmp;
    }
    bool operator==(const iterator &other) const { return ptr == other.ptr; }
    bool operator!=(const iterator &other) const { return ptr != other.ptr; }

   private:
    pointer ptr;
  };
  bool empty() { return !N; }
  size_type size() { return N; }
  size_type max_size() {}
  void swap(array &other);
  void fill(const_reference value);
  iterator begin() { return iterator(data); }
  iterator end() { return iterator(data + N); }
  
 private:
  T data[N];
};
#include "s21_array.tpp"
}  // namespace s21

#endif