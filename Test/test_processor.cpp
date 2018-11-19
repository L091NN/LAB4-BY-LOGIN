#include"gtest.h"
#include"Processor.h"

TEST(Processor, can_create_processor)
{
	ASSERT_NO_THROW(Processor P);
}

TEST(Processor, can_add_program)
{
	Program_Generation PG;
	Program Prog;
	Prog = PG.Generate();
	Processor P;
	ASSERT_NO_THROW(P.add_program(Prog,0));
}

TEST(Processor, check_correct_add_program)
{
	Program Prog1,Prog2;
	Processor P(16);
	for (int i = 0; i < 4; i++)
	{
		Prog1.act_core[0].push_back(0);
	}
	for (int i = 0; i < 10; i++)
	{
		Prog2.act_core[0].push_back(0);
	}
	P.add_program(Prog1, 0);
	P.add_program(Prog2, 0);
	EXPECT_EQ(P.Get_free_cores(), 2);
	EXPECT_EQ(P.Get_num_of_act_program(), 2);
	for (int i = 0; i < 4; i++)
	{
		EXPECT_EQ(i + 1, P.Get_act_program(0).act_core[0][i]);
	}
	for (int i = 0; i < 10; i++)
	{
		EXPECT_EQ(i + 5, P.Get_act_program(1).act_core[0][i]);
	}
}

TEST(Processor, check_correct_complete_program)
{
	Program Prog1, Prog2;
	Processor P(16);
	Prog1.ID = 1;
	Prog2.ID = 2;
	for (int i = 0; i < 4; i++)
	{
		Prog1.act_core[0].push_back(0);
	}
	for (int i = 0; i < 10; i++)
	{
		Prog2.act_core[0].push_back(0);
	}
	P.add_program(Prog1, 0);
	P.add_program(Prog2, 0);
	P.complete_program(Prog1, 0);
	EXPECT_EQ(P.Get_free_cores(), 6);
	EXPECT_EQ(P.Get_num_of_act_program(), 1);
	for (int i = 0; i < 4; i++)
	{
		EXPECT_EQ(0,P.Get_core(i).is_work);
	}
	for (int i = 0; i < 10; i++)
	{
		EXPECT_EQ(i + 5, P.Get_act_program(0).act_core[0][i]);
	}
	P.complete_program(Prog2, 0);
	for (int i = 0; i < 16; ++i)
	{
		EXPECT_EQ(0, P.Get_core(i).is_work);
	}
}
