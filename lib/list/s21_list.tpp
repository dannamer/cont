
namespace s21 {
// ITERATOR
template <typename T>
typename list<T>::Iterator& list<T>::Iterator::operator++() {
  node_ = node_->next;
  return *this;
}

template <typename T>
typename list<T>::Iterator list<T>::Iterator::operator++(int) {
  iterator temp = *this;
  ++(*this);
  return temp;
}

template <typename T>
typename list<T>::Iterator& list<T>::Iterator::operator--() {
  if (node_ != nullptr) node_ = node_->prev;
  return *this;
}

template <typename T>
typename list<T>::Iterator list<T>::Iterator::operator--(int) {
  iterator temp = *this;
  --(*this);
  return temp;
}
// ITERATOR

// LIST
template <typename T>
void list<T>::checkSize() const {
  if (!size_) {
    throw std::runtime_error("Список пуст");
  }
}

template <typename T>
typename list<T>::const_reference list<T>::front() const {
  checkSize();
  return head_->value;
}

template <typename T>
typename list<T>::const_reference list<T>::back() const {
  checkSize();
  return tail_->value;
}

template <typename T>
typename list<T>::Node* list<T>::findNode(iterator pos) {
  Node* current = head_;
  while (current != nullptr && iterator(current) != pos) {
    current = current->next;
  }
  return current;
}

template <typename T>
void list<T>::clear() {
  Node* current = head_;
  while (current != nullptr) {
    Node* next = current->next;
    delete current;
    current = next;
  }
  head_ = tail_ = nullptr;
  size_ = 0;
}

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  Node* newNode = new Node(value);
  if (head_ == nullptr) {
    head_ = tail_ = newNode;
  } else if (pos == begin()) {
    newNode->next = head_;
    head_->prev = newNode;
    head_ = newNode;
  } else if (pos == end()) {
    tail_->next = newNode;
    newNode->prev = tail_;
    tail_ = newNode;
  } else {
    Node* current = pos.get_node()->prev;
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
  }
  ++size_;
  return iterator(newNode);
}

template <typename T>
void list<T>::erase(iterator pos) {
  checkSize();
  Node* nodeToDelete = findNode(pos);
  if (nodeToDelete == nullptr) {
    throw std::runtime_error("Элемент не найден");
  }
  if (nodeToDelete == head_) {
    head_ = head_->next;
    if (head_) head_->prev = nullptr;
  } else if (nodeToDelete == tail_) {
    tail_ = nodeToDelete->prev;
    tail_->next = nullptr;
  } else {
    nodeToDelete->prev->next = nodeToDelete->next;
    if (nodeToDelete->next) {
      nodeToDelete->next->prev = nodeToDelete->prev;
    }
  }
  delete nodeToDelete;
  --size_;
  if(size_ == 0) tail_ = head_ = nullptr;
}

template <typename T>
void list<T>::pop_back() {
  erase(iterator(tail_));
}

template <typename T>
void list<T>::pop_front() {
  erase(iterator(head_));
}

template <typename T>
void list<T>::push_back(const_reference value) {
  insert(end(), value);
}
template <typename T>
void list<T>::push_front(const_reference value) {
  insert(begin(), value);
}

template <typename T>
void list<T>::swap(list& other) {
  list<T> tmp = std::move(other);
  other = std::move(*this);
  *this = std::move(tmp);
}
template <typename T>
void list<T>::merge(list<T>& other) {
  while (!other.empty()) {
    this->push_back(other.front());
    other.pop_front();
  }
  this->sort();
}

template <typename T>
void list<T>::splice(const_iterator pos, list& other) {
  if (!other.size()) return;
  Node* splicePos = pos.get_node();
  if (splicePos == nullptr) {
    tail_->next = other.head_;
    other.head_->prev = tail_;
    tail_ = other.tail_;
  } else {
    Node* prevPos = splicePos->prev;
    prevPos ? prevPos->next = other.head_ : head_ = other.head_;
    other.head_->prev = prevPos;
    splicePos->prev = other.tail_;
    other.tail_->next = splicePos;
  }
  size_ += other.size();
  other.size_ = 0;
  other.head_ = other.tail_ = nullptr;
}

template <typename T>
template <typename... Args>
typename list<T>::iterator list<T>::emplace(iterator pos, Args&&... args) {
  return ([&] { return insert(pos, std::forward<Args>(args)); }(), ...);
}

template <typename T>
template <typename... Args>
void list<T>::emplace_back(Args&&... args) {
  ([&] { push_back(std::forward<Args>(args)); }(), ...);
}

template <typename T>
template <typename... Args>
void list<T>::emplace_front(Args&&... args) {
  ([&] { push_front(std::forward<Args>(args)); }(), ...);
}

template <typename T>
void list<T>::split(list<T>& source, list<T>& left, list<T>& right) {
  left.clear();
  right.clear();
  if (source.size_ == 1) {
    left.head_ = left.tail_ = source.head_;
  } else {
    Node* slow = source.head_;
    Node* fast = source.head_->next;
    while (fast != nullptr) {
      fast = fast->next;
      if (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
      }
    }
    left.head_ = source.head_;
    left.tail_ = slow;
    right.head_ = slow->next;
    right.tail_ = source.tail_;
    slow->next = nullptr;
    if (right.head_) right.head_->prev = nullptr;
  }
}

template <typename T>
list<T>::list(size_type n) {
  for (size_type i = 0; i < n; ++i) {
    push_back(T());
  }
}

template <typename T>
list<T>::list(std::initializer_list<value_type> const& items) {
  for (const auto& item : items) {
    push_back(item);
  }
}

template <typename T>
list<T>::list(const list& l) {
  *this = l;
}

template <typename T>
list<T>::list(list&& l) {
  *this = std::move(l);
}

template <typename T>
list<T>& list<T>::operator=(const list& l) {
  clear();
  Node* current = l.head_;
  while (current != nullptr) {
    push_back(current->value);
    current = current->next;
  }
  return *this;
}

template <typename T>
list<T>& list<T>::operator=(list&& l) {
  if (this != &l) {
    clear();
    head_ = l.head_;
    tail_ = l.tail_;
    size_ = l.size_;
    l.head_ = l.tail_ = nullptr;
    l.size_ = 0;
  }
  return *this;
}

template <typename T>
void list<T>::sort() {
  Node* temp = head_;
  while (temp->next) {
    if (temp->value > temp->next->value) {
      std::swap(temp->value, temp->next->value);
      temp = temp->next;
      sort();
    } else
      temp = temp->next;
  }
}
// LIST

}  // namespace s21