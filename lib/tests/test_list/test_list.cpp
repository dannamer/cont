#include "test_list.h"

#include <iostream>

TEST_F(TEST_LIST, test_constructor_1) {
  s21::list<int> a;
  std::list<int> b;
  EXPECT_EQ(a.empty(), b.empty());
}

TEST_F(TEST_LIST, test_constructor_2) {
  s21::list<int> a(15);
  std::list<int> b(15);
  EXPECT_EQ(a.size(), b.size());
}

TEST_F(TEST_LIST, test_constructor_3) {
  s21::list<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  std::list<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  EXPECT_TRUE(eq_list(a, b));
}
TEST_F(TEST_LIST, test_constructor_4) {
  s21::list<int> a{1};
  std::list<int> b{1};
  EXPECT_TRUE(eq_list(a, b));
}
TEST_F(TEST_LIST, test_constructor_5) {
  s21::list<int> a{1, 2, 431, 2, 321, 321312, 123, 21, 3, 12, 312, 3, 12};
  std::list<int> b{1, 2, 431, 2, 321, 321312, 123, 21, 3, 12, 312, 3, 12};

  EXPECT_TRUE(eq_list(a, b));
}

TEST_F(TEST_LIST, test_constructor_6) {
  s21::list<int> a{1, 2, 431, -2, 321, -321312, 123, 21, 3, -12, 312, -3, 12};
  std::list<int> b{1, 2, 431, -2, 321, -321312, 123, 21, 3, -12, 312, -3, 12};

  EXPECT_TRUE(eq_list(a, b));
}

TEST_F(TEST_LIST, test_constructor_7) {
  s21::list<int> a{1, 2, 431, -2, 321, -321312, 123, 21, 3, -12, 312, -3, 12};
  std::list<int> b{1, 2, 431, -2, 321, -321312, 123, 21, 3, -12, 312, -3, 12};
  s21::list<int> a_copy_list(a);
  std::list<int> b_copy_list(b);

  EXPECT_TRUE(eq_list(a_copy_list, b_copy_list));
}

TEST_F(TEST_LIST, test_constructor_8) {
  s21::list<int> a{1, 2, 431, 2, 321, 321312, 123, 21, 3, 12, 312, 3, 12};
  std::list<int> b{1, 2, 431, 2, 321, 321312, 123, 21, 3, 12, 312, 3, 12};
  s21::list<int> a_copy_list(a);
  std::list<int> b_copy_list(b);

  EXPECT_TRUE(eq_list(a_copy_list, b_copy_list));
}

TEST_F(TEST_LIST, test_constructor_9) {
  s21::list<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  std::list<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  s21::list<int> a_copy_list(a);
  std::list<int> b_copy_list(b);

  EXPECT_TRUE(eq_list(a_copy_list, b_copy_list));
}

TEST_F(TEST_LIST, test_constructor_10) {
  s21::list<int> a(15);
  std::list<int> b(15);
  s21::list<int> a_copy_list(a);
  std::list<int> b_copy_list(b);

  EXPECT_TRUE(eq_list(a_copy_list, b_copy_list));
}

TEST_F(TEST_LIST, test_constructor_11) {
  s21::list<int> a{1, 2, 431, -2, 321, -321312, 123, 21, 3, -12, 312, -3, 12};
  std::list<int> b{1, 2, 431, -2, 321, -321312, 123, 21, 3, -12, 312, -3, 12};
  s21::list<int> a_copy_list(std::move(a));
  std::list<int> b_copy_list(std::move(b));

  EXPECT_TRUE(eq_list(a_copy_list, b_copy_list));
  EXPECT_EQ(a.empty(), b.empty());
}

TEST_F(TEST_LIST, test_constructor_12) {
  s21::list<int> a{1, 2, 431, 2, 321, 321312, 123, 21, 3, 12, 312, 3, 12};
  std::list<int> b{1, 2, 431, 2, 321, 321312, 123, 21, 3, 12, 312, 3, 12};
  s21::list<int> a_copy_list(std::move(a));
  std::list<int> b_copy_list(std::move(b));

  EXPECT_TRUE(eq_list(a_copy_list, b_copy_list));
  EXPECT_EQ(a.empty(), b.empty());
}

TEST_F(TEST_LIST, test_constructor_13) {
  s21::list<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  std::list<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  s21::list<int> a_copy_list(std::move(a));
  std::list<int> b_copy_list(std::move(b));

  EXPECT_TRUE(eq_list(a_copy_list, b_copy_list));
  EXPECT_EQ(a.empty(), b.empty());
}

TEST_F(TEST_LIST, test_constructor_14) {
  s21::list<int> a(15);
  std::list<int> b(15);
  s21::list<int> a_copy_list(std::move(a));
  std::list<int> b_copy_list(std::move(b));

  EXPECT_TRUE(eq_list(a_copy_list, b_copy_list));
  EXPECT_EQ(a.empty(), b.empty());
}

