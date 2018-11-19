#ifndef __PROCESSOR_H__
#define __PROCESSOR_H__

#include"Program.h"

using namespace std;

class Processor
{
	int noc; // number of core
	vector<Core> cores;
	int free_cores;
	vector<Program> act_program;
	vector<Program>::iterator act_program_it;

public:
	Processor(int cores = 4);
	~Processor();


	bool add_program(const Program &P, int number_of_processor);
	int Get_free_cores();
	int Get_cores();
	Core Get_core(int num);

	Program Get_act_program(int num);
	int Get_num_of_act_program();
	Program complete_program(const Program &P, int number_of_processor);
};





#endif
