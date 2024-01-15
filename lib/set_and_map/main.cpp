#include <iostream>
#include <set>
#include "BinaryTree.h"

int main() {
  s21::BinaryTree<int> mySet;

  // Добавляем элементы в множество
  mySet.insert(4);
  mySet.insert(2);
  mySet.insert(6);
  mySet.insert(1);
  mySet.insert(3);
  mySet.insert(5);
  mySet.insert(7);

  // Итерируемся по множеству и выводим каждый элемент
  
    // iterator<int> lol = mySet.find(6);
    s21::BinaryTree<int>::iterator lol = mySet.find(6);
    s21::BinaryTree<int>::iterator lol2 = mySet.begin();
    s21::BinaryTree<int>::iterator lol3 = mySet.begin(lol);
    auto it = *lol3;
    iterator<int> a = mySet.find(6);
    ++a;
    lol++;
    // lol++;
    // lol--;

  return 0;
}