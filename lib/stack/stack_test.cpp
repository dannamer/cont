#include <gtest/gtest.h>

#include "s21_stack.h"

TEST(StackTest, CanCreateStack) {
  s21::stack<int> myStack;
  EXPECT_TRUE(myStack.empty());
}

TEST(StackTest, CanPushElements) {
  s21::stack<int> myStack;
  myStack.push(1);
  myStack.push(2);
  EXPECT_EQ(myStack.top(), 2);
  EXPECT_FALSE(myStack.empty());
}

TEST(StackTest, CanPopElements) {
  s21::stack<int> myStack;
  myStack.push(1);
  myStack.push(2);
  myStack.pop();
  EXPECT_EQ(myStack.top(), 1);
  myStack.pop();
  EXPECT_TRUE(myStack.empty());
}

TEST(StackTest, CanTopElement) {
  s21::stack<int> myStack;
  myStack.push(42);
  int topElement = myStack.top();
  EXPECT_EQ(topElement, 42);
}

TEST(StackTest, CheckEmpty) {
  s21::stack<int> myStack;
  EXPECT_TRUE(myStack.empty());
  myStack.push(1);
  EXPECT_FALSE(myStack.empty());
  myStack.pop();
  EXPECT_TRUE(myStack.empty());
}

TEST(StackTest, CanCheckSize) {
  s21::stack<int> myStack;
  EXPECT_EQ(myStack.size(), 0);
  myStack.push(1);
  EXPECT_EQ(myStack.size(), 1);
  myStack.push(42);
  EXPECT_EQ(myStack.size(), 2);
  myStack.pop();
  EXPECT_EQ(myStack.size(), 1);
}

TEST(StackTest, CanPushAndPopMultipleElements) {
  s21::stack<int> myStack;
  for (int i = 0; i < 5; ++i) {
    myStack.push(i * 10);
  }
  EXPECT_EQ(myStack.size(), 5);
  EXPECT_EQ(myStack.top(), 40);

  for (int i = 0; i < 3; ++i) {
    myStack.pop();
  }
  EXPECT_EQ(myStack.size(), 2);
  EXPECT_EQ(myStack.top(), 10);
}

TEST(StackTest, PopFromEmptyStack) {
  s21::stack<int> myStack;
  EXPECT_TRUE(myStack.empty());
  EXPECT_THROW(myStack.pop(), std::out_of_range);
}

TEST(StackTest, CanHandleDifferentTypes) {
  s21::stack<std::string> stringStack;
  stringStack.push("Hello");
  stringStack.push("World");
  EXPECT_EQ(stringStack.top(), "World");
  stringStack.pop();
  EXPECT_EQ(stringStack.top(), "Hello");

  s21::stack<double> doubleStack;
  doubleStack.push(3.14);
  doubleStack.push(2.718);
  EXPECT_EQ(doubleStack.top(), 2.718);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}