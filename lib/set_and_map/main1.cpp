#include <iostream>
#include <map>
#include "s21_map.h"
#include "s21_set.h"
int main() {
  s21::map<int, int> a;
  s21::set<int> lol = {1, 3, 4, 5, 6};
  a.insert(std::make_pair(-1, 3));
  a.insert(-5, 3);
  a.insert(3, 3);
  a.insert(9, 3);
  a.insert(6, 3);
  auto itm = a.end();
  return 0;
}