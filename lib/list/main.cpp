#include <iostream>
#include <list>
#include <string>

#include "s21_list.h"  // Убедитесь, что путь к вашему заголовочному файлу указан правильно

int main() {
  std::list<std::pair<int, std::string>> vec;
  s21::list<std::pair<int, std::string>> lol;
  // Создаем и добавляем пару на месте без необходимости создавать временный
  // объект
  vec.emplace_back(1, "Apple");
  lol.emplace_back(1, "Apple");

  // Элемент сконструирован напрямую в памяти вектора, оптимизируя
  // производительность
  vec.emplace_back(2, "Banana");
  lol.emplace_back(2, "lol");
}