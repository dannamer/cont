// #include <iostream>

// #include "s21_vector.h"

// int main() {
//     s21::vector<char> lol1 = {1, 3, 4, 5, 2, 2};
//     s21::vector<char> lol2 = {3, 3, 3, 3, 3, 3};
//     s21::ContainerBase<int> lol3;
//     lol1.swap(lol2);
//     lol1.clear();
//     lol1.push_back(10);
//     std::cout << sizeof(s21::vector<int>) << std::endl;
//     // lol1.push(10);

// }

#include <iostream>
#include <new>  // для std::nothrow

class MemoryBlock {
 public:
  // Конструктор
  MemoryBlock(size_t size)
      : _size(size), _data(new(std::nothrow) char[size]()) {
    std::cout << "Выделено " << _size << " байт" << std::endl;
  }

  // Деструктор
  ~MemoryBlock() {
    if (_data) {
      std::cout << "Освобождено " << _size << " байт" << std::endl;
      delete[] _data;
    }
  }

  // Размер выделенной памяти
  size_t size() const { return _size; }

  size_t _size;
  char* _data;
};

int main() {
  MemoryBlock block(100);  // выделение 1024 байт
  std::cout << static_cast<void*>(block._data) << std::endl;
  block._data--;
  std::cout << static_cast<void*>(block._data) << std::endl;
  std::cout << block._data[0] << std::endl;
  std::cout << "Размер блока: " << block.size() << " байт" << std::endl;
  return 0;
}