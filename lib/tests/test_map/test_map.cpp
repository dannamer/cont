#include "test_map.h"

#include <string>

TEST(TEST_MAP, DefaultConstructor) {
  s21::map<int, int> m;
  EXPECT_EQ(m.size(), 0);
}
TEST(TEST_MAP, InitializerListConstructor) {
  s21::map<int, int> m{{1, 2}, {3, 4}, {5, 6}};
  EXPECT_EQ(m.size(), 3);
  EXPECT_EQ(m[1], 2);
  EXPECT_EQ(m[3], 4);
  EXPECT_EQ(m[5], 6);
}

TEST(TEST_MAP, CopyConstructor) {
  s21::map<int, int> originalMap;
  originalMap.insert(std::make_pair(1, 100));
  originalMap.insert(std::make_pair(2, 200));

  s21::map<int, int> copiedMap(originalMap);

  EXPECT_EQ(copiedMap.size(), originalMap.size());
  EXPECT_EQ(copiedMap[1], 100);
  EXPECT_EQ(copiedMap[2], 200);
}

TEST(TEST_MAP, MoveConstructor) {
  s21::map<int, int> originalMap;
  originalMap.insert(std::make_pair(1, 100));
  originalMap.insert(std::make_pair(2, 200));

  s21::map<int, int> movedMap(std::move(originalMap));

  EXPECT_EQ(movedMap.size(), 2);
  EXPECT_EQ(movedMap[1], 100);
  EXPECT_EQ(movedMap[2], 200);
  EXPECT_TRUE(originalMap.empty());
}

TEST(TEST_MAP, MoveAssignmentOperator) {
  s21::map<int, int> originalMap;
  originalMap.insert(std::make_pair(1, 100));
  originalMap.insert(std::make_pair(2, 200));

  s21::map<int, int> movedMap = std::move(originalMap);

  EXPECT_EQ(movedMap.size(), 2);
  EXPECT_EQ(movedMap[1], 100);
  EXPECT_EQ(movedMap[2], 200);

  EXPECT_TRUE(originalMap.empty());
}

TEST(TEST_MAP, AtMethod) {
  s21::map<int, int> myMap;
  myMap.insert(std::make_pair(1, 100));
  myMap.insert(std::make_pair(2, 200));

  // Проверяем успешный доступ
  EXPECT_EQ(myMap.at(1), 100);
  EXPECT_EQ(myMap.at(2), 200);

  // Проверяем генерацию исключения при доступе к несуществующему ключу
  EXPECT_THROW(myMap.at(3), std::out_of_range);
}

// Тест для оператора []
TEST(TEST_MAP, SubscriptOperator) {
  s21::map<int, int> myMap;

  // Доступ или вставка элемента
  myMap[1] = 100;
  myMap[2] = 200;

  // Проверяем, что элементы были успешно вставлены
  EXPECT_EQ(myMap[1], 100);
  EXPECT_EQ(myMap[2], 200);

  // Вставка нового элемента через оператор []
  myMap[3] = 300;
  EXPECT_EQ(myMap[3], 300);

  // Проверяем размер map после вставки
  EXPECT_EQ(myMap.size(), 3);
}

// Тест для метода begin
TEST(TEST_MAP, BeginMethod) {
  s21::map<int, int> myMap;
  myMap.insert(std::make_pair(1, 100));
  myMap.insert(std::make_pair(2, 200));

  // Проверяем, что begin возвращает итератор на первый элемент
  auto it = myMap.begin();
  EXPECT_EQ(it->first, 1);
  EXPECT_EQ(it->second, 100);
}

// Тест для метода end
TEST(TEST_MAP, EndMethod) {
  s21::map<int, int> myMap;
  myMap.insert(std::make_pair(1, 100));
  myMap.insert(std::make_pair(2, 200));

  // Проверяем, что end возвращает итератор за последний элемент
  auto it = myMap.end();
  // Поскольку end возвращает итератор за последний элемент, мы не можем
  // напрямую проверить его значение. Вместо этого проверяем, что предыдущий
  // элемент от end() это действительно последний элемент в контейнере.
  --it;  // Перемещаемся к последнему элементу
  EXPECT_EQ(it->first, 2);
  EXPECT_EQ(it->second, 200);
}

