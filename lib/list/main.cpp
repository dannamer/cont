#include <list>
// #include <algorithm>
#include <iostream>

// #include "s21_list.h"
int main() {
  std::list<int> a{1, 1, 2, 3, 2, 1, 2, 3, 3, 3, 3, 4, 5};
  a.unique();
  for (auto it = a.begin(); it != a.end(); it++) std::cout << *it << " ";
  std::cout << std::endl;
  auto it = a.begin();
  return 0;
}