TEST_F(TEST_LIST, test_constructor_15) {
  s21::list<int> a{1, 2, 431, -2, 321, -321312, 123, 21, 3, -12, 312, -3, 12};
  std::list<int> b{1, 2, 431, -2, 321, -321312, 123, 21, 3, -12, 312, -3, 12};
  s21::list<int> a_copy_list = std::move(a);
  std::list<int> b_copy_list = std::move(b);

  EXPECT_TRUE(eq_list(a_copy_list, b_copy_list));
  EXPECT_EQ(a.empty(), b.empty());
}

TEST_F(TEST_LIST, test_constructor_16) {
  s21::list<int> a{1, 2, 431, 2, 321, 321312, 123, 21, 3, 12, 312, 3, 12};
  std::list<int> b{1, 2, 431, 2, 321, 321312, 123, 21, 3, 12, 312, 3, 12};
  s21::list<int> a_copy_list = std::move(a);
  std::list<int> b_copy_list = std::move(b);

  EXPECT_TRUE(eq_list(a_copy_list, b_copy_list));
  EXPECT_EQ(a.empty(), b.empty());
}

TEST_F(TEST_LIST, test_constructor_17) {
  s21::list<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  std::list<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  s21::list<int> a_copy_list = std::move(a);
  std::list<int> b_copy_list = std::move(b);

  EXPECT_TRUE(eq_list(a_copy_list, b_copy_list));
  EXPECT_EQ(a.empty(), b.empty());
}

TEST_F(TEST_LIST, test_constructor_18) {
  s21::list<int> a(15);
  std::list<int> b(15);
  s21::list<int> a_copy_list = std::move(a);
  std::list<int> b_copy_list = std::move(b);

  EXPECT_TRUE(eq_list(a_copy_list, b_copy_list));
  EXPECT_EQ(a.empty(), b.empty());
}

TEST_F(TEST_LIST, test_front_1) {
  s21::list<char> a;
  std::list<char> b;
  a.push_front('1');
  b.push_front('1');

  EXPECT_EQ(a.front(), b.front());
  EXPECT_EQ(a.back(), b.back());
  a.push_front('2');
  b.push_front('2');
  EXPECT_EQ(a.front(), b.front());
  EXPECT_EQ(a.back(), b.back());
  a.push_front('3');
  b.push_front('3');
  EXPECT_EQ(a.front(), b.front());
  EXPECT_EQ(a.back(), b.back());
}

TEST_F(TEST_LIST, test_back_1) {
  s21::list<int> a;
  std::list<int> b;
  a.push_back('1');
  b.push_back('1');
  EXPECT_EQ(a.front(), b.front());
  EXPECT_EQ(a.back(), b.back());
  a.push_back('2');
  b.push_back('2');
  EXPECT_EQ(a.front(), b.front());
  EXPECT_EQ(a.back(), b.back());
  a.push_back('3');
  b.push_back('3');
  EXPECT_EQ(a.front(), b.front());
  EXPECT_EQ(a.back(), b.back());
}

TEST_F(TEST_LIST, test_pop_front) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.pop_front();
  std_list.pop_front();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  EXPECT_TRUE(eq_list(our_list, std_list));
}

TEST_F(TEST_LIST, test_pop_back) {
  s21::list<int> our_list;
  std::list<int> std_list;
  our_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  our_list.pop_back();
  std_list.pop_back();
  EXPECT_EQ(our_list.front(), std_list.front());
  EXPECT_EQ(our_list.back(), std_list.back());
  EXPECT_TRUE(eq_list(our_list, std_list));
}

TEST_F(TEST_LIST, test_iterator_begin_1) {
  s21::list<int> a{1, 2, 431, -2, 321, -321312, 123, 21, 3, -12, 312, -3, 12};
  std::list<int> b{1, 2, 431, -2, 321, -321312, 123, 21, 3, -12, 312, -3, 12};
  EXPECT_EQ(*(a.begin()), *(b.begin()));
  a.pop_front();
  b.pop_front();
  EXPECT_EQ(*(a.begin()), *(b.begin()));
  a.pop_front();
  b.pop_front();
  a.pop_front();
  b.pop_front();
  a.pop_front();
  b.pop_front();
  EXPECT_EQ(*(a.begin()), *(b.begin()));
}

TEST_F(TEST_LIST, test_iterator_begin_2) {
  s21::list<int> a{1};
  std::list<int> b{1};
  EXPECT_EQ(*(a.begin()), *(b.begin()));
}

// TEST_F(TEST_LIST, test_iterator_end_1) {
//   std::list<int> b{1,2,3,123,1};
//   s21::list<int> a{1,2,3,123,1};
//   auto it = a.begin();
//   (it++);
//   (it++);
//   (it++);
//   (it++);
//   (it++);
//   std::cout << *(b.end()) << std::endl;
//   std::cout << *(it) << std::endl;
//   std::cout << *(a.end()) << std::endl;
//   EXPECT_EQ(*(a.end()), *(b.end()));
//   a.pop_back();
//   b.pop_back();
//   EXPECT_EQ(*(a.end()), *(b.end()));
//   a.pop_back();
//   b.pop_back();
//   a.pop_back();
//   b.pop_back();
//   a.pop_back();
//   b.pop_back();
//   EXPECT_EQ(*(a.end()), *(b.end()));
// }

