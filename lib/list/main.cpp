#include <iostream>
#include <list>
#include <string>

#include "s21_list.h"  // Убедитесь, что путь к вашему заголовочному файлу указан правильно

int main() {
  std::list<double> b {2};
  // s21::list<int> a{1, 2, 3, 123, 1, 4};
  // auto it = a.begin();
  // (it++);
  // (it++);
  // (it++);
  // (it++);




  // (it++);
  auto l = b.begin();
  // auto bb = b.begin();
  // bb--;
  // bb--;
  // bb--;
  // l--;
    std::cout << nullptr << std::endl;
    std::cout << NULL << std::endl;
  while (1) {
    printf("%p\n", &(*l));
    std::cout << (*l++) << std::endl;
    // printf("%s\n", (*l++).c_str());
    // std::cout << std::hex <<( l++) << std::endl;
  }
  // std::cout << *(it) << std::endl;
}