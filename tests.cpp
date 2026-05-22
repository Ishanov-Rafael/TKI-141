#include <gtest/gtest.h>
#include "DoubleEndedPriorityQueue.h"

TEST(PriorityQueueTests, EmptyOnCreation)
{
    DoubleEndedPriorityQueue q;
    EXPECT_TRUE(q.is_empty());
    EXPECT_EQ(q.get_size(), 0);
}

TEST(PriorityQueueTests, InitializerListSorting)
{
    DoubleEndedPriorityQueue q = {40, 10, 30, 20};
    EXPECT_EQ(q.to_string(), "10 20 30 40");
    EXPECT_EQ(q.get_min(), 10);
    EXPECT_EQ(q.get_max(), 40);
}

TEST(PriorityQueueTests, InsertionMaintainsOrder)
{
    DoubleEndedPriorityQueue q;
    q.insert(15);
    q.insert(5);
    q.insert(10);
    EXPECT_EQ(q.to_string(), "5 10 15");
}

TEST(PriorityQueueTests, DeletionWorksFine)
{
    DoubleEndedPriorityQueue q = {1, 2, 3, 4};
    q.remove_min();
    EXPECT_EQ(q.to_string(), "2 3 4");
    q.remove_max();
    EXPECT_EQ(q.to_string(), "2 3");
}

TEST(PriorityQueueTests, ExceptionHandling)
{
    DoubleEndedPriorityQueue q;
    EXPECT_THROW(q.get_min(), std::out_of_range);
    EXPECT_THROW(q.remove_max(), std::out_of_range);
}

TEST(PriorityQueueTests, ShiftOperatorsChain)
{
    DoubleEndedPriorityQueue q;
    q << 100 << 10 << 50; 
    EXPECT_EQ(q.to_string(), "10 50 100");

    int extracted = 0;
    q >> extracted;
    EXPECT_EQ(extracted, 100);
    EXPECT_EQ(q.to_string(), "10 50");
}
