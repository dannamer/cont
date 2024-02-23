#include <iostream>
#include <list>
#include <string>

#include "s21_list.h"  // Убедитесь, что путь к вашему заголовочному файлу указан правильно

int main() {
  s21::list<int> myList;
  myList.emplace_back(30, 34, 50);
  int a = myList.front();
}