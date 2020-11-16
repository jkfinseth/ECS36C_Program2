#include <gtest/gtest.h>
#include "deque.h"

TEST(Deque, Empty) {
  Deque<int> dq;

  /* Should be fully empty */
  EXPECT_EQ(dq.Empty(), true);
  EXPECT_EQ(dq.Size(), 0);
  EXPECT_THROW(dq.PopFront(), std::exception);
}

TEST(Deque, DoubleInsertionBack) {
  Deque<int> dq;

  /* Test some insertions at back */
  dq.PushBack(23);
  dq.PushBack(42);
  EXPECT_EQ(dq.Empty(), false);
  EXPECT_EQ(dq.Size(), 2);
  EXPECT_EQ(dq[0], 23);
  EXPECT_EQ(dq[1], 42);
  EXPECT_EQ(dq.Back(), 42);
}

TEST(Deque, DoubleInsertionBackFront) {
  Deque<int> dq;

  /* Test some insertions at back and front */
  dq.PushBack(23);
  dq.PushFront(42);
  EXPECT_EQ(dq.Empty(), false);
  EXPECT_EQ(dq.Size(), 2);
  EXPECT_EQ(dq[0], 42);
  EXPECT_EQ(dq[1], 23);
  EXPECT_EQ(dq.Back(), 23);
}

TEST(Deque, ItemOutOfRange) {
  Deque<int> dq;

  /* Item should be out of range of the deque */
  EXPECT_EQ(dq.Empty(), true);
  EXPECT_EQ(dq.Size(), 0);
  EXPECT_THROW(dq[4], std::exception);
}

TEST(Deque, HeadAndBack) {
  Deque<int> dq;

  /* Test the Front and Back Functionality */
  dq.PushBack(23);
  dq.PushFront(21);
  dq.PushFront(42);
  EXPECT_EQ(dq.Empty(), false);
  EXPECT_EQ(dq.Size(), 3);
  EXPECT_EQ(dq[0], 42);
  EXPECT_EQ(dq[2], 23);
  EXPECT_EQ(dq[1], 21);
  EXPECT_EQ(dq.Front(), 42);
  EXPECT_EQ(dq.Back(), 23);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

