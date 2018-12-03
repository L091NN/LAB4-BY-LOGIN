#include"Processor.h"

int Processor::num_of_processors = 0;

Processor::Processor(int num,int cores)
{
	num_of_processors++;
	if (num < 1)
	{
		Number = num_of_processors;
	}
	else
	{
		Number = num;
	}
	noc = cores;
	free_cores = cores;
	for (int i = 0; i < cores; i++)
	{
		Core c;
		c.num = i + 1;
		this->cores.push_back(c);
	}
	act_program = {};
	//act_program_it = act_program.begin();

}

Processor::~Processor()
{
	num_of_processors--;
}

bool Processor::add_program(const Program &P, int number_of_processor)
{
	Program Pr = P;
	for (int x = 0; x < P.act_core[number_of_processor].size(); x++)
	{
		for (int y = 0; y < this->noc; y++)
		{
			if (cores[y].is_work == 0)
			{
				cores[y].P = P;
				cores[y].is_work = 1;
				Pr.act_core[number_of_processor][x] = cores[y].num;
				--free_cores;
				break;
			}
		}
	}
	act_program.push_back(Pr);

	return 1;
}

int Processor::Get_free_cores()
{
	return free_cores;
}

int Processor::Get_cores()
{
	return noc;
}

Core Processor::Get_core(int num)
{
	return cores[num];
}

int Processor::Get_num_of_act_program()
{
	return act_program.size();
}

Program Processor::Get_act_program(int num)
{
	return act_program[num];
}

Program Processor::complete_program(const Program &P, int number_of_processor)
{
	Program Pr;
	for (act_program_it = act_program.begin(); act_program_it != act_program.end(); act_program_it++)
	{
		if (act_program_it._Ptr->ID == P.ID)
		{
			Pr = *act_program_it;
			act_program.erase(act_program_it);
			break;
		}
	}
	for (int x = 0; x < P.act_core[number_of_processor].size(); x++)
	{
		cores[Pr.act_core[number_of_processor][x] - 1].is_work = 0;
		cores[Pr.act_core[number_of_processor][x] - 1].P = {};
		++free_cores;
	}
	
	return Pr;

}

void Processor::Set_configuration(int noc)
{
	this->noc = noc;
	free_cores = noc;
	act_program = {};
	cores = {};
	for (int i = 0; i < noc; i++)
	{
		Core c;
		c.num = i + 1;
		this->cores.push_back(c);
	}
}

void Processor::Set_number(int num)
{
	Number = num;
}

int Processor::Get_number()
{
	return Number;
}

void Processor::Set_core(int num, bool work, const Program Prog)
{
	cores[num].is_work = work;
	cores[num].P = Prog;
}