#include <gtest/gtest.h>

#include "s21_map.h"

TEST(MapTest, DefaultConstructor) {
    s21::map<int, int> m;
    EXPECT_EQ(m.size(), 0);
}
TEST(MapTest, InitializerListConstructor) {
    s21::map<int, int> m{{1, 2}, {3, 4}, {5, 6}};
    EXPECT_EQ(m.size(), 3);
    EXPECT_EQ(m[1], 2);
    EXPECT_EQ(m[3], 4);
    EXPECT_EQ(m[5], 6);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}