TEST(TEST_MAP, EmptyMapBeginEnd) {
  s21::map<int, int> myMap;

  // Проверяем, что begin и end возвращают одно и то же для пустого map, т.е.,
  // оба указывают на "конец"
  EXPECT_EQ(myMap.begin(), myMap.end());
}

TEST(TEST_MAP, Empty) {
  s21::map<int, int> myMap;

  // Проверяем, что карта пустая при создании
  EXPECT_TRUE(myMap.empty());

  // Добавляем элемент
  myMap.insert({1, 42});

  // Проверяем, что карта не пустая после добавления элемента
  EXPECT_FALSE(myMap.empty());
}

// Пример тестов для функции size()
TEST(TEST_MAP, Size) {
  s21::map<int, int> myMap;

  // Проверяем, что размер карты равен 0 при создании
  EXPECT_EQ(myMap.size(), 0);

  // Добавляем элементы
  myMap.insert({1, 10});
  myMap.insert({2, 20});

  // Проверяем, что размер карты соответствует количеству добавленных элементов
  EXPECT_EQ(myMap.size(), 2);
}

// // Пример тестов для функции max_size()
// TEST(TEST_MAP, MaxSize) {
//   s21::map<int, int> myMap;

//   // Проверяем, что размер карты не превышает максимально возможный размер
//   EXPECT_LE(myMap.size(), myMap.max_size());
// }
TEST(TEST_MAP, DefaultConstruct) {
  s21::map<int, std::string> m;
  EXPECT_EQ(m.size(), 0);
  EXPECT_TRUE(m.empty());
}

TEST(TEST_MAP, InitializerListConstruc) {
  s21::map<int, std::string> m{{1, "one"}, {2, "two"}, {3, "three"}};
  EXPECT_EQ(m.size(), 3);
  EXPECT_FALSE(m.empty());
  EXPECT_EQ(m.at(1), "one");
  EXPECT_EQ(m.at(2), "two");
  EXPECT_EQ(m.at(3), "three");
}

TEST(TEST_MAP, CopyConstruct) {
  s21::map<int, std::string> m{{1, "one"}, {2, "two"}, {3, "three"}};
  s21::map<int, std::string> copy_m(m);
  EXPECT_EQ(copy_m.size(), 3);
  EXPECT_FALSE(copy_m.empty());
  EXPECT_EQ(copy_m.at(1), "one");
}
// Test the insert(key, value) function
TEST(TEST_MAP, InsertKeyValue) {
  s21::map<int, std::string> map;
  // Insert a single key-value pair
  map.insert(1, "one");
  // Check that the size is correct
  EXPECT_EQ(map.size(), 1);
  // Check that the inserted key-value pair is in the map
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");
  // Insert another key-value pair
  map.insert(2, "two");
  // Check that the size is correct
  EXPECT_EQ(map.size(), 2);
  // Check that both inserted key-value pairs are in the map
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");
  EXPECT_EQ(map.contains(2), true);
  EXPECT_EQ(map[2], "two");
}
// Test the insert(pair) function
TEST(TEST_MAP, InsertPair) {
  s21::map<int, std::string> map;
  // Insert a single key-value pair using a pair object
  map.insert(std::make_pair(1, "one"));
  // Check that the size is correct
  EXPECT_EQ(map.size(), 1);
  // Check that the inserted key-value pair is in the map
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");
  // Insert another key-value pair using a pair object
  map.insert(std::make_pair(2, "two"));
  // Check that the size is correct
  EXPECT_EQ(map.size(), 2);
  // Check that both inserted key-value pairs are in the map
  EXPECT_EQ(map.contains(1), true);
  EXPECT_EQ(map[1], "one");
  EXPECT_EQ(map.contains(2), true);
  EXPECT_EQ(map[2], "two");
}
// TEST(TEST_MAP, InsertOrAssign) {
//   s21::map<int, std::string> map;
//   // Insert a new element with a key that does not exist.
//   auto [it1, inserted1] = map.insert_or_assign(1, "one");
//   EXPECT_TRUE(inserted1);
//   EXPECT_EQ(it1->first, 1);
//   EXPECT_EQ(it1->second, "one");
//   // Insert a new element with a key that already exists.
//   auto [it2, inserted2] = map.insert_or_assign(1, "ONE");
//   EXPECT_FALSE(inserted2);
//   EXPECT_EQ(it2->first, 1);
//   EXPECT_EQ(it2->second, "ONE");
//   // Insert multiple elements.
//   map.insert_or_assign(2, "two");
//   map.insert_or_assign(3, "three");
//   map.insert_or_assign(4, "four");
//   map.insert_or_assign(5, "five");
//   EXPECT_EQ(map.size(), 5);
//   EXPECT_EQ(map[1], "ONE");
//   EXPECT_EQ(map[2], "two");
//   EXPECT_EQ(map[3], "three");
//   EXPECT_EQ(map[4], "four");
//   EXPECT_EQ(map[5], "five");
// }
TEST(TEST_MAP, AtAndOperatorBrackets) {
  s21::map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};

  EXPECT_EQ(map.at(1), "one");
  EXPECT_EQ(map[2], "two");
  EXPECT_THROW(map.at(4), std::out_of_range);
  map[4] = "four";
  EXPECT_EQ(map[4], "four");
  map[2] = "TWO";
  EXPECT_EQ(map[2], "TWO");
}

