#include <iostream>
#include <list>
#include <string>

#include "s21_list.h"  // Убедитесь, что путь к вашему заголовочному файлу указан правильно

int main() {
  // s21::list<int> myList1 = {30, 34, 50};
  // std::list<int> myList2 = {30, 34, 50};
  // myList1.push_back(9);
  // myList2.push_back(9);
  // int a = myList.front();
  s21::list<int> lst;
  lst.push_back(1);
  lst.push_back(2);
  auto it = lst.back();
}