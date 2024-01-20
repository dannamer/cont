#ifndef ITERATOR_H__
#define ITERATOR_H__
template <class Key, class T>
struct Node;

template <class Key>
class BinaryTree;
namespace it {
template <class Key, class T>
class iterator {
 public:
  using value_type = std::pair<const Key, T>;
  using reference = value_type &;
  using pointer = value_type *;

  iterator(Node<Key, T> *node) : CNode(node) {}
  reference operator*() const { return CNode->value_; }
  pointer operator->() const { return &(CNode->value_); }

  iterator operator++() {
    if (CNode->right != nullptr) {
      CNode = CNode->right;
      while (CNode->left != nullptr) {
        CNode = CNode->left;
      }
    } else {
      Node<Key, T> *tempNode = CNode->parent;
      while (tempNode != nullptr && CNode == tempNode->right) {
        CNode = tempNode;
        tempNode = tempNode->parent;
      }
      CNode = tempNode;
    }
    return *this;
  }
  iterator operator++(int) {
    iterator temp = *this;
    ++(*this);
    return temp;
  }

 private:
  Node<Key, T> *CNode = nullptr;
};

template <class Key, class T>
class const_iterator {
 public:
 private:
};

class iterator {
 public:
  using value_type = T;
  using pointer = T *;
  using reference = T &;
  iterator() {}
  iterator(Node<T> *node) : currentNode(node) {}
  reference operator*() {
    if (currentNode != nullptr) {
      return currentNode->value;
    } else {
      throw std::runtime_error("Attempt to dereference a null iterator");
    }
  }
  Node<T> *operator&() { return currentNode; }
  iterator &operator--() {
    if (currentNode->left != nullptr) {
      currentNode = currentNode->left;
      while (currentNode->right != nullptr) {
        currentNode = currentNode->right;
      }
    } else {
      Node<T> *tempNode = currentNode->parent;
      while (tempNode != nullptr && currentNode == tempNode->left) {
        currentNode = tempNode;
        tempNode = tempNode->parent;
      }
      currentNode = tempNode;
    }
    return *this;
  }
  iterator<T> operator--(int) {
    iterator<T> temp = *this;
    --(*this);
    return temp;
  }
  iterator &operator++() {
    if (currentNode->right != nullptr) {
      currentNode = currentNode->right;
      while (currentNode->left != nullptr) {
        currentNode = currentNode->left;
      }
    } else {
      Node<T> *tempNode = currentNode->parent;
      while (tempNode != nullptr && currentNode == tempNode->right) {
        currentNode = tempNode;
        tempNode = tempNode->parent;
      }
      currentNode = tempNode;
    }
    return *this;
  }

  iterator<T> operator++(int) {
    iterator<T> temp = *this;
    ++(*this);
    return temp;
  }
  bool operator==(iterator<T> &other) {
    return currentNode == other.currentNode;
  }
  bool operator!=(iterator<T> &other) {
    return currentNode != other.currentNode;
  }
  Node<T> *operator->() { return currentNode; }
  Node<T> *getNode() const { return currentNode; }

  void setNode(Node<T> *newNode) { currentNode = newNode; }

 private:
  Node<T> *currentNode = nullptr;
};

template <class T>
class const_iterator {
 public:
  using value_type = T;
  using const_pointer = const T *;
  using const_reference = const T &;

  const_iterator() : currentNode(nullptr) {}
  const_iterator(const Node<T> *node) : currentNode(node) {}

  const_reference operator*() const {
    if (currentNode != nullptr) {
      return currentNode->value;
    } else {
      throw std::runtime_error("Attempt to dereference a null const_iterator");
    }
  }

  const Node<T> *operator&() const { return currentNode; }

  const_iterator &operator--() {
    if (currentNode->left != nullptr) {
      currentNode = currentNode->left;
      while (currentNode->right != nullptr) {
        currentNode = currentNode->right;
      }
    } else {
      const Node<T> *tempNode = currentNode->parent;
      while (tempNode != nullptr && currentNode == tempNode->left) {
        currentNode = tempNode;
        tempNode = tempNode->parent;
      }
      currentNode = tempNode;
    }
    return *this;
  }

  const_iterator operator--(int) {
    const_iterator temp = *this;
    --(*this);
    return temp;
  }

  const_iterator &operator++() {
    if (currentNode->right != nullptr) {
      currentNode = currentNode->right;
      while (currentNode->left != nullptr) {
        currentNode = currentNode->left;
      }
    } else {
      const Node<T> *tempNode = currentNode->parent;
      while (tempNode != nullptr && currentNode == tempNode->right) {
        currentNode = tempNode;
        tempNode = tempNode->parent;
      }
      currentNode = tempNode;
    }
    return *this;
  }

  const_iterator operator++(int) {
    const_iterator temp = *this;
    ++(*this);
    return temp;
  }
  bool operator==(const const_iterator &other) const {
    return currentNode == other.currentNode;
  }
  bool operator!=(const const_iterator &other) const {
    return currentNode != other.currentNode;
  }
  const Node<T> *operator->() const { return currentNode; }
  const Node<T> *getNode() const { return currentNode; }

 private:
  const Node<T> *currentNode;
};
}  // namespace it
#endif
