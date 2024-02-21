#include <iostream>
#include <set>
#include "s21_multiset.h" // Предполагаем, что ваш класс multiset находится здесь

int main() {
    s21::multiset<int> myMultiset;

    // Тестирование emplace с добавлением новых элементов
    auto result1 = myMultiset.emplace(5, 5, 5);
    // std::cout << "Inserted 5: " << result1.second << std::endl; // Должно вывести 1 (true)

    auto result2 = myMultiset.emplace(10);
    auto result4 = myMultiset.emplace(10);
    // std::cout << "Inserted 10: " << result2.second << std::endl; // Должно вывести 1 (true)

    // Тестирование emplace с элементом, который уже существует
    auto result3 = myMultiset.emplace(5);
    // std::cout << "Inserted 5 again: " << result3.second << std::endl; // Должно вывести 0 (false), если multiset не позволяет дубликаты

    // Проверка размера multiset после вставки
    // std::cout << "Size of multiset: " << myMultiset.size() << std::endl; // Должно вывести 3, если дубликаты разрешены, иначе 2

    // Попытка вставки с использованием emplace и нескольких аргументов (если Key сложного типа)
    // Пример для класса Key с конструктором Key(int, int)
    // auto result4 = myMultiset.emplace(20, 30);
    // std::cout << "Inserted complex key: " << result4.second << std::endl;

    return 0;
}
