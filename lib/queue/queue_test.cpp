#include <gtest/gtest.h>
#include "s21_queue.h" 

// Тестирование конструкторов
TEST(QueueTest, Constructors) {
    s21::queue<int> defaultQueue;
    EXPECT_TRUE(defaultQueue.empty());

    s21::queue<int> initListQueue({1, 2, 3});
    EXPECT_EQ(initListQueue.size(), 3);
    EXPECT_EQ(initListQueue.front(), 1);
    EXPECT_EQ(initListQueue.back(), 3);

    s21::queue<int> copyQueue(initListQueue);
    EXPECT_EQ(copyQueue.size(), 3);

    s21::queue<int> moveQueue(std::move(copyQueue));
    EXPECT_EQ(moveQueue.size(), 3);
    EXPECT_TRUE(copyQueue.empty());
}

// Тестирование операторов присваивания
TEST(QueueTest, AssignmentOperators) {
    s21::queue<int> queue1({1, 2, 3});
    s21::queue<int> queue2;
    queue2 = queue1;
    EXPECT_EQ(queue2.size(), 3);

    s21::queue<int> queue3;
    queue3 = std::move(queue2);
    EXPECT_EQ(queue3.size(), 3);
    EXPECT_TRUE(queue2.empty());
}

// Тестирование доступа к элементам
TEST(QueueTest, ElementAccess) {
    s21::queue<int> queue({10, 20, 30});
    EXPECT_EQ(queue.front(), 10);
    EXPECT_EQ(queue.back(), 30);
}

// Тестирование информации о наполнении
TEST(QueueTest, Capacity) {
    s21::queue<int> queue;
    EXPECT_TRUE(queue.empty());

    queue.push(1);
    EXPECT_FALSE(queue.empty());
    EXPECT_EQ(queue.size(), 1);
}

// Тестирование модификаторов
TEST(QueueTest, Modifiers) {
    s21::queue<int> queue;
    queue.push(1);
    queue.push(2);
    EXPECT_EQ(queue.size(), 2);

    queue.pop();
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(queue.front(), 2);

    s21::queue<int> otherQueue;
    otherQueue.push(3);
    queue.swap(otherQueue);
    EXPECT_EQ(queue.size(), 1);
    EXPECT_EQ(queue.front(), 3);
    EXPECT_EQ(otherQueue.size(), 1);
    EXPECT_EQ(otherQueue.front(), 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
