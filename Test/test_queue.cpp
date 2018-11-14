#include "gtest.h"
#include "TQueue.h"

using namespace std;


TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue<int> Q);
}

TEST(TQueue, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue<int> Q(-1));
}

TEST(TQueue, can_create_copied_queue)
{
	TQueue<int> Q1;
	ASSERT_NO_THROW(TQueue<int> Q2(Q1));
}
/*
TEST(TQueue, check_copied_queue_equal_to_source_one)
{
	TQueue<int> Q1;
	Q1.push(2);
	TQueue<int> Q2(Q1);

	EXPECT_EQ(Q1,Q2);
}
*/
TEST(TQueue, can_create_queue_with_size_1)
{
	ASSERT_NO_THROW(TQueue<int> Q(10));
}

TEST(TQueue, check_full_size_1)
{
	TQueue<int> Q(10);
	EXPECT_EQ(10, Q.Get_full_size());
}

TEST(TQueue, can_create_queue_with_size_2)
{
	ASSERT_NO_THROW(TQueue<int> Q(100000));
}

TEST(TQueue, check_full_size_2)
{
	TQueue<int> Q(100000);
	EXPECT_EQ(100000, Q.Get_full_size());
}

TEST(TQueue, check_is_empty_when_queue_empty)
{
	TQueue<int> Q;
	Q.push(2);
	Q.pop();
	EXPECT_EQ(1,Q.is_empty());
}

TEST(TQueue, check_is_empty_when_queue_not_empty)
{
	TQueue<int> Q(2);
	Q.push(2);
	Q.push(3);
	EXPECT_EQ(0, Q.is_empty());
}

TEST(TQueue, check_is_full_when_queue_full)
{
	TQueue<int> Q(50);
	for (int i = 0; i < 50; i++)
	{
		Q.push(i);
	}
	EXPECT_EQ(1, Q.is_full());
}

TEST(TQueue, check_is_full_when_queue_not_full)
{
	TQueue<int> Q(50);
	for (int i = 0; i < 49; i++)
	{
		Q.push(i);
	}
	EXPECT_EQ(0, Q.is_full());
}

TEST(TQueue, throw_when_pop_empty_queue)
{
	TQueue<int> Q;
	ASSERT_ANY_THROW(Q.pop());
}

TEST(TQueue, throw_when_push_full_queue)
{
	TQueue<int> Q(2);
	Q.push(1);
	Q.push(2);
	ASSERT_ANY_THROW(Q.push(3));
}

TEST(TQueue, check_top_queue)
{
	TQueue<int> Q(50);
	for (int i = 0; i < 50; i++)
	{
		Q.push(i);
	}

	EXPECT_EQ(0, Q.top());
}

/*
TEST(TQueue, check_assign_queue)
{
	TQueue<int> Q1;
	Q1.push(2);
	TQueue<int> Q2 = Q1;

	EXPECT_EQ(Q1, Q2);
}
*/
TEST(TQueue, check_equal_queue)
{
	TQueue<int> Q1;
	TQueue<int> Q2;
	Q1.push(2);
	Q2.push(2);
	EXPECT_EQ(1, Q1 == Q2);
}