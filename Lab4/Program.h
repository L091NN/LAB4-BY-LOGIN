#ifndef __PROGRAM_H__
#define __PROGRAM_H__

#include<vector>


constexpr auto MAX_PROCESSORS = 4; // максимальное количество процессоров

using namespace std;

struct Program
{
	int ID; // имя программы
	int tacts; // количество тактов для выполнения
	vector<vector<int>> act_core; // 1 вектор зависит от колечества процессоров, 2 от количества занимаемых ядер
};

class Program_Generation
{
	int max_core[MAX_PROCESSORS];
	int min_core[MAX_PROCESSORS];
	int max_proc;
	int min_proc;
	unsigned int max_tact;
	unsigned int min_tact;
public:
	Program_Generation();
	~Program_Generation();
	void Set_max_proc(int num);
	void Set_max_tact(unsigned int num);
	void Set_max_core(int index, int num);
	void Set_min_proc(int num);
	void Set_min_tact(unsigned int num);
	void Set_min_core(int index, int num);

	int Get_max_proc();
	unsigned int Get_max_tact();
	int Get_max_core(int index);
	int Get_min_proc();
	unsigned int Get_min_tact();
	int Get_min_core(int index);

	Program Generate(int ID);
};


#endif


