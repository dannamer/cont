#ifndef _HELP_H_
#define _HELP_H_
namespace s21 {
template <typename T>
class help {
 protected:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = std::size_t;
  T* data_ = nullptr;
  size_type size_ = 0;
  size_type capacity_ = 0;
  void malloc();
  void realloc();
  void NewCapacity();
  void CopyElements(T* dest, const T* source);
  void initializeFromList(const std::initializer_list<T>& list);
  void copyFromOther(const help& other);
  void move(help &s);
  void checkEmpty();
};
#include "help.tpp"
}  // namespace s21
#endif