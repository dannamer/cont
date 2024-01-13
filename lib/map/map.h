#pragma once
#include <iostream>
#include <map>
#include <cstddef>
#include <utility>
#include <string>

template <typename Key, typename T>
class Map {
public:
    // Определение типов
    using key_type = Key;
    using mapped_type = T; 
    using value_type = std::pair<const key_type, mapped_type>;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = typename std::map<Key, T>::iterator;
    
    using const_iterator = typename std::map<Key, T>::const_iterator;
    using size_type = std::size_t;

private:
    struct Node
    {
        key_type key_;
        mapped_type value_;
        Node *left;
        Node *right;
        Node(value_type pair) : key_(pair.first), value_(pair.second), left(nullptr), right(nullptr) {}
        Node(key_type key, mapped_type value) : key_(key), value_(value), left(nullptr), right(nullptr) {}
    };
    Node* insertRecursive(Node* current, const key_type& key, const mapped_type& value);
    Node* removeRecursive(Node* current, const key_type& key);
    Node* findMin(Node* node);
    void destroyTree(Node* node);
    void inOrderTraversal(Node* node) const;
    Node * root;

    std::map<key_type, mapped_type> data;

public:
    // Constructor
    Map() : root(nullptr) {}
    Map(std::initializer_list<value_type> const &items);

    ~Map() {
        destroyTree(root);
    }

    // Методы для доступа к элементам, изменения карты и т.д.

    size_type size() const {
        return data.size();
    }

    // Другие функции и операции, например, вставка, удаление, поиск и т.д.
    
    // Метод для вставки элемента:
    std::pair<iterator, bool> insert(const key_type& key, const mapped_type& obj);
    
    // Метод для удаления элемента:
    void remove(const key_type& key);

    void printTree() const;
};
