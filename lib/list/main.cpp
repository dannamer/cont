#include <iostream>
#include <list>
#include "s21_list.h"  // Убедитесь, что путь к вашему заголовочному файлу указан правильно

int main() {
    s21::list<int> myList = {10, 20, 30}; // Создаем список
    // Показываем элементы списка
    std::cout << "List contents: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    // Вставляем элемент перед последним элементом
    auto it = myList.end();
    auto lol = myList.insert(it, 25);
    std::cout << "List after insertion: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}