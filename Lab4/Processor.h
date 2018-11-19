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

public:
	Processor(int cores = 4);
	~Processor();


	bool add_program(Program P);

};





#endif