TEST(TEST_MAP, EmptyAndSize) {
  s21::map<int, std::string> empty_map;
  s21::map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};

  EXPECT_TRUE(empty_map.empty());
  EXPECT_EQ(empty_map.size(), 0);

  EXPECT_FALSE(map.empty());
  EXPECT_EQ(map.size(), 3);
}

TEST(TEST_MAP, MaxSize) {
  s21::map<int, std::string> map;
  std::map<int, std::string> map1;

  // Max size is implementation-dependent, but it should be greater than 0
  EXPECT_GT(map.max_size(), map1.max_size());
}
// TEST(TEST_MAP, Erase) {
//   s21::map<int, std::string> map;

//   map.insert({1, "one"});
//   map.insert({2, "two"});
//   map.insert({3, "three"});
//   map.insert({5, "five"});

//   // Erase an existing element.
//   auto it1 = map.begin()++;
//   map.erase(it1);
//   EXPECT_EQ(map.size(), 3);
//   EXPECT_FALSE(map.contains(1));
// }

TEST(TEST_MAP, Swap) {
  s21::map<int, std::string> map1;
  map1.insert({1, "one"});
  map1.insert({2, "two"});

  s21::map<int, std::string> map2;
  map2.insert({3, "three"});
  map2.insert({4, "four"});

  map1.swap(map2);

  EXPECT_EQ(map1.size(), 2);
  EXPECT_TRUE(map1.contains(3));
  EXPECT_TRUE(map1.contains(4));

  EXPECT_EQ(map2.size(), 2);
  EXPECT_TRUE(map2.contains(1));
  EXPECT_TRUE(map2.contains(2));
}

TEST(TEST_MAP, Merge) {
  s21::map<int, std::string> map1;
  map1.insert({1, "one"});
  map1.insert({2, "two"});

  s21::map<int, std::string> map2;
  map2.insert({3, "three"});
  map2.insert({4, "four"});

  map1.merge(map2);

  EXPECT_EQ(map1.size(), 4);
  EXPECT_TRUE(map1.contains(1));
  EXPECT_TRUE(map1.contains(2));
  EXPECT_TRUE(map1.contains(3));
  EXPECT_TRUE(map1.contains(4));
}

TEST(TEST_MAP, Contains) {
  s21::map<int, std::string> map;

  map.insert({1, "one"});
  map.insert({2, "two"});
  EXPECT_TRUE(map.contains(2));
  EXPECT_FALSE(map.contains(3));
}
