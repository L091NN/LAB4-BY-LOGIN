#include"gtest.h"
#include"Virtual_machine.h"

TEST(Virtual_machine, can_create_virtual_machine)
{
	ASSERT_NO_THROW(Virtual_machine VM);
}

TEST(Virtual_machine, can_start)
{
	Virtual_machine VM;
	VM.Set_number_processors(3);
	VM.Set_max_proc(3);
	VM.Set_min_proc(1);
	VM.Set_max_core(0, 32);
	VM.Set_max_core(1, 32);
	VM.Set_max_core(2, 32);
	VM.Set_min_core(0, 1);
	VM.Set_max_tact(100);
	VM.Set_min_tact(10);
	VM.Set_configuration_p(1, 32);
	VM.Set_configuration_p(2, 32);
	VM.Set_configuration_p(3, 32);
	VM.Set_program_per_tact(2.0);
	VM.Set_prog_in_queue_when_start(5);
	ASSERT_NO_THROW(VM.START());
}

TEST(Virtual_machine, can_plus_tact)
{
	Virtual_machine VM;
	VM.Set_number_processors(3);
	VM.Set_max_proc(3);
	VM.Set_min_proc(1);
	VM.Set_max_core(0, 32);
	VM.Set_max_core(1, 32);
	VM.Set_max_core(2, 32);
	VM.Set_min_core(0, 1);
	VM.Set_max_tact(100);
	VM.Set_min_tact(10);
	VM.Set_configuration_p(1, 32);
	VM.Set_configuration_p(2, 32);
	VM.Set_configuration_p(3, 32);
	VM.Set_program_per_tact(2.0);
	VM.Set_prog_in_queue_when_start(5);
	VM.START();
	ASSERT_NO_THROW(VM.plus_tact());
}
