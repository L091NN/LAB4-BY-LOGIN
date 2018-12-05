#ifndef __VIRTUAL_MACHINE_H__
#define __VIRTUAL_MACHINE_H__

#include<list>
#include<math.h>
#include"Processor.h"
#include"TQueue.h"

class Statistic
{
protected:
	list<Program> Complete_Program;
	list<Program> Fail_Program_q;
	list<Program> Fail_Program_p;
	list<Program> Act_Program;
	list<int> tact_now;
	list<Program> Queue_Program;
	double num_of_prog;
	list<Program>::iterator PIT;
	list<int>::iterator IIT;
public:
	Statistic();
	list<Program> Get_Complete_Program();
	list<Program> Get_Fail_Program_q();
	list<Program> Get_Fail_Program_p();
	list<Program> Get_Act_Program();
	list<Program> Get_Queue_Program();
	int Get_num_of_prog();
};

class Virtual_machine : public Program_Generation , public Statistic
{
	TQueue<Program> Queue;
	vector<Processor> P;
	double program_per_tact;
	int piq; //program in queue, when start
	int tact;

protected:
	bool fit_program(const Program &P);
	vector<int> suitable_option(const Program &P);
	bool fit_program_p(const Program &Pr);

public:
	Virtual_machine(double ppt = 1.0, int piq = 1);
	~Virtual_machine();

	void Set_queue(int size);
	void Set_number_processors(int np);
	void Set_configuration_p(int num, int noc);
	void Set_program_per_tact(double ppt);
	void Set_prog_in_queue_when_start(int piq);

	vector<Processor> Get_processors();
	vector<Processor>::iterator Get_begin_ptr_Proc();
	vector<Processor>::iterator Get_end_ptr_Proc();

	TQueue<Program> Get_queue();

	bool START();
	void plus_tact(int t = 1);

	int Get_tact();
	list<int> Get_tact_now();

	int Get_index_of_proc(int num);
	int Get_num_of_proc(int index);

	int Get_programm_in_queue_when_start();
	double Get_program_per_tact();


};


#endif
