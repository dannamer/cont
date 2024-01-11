#include <gtest/gtest.h>

#include "s21_queue.h"

TEST(queueTest, ConstructorTest) {
  s21::queue<int> testqueue;
  EXPECT_TRUE(testqueue.empty());
}

TEST(queueTest, CopyConstructorTest) {
  s21::queue<int> originalqueue;
  originalqueue.push(10);
  s21::queue<int> copiedqueue(originalqueue);
  EXPECT_FALSE(copiedqueue.empty());
  EXPECT_EQ(copiedqueue.back(), 10);
}

TEST(queueTest, MoveConstructorTest) {
  s21::queue<int> originalqueue;
  originalqueue.push(20);
  s21::queue<int> movedqueue(std::move(originalqueue));
  EXPECT_TRUE(originalqueue.empty());
  EXPECT_EQ(movedqueue.back(), 20);
}

TEST(queueTest, CopyAssignmentOperatorTest) {
  s21::queue<int> queue1;
  queue1.push(30);
  s21::queue<int> queue2;
  queue2 = queue1;
  EXPECT_EQ(queue2.back(), 30);
}

TEST(queueTest, MoveAssignmentOperatorTest) {
  s21::queue<int> queue1;
  queue1.push(40);
  s21::queue<int> queue2;
  queue2 = std::move(queue1);
  EXPECT_TRUE(queue1.empty());
  EXPECT_EQ(queue2.back(), 40);
}

TEST(queueTest, PushTest) {
  s21::queue<int> queue;
  queue.push(50);
  EXPECT_FALSE(queue.empty());
  EXPECT_EQ(queue.back(), 50);
}

TEST(queueTest, PopTest) {
  s21::queue<int> queue;
  queue.push(60);
  queue.pop();
  EXPECT_TRUE(queue.empty());
}

TEST(queueTest, TopTest) {
  s21::queue<int> queue;
  queue.push(70);
  EXPECT_EQ(queue.back(), 70);
}

TEST(queueTest, EmptyTest) {
  s21::queue<int> queue;
  EXPECT_TRUE(queue.empty());
}

TEST(queueTest, SizeTest) {
  s21::queue<int> queue;
  queue.push(80);
  queue.push(90);
  EXPECT_EQ(queue.size(), 2);
}