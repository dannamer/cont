#include <iostream>
#include <map>
#include <set>

#include "s21_map.h"
#include "s21_set.h"

// namespace s21 {
// template <class Key>
// class set : public BinaryTree<Key, Key> {
//  public:
//   using value_type = Key;
//   using iterator = it::iterator<Key, Key>;
//   using reference = value_type&;
//   using const_reference = const value_type&;

//   std::pair<iterator, bool> insert(const_reference value) {
//     auto keyValue = std::make_pair(value, value);
//     bool isset = true;
//     N tmp = insertRec(root, keyValue, nullptr, isset);
//     if (isset) ++size_;
//     this->setNewEnd();
//     return std::make_pair(iterator(tmp), isset);
//   }

//   iterator find(const Key& key) {
//     N fNode = root;
//     this->searchNode(key, fNode);
//     return fNode ? iterator(fNode) : this->end();
//   }

//  private:
//   using BinaryTree<Key, Key>::root;
//   using BinaryTree<Key, Key>::insertRec;
//   using BinaryTree<Key, Key>::size_;
//   using N = Node<Key, Key>*;
// };
// }  // namespace s21

int main() {
    s21::set<int> a = {3}; 
    return 0;
}