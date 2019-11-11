#include"Virtual_machine.h"

Statistic::Statistic()
{
	list<Program> Complete_Program = {};
	list<Program> Fail_Program_p = {};
	list<Program> Fail_Program_q = {};
	list<Program> Act_Program = {};
	list<int> tact_now = {};
	list<Program> Queue_Program = {};
	double num_of_prog = 0.0;
	list<Program>::iterator PIT = {};
	list<int>::iterator IIT = {};
}

list<Program> Statistic::Get_Complete_Program()
{
	return Complete_Program;
}
list<Program> Statistic::Get_Fail_Program_p()
{
	return Fail_Program_p;
}
list<Program> Statistic::Get_Fail_Program_q()
{
	return Fail_Program_q;
}
list<Program> Statistic::Get_Act_Program()
{
	return Act_Program;
}
list<Program> Statistic::Get_Queue_Program()
{
	return Queue_Program;
}
int Statistic::Get_num_of_prog()
{
	return trunc(num_of_prog);
}



Virtual_machine::Virtual_machine(double ppt, int piq)
{
	program_per_tact = ppt;
	this->piq = piq;
	tact = 0;
	Queue = {};
	Processor Proc;
	P.push_back(Proc);
}

Virtual_machine::~Virtual_machine()
{

}

void Virtual_machine::Set_queue(int size)
{
	TQueue<Program> Q(size);
	Queue = Q;
}

void Virtual_machine::Set_number_processors(int np)
{
	P = {};
	for (int x = 0; x < np; ++x)
	{
		Processor Pr;
		Pr.Set_number(x + 1);
		P.push_back(Pr);
	}
}

void Virtual_machine::Set_configuration_p(int num, int noc)
{
	auto IT = P.begin();
	for (; IT != P.end(); IT++)
	{
		if (IT->Get_number() == num)
		{
			break;
		}
	}
	if (IT != P.end())
	{
		Set_max_core(num - 1, noc);
		Set_min_core(num - 1, 0);
		if (noc < 1)
		{
			P.erase(IT);
		}
		else
		{
			IT->Set_configuration(noc);
		}
	}
	else
	{
		Processor Pro(num, noc);
		P.push_back(Pro);
		Set_max_core(num - 1, noc);
		Set_min_core(num - 1, 0);
	}
	
}

void Virtual_machine::Set_program_per_tact(double ppt)
{
	program_per_tact = ppt;
}

void Virtual_machine::Set_prog_in_queue_when_start(int piq)
{
	this->piq = piq;
}

vector<Processor> Virtual_machine::Get_processors()
{
	return P;
}

bool Virtual_machine::fit_program_p(const Program &Pr)
{
	vector<int> Proc;
	vector<int> numpc;
	vector<int> Prog;
	vector<int> numpg;

	for (int x = 0; x < Pr.act_core.size(); ++x)
	{
		int max = 0;
		int num = 0;
		for (int y = 0; y < Pr.act_core.size(); ++y)
		{
			if (Pr.act_core[y].size() > max)
			{
				int ind = 0;
				for (int z = 0; z < numpg.size(); ++z)
				{
					if (y == numpg[z])
					{
						ind = 1;
						break;
					}
				}
				if (ind == 0)
				{
					max = Pr.act_core[y].size();
					num = y;

				}
			}
		}
		if (Pr.act_core[x].size())
		{
			Prog.push_back(max);
			numpg.push_back(num);
		}
		max = 0;
		num = 0;
		for (int y = 0; y < P.size(); ++y)
		{
			if (P[y].Get_cores() > max)
			{
				int ind = 0;
				for (int z = 0; z < numpc.size(); ++z)
				{
					if (y == numpc[z])
					{
						ind = 1;
						break;
					}
				}
				if (ind == 0)
				{
					max = P[y].Get_cores();
					num = y;

				}
			}
		}
		if (Pr.act_core[x].size())
		{
			Proc.push_back(max);
			numpc.push_back(num);
			if (Proc.back() < Prog.back())
				return 0;
		}
	}

	return 1;
}

bool Virtual_machine::fit_program(const Program &Pr)
{
	vector<int> Proc;
	vector<int> numpc;
	vector<int> Prog;
	vector<int> numpg;

	for (int x = 0; x < Pr.act_core.size(); ++x)
	{
		int max = 0;
		int num = 0;
		for (int y = 0; y < Pr.act_core.size(); ++y)
		{
			if (Pr.act_core[y].size() > max)
			{
				int ind = 0;
				for (int z = 0; z < numpg.size(); ++z)
				{
					if (y == numpg[z])
					{
						ind = 1;
						break;
					}
				}
				if (ind == 0)
				{
					max = Pr.act_core[y].size();
					num = y;

				}
			}
		}
		if (Pr.act_core[x].size())
		{
			Prog.push_back(max);
			numpg.push_back(num);
		}
		max = 0;
		num = 0;
		for (int y = 0; y < P.size(); ++y)
		{
			if (P[y].Get_free_cores() > max)
			{
				int ind = 0;
				for (int z = 0; z < numpc.size(); ++z)
				{
					if (y == numpc[z])
					{
						ind = 1;
						break;
					}
				}
				if (ind == 0)
				{
					max = P[y].Get_free_cores();
					num = y;

				}
			}
		}
		if (Pr.act_core[x].size())
		{
			Proc.push_back(max);
			numpc.push_back(num);
			if (Proc.back() < Prog.back())
				return 0;
		}

	}

	return 1;
}

