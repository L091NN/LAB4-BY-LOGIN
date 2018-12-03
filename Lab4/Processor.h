#ifndef __PROCESSOR_H__
#define __PROCESSOR_H__

#include"Program.h"

using namespace std;

class Processor
{
	static int num_of_processors;
	int Number;
	int noc; // number of core
	vector<Core> cores;
	int free_cores;
	vector<Program> act_program;
	vector<Program>::iterator act_program_it;
	void Set_core(int num, bool work, const Program Prog);
public:
	Processor(int num = 0, int cores = 4);
	~Processor();


	bool add_program(const Program &P, int number_of_processor);

	int Get_free_cores();
	int Get_cores();
	Core Get_core(int num);

	Program Get_act_program(int num);
	int Get_num_of_act_program();
	int Get_number();
	


	Program complete_program(const Program &P, int number_of_processor);

	void Set_configuration(int noc);
	void Set_number(int num);

};





#endif
