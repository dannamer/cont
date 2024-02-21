#include <iostream>
#include <list>
#include <string>

#include "s21_list.h"  // Убедитесь, что путь к вашему заголовочному файлу указан правильно

int main() {
  // std::list<int> vec = {2, 3, 4, 5};
  s21::list<int> lol = {2, 3, 4, 5};
  // Создаем и добавляем пару на месте без необходимости создавать временный
  // объект
  // vec.emplace_front(1, -5, 8);
  lol.emplace_front(1, -5, 8);

  // Элемент сконструирован напрямую в памяти вектора, оптимизируя
  // производительность
//   vec.emplace_front(2, "Banana");
//   lol.emplace_front(2, "lol");
}