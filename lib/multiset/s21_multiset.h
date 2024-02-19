#ifndef MULTISET_
#define MULTISET_

namespace s21 {
// template <typename T>
// struct Node {
//   T value;
//   unsigned int count;
//   Node* left;
//   Node* right;
//   Node* parent;
//   Node(const T& val, Node* par = nullptr)
//       : value(val), count(1), left(nullptr), right(nullptr), parent(par) {}
// };

// template <class Key>
// class iterator {
//  public:
//   using value_type = Key;
//   using reference = value_type&;
//   using pointer = value_type*;
//   iterator(Node<Key>* node_) : node(node_);
//   reference operator*() const;

//  private:
//   Node<Key>* node;
// };

template <class Key>
class multiset {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const value_type&;

 private:
  struct Node {
    Key value;
    unsigned int count = 1;
    Node *left = nullptr, *right = nullptr, *parent, *last = nullptr;
    Node(const_reference val, Node* par = nullptr) : value(val), parent(par) {}
  };

 public:
  // using iterator = iterator<Key>;
  // using const_iterator = const_iterator<Key>;
  using size_type = std::size_t;
  class iterator {
   public:
    iterator(Node* node_) : node(node_) {}
    reference operator*() const { return node->value; }
    // Node& operator->() const { return *node->value; }
    Node* operator&() { return node; }
    iterator operator++();
    iterator operator++(int);

   private:
    Node* node;
  };
  multiset() {}
  multiset(std::initializer_list<value_type> const& items);
  multiset(const multiset& ms);
  multiset(multiset&& ms);
  ~multiset() { clear(); }
  multiset& operator=(multiset&& ms);
  void erase(iterator pos);
  iterator begin();
  iterator end();
  bool empty() { return !size_; }
  size_type size() { return size_; }
  size_type max_size() { return 0; }
  void merge(multiset& other);
  void swap(multiset& other);
  iterator insert(const_reference value);
  void clear();
  size_type count(const_reference key) const {
    Node* node1 = search(root, key);
    return (node1 != nullptr) ? node1->count : 0;
  }
  iterator find(const_reference key) { return iterator(search(root, key)); }
  bool contains(const_reference key) const {
    return search(root, key) != nullptr;
  }
  std::pair<iterator, iterator> equal_range(const Key& key);
  iterator lower_bound(const_reference key);
  iterator upper_bound(const_reference key);

 private:
  Node* root = nullptr;
  Node* rootEnd = nullptr;
  size_type size_ = 0;
  Node* insertRec(Node* node, const_reference value, Node* parent);
  void clearRec(Node* node);
  void clearEnd();
  // void setNewEnd();
  Node* getMin(Node* node) {
    if (node == nullptr) return nullptr;
    if (node->left == nullptr) return node;
    return getMin(node->left);
  }
  Node* getMax(Node* node) {
    if (node == nullptr) return nullptr;
    if (node->right == nullptr) return node;
    return getMax(node->right);
  }
  Node* search(Node* node, const_reference key) const;
  Node* copyNode(const Node* node);
  Node* deleteNode(Node* node, Key key);
};
#include "multiset.tpp"
}  // namespace s21

#endif