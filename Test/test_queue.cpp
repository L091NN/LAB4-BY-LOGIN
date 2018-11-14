#include "gtest.h"
#include "TQueue.h"

using namespace std;

TEST(TQueue, can_create_stack)
{
	ASSERT_NO_THROW(TQueue<int> Q);
}