vector<int> Virtual_machine::suitable_option(const Program &Pr) // возвращает номера процессоров для эффективной работы данной программы(по порядку)
{
	vector<int> Proc;
	vector<int> numpc;
	vector<int> Prog;
	vector<int> numpg;

	for (int x = 0; x < Pr.act_core.size(); ++x)
	{
		int max = 0;
		int num = 0;
		for (int y = 0; y < Pr.act_core.size(); ++y)
		{
			if (Pr.act_core[y].size() > max)
			{
				int ind = 0;
				for (int z = 0; z < numpg.size(); ++z)
				{
					if (y == numpg[z])
					{
						ind = 1;
						break;
					}
				}
				if (ind == 0)
				{
					max = Pr.act_core[y].size();
					num = y;

				}
			}
		}
		if (Pr.act_core[x].size())
		{
			Prog.push_back(max);
			numpg.push_back(num);
		}
		max = 0;
		num = 0;
		for (int y = 0; y < P.size(); ++y)
		{
			if (P[y].Get_free_cores() > max)
			{
				int ind = 0;
				for (int z = 0; z < numpc.size(); ++z)
				{
					if (y == numpc[z])
					{
						ind = 1;
						break;
					}
				}
				if (ind == 0)
				{
					max = P[y].Get_free_cores();
					num = y;

				}
			}
		}
		if (Pr.act_core[x].size())
		{
			Proc.push_back(max);
			numpc.push_back(num);
		}

	}
	for (int i = numpg.size() - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (numpg[j] > numpg[j + 1])
			{
				int buf;
				buf = numpg[j];
				numpg[j] = numpg[i];
				numpg[i] = buf;

				buf = numpc[j];
				numpc[j] = numpc[i];
				numpc[i] = buf;
			}
		}
	}

	return numpc;
}

bool Virtual_machine::START()
{
	tact = 0;
	for (int x = 0; x < piq; ++x)
	{
		if (!Queue.is_full())
		{
			num_of_prog += 1.0;
			Queue.push(Generate());
		}
		else
		{
			return 0;
		}
	}

	return 1;
}

void Virtual_machine::plus_tact(int t)
{
	for (int x = 0; x < t; x++)
	{
		++tact;
		for (PIT = Act_Program.begin(), IIT = tact_now.begin();IIT != tact_now.end();)
		{
			*IIT -= 1;
			if (*IIT == 0)
			{
				Complete_Program.push_back(*(PIT));
				for (int y = 0; y < PIT -> act_proc.size(); ++y)
				{
					P[PIT->act_proc[y]].complete_program(*PIT, PIT ->act_proc[y]);
				}
				Act_Program.erase(PIT++);
				tact_now.erase(IIT++);
			}
			else
			{
					PIT++;
					IIT++;
			}
		}
		double ppt = num_of_prog;
		num_of_prog += program_per_tact;
		for (int y = 0; y < trunc(num_of_prog - trunc(ppt)); ++y)
		{
			if (!Queue.is_full())
			{
				Queue.push(Generate());
			}
			else
			{
				Fail_Program_q.push_back(Generate());
			}
		}
		while (1)
		{
			if (!Queue.is_empty())
			{
				if (!fit_program_p(Queue.top()))
				{
					Fail_Program_p.push_back(Queue.pop());
				}
				else
				{
					if (fit_program(Queue.top()))
					{
						vector<int> distribution = suitable_option(Queue.top());
						Program Proga = Queue.pop();
						for (int z = 0; z < distribution.size(); ++z)
						{
							P[distribution[z]].add_program(Proga, distribution[z]);
							Proga.act_proc.push_back(distribution[z]);
						}
						tact_now.push_back(Proga.tacts);
						Act_Program.push_back(Proga);
					}
					else
					{
						break; // ??
					}
				}
			}
			else
			{
				break;
			}
		}

	}
}

int Virtual_machine::Get_tact()
{
	return tact;
}

list<int> Virtual_machine::Get_tact_now()
{
	return tact_now;
}

vector<Processor>::iterator Virtual_machine::Get_begin_ptr_Proc()
{
	return P.begin();
}
vector<Processor>::iterator Virtual_machine::Get_end_ptr_Proc()
{
	return P.end();
}

TQueue<Program> Virtual_machine::Get_queue()
{
	return Queue;
}

int Virtual_machine::Get_programm_in_queue_when_start()
{
	return piq;
}

int Virtual_machine::Get_index_of_proc(int num)
{
	for (int i = 0; i < P.size(); i++)
	{
		if (P[i].Get_number() == num)
		{
			return i;
		}
	}
	return -1;
}
int Virtual_machine::Get_num_of_proc(int index)
{
	if (index < P.size())
	{
		return P[index].Get_number();
	}
	
	return -1;
}

double Virtual_machine::Get_program_per_tact()
{
	return program_per_tact;
}