#include <gtest/gtest.h>
#include "s21_array.h"  // Убедитесь, что путь к файлу верный

// Тестирование конструкторов
TEST(ArrayTest, Constructors) {
    s21::array<int, 5> arrDefault;
    EXPECT_EQ(arrDefault.size(), 5);

    s21::array<int, 3> arrInitList{1, 2, 3};
    EXPECT_EQ(arrInitList.size(), 3);
    EXPECT_EQ(arrInitList[0], 1);
    EXPECT_EQ(arrInitList[1], 2);
    EXPECT_EQ(arrInitList[2], 3);

    s21::array<int, 3> arrCopy(arrInitList);
    EXPECT_EQ(arrCopy.size(), 3);
    EXPECT_EQ(arrCopy[0], 1);
    EXPECT_EQ(arrCopy[1], 2);
    EXPECT_EQ(arrCopy[2], 3);

    s21::array<int, 3> arrMove(std::move(arrInitList));
    EXPECT_EQ(arrMove.size(), 3);
}

// Тестирование доступа к элементам
TEST(ArrayTest, ElementAccess) {
    s21::array<int, 3> arr{1, 2, 3};
    EXPECT_EQ(arr.at(1), 2);
    EXPECT_EQ(arr[2], 3);
    EXPECT_EQ(arr.front(), 1);
    EXPECT_EQ(arr.back(), 3);

    // Тест на выход за границы
    EXPECT_THROW(arr.at(3), std::out_of_range);
}

// Тестирование свойств
TEST(ArrayTest, Properties) {
    s21::array<int, 0> emptyArr;
    EXPECT_TRUE(emptyArr.empty());

    s21::array<int, 3> arr{1, 2, 3};
    EXPECT_FALSE(arr.empty());
    EXPECT_EQ(arr.size(), 3);
}

// Тестирование модификаторов
TEST(ArrayTest, Modifiers) {
    s21::array<int, 3> arr;
    arr.fill(42);
    EXPECT_EQ(arr[0], 42);
    EXPECT_EQ(arr[1], 42);
    EXPECT_EQ(arr[2], 42);

    s21::array<int, 3> otherArr{1, 2, 3};
    arr.swap(otherArr);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(otherArr[0], 42);
}

// Тестирование итераторов
TEST(ArrayTest, Iterators) {
    s21::array<int, 3> arr{1, 2, 3};
    auto it = arr.begin();
    EXPECT_EQ(*it, 1);
    it++;
    EXPECT_EQ(*it, 2);

    auto itEnd = arr.end();
    itEnd--;
    EXPECT_EQ(*itEnd, 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
