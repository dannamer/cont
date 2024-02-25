// #include <list>
#include "s21_list.h"
#include <algorithm>
#include <iostream>
int main () {

    s21::list<int> a;
    s21::list<int> b{13,15,-2,16,24,40};
    a.merge(b);
    for(auto it = a.begin(); it != a.end(); it++)
        std::cout << *it << std::endl; 
    return 0;
}