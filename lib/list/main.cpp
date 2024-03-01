#include <list>
#include "s21_list.h"
#include <iostream>

// #include "s21_list.h"
int main() {
  s21::list<int> a;
  s21::list<int> b;
  b.push_front(2);
  b.push_front(1);

b.reverse();  


  return 0;
}