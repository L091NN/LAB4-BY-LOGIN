#ifndef __PROGRAM_H__
#define __PROGRAM_H__

#include<vector>

constexpr auto MAX_CORES = 64;
constexpr auto MAX_PROCESSORS = 4; // максимальное количество процессоров

using namespace std;

struct Program
{
	int ID; // имя программы
	int tacts; // количество тактов для выполнения
	vector<vector<int>> act_core; // 1 вектор зависит от колечества задействованных процессоров, 2 от количества занимаемых программой ядер

	Program()
	{
		ID = -1;
		tacts = -1;
		vector<int> s = {};
		act_core.push_back(s);
	}

	Program& operator=(const Program &P)
	{
		if (this != &P)
		{
			ID = P.ID;
			tacts = P.tacts;
			for (int x = 0; x < P.act_core.size(); ++x)
			{
				act_core[x] = P.act_core[x];
			}
		}

		return *this;
	}
};

struct Core
{
	int num;
	Program P;
	bool is_work = 0;
};

class Program_Generation
{
	int ID;
	int max_core[MAX_PROCESSORS];
	int min_core[MAX_PROCESSORS];
	int max_proc;
	int min_proc;
	int max_tact;
	int min_tact;
public:
	Program_Generation();
	~Program_Generation();

	void Set_max_proc(int num);
	void Set_max_tact(int num);
	void Set_max_core(int index, int num);
	void Set_min_proc(int num);
	void Set_min_tact(int num);
	void Set_min_core(int index, int num);

	int Get_max_proc();
	int Get_max_tact();
	int Get_max_core(int index);
	int Get_min_proc();
	int Get_min_tact();
	int Get_min_core(int index);

	Program Generate();
};


#endif


