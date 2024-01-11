template <typename T>
void help<T>::malloc() {
  size_type oldCapacity = capacity_;
  NewCapacity();
  if (data_ == nullptr && capacity_) {
    data_ = new T[capacity_];
  } else if (capacity_ >= oldCapacity) {
    realloc();
  }
}

template <typename T>
void help<T>::NewCapacity() {
  if (size_) {
    capacity_ = 1;
    while (capacity_ < size_) {
      capacity_ *= 2;
    }
  } else {
    capacity_ = 0;
  }
}

template <typename T>
void help<T>::realloc() {
  T* NewData = new T[capacity_];
  CopyElements(NewData, data_);
  delete[] data_;
  data_ = NewData;
}

template <typename T>
void help<T>::CopyElements(T* dest, const T* source) {
  for (size_type i = 0; i < size_; i++) {
    dest[i] = source[i];
  }
}

template <typename T>
void help<T>::copyFromOther(const help& other) {
  size_ = other.size_;
  malloc();
  CopyElements(data_, other.data_);
}

template <typename T>
void help<T>::move(help& s) {
  if (this != &s) {
    delete[] this->data_;
    data_ = s.data_;
    size_ = s.size_;
    capacity_ = s.capacity_;
    s.data_ = nullptr;
  }
}

template <typename T>
void help<T>::checkEmpty() {
  if (!size_) {
    throw std::out_of_range("Контейнер пуст");
  }
}