#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <limits>
namespace s21 {
template <class Key>
class BinaryTree {
 protected:
  struct Node {
    Key key_;
    Node *left = nullptr, *right = nullptr, *parent = nullptr;
    Node(Key key) : key_(key) {}
    Node(Key key, Node* parent) : key_(key), parent(parent) {}
  };
  Node* root = nullptr;

 public:
  using key_type = Key;
  using reference = Key&;
  using const_reference = const Key&;
  using size_type = std::size_t;
  class iterator {
   public:
    iterator(Node* node, BinaryTree<Key>* tree_ = nullptr)
        : itNode(node), tree(tree_) {}
    Key& operator*() { return itNode->key_; }
    Key* operator->() { return &(itNode->key_); }
    iterator operator+(const std::size_t size) {
      for (std::size_t i = 0; i < size; ++i) {
        ++(*this);
      }
      return *this;
    }
    iterator operator++() {
      if (itNode->right != nullptr) {
        itNode = itNode->right;
        while (itNode->left != nullptr) {
          itNode = itNode->left;
        }
      } else {
        Node* tempNode = itNode->parent;
        while (tempNode != nullptr && itNode == tempNode->right) {
          itNode = tempNode;
          tempNode = tempNode->parent;
        }
        itNode = tempNode;
      }
      return *this;
    }
    iterator operator++(int) {
      iterator temp = *this;
      ++(*this);
      return temp;
    }
    iterator operator--();
    iterator operator--(int) {
      iterator temp = *this;
      --(*this);
      return temp;
    }
    bool operator==(const iterator& other) const {
      return this->itNode == other.itNode;
    }
    bool operator!=(const iterator& other) const { return !(*this == other); }

   protected:
    Node* itNode;
    BinaryTree<Key>* tree;
  };
  class const_iterator {};
  BinaryTree() {}
  ~BinaryTree();
  BinaryTree(std::initializer_list<Key> const& items);
  BinaryTree(const BinaryTree& m);
  BinaryTree(BinaryTree&& m);
  BinaryTree<Key>& operator=(BinaryTree&& m);
  std::pair<iterator, bool> insert(const_reference value);
  bool empty() const { return !size_; }
  size_type size() const { return size_; }
  size_type max_size() { return std::numeric_limits<size_type>::max(); }  // ?
  iterator begin();
  iterator end();
  iterator find(const Key& key);
  void clear();
  void erase(iterator pos);
  bool contains(const Key& key);
  void swap(BinaryTree& other);
  void merge(BinaryTree& other);

 protected:
  using N = Node*;
  N insertRec(N node, const_reference value, N parrent, bool& isset);
  void clearRec(N node);
  // void clearEnd();
  // void setNewEnd();
  N copyBinaryTree(N CRoot);
  Node* findMax(Node* node);
  // N rootEnd = nullptr;
  size_type size_ = 0;
  Node* deleteNode(Node* node, Key key);
  
};
#include "BinaryTree.tpp"
}  // namespace s21
#endif