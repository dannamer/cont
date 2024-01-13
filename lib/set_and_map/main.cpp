#include <iostream>
#include <set>

int main() {
  std::set<int> mySet;

  // Добавляем элементы в множество
  mySet.insert(4);
  mySet.insert(2);
  mySet.insert(6);
  mySet.insert(1);
  mySet.insert(3);
  mySet.insert(5);
  mySet.insert(7);

  // Итерируемся по множеству и выводим каждый элемент
  
    auto lol = mySet.begin();
    lol++;
    lol++;
    lol++;
    lol--;

  return 0;
}