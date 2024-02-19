#include <gtest/gtest.h>

#include <set>

#include "../multiset/s21_multiset.h"

TEST(MultisetTest, InsertAndContains) {
  s21::multiset<int> mset;
  mset.insert(5);
  EXPECT_TRUE(mset.contains(5));
}

TEST(MultisetTest, Erase) {
  s21::multiset<int> mset;
  mset.insert(5);
  mset.erase(mset.find(5));
  EXPECT_FALSE(mset.contains(5));
}

TEST(MultisetTest, Count) {
  s21::multiset<int> mset;
  mset.insert(5);
  mset.insert(5);
  EXPECT_EQ(mset.count(5), 2);
}

TEST(MultisetTest, Empty) {
  s21::multiset<int> mset;
  EXPECT_TRUE(mset.empty());
  mset.insert(5);
  EXPECT_FALSE(mset.empty());
}

TEST(MultisetTest, Iterators) {
  s21::multiset<int> mset;
  mset.insert(1);
  mset.insert(2);
  mset.insert(3);

  auto it = mset.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
  ++it;
  EXPECT_EQ(*it, 3);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
