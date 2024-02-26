#include <iostream>
#include <map>
#include <set>

#include "BinaryTree.h"
#include "s21_map.h"
#include "s21_set.h"

int main() {
  s21::map<int, std::string> map;

  // Insert a new element with a key that does not exist.
  auto [it1, inserted1] = map.insert_or_assign(1, "one");
  std::cout << "Inserting key 1: " << (inserted1 ? "success" : "failed")
            << std::endl;

  // Insert a new element with a key that already exists.
  auto [it2, inserted2] = map.insert_or_assign(1, "ONE");
  std::cout << "Inserting key 1 again: " << (inserted2 ? "success" : "failed")
            << std::endl;

  // Insert multiple elements.
  map.insert_or_assign(2, "two");
  map.insert_or_assign(3, "three");
  map.insert_or_assign(4, "four");
  map.insert_or_assign(5, "five");

  std::cout << "Map size: " << map.size() << std::endl;

  std::cout << "Map contents:" << std::endl;
  for (const auto& pair : map) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }

  return 0;
}
