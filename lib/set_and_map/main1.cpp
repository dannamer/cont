#include <iostream>

template<typename T>
void print(T t) {
    std::cout << t << std::endl;
}

template<typename T, typename... Args>
void print(T t, Args... args) {
    std::cout << t << ", ";
    print(args...); // Рекурсивный вызов с оставшимися аргументами
}

int main() {
    print(1, 2.5, "hello", 'a');
    return 0;
}