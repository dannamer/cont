#include "test_vector.h"

TEST_F(TEST_VECTOR, DefaultConstructor_EmptyVector) {
  s21::vector<int> v;
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
}

TEST_F(TEST_VECTOR, SizeConstructor_PositiveSize) {
  const size_t size = 5;
  s21::vector<int> v(size);
  EXPECT_FALSE(v.empty());
  EXPECT_EQ(v.size(), size);
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(v[i], 0);
  }
}

TEST_F(TEST_VECTOR, SizeConstructor_ZeroSize) {
  const size_t size = 0;
  s21::vector<int> v(size);
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), size);
}

TEST_F(TEST_VECTOR, InitializerListConstructor_EmptyList) {
  s21::vector<int> v = {};
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
}

TEST_F(TEST_VECTOR, InitializerListConstructor_NonEmptyList) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_FALSE(v.empty());
  EXPECT_EQ(v.size(), 5);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[4], 5);
}

TEST_F(TEST_VECTOR, CopyConstructor_EmptyVector) {
  s21::vector<int> v1;
  s21::vector<int> v2(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST_F(TEST_VECTOR, CopyConstructor_NonEmptyVector) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2(v1);
  EXPECT_EQ(v2.size(), v1.size());
  for (size_t i = 0; i < v1.size(); ++i) {
    EXPECT_EQ(v2[i], v1[i]);
  }
}

TEST_F(TEST_VECTOR, MoveConstructor_EmptyVector) {
  s21::vector<int> v1;
  s21::vector<int> v2(std::move(v1));
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST_F(TEST_VECTOR, MoveConstructor_NonEmptyVector) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2(std::move(v1));
  EXPECT_EQ(v2.size(), 3);
  EXPECT_TRUE(v1.empty());  // Source vector should be empty after move
}

TEST_F(TEST_VECTOR, Destructor_EmptyVector) {
  s21::vector<int>* v = new s21::vector<int>();
  delete v;  // Destructor should be called here
  // No specific assertions, but this ensures the destructor is working
}

TEST_F(TEST_VECTOR, Destructor_NonEmptyVector) {
  s21::vector<int>* v = new s21::vector<int>{1, 2, 3};
  delete v;  // Destructor should be called here
  // No specific assertions, but this ensures the destructor is working
}

TEST_F(TEST_VECTOR, MoveAssignmentOperator_EmptyToEmpty) {
  s21::vector<int> v1;
  s21::vector<int> v2;
  v2 = std::move(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST_F(TEST_VECTOR, MoveAssignmentOperator_NonEmptyToEmpty) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2;
  v2 = std::move(v1);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_TRUE(v1.empty());  // Source vector should be empty after move
}

TEST_F(TEST_VECTOR, MoveAssignmentOperator_EmptyToNonEmpty) {
  s21::vector<int> v1;
  s21::vector<int> v2 = {4, 5, 6};
  v2 = std::move(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST_F(TEST_VECTOR, MoveAssignmentOperator_NonEmptyToNonEmpty) {
  s21::vector<int> v1 = {1, 2, 3};
  s21::vector<int> v2 = {4, 5, 6};
  v2 = std::move(v1);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_TRUE(v1.empty());  // Source vector should be empty after move
}

TEST_F(TEST_VECTOR, At_ValidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.at(0), 1);
  EXPECT_EQ(v.at(2), 3);
  EXPECT_EQ(v.at(4), 5);
}

TEST_F(TEST_VECTOR, At_InvalidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_THROW(v.at(5), std::out_of_range);
  EXPECT_THROW(v.at(10), std::out_of_range);
}

TEST_F(TEST_VECTOR, IndexOperator_ValidIndex) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[4], 5);
}

TEST_F(TEST_VECTOR, front_back_and_pop) {
  s21::vector<int> v21 = {1, 2, 3, 4, 5};
  std::vector<int> vstd = {1, 2, 3, 4, 5};
  EXPECT_EQ(v21.front(), vstd.front());
  EXPECT_EQ(v21.back(), vstd.back());
  v21.pop_back();
  vstd.pop_back();
  v21.pop_back();
  vstd.pop_back();
  EXPECT_EQ(v21.front(), vstd.front());
  EXPECT_EQ(v21.back(), vstd.back());
}

TEST_F(TEST_VECTOR, Iterator_test) {
  s21::vector<int> v21 = {1, 2, 3, 4, 5};
  std::vector<int> vstd = {1, 2, 3, 4, 5};
  auto it1 = v21.begin();
  auto it2 = vstd.begin();
  for (; it1 != v21.end() || it2 != vstd.end(); it1++, it2++) {
    EXPECT_EQ(*it1, *it2);
  }
}

TEST_F(TEST_VECTOR, empty_test) {
  s21::vector<int> v21 = {1, 2, 3, 4, 5};
  std::vector<int> vstd = {1, 2, 3, 4, 5};
  for (; !v21.empty() || !vstd.empty();) {
    EXPECT_EQ(v21.back(), vstd.back());
    v21.pop_back();
    vstd.pop_back();
  }
}

TEST_F(TEST_VECTOR, size_eq_1) {
  s21::vector<int> v21 = {1, 2, 3, 4, 5};
  std::vector<int> vstd = {1, 2, 3, 4, 5};
  EXPECT_EQ(vstd.size(), v21.size());
}

TEST_F(TEST_VECTOR, size_eq_2) {
  s21::vector<char> v21 = {'1', '2', '3', '4', '5'};
  std::vector<char> vstd = {'1', '2', '3', '4', '5'};
  EXPECT_EQ(vstd.size(), v21.size());
}

TEST_F(TEST_VECTOR, size_eq_3) {
  s21::vector<char> v21 = {};
  std::vector<char> vstd = {};
  EXPECT_EQ(vstd.size(), v21.size());
}
TEST_F(TEST_VECTOR, size_not_eq_4) {
  s21::vector<char> v21 = {'1', '2', '2', '1'};
  std::vector<char> vstd = {};
  EXPECT_NE(vstd.size(), v21.size());
}
TEST_F(TEST_VECTOR, size_not_eq_5) {
  s21::vector<char> v21 = {'1', '2', '2', '1'};
  std::vector<char> vstd = {'1'};
  EXPECT_NE(vstd.size(), v21.size());
}

TEST_F(TEST_VECTOR, max_size_eq_1) {
  s21::vector<double> v21;
  std::vector<double> vstd;
  EXPECT_EQ(vstd.max_size(), v21.max_size());
}

TEST_F(TEST_VECTOR, max_size_eq_2) {
  s21::vector<char> v21 = {'1', '2', '3', '4', '5'};
  std::vector<char> vstd = {'1', '2', '3', '4', '5'};
  EXPECT_EQ(vstd.max_size(), v21.max_size());
}

TEST_F(TEST_VECTOR, max_size_eq_3) {
  s21::vector<char> v21 = {};
  std::vector<char> vstd = {};
  EXPECT_EQ(vstd.max_size(), v21.max_size());
}


TEST_F(TEST_VECTOR, reserve_test_0) {
  s21::vector<char> v21;
  std::vector<char> vstd;
  v21.reserve(10);
  vstd.reserve(10);
  EXPECT_EQ(vstd.size(), v21.size());
}

TEST_F(TEST_VECTOR, reserve_test_1) {
  s21::vector<char> v21;
  std::vector<char> vstd;
  v21.reserve(0);
  vstd.reserve(0);
  EXPECT_EQ(vstd.size(), v21.size());
}

TEST_F(TEST_VECTOR, reserve_test_2) {
  s21::vector<char> v21;
  std::vector<char> vstd;
  v21.reserve(239478);
  vstd.reserve(239478);
  EXPECT_EQ(vstd.size(), v21.size());
}

TEST_F(TEST_VECTOR, reserve_test_3) {
  s21::vector<char> v21;
  std::vector<char> vstd;
  EXPECT_THROW(v21.reserve(__INT64_MAX__), std::bad_alloc);
  EXPECT_THROW(vstd.reserve(__INT64_MAX__), std::bad_alloc);
}

TEST_F(TEST_VECTOR, capacity_test_0) {
  s21::vector<char> v21{'1', '2', '3', '1', '2', '3',
                        '1', '2', '3', '1', '2', '3'};
  std::vector<char> vstd{'1', '2', '3', '1', '2', '3',
                         '1', '2', '3', '1', '2', '3'};
  EXPECT_EQ(vstd.capacity(), v21.capacity());
}

TEST_F(TEST_VECTOR, capacity_test_1) {
  s21::vector<char> v21;
  std::vector<char> vstd;
  EXPECT_EQ(vstd.capacity(), v21.capacity());
}

TEST_F(TEST_VECTOR, capacity_test_2) {
  s21::vector<int> v21{123,    12,   3,  123, 1321, 123,
                       210321, -213, -3, 3,   123,  12};
  std::vector<int> vstd{123,    12,   3,  123, 1321, 123,
                        210321, -213, -3, 3,   123,  12};
  EXPECT_EQ(vstd.capacity(), v21.capacity());
}

TEST_F(TEST_VECTOR, capacity_test_3) {
  s21::vector<double> v21{12.32, 321.312, 213.231, 123.12};
  std::vector<double> vstd{12.32, 321.312, 213.231, 123.12};
  EXPECT_EQ(vstd.capacity(), v21.capacity());
}

TEST_F(TEST_VECTOR, Capacity_shrink_to_fit_1) {
  s21::vector<int> s21_v;
  std::vector<int> std_v;
  s21_v.reserve(10);
  std_v.reserve(10);
  s21_v.shrink_to_fit();
  std_v.shrink_to_fit();
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST_F(TEST_VECTOR, Capacity_shrink_to_fit_2) {
  s21::vector<int> s21_v{1, 2, 3};
  std::vector<int> std_v{1, 2, 3};
  s21_v.reserve(10);
  std_v.reserve(10);
  s21_v.shrink_to_fit();
  std_v.shrink_to_fit();
  EXPECT_EQ(s21_v.capacity(), std_v.capacity());
}

TEST_F(TEST_VECTOR, clear_test_1) {
  s21::vector<char> v21;
  std::vector<char> vstd;
  v21.reserve(239478);
  vstd.reserve(239478);
  v21.clear();
  vstd.clear();
  EXPECT_EQ(vstd.size(), v21.size());
}

TEST_F(TEST_VECTOR, clear_test_2) {
  s21::vector<char> v21;
  std::vector<char> vstd;
  v21.clear();
  vstd.clear();
  EXPECT_EQ(vstd.size(), v21.size());
}

TEST_F(TEST_VECTOR, clear_test_3) {
  s21::vector<char> v21{'1', '2', '3', '1', '2', '3',
                        '1', '2', '3', '1', '2', '3'};
  std::vector<char> vstd{'1', '2', '3', '1', '2', '3',
                         '1', '2', '3', '1', '2', '3'};
  v21.clear();
  vstd.clear();
  EXPECT_EQ(vstd.size(), v21.size());
}

TEST_F(TEST_VECTOR, erase_test_1) {
  s21::vector<char> v21{'1', '2', '3', '1', '2', '3',
                        '1', '2', '3', '1', '2', '3'};
  std::vector<char> vstd{'1', '2', '3', '1', '2', '3',
                         '1', '2', '3', '1', '2', '3'};
  auto it = v21.begin();
  v21.erase(it);
  auto it2 = vstd.begin();
  vstd.erase(it2);
  EXPECT_EQ(vstd.size(), v21.size());
  v21.erase(it);
  vstd.erase(it2);
  EXPECT_EQ(vstd.size(), v21.size());
  it = v21.end();
  it2 = vstd.end();
  EXPECT_EQ(vstd.size(), v21.size());
  it = v21.end();
  it2 = vstd.end();
  EXPECT_EQ(vstd.size(), v21.size());
}

TEST_F(TEST_VECTOR, push_pop_1) {
  s21::vector<int> v21{};
  std::vector<int> vstd{1, 2, 4, 7, -1, 5, -64, -1, -334};

  v21.push_back(1);
  v21.push_back(2);
  v21.push_back(4);
  v21.push_back(7);
  v21.push_back(-1);
  v21.push_back(5);
  v21.push_back(-64);
  v21.push_back(-1);
  v21.push_back(-334);

  EXPECT_EQ(vstd[0], v21[0]);
  EXPECT_EQ(vstd[3], v21[3]);
  EXPECT_EQ(vstd[7], v21[7]);

  EXPECT_EQ(vstd.size(), v21.size());
}

TEST_F(TEST_VECTOR, push_pop_2) {
  s21::vector<int> v21{32, 3, 23, 2, 3};
  std::vector<int> vstd{32, 3, 23, 2, 3, 1, 2, 4, 7, -1, 5, -64, -1, -334};

  v21.push_back(1);
  v21.push_back(2);
  v21.push_back(4);
  v21.push_back(7);
  v21.push_back(-1);
  v21.push_back(5);
  v21.push_back(-64);
  v21.push_back(-1);
  v21.push_back(-334);

  EXPECT_EQ(vstd[0], v21[0]);
  EXPECT_EQ(vstd[3], v21[3]);
  EXPECT_EQ(vstd[9], v21[9]);

  EXPECT_EQ(vstd.size(), v21.size());
}

TEST_F(TEST_VECTOR, swap_test_1) {
  // s21::vector<int> v21_1{32, 3, 23, 2, 3};
  // std::vector<int> v21_2{32, 3, 23, 2, 3, 1, 2, 4, 7, -1, 5, -64, -1, -334};
  // s21::vector<int> vstd_1{32, 3, 23, 2, 3};
  // std::vector<int> vstd_2{32, 3, 23, 2, 3, 1, 2, 4, 7, -1, 5, -64, -1, -334};

  // std::pair<int,int> a = std::make_pair(1,4); 
  // std::pair<int,int> b = std::make_pair(1,2); 


  // std::cout << (a < b) << std::endl;




  // EXPECT_EQ(vstd.size(), v21.size());
}
