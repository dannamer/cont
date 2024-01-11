#include <gtest/gtest.h>

#include "s21_stack.h"

TEST(StackTest, ConstructorTest) {
  s21::stack<int> testStack;
  EXPECT_TRUE(testStack.empty());
}

TEST(StackTest, CopyConstructorTest) {
  s21::stack<int> originalStack;
  originalStack.push(10);
  s21::stack<int> copiedStack(originalStack);
  EXPECT_FALSE(copiedStack.empty());
  EXPECT_EQ(copiedStack.top(), 10);
}

TEST(StackTest, MoveConstructorTest) {
  s21::stack<int> originalStack;
  originalStack.push(20);
  s21::stack<int> movedStack(std::move(originalStack));
  EXPECT_TRUE(originalStack.empty());
  EXPECT_EQ(movedStack.top(), 20);
}

TEST(StackTest, CopyAssignmentOperatorTest) {
  s21::stack<int> stack1;
  stack1.push(30);
  s21::stack<int> stack2;
  stack2 = stack1;
  EXPECT_EQ(stack2.top(), 30);
}

TEST(StackTest, MoveAssignmentOperatorTest) {
  s21::stack<int> stack1;
  stack1.push(40);
  s21::stack<int> stack2;
  stack2 = std::move(stack1);
  EXPECT_TRUE(stack1.empty());
  EXPECT_EQ(stack2.top(), 40);
}

TEST(StackTest, PushTest) {
  s21::stack<int> stack;
  stack.push(50);
  EXPECT_FALSE(stack.empty());
  EXPECT_EQ(stack.top(), 50);
}

TEST(StackTest, PopTest) {
  s21::stack<int> stack;
  stack.push(60);
  stack.pop();
  EXPECT_TRUE(stack.empty());
}

TEST(StackTest, TopTest) {
  s21::stack<int> stack;
  stack.push(70);
  EXPECT_EQ(stack.top(), 70);
}

TEST(StackTest, EmptyTest) {
  s21::stack<int> stack;
  EXPECT_TRUE(stack.empty());
}

TEST(StackTest, SizeTest) {
  s21::stack<int> stack;
  stack.push(80);
  stack.push(90);
  EXPECT_EQ(stack.size(), 2);
}