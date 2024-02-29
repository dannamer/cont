#include <list>
#include "s21_list.h"
#include <iostream>

// #include "s21_list.h"
int main() {
  s21::list<int> a {1,2,3,4,5,6};
  std::list<int> b {1,2,3,4,5,6};


  auto ita = a.begin();
  auto itb = b.begin();
  auto itb2 = b.begin();
  

  std::cout << *ita << std::endl;
  std::cout << *itb << std::endl;
  std::cout << (itb == itb2) << std::endl;

  return 0;
}