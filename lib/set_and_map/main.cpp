#include <iostream>
#include <map>
// #include <set>

#include "BinaryTree.h"

template <class Key>
class set : public s21::BinaryTree<Key, Key> {
 private:
 public:
  using value_type = Key;
  using iterator = it::iterator<Key, Key>;
  std::pair<iterator, bool> insert(const value_type& value) override {
    this->isset = true;
    this->root = insertRec(this->root, value, nullptr);
    return std::make_pair(iterator(this->root), this->isset);
  }
};
int main() {
  s21::BinaryTree<int, int> mySet;
  // Добавляем элементы в множество
  auto lol = mySet.insert(std::make_pair<int, int>(1, 2));
  auto lol2 = mySet.insert(std::make_pair<int, int>(1, 2));
  lol.first++;
  mySet.insert(std::make_pair<int, int>(3, 4));
  mySet.insert(std::make_pair<int, int>(5, 6));
  mySet.insert(std::make_pair<int, int>(7, 8));
  set<int> Set2;
  Set2.insert(2);
  std::map<int, int> mySet1;
  // Добавляем элементы в множество
  auto lol1 = mySet1.insert(std::make_pair<int, int>(1, 2));
  lol1.first++;
  auto lol3 = mySet1.insert(std::make_pair<int, int>(1, 2));
  mySet1.insert(std::make_pair<int, int>(3, 4));
  mySet1.insert(std::make_pair<int, int>(5, 6));
  mySet1.insert(std::make_pair<int, int>(7, 8));
  // Итерируемся по множеству и выводим каждый элемент

  // iterator<int> lol = mySet.find(6);
  // s21::BinaryTree<int>::iterator lol = mySet.find(6);
  // s21::BinaryTree<int>::iterator lol2 = mySet.begin();
  // s21::BinaryTree<int>::iterator lol3 = mySet.begin(lol);

  // // auto it = *lol3;
  // it::iterator<int> a = mySet.find(4);
  // ++a;
  // a++;
  // it::iterator<int> l;
  // l = a++;
  // --a;
  // --l;
  // l--;
  // lol++;
  // s21::BinaryTree<int>::iterator p = mySet.begin(l);
  // lol++;
  // lol--;

  return 0;
}

// template <class T>
// struct Node {
//   T key_;

//   Node *left = nullptr, *right = nullptr, *parent = nullptr;

//   Node(T key) : key_(key) {}

//   Node(T key, Node<T>* parent) : key_(key), parent(parent) {}
// };

// int main() {
//   Node<std::pair<int, int>> a(std::make_pair<int, int>(1, 2));

// }