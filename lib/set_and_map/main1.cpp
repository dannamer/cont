#include <iostream>
#include <map>
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
    
      std::map<int, int> a;
  a.insert(std::make_pair(-1, 3));
  a.insert(-5, 3);
  a.insert(3, 3);
  a.insert(9, 3);
  a.insert(6, 3);
  auto itm = a.end();
    return 0;
}