#include <list>
#include "s21_list.h"
#include <iostream>

// #include "s21_list.h"
int main() {
  std::list<int> a {10,1,2,2,4,5};
  std::list<int> b {23, 8, 123123};
  a.merge(b);
  


  return 0;
}