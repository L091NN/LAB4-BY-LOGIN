#include "gtest.h"
#include "TQueue.h"

using namespace std;

TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue<int> Q);
}

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
