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
  Node<T>* current = l.head_;
  while (current != nullptr) {
    push_back(current->value);
    current = current->next;
  }
}

template <typename T>
list<T>::list(list&& l) : head_(l.head_), tail_(l.tail_), size_(l.size_) {
  l.head_ = l.tail_ = nullptr;
  l.size_ = 0;
}

template <typename T>
list<T>& list<T>::operator=(list& l) {
  clear();
  Node<T>* current = l.head_;
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
void list<T>::clear() {
  Node<T>* current = head_;
  while (current != nullptr) {
    Node<T>* next = current->next;
    delete current;
    current = next;
  }
  head_ = tail_ = nullptr;
  size_ = 0;
}

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  if (head_ == nullptr || pos == begin()) {
    push_front(value);
    return begin();
  } else if (pos == end()) {
    push_back(value);
    return end();
  } else {
    Node<T>* newNode = new Node<T>(value);
    Node<T>* current = head_;
    while (current->next != nullptr && iterator(current->next) != pos) {
      current = current->next;
    }
    newNode->next = current->next;
    if (current->next != nullptr) {
      current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
    ++size_;
    return iterator(newNode);
  }
}

template <typename T>
void list<T>::pop_back() {
  checkSize();
  if (size_ == 1) {
    delete tail_;
    head_ = tail_ = nullptr;
  } else {
    node<T>* temp = tail_;
    tail_ = tail_->prev;
    tail_->next = nullptr;
    delete temp;
  }
  --size_;
}

template <typename T>
void list<T>::pop_front() {
  checkSize();
  if (size_ == 1) {
    delete tail_;
    head_ = tail_ = nullptr;
  } else {
    node<T>* temp = head_;
    head_ = head_->next;
    head_->prev = nullptr;
    delete temp;
  }
  --size_;
}

template <typename T>
void list<T>::push_back(const_reference value) {
  Node<T>* newNode = new Node<T>(value);
  if (head_ == nullptr) {
    head_ = tail_ = newNode;
  } else {
    tail_->next = newNode;
    newNode->prev = tail_;
    tail_ = newNode;
  }
  ++size_;
}
template <typename T>
void list<T>::push_front(const_reference value) {
  Node<T>* newNode = new Node<T>(value);
  if (head_ == nullptr) {
    head_ = tail_ = newNode;
  } else {
    head_->prev = newNode;
    newNode->next = head_;
    head_ = newNode;
  }
  ++size_;
}

template <typename T>
void list<T>::erase(iterator pos) {
  checkSize();
  Node<T>* current = head_;
  Node<T>* prev = nullptr;
  while (current != nullptr && current != pos.get_node()) {
    prev = current;
    current = current->next;
  }
  if (current == nullptr) {
    throw std::runtime_error("Элемент не найден");
  }
  if (current == head_) {
    head_ = head_->next;
    if (head_ != nullptr) {
      head_->prev = nullptr;
    }
  } else if (current == tail_) {
    tail_ = prev;
    tail_->next = nullptr;
  } else {
    prev->next = current->next;
    if (current->next != nullptr) {
      current->next->prev = prev;
    }
  }
  delete current;
  --size_;
}

template <typename T>
void list<T>::swap(list& other) {
  Node<T>* tempHead = head_;
  head_ = other.head_;
  other.head_ = tempHead;

  Node<T>* tempTail = tail_;
  tail_ = other.tail_;
  other.tail_ = tempTail;

  size_type tempSize = size_;
  size_ = other.size_;
  other.size_ = tempSize;
}

template <typename T>
void list<T>::splice(const_iterator pos, list& other) {
  if (!other.size()) return;
  Node<T>* splicePos = pos.get_node();
  if (splicePos == nullptr) {
    tail_->next = other.head_;
    other.head_->prev = tail_;
    tail_ = other.tail_;
  } else {
    Node<T>* prevPos = splicePos->prev;
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
void list<T>::split(list<T>& source, list<T>& left, list<T>& right) {
  left.clear();
  right.clear();
  if (source.size_ == 1) {
    left.head_ = left.tail_ = source.head_;
  } else {
    Node<T>* slow = source.head_;
    Node<T>* fast = source.head_->next;
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