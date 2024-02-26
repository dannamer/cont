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