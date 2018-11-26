#include"Program.h"

Program_Generation::Program_Generation()
{
	ID = 100001;
	Set_max_proc(1);
	Set_min_proc(1);
	for (int i = 0; i < MAX_PROCESSORS; i++)
	{
		max_core[i] = 0;
		min_core[i] = 0;
	}
	Set_max_core(0, 2);
	Set_max_tact(100);
	Set_min_tact(1);
}

Program_Generation::~Program_Generation()
{

}

void Program_Generation::Set_max_proc(int num)
{
	if (num > MAX_PROCESSORS || num < min_proc) throw("Incorrect parameter");
	max_proc = num;
}
void Program_Generation::Set_min_proc(int num)
{
	if (num > max_proc || num < 1) throw("Incorrect parameter");
	min_proc = num;
}
void Program_Generation::Set_max_tact(int num)
{
	if(num < min_tact) throw("Incorrect parameter");
	max_tact = num;
}
void Program_Generation::Set_min_tact(int num)
{
	if (num > max_tact || num < 1) throw("Incorrect parameter");
	min_tact = num;
}
void Program_Generation::Set_max_core(int index, int num)
{
	if (index < 0 || index >= max_proc) throw("Incorrect parameter");
	if (num < 0 || num > MAX_CORES) throw("Incorrect parameter"); // �������� MAX_CORES �� ���������� � ������������ ����������, ����� ��������� ������ ���������
	max_core[index] = num;
}
void Program_Generation::Set_min_core(int index, int num)
{
	if (index < 0 || index >= max_proc) throw("Incorrect parameter");
	if (num > max_core[index] || num < 0) throw("Incorrect parameter");
	min_core[index] = num;
}
int Program_Generation::Get_max_proc()
{
	return max_proc;
}
int Program_Generation::Get_min_proc()
{
	return min_proc;
}
int Program_Generation::Get_max_tact()
{
	return max_tact;
}
int Program_Generation::Get_min_tact()
{
	return min_tact;
}
int Program_Generation::Get_max_core(int index)
{
	return max_core[index];
}
int Program_Generation::Get_min_core(int index)
{
	return min_core[index];
}
Program Program_Generation::Generate()
{
	Program p;
	p.act_core.pop_back();
	p.ID = ID++;
	if (min_tact == max_tact)
	{
		p.tacts = min_tact;
		int proc_num = rand() % max_proc + 1;
		for (int i = 0; i < proc_num; i++)
		{
			int core_num = rand() % max_core[i] + 1;
			vector<int> c;
			for (int j = 0; j < core_num; j++)
			{
				c.push_back(0);
			}
			p.act_core.push_back(c);
		}
	}
	else 
	{

		p.tacts = rand() % (max_tact - min_tact) + min_tact;
		int proc_num = rand() % max_proc + 1;
		for (int i = 0; i < proc_num; i++)
		{
			int core_num = rand() % max_core[i] + 1;
			vector<int> c;
			for (int j = 0; j < core_num; j++)
			{
				c.push_back(0);
			}
			p.act_core.push_back(c);
		}
	}

	return p;
}