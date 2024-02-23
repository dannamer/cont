#include <gtest/gtest.h>

#include "s21_list.h"  // Предполагается, что ваш класс list находится в файле list.hpp

// Используйте namespace вашего проекта
using namespace s21;

// Тестирование конструктора по умолчанию
TEST(ListTest, DefaultConstructor) {
  list<int> lst;
  EXPECT_TRUE(lst.empty());
}

// Тестирование конструктора с инициализацией списком
TEST(ListTest, InitializerListConstructor) {
  list<int> lst = {1, 2, 3};
  EXPECT_EQ(lst.size(), 3);
}

// Тестирование метода push_back
TEST(ListTest, PushBack) {
  list<int> lst;
  lst.push_back(1);
  lst.push_back(2);
  EXPECT_EQ(lst.back(), 2);
}

// Тестирование метода push_front
TEST(ListTest, PushFront) {
  list<int> lst;
  lst.push_front(1);
  lst.push_front(2);
  EXPECT_EQ(lst.front(), 2);
}

// Тестирование метода pop_back
TEST(ListTest, PopBack) {
  list<int> lst = {1, 2, 3};
  lst.pop_back();
  EXPECT_EQ(lst.back(), 2);
}

// Тестирование метода pop_front
TEST(ListTest, PopFront) {
  list<int> lst = {1, 2, 3};
  lst.pop_front();
  EXPECT_EQ(lst.front(), 2);
}

// Тестирование метода clear
TEST(ListTest, Clear) {
  list<int> lst = {1, 2, 3};
  lst.clear();
  EXPECT_TRUE(lst.empty());
}

// Добавьте дополнительные тесты для проверки оставшихся методов
TEST(ListEmplace, EmplaceFront) {
  s21::list<int> myList;
  myList.emplace_front(10, 20, 30);
  EXPECT_EQ(myList.front(), 30);
  myList.emplace_front(20);
  EXPECT_EQ(myList.front(), 20);
}

TEST(ListEmplace, EmplaceBack) {
  s21::list<int> myList;
  myList.emplace_back(30, 34, 50);
  EXPECT_EQ(myList.back(), 50);
  myList.emplace_back(40, 34, 23);
  EXPECT_EQ(myList.back(), 23);
}

// TEST(ListEmplace, Emplace) {
//   s21::list<int> myList;
//   auto it = myList.emplace(myList.end(), 50);
//   EXPECT_EQ((*it).value, 50);
//   it = myList.emplace(myList.begin(), 60);
//   EXPECT_EQ((*it).value, 60);
// }
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
