#include"Processor.h"

Processor::Processor(int cores = 4)
{
	noc = cores;
	free_cores = cores;
	for (int i = 0; i < cores; i++)
	{
		Core c;
		c.num = i + 1;
		this->cores.push_back(c);
	}
	act_program = {};

}

Processor::~Processor()
{

}

bool Processor::add_program(Program P)
{
	//if (free_cores > P.act_core)
}