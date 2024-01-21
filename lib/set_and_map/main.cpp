#include <iostream>
#include <map>
#include <set>

#include "BinaryTree.h"

namespace s21 {
template <class Key>
class set : public BinaryTree<Key, Key> {
 public:
  using value_type = Key;
  using iterator = it::iterator<Key, Key>;
  using reference = value_type&;
  using const_reference = const value_type&;

  std::pair<iterator, bool> insert(const_reference value) {
    auto keyValue = std::make_pair(value, value);
    bool isset = true;
    N tmp = insertRec(root, keyValue, nullptr, isset);
    if (isset) ++size_;
    this->setNewEnd();
    return std::make_pair(iterator(tmp), isset);
  }

 private:
  using BinaryTree<Key, Key>::root;
  using BinaryTree<Key, Key>::insertRec;
  using BinaryTree<Key, Key>::size_;
  using N = Node<Key, Key>*;
};set
  st.insert(3);
  st.insert(9);
  st.insert(5);
  int a = st.size();
  auto it = st.end();
  it++;
  it++;
  it++;
  it++;

  // s21::BinaryTree<int, int> mySet;
  // // Добавляем элементы в множество
  // auto lol = mySet.insert(std::make_pair<int, int>(1, 2));
  // auto lol2 = mySet.insert(std::make_pair<int, int>(1, 2));
  // lol.first++;
  // mySet.insert(std::make_pair<int, int>(3, 4));
  // mySet.insert(std::make_pair<int, int>(-1, 4));
  // mySet.insert(std::make_pair<int, int>(-2, 4));
  // mySet.insert(std::make_pair<int, int>(5, 6));
  // mySet.insert(std::make_pair<int, int>(7, 8));
  // s21::set<int> Set1;
  // std::set<int> Set2;
  // auto a1 = Set1.insert(2);
  // auto a2 = Set2.insert(2);
  // auto a1w = Set1.insert(5);
  // auto a2w = Set2.insert(5);
  // auto a3w = Set2.insert(5);
  // auto a4w = Set1.insert(5);
  // std::map<int, int> mySet1;
  // // Добавляем элементы в множество
  // auto lol1 = mySet1.insert(std::make_pair<int, int>(1, 2));
  // lol1.first++;
  // auto lol3 = mySet1.insert(std::make_pair<int, int>(1, 2));
  // mySet1.insert(std::make_pair<int, int>(3, 4));
  // mySet1.insert(std::make_pair<int, int>(5, 6));
  // mySet1.insert(std::make_pair<int, int>(7, 8));

  // auto beg = mySet.begin();
  // Итерируемся по множеству и выводим каждый элемент

  // st.insert(-1);
  // st.insert(-5);
  // st.insert(3);
  // st.insert(9);
  // st.insert(6);
  // auto it = st.end();
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