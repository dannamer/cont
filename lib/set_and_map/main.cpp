#include <string>

#include "s21_map.h"

int main() {
  s21::map<int, std::string> map;

  map.insert({1, "one"});
  map.insert({2, "two"});
  map.insert({3, "three"});
  map.insert({5, "five"});

  auto it1 = ++map.begin();
  map.erase(it1);

  return 0;
}