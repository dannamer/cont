#include "map.h"

template <typename Key, typename T>
typename Map<Key, T>::Node* Map<Key, T>::insertRecursive(Node* current, const key_type& key, const mapped_type& value) {
    if (current == nullptr) {
        // Создаем новый узел, если текущий узел пуст
        return new Node(std::make_pair(key, value));
    }

    if (key < current->key_) {
        // Рекурсивно вставляем в левое поддерево, если ключ меньше текущего
        current->left = insertRecursive(current->left, key, value);
    } else if (key > current->key_) {
        // Рекурсивно вставляем в правое поддерево, если ключ больше текущего
        current->right = insertRecursive(current->right, key, value);
    } else {
        // Если ключ уже существует, возвращаем nullptr
        return nullptr;
    }

    return current;
}

template <typename Key, typename T>
std::pair<typename Map<Key, T>::iterator, bool> Map<Key, T>::insert(const key_type& key, const mapped_type& obj) { 
    Node* newNode = insertRecursive(root, key, obj);

    if (newNode) {
        data.insert(std::make_pair(key, obj));
        return std::make_pair(typename Map<Key, T>::iterator(data.find(key)), true);
    } else {
        return std::make_pair(data.end(), false);
    }
}



template <typename Key, typename T>
void Map<Key, T>::remove(const key_type& key) {
    root = removeRecursive(root, key);
    data.erase(key);  // Удаляем также из std::map для поддержки операций
}

template <typename Key, typename T>
typename Map<Key, T>::Node* Map<Key, T>::removeRecursive(Node* current, const key_type& key) {
    if (current == nullptr) {
        return nullptr;  // Если узел пуст, возвращаем nullptr
    }

    if (key < current->key_) {
        current->left = removeRecursive(current->left, key);
    } else if (key > current->key_) {
        current->right = removeRecursive(current->right, key);
    } else {
        // Нашли узел для удаления
        if (current->left == nullptr) {
            Node* temp = current->right;
            delete current;
            return temp;
        } else if (current->right == nullptr) {
            Node* temp = current->left;
            delete current;
            return temp;
        }

        // Узел имеет двух потомков
        Node* temp = findMin(current->right);  // Находим минимальный узел в правом поддереве
        current->key_ = temp->key_;
        current->value_ = temp->value_;
        current->right = removeRecursive(current->right, temp->key_);
    }

    return current;
}

template <typename Key, typename T>
typename Map<Key, T>::Node* Map<Key, T>::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

template <typename Key, typename T>
void Map<Key, T>::destroyTree(Node* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

// Реализация метода printTree
template <typename Key, typename T>
void Map<Key, T>::printTree() const {
    inOrderTraversal(root);
    std::cout << std::endl;
}

// Вспомогательная функция для in-order traversal
template <typename Key, typename T>
void Map<Key, T>::inOrderTraversal(Node* node) const {
    if (node) {
        inOrderTraversal(node->left);
        std::cout << "(" <<"Key: " << node->key_ << ", " << " Value: "<< node->value_ << ") ";
        inOrderTraversal(node->right);
    }
}

// Использование класса Map
int main() {
    Map<int, std::string> myMap;
    myMap.insert(1, "Nano");
    myMap.insert(1, "Nano");
    myMap.printTree();
    return 0;
}