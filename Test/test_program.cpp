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
	ASSERT_NO_THROW(PG.Generate(1));
}