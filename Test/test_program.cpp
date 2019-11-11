#include"gtest.h"
#include "Program.h"

TEST(Program_Generation, can_create_program_generation)
{
	ASSERT_NO_THROW(Program_Generation PG);
}

TEST(Program_Generation, can_generation_1)
{
	Program_Generation PG;
	PG.Set_min_tact(100);
	ASSERT_NO_THROW(PG.Generate());
}

TEST(Program_Generation, check_set_max_proc)
{
	Program_Generation PG;
	PG.Set_max_proc(3);
	EXPECT_EQ(3, PG.Get_max_proc());
}

TEST(Program_Generation, check_set_min_proc)
{
	Program_Generation PG;
	PG.Set_max_proc(3);
	PG.Set_min_proc(2);
	EXPECT_EQ(2, PG.Get_min_proc());
}

TEST(Program_Generation, throw_when_max_proc_less_min_proc)
{
	Program_Generation PG;
	ASSERT_ANY_THROW(PG.Set_max_proc(PG.Get_min_proc() - 1));
}

TEST(Program_Generation, throw_when_min_proc_less_1)
{
	Program_Generation PG;
	ASSERT_ANY_THROW(PG.Set_min_proc(0));
}

TEST(Program_Generation, throw_when_max_proc_more_MAX_PROCESSORS)
{
	Program_Generation PG;
	ASSERT_ANY_THROW(PG.Set_max_proc(MAX_PROCESSORS + 1));
}

TEST(Program_Generation, throw_when_min_proc_more_max_proc)
{
	Program_Generation PG;
	ASSERT_ANY_THROW(PG.Set_min_proc(PG.Get_max_proc() + 1));
}

TEST(Program_Generation, check_set_max_tact)
{
	Program_Generation PG;
	PG.Set_max_tact(300);
	EXPECT_EQ(300, PG.Get_max_tact());
}

TEST(Program_Generation, check_set_min_tact)
{
	Program_Generation PG;
	PG.Set_min_tact(50);
	EXPECT_EQ(50, PG.Get_min_tact());
}

TEST(Program_Generation, throw_when_max_tact_less_min_tact)
{
	Program_Generation PG;
	ASSERT_ANY_THROW(PG.Set_max_tact(PG.Get_min_tact() - 1));
}

TEST(Program_Generation, throw_when_min_tact_less_1)
{
	Program_Generation PG;
	ASSERT_ANY_THROW(PG.Set_min_tact(0));
}

TEST(Program_Generation, throw_when_min_tact_more_max_tact)
{
	Program_Generation PG;
	ASSERT_ANY_THROW(PG.Set_min_tact(PG.Get_max_tact() + 1));
}

TEST(Program_Generation, check_set_max_core)
{
	Program_Generation PG;
	PG.Set_max_core(0,2);
	EXPECT_EQ(2, PG.Get_max_core(0));
}

TEST(Program_Generation, check_set_min_core)
{
	Program_Generation PG;
	PG.Set_max_core(0, 2);
	EXPECT_EQ(2, PG.Get_max_core(0));
}

TEST(Program_Generation, throw_when_max_core_more_MAX_CORES) // изменить после написания класса процессор
{
	Program_Generation PG;
	ASSERT_ANY_THROW(PG.Set_max_core(0, MAX_CORES + 1));
}

TEST(Program_Generation, throw_when_max_core_less_min_core)
{
	Program_Generation PG;
	ASSERT_ANY_THROW(PG.Set_max_core(0, PG.Get_min_core(0) - 1));
}

TEST(Program_Generation, throw_when_min_core_more_max_core)
{
	Program_Generation PG;
	ASSERT_ANY_THROW(PG.Set_min_core(0, PG.Get_max_core(0) + 1));
}

TEST(Program_Generation, throw_when_min_core_less_0)
{
	Program_Generation PG;
	ASSERT_ANY_THROW(PG.Set_min_core(0, -1));
}

TEST(Program_Generation, throw_when_index_min_core_more_max_proc)
{
	Program_Generation PG;
	ASSERT_ANY_THROW(PG.Set_min_core(PG.Get_max_proc(), 1));
}

TEST(Program_Generation, throw_when_index_max_core_less_0)
{
	Program_Generation PG;
	ASSERT_ANY_THROW(PG.Set_max_core(-1, 1));
}

TEST(Program_Generation, throw_when_index_min_core_less_0)
{
	Program_Generation PG;
	ASSERT_ANY_THROW(PG.Set_min_core(-1, 1));
}

TEST(Program_Generation, check_program_generator_1)
{
	Program_Generation PG;
	Program P1, P2;
	int tacts = 10;
	int proc = 1;
	int cores = 4;
	P1.tacts = tacts;
	vector<int> c;
	for (int i = 0; i < cores; i++)
	{
		c.push_back(0);
	}
	P1.act_core.push_back(c);
	PG.Set_max_tact(tacts);
	PG.Set_min_tact(tacts);
	PG.Set_max_proc(proc);
	PG.Set_min_proc(proc);
	PG.Set_max_core(0, cores);
	PG.Set_min_core(0, cores);
	P2 = PG.Generate();
	EXPECT_EQ(P1.tacts, P2.tacts);
	EXPECT_EQ(P1.act_core.size(), P2.act_core.size());
	EXPECT_EQ(P1.act_core[0].size(), P2.act_core[0].size());
	
}