// TEST_F(TEST_LIST, test_iterator_end_2) {
//   s21::list<int> a{1};
//   std::list<int> b{1};
//   EXPECT_EQ(*(a.end()), *(b.end()));
// }

TEST_F(TEST_LIST, test_insert_1) {
  s21::list<double> our_list;
  std::list<double> std_list;
  s21::list<double>::iterator our_it;
  our_it = our_list.begin();
  std::list<double>::iterator std_it;
  std_it = std_list.begin();
  our_list.insert(our_it, 5.2321);
  std_list.insert(std_it, 5.2321);
  EXPECT_TRUE(eq_list(our_list, std_list));
  our_list.insert(our_it, 75.2321);
  std_list.insert(std_it, 75.2321);
  our_list.insert(our_it, 975.2321);
  std_list.insert(std_it, 975.2321);
  EXPECT_TRUE(eq_list(our_list, std_list));
}

TEST_F(TEST_LIST, test_insert_2) {
  s21::list<double> our_list = {1.231, 21.231, 321.231, 4321.231, 54321.231};
  std::list<double> std_list = {1.231, 21.231, 321.231, 4321.231, 54321.231};

  s21::list<double>::iterator our_it;
  our_it = our_list.begin();
  std::list<double>::iterator std_it;
  std_it = std_list.begin();
  our_it++;
  our_it++;
  std_it++;
  std_it++;
  our_list.insert(our_it, 75.2321);
  std_list.insert(std_it, 75.2321);
  our_list.insert(our_it, 6.2321);
  std_list.insert(std_it, 6.2321);
  EXPECT_TRUE(eq_list(our_list, std_list));
  our_it--;
  our_it--;
  std_it--;
  std_it--;
  our_list.insert(our_it, -75.2321);
  std_list.insert(std_it, -75.2321);
  our_list.insert(our_it, -6.2321);
  std_list.insert(std_it, -6.2321);
  EXPECT_TRUE(eq_list(our_list, std_list));
}

TEST_F(TEST_LIST, test_erase_1) {
  s21::list<int> our_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  our_list.erase(our_list.begin());
  std_list.erase(std_list.begin());
  EXPECT_TRUE(eq_list(our_list, std_list));

  s21::list<int>::iterator our_it;
  our_it = our_list.begin();
  ++our_it;
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  ++std_it;
  our_list.erase(our_it);
  std_list.erase(std_it);
  EXPECT_TRUE(eq_list(our_list, std_list));
}

TEST_F(TEST_LIST, test_swap) {
  s21::list<int> s21_list1 = {6, 7, 8, 9, 10};
  s21::list<int> s21_list2 = {1, 2, 3, 4, 5};
  std::list<int> std_list1 = {1, 2, 3, 4, 5};
  std::list<int> std_list2 = {6, 7, 8, 9, 10};

  EXPECT_FALSE(eq_list(s21_list1, std_list1));
  EXPECT_FALSE(eq_list(s21_list2, std_list2));
  s21_list1.swap(s21_list2);
  EXPECT_TRUE(eq_list(s21_list1, std_list1));
  EXPECT_TRUE(eq_list(s21_list2, std_list2));
  std_list1.swap(std_list2);
  s21_list1.swap(s21_list2);
  EXPECT_TRUE(eq_list(s21_list1, std_list1));
  EXPECT_TRUE(eq_list(s21_list2, std_list2));
  std_list1.swap(std_list2);
  std_list1.swap(std_list2);
  std_list1.swap(std_list2);
  s21_list1.swap(s21_list2);
  s21_list1.swap(s21_list2);
  s21_list1.swap(s21_list2);
  EXPECT_TRUE(eq_list(s21_list1, std_list1));
  EXPECT_TRUE(eq_list(s21_list2, std_list2));
}


// TEST_F(TEST_LIST, test_merge) {
//   s21::list<char *> s21_list1 = {"Hello, "};
//   s21::list<char *> s21_list2 = {"Wordl!"};
//   std::list<char *> std_list1 = {"Hello, "};
//   std::list<char *> std_list2 = {"Wordl!"};
    

// }

// TEST_F(TEST_LIST, test_splice) {
//   s21::list<int> our_list_first = {1};
//   s21::list<int> our_list_second = {2, 3, 4, 5};
//   std::list<int> std_list_first = {1};
//   std::list<int> std_list_second = {2, 3, 4, 5};
//   s21::list<int>::iterator our_it = our_list_first.begin();
//   std::list<int>::iterator std_it = std_list_first.begin();
//   our_list_first.splice(our_it, our_list_second);
//   std_list_first.splice(std_it, std_list_second);
//   EXPECT_EQ(our_list_first.front(), std_list_first.front());
//   EXPECT_EQ(our_list_first.back(), std_list_first.back());
// }