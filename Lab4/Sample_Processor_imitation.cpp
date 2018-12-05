#include"Virtual_machine.h"
#include<conio.h>
#include<Windows.h>
#include<iostream>
#include<ctime>
#include<locale>

using namespace std;

int style = 0;
int col_of_text = 0;
int col_of_bg = 15;

int mass_of_style[6][2] = 
{
	{ 15, 0},{ 0, 15},{ 14, 9},{ 12, 15},{ 15, 1},{ col_of_text, col_of_bg}
};

bool Show_RTI = 1;
bool Show_Proc = 1;
unsigned int FPT = 1;
unsigned int time_of_work = 0;
unsigned int V = 1000;
bool big_statistic_now = 1;
bool big_statistic_after = 0;
unsigned int LOGIN = 0;

void gotoxy(int xpos, int ypos);
void display_cursor(bool tf);
void set_colour(int colour_of_text, int colour_of_background);
void Output_information();
void START_MENU(int first_item, const Virtual_machine &VM, int ind = 0);
void DROW(int menu_future, int menu_past, int menu_post, const Virtual_machine &Vm);
void plus_1_power_proc(Virtual_machine &VM, int num_proc);
void minus_1_power_proc(Virtual_machine &VM, int num_proc);
void plus_1_elem_in_queue(Virtual_machine &VM);
void minus_1_elem_in_queue(Virtual_machine &VM);
void plus_1_program_in_queue(Virtual_machine &VM);
void minus_1_program_in_queue(Virtual_machine &VM);
void plus_1_style();
void minus_1_style();
void Rand_colour();
string Get_name_of_style(int num);
string MENU_ITEM(int menu, const Virtual_machine &Vm);


enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	display_cursor(0);
	int x = 0;
	int y = 0;
	int menu_future = 1;
	int menu_past = 1;
	int menu_post = 0;
	int menu_futurec = 1;
	int menu_pastc = 1;
	int menu_postc = 0;
	Virtual_machine VM;
	int proc_num = VM.Get_processors().size();
	char key = 0;
	START_MENU(1, VM);
	while (1)
	{
		if (style == 5) Rand_colour();
		vector<Processor> VMP = VM.Get_processors();
		key = _getch();
		switch (key)
		{
		case 13: // ENTER
		{
			switch (menu_future)
			{
			case 1:
			{

				break;
			}
			case 16:
			{

				break;
			}
			case 17:
			{

				break;
			}
			case 18:
			{
				if (FPT == 91)
				{
					if (LOGIN == 0)
					{
						LOGIN = 1;
					}
				}
				break;
			}
			case 19:
			{
				if (style == 5 && LOGIN == 1)
				{
					LOGIN = 2;
				}
				break;
			}
			case 56:
			{

				break;
			}
			case 57:
			{

				break;
			}
			case 58:
			{

				break;
			}
			case 59:
			{

				break;
			}
			case 61:
			{

				break;
			}
			case 62:
			{

				break;
			}
			case 63:
			{

				break;
			}
			case 64:
			{

				break;
			}
			case 66:
			{

				break;
			}
			case 67:
			{

				break;
			}
			case 69:
			{

				break;
			}
			case 71:
			{

				break;
			}
			case 72:
			{

				break;
			}
			case 73:
			{
				big_statistic_now -= 1;
				break;
			}
			case 74:
			{
				big_statistic_after -= 1;
				break;
			}
			case 341:
			{

				break;
			}
			case 342:
			{

				break;
			}
			case 343:
			{

				break;
			}
			case 344:
			{

				break;
			}
			default:
			{
				if (menu_future % 5 != 0)
				{
					menu_past = menu_future;
					menu_future *= 5;
					menu_future++;
				}
				else
				{
					if (menu_future == 5)
					{
						menu_past = menu_future;
						menu_future *= 5;
						menu_future++;
					}
					else
					{
						menu_past = menu_future;
						menu_future = trunc((menu_future - 1) / 5);
						menu_future = trunc((menu_future - 1) / 5) * 5 + 1;
					}
				}
			}
			}

			break;
		}
		case 27: // ESC
		{
			exit(0);
			break;
		}
		case 72: // UP
		{
			switch (menu_future)
			{
			case 66:
			{
				if (menu_post == 0)
				{
					menu_past = menu_future;
					if (menu_future % 5 != 1)
						menu_future -= 1;
					else
						menu_future += 4;
				}
				if (menu_post == 1)
				{
					if (VM.Get_max_tact() != VM.Get_min_tact())
					{
						VM.Set_min_tact(VM.Get_min_tact() + 1);
					}
					else
					{
						VM.Set_min_tact(1);
					}
				}
				if (menu_post == 2)
				{
					VM.Set_max_tact(VM.Get_max_tact() + 1);
				}

				break;
			}
			case 67:
			{
				if (menu_post == 0)
				{
					menu_past = menu_future;
					if (menu_future % 5 != 1)
						menu_future -= 1;
					else
						menu_future += 4;
				}
				if (menu_post == 1)
				{
					if (VM.Get_max_proc() != VM.Get_min_proc())
					{
						VM.Set_min_proc(VM.Get_min_proc() + 1);
					}
					else
					{
						VM.Set_min_proc(1);
					}
				}
				if (menu_post == 2)
				{
					if (VM.Get_max_proc() < VM.Get_processors().size())
					{
						VM.Set_max_proc(VM.Get_max_proc() + 1);
					}
				}

				break;
			}
			case 69:
			{
				if (menu_post == 0)
				{
					menu_past = menu_future;
					if (menu_future % 5 != 1)
						menu_future -= 1;
					else
						menu_future += 4;
				}
				if (menu_post == 1)
				{
					VM.Set_program_per_tact(VM.Get_program_per_tact() + 1.0);
				}
				if (menu_post == 2)
				{
					VM.Set_program_per_tact(VM.Get_program_per_tact() + 0.1);
				}

				break;
			}
			case 341:
			{
				if (menu_post == 0)
				{
					menu_past = menu_future;
					if (menu_future % 5 != 1)
						menu_future -= 1;
					else
						menu_future += 4;
				}
				if (menu_post == 1)
				{
					if (VM.Get_index_of_proc(1) != -1)
					{
						if (VM.Get_min_core(VM.Get_index_of_proc(1)) == VM.Get_max_core(VM.Get_index_of_proc(1)))
						{
							VM.Set_min_core(VM.Get_index_of_proc(1), 0);
						}
						else
						{
							VM.Set_min_core(VM.Get_index_of_proc(1), VM.Get_min_core(VM.Get_index_of_proc(1)) + 1);
						}
					}
				}
				if (menu_post == 2)
				{
					if (VM.Get_index_of_proc(1) != -1)
					{
						if (VM.Get_max_core(VM.Get_index_of_proc(1)) != VM.Get_processors()[VM.Get_index_of_proc(1)].Get_cores())
						{
							VM.Set_max_core(VM.Get_index_of_proc(1), VM.Get_max_core(VM.Get_index_of_proc(1)) + 1);
						}
					}
				}
				break;
			}
			case 342:
			{
				if (menu_post == 0)
				{
					menu_past = menu_future;
					if (menu_future % 5 != 1)
						menu_future -= 1;
					else
						menu_future += 4;
				}
				if (menu_post == 1)
				{
					if (VM.Get_index_of_proc(2) != -1)
					{
						if (VM.Get_min_core(VM.Get_index_of_proc(2)) == VM.Get_max_core(VM.Get_index_of_proc(2)))
						{
							VM.Set_min_core(VM.Get_index_of_proc(2), 0);
						}
						else
						{
							VM.Set_min_core(VM.Get_index_of_proc(2), VM.Get_min_core(VM.Get_index_of_proc(2)) + 1);
						}
					}
				}
				if (menu_post == 2)
				{
					if (VM.Get_index_of_proc(2) != -1)
					{
						if (VM.Get_max_core(VM.Get_index_of_proc(2)) != VM.Get_processors()[VM.Get_index_of_proc(2)].Get_cores())
						{
							VM.Set_max_core(VM.Get_index_of_proc(2), VM.Get_max_core(VM.Get_index_of_proc(2)) + 1);
						}
					}
				}
				break;
			}
			case 343:
			{
				if (menu_post == 0)
				{
					menu_past = menu_future;
					if (menu_future % 5 != 1)
						menu_future -= 1;
					else
						menu_future += 4;
				}
				if (menu_post == 1)
				{
					if (VM.Get_index_of_proc(3) != -1)
					{
						if (VM.Get_min_core(VM.Get_index_of_proc(3)) == VM.Get_max_core(VM.Get_index_of_proc(3)))
						{
							VM.Set_min_core(VM.Get_index_of_proc(3), 0);
						}
						else
						{
							VM.Set_min_core(VM.Get_index_of_proc(3), VM.Get_min_core(VM.Get_index_of_proc(3)) + 1);
						}
					}
				}
				if (menu_post == 2)
				{
					if (VM.Get_index_of_proc(3) != -1)
					{
						if (VM.Get_max_core(VM.Get_index_of_proc(3)) != VM.Get_processors()[VM.Get_index_of_proc(3)].Get_cores())
						{
							VM.Set_max_core(VM.Get_index_of_proc(3), VM.Get_max_core(VM.Get_index_of_proc(3)) + 1);
						}
					}
				}
				break;
			}
			case 344:
			{
				if (menu_post == 0)
				{
					menu_past = menu_future;
					if (menu_future % 5 != 1)
						menu_future -= 1;
					else
						menu_future += 4;
				}
				if (menu_post == 1)
				{
					if (VM.Get_index_of_proc(4) != -1)
					{
						if (VM.Get_min_core(VM.Get_index_of_proc(4)) == VM.Get_max_core(VM.Get_index_of_proc(4)))
						{
							VM.Set_min_core(VM.Get_index_of_proc(4), 0);
						}
						else
						{
							VM.Set_min_core(VM.Get_index_of_proc(4), VM.Get_min_core(VM.Get_index_of_proc(4)) + 1);
						}
					}
				}
				if (menu_post == 2)
				{
					if (VM.Get_index_of_proc(4) != -1)
					{
						if (VM.Get_max_core(VM.Get_index_of_proc(4)) != VM.Get_processors()[VM.Get_index_of_proc(4)].Get_cores())
						{
							VM.Set_max_core(VM.Get_index_of_proc(4), VM.Get_max_core(VM.Get_index_of_proc(4)) + 1);
						}
					}
				}
				break;
			}
			default:
			{
				menu_past = menu_future;
				if (menu_future % 5 != 1)
					menu_future -= 1;
				else
					menu_future += 4;
				break;
			}
			}

			break;
		}
		case 75: // LEFT
		{
			switch (menu_future)
			{
			case 16:
			{
				Show_RTI -= 1;
				break;
			}
			case 17:
			{
				Show_Proc -= 1;
				break;
			}
			case 18:
			{
				if (FPT > 1)
				{
					FPT--;
				}

				break;
			}
			case 19:
			{
				menu_past = menu_future;
				minus_1_style();
				break;
			}
			case 56:
			{
				menu_past = menu_future;
				minus_1_power_proc(VM,1);

				break;
			}
			case 57:
			{
				menu_past = menu_future;
				minus_1_power_proc(VM, 2);

				break;
			}
			case 58:
			{
				menu_past = menu_future;
				minus_1_power_proc(VM, 3);

				break;
			}
			case 59:
			{
				menu_past = menu_future;
				minus_1_power_proc(VM, 4);

				break;
			}
			case 61:
			{
				menu_past = menu_future;
				minus_1_elem_in_queue(VM);
				break;
			}
			case 62:
			{
				menu_past = menu_future;
				minus_1_program_in_queue(VM);
				break;
			}
			case 63:
			{

				break;
			}
			case 64:
			{

				break;
			}
			case 66:
			{
				menu_past = menu_future;
				if (menu_post == 0)
				{
					menu_post = 2;
				}
				else
				{
					menu_post--;
				}
				break;
			}
			case 67:
			{
				menu_past = menu_future;
				if (menu_post == 0)
				{
					menu_post = 2;
				}
				else
				{
					menu_post--;
				}
				break;
			}
			case 69:
			{
				menu_past = menu_future;
				if (menu_post == 0)
				{
					menu_post = 2;
				}
				else
				{
					menu_post--;
				}
				break;
			}
			case 71:
			{
				if (time_of_work)
				{
					time_of_work--;
				}
				break;
			}
			case 72:
			{
				if (V)
				{
					V -= 5;
				}
				break;
			}
			case 73:
			{
				big_statistic_now -= 1;
				break;
			}
			case 74:
			{
				big_statistic_after -= 1;
				break;
			}
			case 341:
			{
				menu_past = menu_future;
				if (menu_post == 0)
				{
					menu_post = 2;
				}
				else
				{
					menu_post--;
				}
				break;
			}
			case 342:
			{
				menu_past = menu_future;
				if (menu_post == 0)
				{
					menu_post = 2;
				}
				else
				{
					menu_post--;
				}
				break;
			}
			case 343:
			{
				menu_past = menu_future;
				if (menu_post == 0)
				{
					menu_post = 2;
				}
				else
				{
					menu_post--;
				}
				break;
			}
			case 344:
			{
				menu_past = menu_future;
				if (menu_post == 0)
				{
					menu_post = 2;
				}
				else
				{
					menu_post--;
				}
				break;
			}
			default:
			{
				menu_past = menu_future;
				menu_future = trunc((menu_future - 1) / 5);
				menu_future = trunc((menu_future - 1) / 5) * 5 + 1;
				break;
			}
			}

			break;
		}
		case 77: // RIGHT
		{
			switch (menu_future)
			{
			case 16:
			{
				Show_RTI -= 1;
				break;
			}
			case 17:
			{
				Show_Proc -= 1;
				break;
			}
			case 18:
			{
				FPT++;
				break;
			}
			case 19:
			{
				menu_past = menu_future;
				plus_1_style();
				break;
			}
			case 56:
			{
				menu_past = menu_future;
				plus_1_power_proc(VM, 1);

				break;
			}
			case 57:
			{
				menu_past = menu_future;
				plus_1_power_proc(VM, 2);

				break;
			}
			case 58:
			{
				menu_past = menu_future;
				plus_1_power_proc(VM, 3);

				break;
			}
			case 59:
			{
				menu_past = menu_future;
				plus_1_power_proc(VM, 4);

				break;
			}
			case 61:
			{
				menu_past = menu_future;
				plus_1_elem_in_queue(VM);
				break;
			}
			case 62:
			{
				menu_past = menu_future;
				plus_1_program_in_queue(VM);
				break;
			}
			case 63:
			{

				break;
			}
			case 64:
			{

				break;
			}
			case 66:
			{
				menu_past = menu_future;
				if (menu_post == 2)
				{
					menu_post = 0;
				}
				else
				{
					menu_post++;
				}
				break;
			}
			case 67:
			{
				menu_past = menu_future;
				if (menu_post == 2)
				{
					menu_post = 0;
				}
				else
				{
					menu_post++;
				}
				break;
			}
			case 69:
			{
				menu_past = menu_future;
				if (menu_post == 2)
				{
					menu_post = 0;
				}
				else
				{
					menu_post++;
				}
				break;
			}
			case 71:
			{
				time_of_work++;
				break;
			}
			case 72:
			{
				V += 5;
				break;
			}
			case 73:
			{
				big_statistic_now -= 1;
				break;
			}
			case 74:
			{
				big_statistic_after -= 1;
				break;
			}
			case 341:
			{
				menu_past = menu_future;
				if (menu_post == 2)
				{
					menu_post = 0;
				}
				else
				{
					menu_post++;
				}
				break;
				break;
			}
			case 342:
			{
				menu_past = menu_future;
				if (menu_post == 2)
				{
					menu_post = 0;
				}
				else
				{
					menu_post++;
				}
				break;
				break;
			}
			case 343:
			{
				menu_past = menu_future;
				if (menu_post == 2)
				{
					menu_post = 0;
				}
				else
				{
					menu_post++;
				}
				break;
				break;
			}
			case 344:
			{
				menu_past = menu_future;
				if (menu_post == 2)
				{
					menu_post = 0;
				}
				else
				{
					menu_post++;
				}
				break;
				break;
			}
			default:
			{
				if (menu_future % 5 != 0)
				{
					menu_past = menu_future;
					menu_future *= 5;
					menu_future++;
				}
				else
				{
					if (menu_future == 5)
					{
						menu_past = menu_future;
						menu_future *= 5;
						menu_future++;
					}
					else
					{
						menu_past = menu_future;
						menu_future = trunc((menu_future - 1) / 5);
						menu_future = trunc((menu_future - 1) / 5) * 5 + 1;
					}
				}
			}
			}
			break;
		}
		case 80: // DOWN
		{
			switch (menu_future)
			{
			case 66:
			{
				if (menu_post == 0)
				{
					menu_past = menu_future;
					if (menu_future % 5 != 0)
						menu_future += 1;
					else
						menu_future -= 4;
					break;
				}
				if (menu_post == 1)
				{
					if (1 != VM.Get_min_tact())
					{
						VM.Set_min_tact(VM.Get_min_tact() - 1);
					}
					else
					{
						VM.Set_min_tact(VM.Get_max_tact());
					}
				}
				if (menu_post == 2)
				{
					if (VM.Get_max_tact() > VM.Get_min_tact())
					VM.Set_max_tact(VM.Get_max_tact() - 1);
				}

				break;
			}
			case 67:
			{
				if (menu_post == 0)
				{
					menu_past = menu_future;
					if (menu_future % 5 != 0)
						menu_future += 1;
					else
						menu_future -= 4;
					break;
				}
				if (menu_post == 1)
				{
					if (VM.Get_min_proc() != 1)
					{
						VM.Set_min_proc(VM.Get_min_proc() - 1);
					}
					else
					{
						VM.Set_min_proc(VM.Get_max_proc());
					}
				}
				if (menu_post == 2)
				{
					if (VM.Get_max_proc() != VM.Get_min_proc())
					{
						VM.Set_max_proc(VM.Get_max_proc() - 1);
					}
				}

				break;
			}
			case 69:
			{
				if (menu_post == 0)
				{
					menu_past = menu_future;
					if (menu_future % 5 != 0)
						menu_future += 1;
					else
						menu_future -= 4;
				}
				if (menu_post == 1)
				{
					if (VM.Get_program_per_tact() > 1.01)
					{
						VM.Set_program_per_tact(VM.Get_program_per_tact() - 1.0);
					}
				}
				if (menu_post == 2)
				{
					if (VM.Get_program_per_tact() > 0.101)
					{
						VM.Set_program_per_tact(VM.Get_program_per_tact() - 0.1);
					}
				}

				break;
			}
			case 341:
			{
				if (menu_post == 0)
				{
					menu_past = menu_future;
					if (menu_future % 5 != 0)
						menu_future += 1;
					else
						menu_future -= 4;
					break;
				}
				if (menu_post == 1)
				{
					if (VM.Get_index_of_proc(1) != -1)
					{
						if (VM.Get_min_core(VM.Get_index_of_proc(1)) == 0)
						{
							VM.Set_min_core(VM.Get_index_of_proc(1), VM.Get_max_core(VM.Get_index_of_proc(1)));
						}
						else
						{
							VM.Set_min_core(VM.Get_index_of_proc(1), VM.Get_min_core(VM.Get_index_of_proc(1)) - 1);
						}
					}
				}
				if (menu_post == 2)
				{
					if (VM.Get_index_of_proc(1) != -1)
					{
						if (VM.Get_max_core(VM.Get_index_of_proc(1)) != 1)
						{
							if (VM.Get_max_core(VM.Get_index_of_proc(1)) != VM.Get_min_core(VM.Get_index_of_proc(1)))
							{
								VM.Set_max_core(VM.Get_index_of_proc(1), VM.Get_max_core(VM.Get_index_of_proc(1)) - 1);
							}
						}
					}
				}
				break;
			}
			case 342:
			{
				if (menu_post == 0)
				{
					menu_past = menu_future;
					if (menu_future % 5 != 0)
						menu_future += 1;
					else
						menu_future -= 4;
					break;
				}
				if (menu_post == 1)
				{
					if (VM.Get_index_of_proc(2) != -1)
					{
						if (VM.Get_min_core(VM.Get_index_of_proc(2)) == 0)
						{
							VM.Set_min_core(VM.Get_index_of_proc(2), VM.Get_max_core(VM.Get_index_of_proc(2)));
						}
						else
						{
							VM.Set_min_core(VM.Get_index_of_proc(2), VM.Get_min_core(VM.Get_index_of_proc(2)) - 1);
						}
					}
				}
				if (menu_post == 2)
				{
					if (VM.Get_index_of_proc(2) != -1)
					{
						if (VM.Get_max_core(VM.Get_index_of_proc(2)) != 1)
						{
							if (VM.Get_max_core(VM.Get_index_of_proc(2)) != VM.Get_min_core(VM.Get_index_of_proc(2)))
							{
								VM.Set_max_core(VM.Get_index_of_proc(2), VM.Get_max_core(VM.Get_index_of_proc(2)) - 1);
							}
						}
					}
				}
				break;
			}
			case 343:
			{
				if (menu_post == 0)
				{
					menu_past = menu_future;
					if (menu_future % 5 != 0)
						menu_future += 1;
					else
						menu_future -= 4;
					break;
				}
				if (menu_post == 1)
				{
					if (VM.Get_index_of_proc(3) != -1)
					{
						if (VM.Get_min_core(VM.Get_index_of_proc(3)) == 0)
						{
							VM.Set_min_core(VM.Get_index_of_proc(3), VM.Get_max_core(VM.Get_index_of_proc(3)));
						}
						else
						{
							VM.Set_min_core(VM.Get_index_of_proc(3), VM.Get_min_core(VM.Get_index_of_proc(3)) - 1);
						}
					}
				}
				if (menu_post == 2)
				{
					if (VM.Get_index_of_proc(3) != -1)
					{
						if (VM.Get_max_core(VM.Get_index_of_proc(3)) != 1)
						{
							if (VM.Get_max_core(VM.Get_index_of_proc(3)) != VM.Get_min_core(VM.Get_index_of_proc(3)))
							{
								VM.Set_max_core(VM.Get_index_of_proc(3), VM.Get_max_core(VM.Get_index_of_proc(3)) - 1);
							}
						}
					}
				}
				break;
			}
			case 344:
			{
				if (menu_post == 0)
				{
					menu_past = menu_future;
					if (menu_future % 5 != 0)
						menu_future += 1;
					else
						menu_future -= 4;
					break;
				}
				if (menu_post == 1)
				{
					if (VM.Get_index_of_proc(4) != -1)
					{
						if (VM.Get_min_core(VM.Get_index_of_proc(4)) == 0)
						{
							VM.Set_min_core(VM.Get_index_of_proc(4), VM.Get_max_core(VM.Get_index_of_proc(4)));
						}
						else
						{
							VM.Set_min_core(VM.Get_index_of_proc(4), VM.Get_min_core(VM.Get_index_of_proc(4)) - 1);
						}
					}
				}
				if (menu_post == 2)
				{
					if (VM.Get_index_of_proc(4) != -1)
					{
						if (VM.Get_max_core(VM.Get_index_of_proc(4)) != 1)
						{
							if (VM.Get_max_core(VM.Get_index_of_proc(4)) != VM.Get_min_core(VM.Get_index_of_proc(4)))
							{
								VM.Set_max_core(VM.Get_index_of_proc(4), VM.Get_max_core(VM.Get_index_of_proc(4)) - 1);
							}
						}
					}
				}
				break;
			}
			default:
			{
				menu_past = menu_future;
				if (menu_future % 5 != 0)
					menu_future += 1;
				else
					menu_future -= 4;
				break;
			}
			}
		}
		default:
			break;
		}
		if (key != -32)
		{
			DROW(menu_future, menu_past, menu_post, VM);
		}
	}
	

	_getch();
	return 0;
}

void gotoxy(int xpos, int ypos)
{
	COORD scrn;

	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = xpos; scrn.Y = ypos;

	SetConsoleCursorPosition(hOuput, scrn);
}

void display_cursor(bool tf)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = tf;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}

void set_colour(int colour_of_text, int colour_of_background)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((colour_of_background << 4) | colour_of_text));

}

void Output_information()
{

}

void DROW(int menu_future, int menu_past, int menu_post, const Virtual_machine &VM)
{
	switch (menu_future)
	{
	case 26:
	{
		exit(0);
		break;
	}
	case 66:
	{
		if (13 == menu_past)
		{
			START_MENU(trunc((menu_future - 1) / 5) * 5 + 1, VM);
		}
		if ((menu_past - 1) / 5 == 68)
		{
			START_MENU(trunc((menu_future - 1) / 5) * 5 + 1, VM);
		}
		if (menu_post == 0 && menu_past != 13)
		{
			int mp = menu_past % 5;
			int mf = menu_future % 5;
			if (mp == 0) mp = 5;
			if (mf == 0) mf = 5;
			gotoxy(0, mp - 1);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			cout << MENU_ITEM(menu_past, VM);
			gotoxy(0, mf - 1);
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			cout << MENU_ITEM(menu_future, VM);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}
		if (menu_post == 1)
		{
			string buf = MENU_ITEM(66, VM);
			gotoxy(0, 0);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			int i = 0;
			for (; i < 42; i++)
			{
				cout << buf[i];
			}
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			while (buf[i] != ' ')
			{
				cout << buf[i];
				i++;
			}
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			while (buf[i] != '\0')
			{
				cout << buf[i];
				i++;
			}
			set_colour(0, mass_of_style[style][1]);
			cout << "          ";
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}
		if (menu_post == 2)
		{
			string buf = MENU_ITEM(66, VM);
			gotoxy(0, 0);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			int i = 0;
			for (; i < 42; i++)
			{
				cout << buf[i];
			}
			while (buf[i] != ' ')
			{
				cout << buf[i];
				i++;
			}
			cout << buf[i++];
			while (buf[i] != ' ')
			{
				cout << buf[i];
				i++;
			}
			cout << buf[i++];
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			while (buf[i] != '\0')
			{
				cout << buf[i];
				i++;
			}
			set_colour(0, mass_of_style[style][1]);
			cout << "          ";
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}

		break;
	}
	case 67:
	{
		if (menu_post == 0)
		{
			int mp = menu_past % 5;
			int mf = menu_future % 5;
			if (mp == 0) mp = 5;
			if (mf == 0) mf = 5;
			gotoxy(0, mp - 1);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			cout << MENU_ITEM(menu_past, VM);
			gotoxy(0, mf - 1);
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			cout << MENU_ITEM(menu_future, VM);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}
		if (menu_post == 1)
		{
			string buf = MENU_ITEM(67, VM);
			gotoxy(0, 1);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			int i = 0;
			for (; i < 50; i++)
			{
				cout << buf[i];
			}
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			while (buf[i] != ' ')
			{
				cout << buf[i];
				i++;
			}
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			while (buf[i] != '\0')
			{
				cout << buf[i];
				i++;
			}
			set_colour(0, mass_of_style[style][1]);
			cout << "          ";
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}
		if (menu_post == 2)
		{
			string buf = MENU_ITEM(67, VM);
			gotoxy(0, 1);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			int i = 0;
			for (; i < 50; i++)
			{
				cout << buf[i];
			}
			while (buf[i] != ' ')
			{
				cout << buf[i];
				i++;
			}
			cout << buf[i++];
			while (buf[i] != ' ')
			{
				cout << buf[i];
				i++;
			}
			cout << buf[i++];
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			while (buf[i] != '\0')
			{
				cout << buf[i];
				i++;
			}
			set_colour(0, mass_of_style[style][1]);
			cout << "          ";
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}

		break;
	}
	case 69:
	{
		if (menu_post == 0)
		{
			int mp = menu_past % 5;
			int mf = menu_future % 5;
			if (mp == 0) mp = 5;
			if (mf == 0) mf = 5;
			gotoxy(0, mp - 1);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			cout << MENU_ITEM(menu_past, VM);
			gotoxy(0, mf - 1);
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			cout << MENU_ITEM(menu_future, VM);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}
		if (menu_post == 1)
		{
			string buf = MENU_ITEM(69, VM);
			gotoxy(0, 3);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			int i = 0;
			for (; i < 29; i++)
			{
				cout << buf[i];
			}
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			while (buf[i] != ',')
			{
				cout << buf[i];
				i++;
			}
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			cout << buf[i++];
			cout << buf[i++];
			set_colour(0, mass_of_style[style][1]);
			cout << "          ";
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}
		if (menu_post == 2)
		{
			string buf = MENU_ITEM(69, VM);
			gotoxy(0, 3);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			int i = 0;
			for (; i < 29; i++)
			{
				cout << buf[i];
			}
			while (buf[i] != ',')
			{
				cout << buf[i];
				i++;
			}
			cout << buf[i++];
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			cout << buf[i];
			set_colour(0, mass_of_style[style][1]);
			cout << "          ";
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}

		break;
	}
	case 341:
	{
		if (menu_past == 68)
		{
			START_MENU(menu_future, VM);
		}
		if (menu_post == 0 && menu_past != 68)
		{
			int mp = menu_past % 5;
			int mf = menu_future % 5;
			if (mp == 0) mp = 5;
			if (mf == 0) mf = 5;
			gotoxy(0, mp - 1);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			cout << MENU_ITEM(menu_past, VM);
			gotoxy(0, mf - 1);
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			cout << MENU_ITEM(menu_future, VM);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}
		if (menu_post == 1)
		{
			string buf = MENU_ITEM(341, VM);
			gotoxy(0, 0);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			int i = 0;
			for (; i < 59; i++)
			{
				cout << buf[i];
			}
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			while (buf[i] != ' ')
			{
				cout << buf[i];
				i++;
			}
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			while (buf[i] != '\0')
			{
				cout << buf[i];
				i++;
			}
			set_colour(0, mass_of_style[style][1]);
			cout << "          ";
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}
		if (menu_post == 2)
		{
			string buf = MENU_ITEM(341, VM);
			gotoxy(0, 0);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			int i = 0;
			for (; i < 59; i++)
			{
				cout << buf[i];
			}
			while (buf[i] != ' ')
			{
				cout << buf[i];
				i++;
			}
			cout << buf[i++];
			while (buf[i] != ' ')
			{
				cout << buf[i];
				i++;
			}
			cout << buf[i++];
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			while (buf[i] != '\0')
			{
				cout << buf[i];
				i++;
			}
			set_colour(0, mass_of_style[style][1]);
			cout << "          ";
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}

		break;
	}
	case 342:
	{
		if (menu_post == 0)
		{
			int mp = menu_past % 5;
			int mf = menu_future % 5;
			if (mp == 0) mp = 5;
			if (mf == 0) mf = 5;
			gotoxy(0, mp - 1);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			cout << MENU_ITEM(menu_past, VM);
			gotoxy(0, mf - 1);
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			cout << MENU_ITEM(menu_future, VM);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}
		if (menu_post == 1)
		{
			string buf = MENU_ITEM(342, VM);
			gotoxy(0, 1);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			int i = 0;
			for (; i < 59; i++)
			{
				cout << buf[i];
			}
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			while (buf[i] != ' ')
			{
				cout << buf[i];
				i++;
			}
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			while (buf[i] != '\0')
			{
				cout << buf[i];
				i++;
			}
			set_colour(0, mass_of_style[style][1]);
			cout << "          ";
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}
		if (menu_post == 2)
		{
			string buf = MENU_ITEM(342, VM);
			gotoxy(0, 1);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			int i = 0;
			for (; i < 59; i++)
			{
				cout << buf[i];
			}
			while (buf[i] != ' ')
			{
				cout << buf[i];
				i++;
			}
			cout << buf[i++];
			while (buf[i] != ' ')
			{
				cout << buf[i];
				i++;
			}
			cout << buf[i++];
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			while (buf[i] != '\0')
			{
				cout << buf[i];
				i++;
			}
			set_colour(0, mass_of_style[style][1]);
			cout << "          ";
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}

		break;
	}
	case 343:
	{
		if (menu_post == 0)
		{
			int mp = menu_past % 5;
			int mf = menu_future % 5;
			if (mp == 0) mp = 5;
			if (mf == 0) mf = 5;
			gotoxy(0, mp - 1);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			cout << MENU_ITEM(menu_past, VM);
			gotoxy(0, mf - 1);
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			cout << MENU_ITEM(menu_future, VM);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}
		if (menu_post == 1)
		{
			string buf = MENU_ITEM(343, VM);
			gotoxy(0, 2);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			int i = 0;
			for (; i < 59; i++)
			{
				cout << buf[i];
			}
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			while (buf[i] != ' ')
			{
				cout << buf[i];
				i++;
			}
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			while (buf[i] != '\0')
			{
				cout << buf[i];
				i++;
			}
			set_colour(0, mass_of_style[style][1]);
			cout << "          ";
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}
		if (menu_post == 2)
		{
			string buf = MENU_ITEM(343, VM);
			gotoxy(0, 2);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			int i = 0;
			for (; i < 59; i++)
			{
				cout << buf[i];
			}
			while (buf[i] != ' ')
			{
				cout << buf[i];
				i++;
			}
			cout << buf[i++];
			while (buf[i] != ' ')
			{
				cout << buf[i];
				i++;
			}
			cout << buf[i++];
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			while (buf[i] != '\0')
			{
				cout << buf[i];
				i++;
			}
			set_colour(0, mass_of_style[style][1]);
			cout << "          ";
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}

		break;
	}
	case 344:
	{
		if (menu_post == 0)
		{
			int mp = menu_past % 5;
			int mf = menu_future % 5;
			if (mp == 0) mp = 5;
			if (mf == 0) mf = 5;
			gotoxy(0, mp - 1);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			cout << MENU_ITEM(menu_past, VM);
			gotoxy(0, mf - 1);
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			cout << MENU_ITEM(menu_future, VM);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}
		if (menu_post == 1)
		{
			string buf = MENU_ITEM(344, VM);
			gotoxy(0, 3);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			int i = 0;
			for (; i < 59; i++)
			{
				cout << buf[i];
			}
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			while (buf[i] != ' ')
			{
				cout << buf[i];
				i++;
			}
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			while (buf[i] != '\0')
			{
				cout << buf[i];
				i++;
			}
			set_colour(0, mass_of_style[style][1]);
			cout << "          ";
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}
		if (menu_post == 2)
		{
			string buf = MENU_ITEM(344, VM);
			gotoxy(0, 3);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			int i = 0;
			for (; i < 59; i++)
			{
				cout << buf[i];
			}
			while (buf[i] != ' ')
			{
				cout << buf[i];
				i++;
			}
			cout << buf[i++];
			while (buf[i] != ' ')
			{
				cout << buf[i];
				i++;
			}
			cout << buf[i++];
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			while (buf[i] != '\0')
			{
				cout << buf[i];
				i++;
			}
			set_colour(0, mass_of_style[style][1]);
			cout << "          ";
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}

		break;
	}
	default:
	{
		if (menu_future == menu_past)
		{

			int mp = menu_past % 5;
			int mf = menu_future % 5;
			gotoxy(0, mp - 1);
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			cout << MENU_ITEM(menu_future, VM);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			cout << "               ";
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			if (menu_future == 19) START_MENU(16, VM, 1);
		}
		else
		{
			if (trunc((menu_past - 1) / 5) == trunc((menu_future - 1) / 5))
			{
				int mp = menu_past % 5;
				int mf = menu_future % 5;
				if (mp == 0) mp = 5;
				if (mf == 0) mf = 5;
				gotoxy(0, mp - 1);
				set_colour(mass_of_style[style][0], mass_of_style[style][1]);
				cout << MENU_ITEM(menu_past, VM);
				gotoxy(0, mf - 1);
				set_colour(mass_of_style[style][1], mass_of_style[style][0]);
				cout << MENU_ITEM(menu_future, VM);
				set_colour(mass_of_style[style][0], mass_of_style[style][1]);
				cout << "  ";
			}
			else
			{
				START_MENU(trunc((menu_future - 1) / 5) * 5 + 1, VM);
			}
		}
	}
	}
}

string MENU_ITEM(int menu, const Virtual_machine &VM)
{
	Virtual_machine ViMa(VM);
	if (menu == 1) return "Запуск";
	if (menu == 2) return "Настройки модели";
	if (menu == 3) return "Настройки графики";
	if (menu == 4) return "О программе";
	if (menu == 5) return "Выход";
	if (menu == 11) return "Настройки процессора";
	if (menu == 12) return "Настройки очереди";
	if (menu == 13) return "Настройки генератора программ";
	if (menu == 14) return "Настройки статистики";
	if (menu == 15) return "Назад";
	if (menu == 16)
	{
		if (Show_RTI)
		{
			return "Отображать REALTIME информацию: ДА";
		}
		else
		{
			return "Отображать REALTIME информацию: НЕТ";
		}
	}
	if (menu == 17)
	{
		if (Show_Proc)
		{
			return "Показывать процессор(-ы): ДА";
		}
		else
		{
			return "Показывать процессор(-ы): НЕТ";
		}
	}
	if (menu == 18)
	{
		if (FPT % 10 == 1 && FPT % 100 != 11)
		{
			if (FPT == 91 && LOGIN == 1)
			{
				return "Частота отрисовки: L091N♥ такт за один кадр";
			}
			return "Частота отрисовки: " + to_string(FPT) + " такт за один кадр";
		}
		else
		{
			if (FPT % 10 >= 2 && FPT % 10 <= 4 && FPT % 100 != 12 && FPT % 100 != 13 && FPT % 100 != 14)
			{
				return "Частота отрисовки: " + to_string(FPT) + " такта за один кадр";
			}
			else
			{
				return "Частота отрисовки: " + to_string(FPT) + " тактов за один кадр";
			}
		}
		
	}
	if (menu == 19)
	{
		if (style == 4)
		{
			return "Стиль:=" + Get_name_of_style(style);
		}
		return "Стиль: " + Get_name_of_style(style);
	}
	if (menu == 20) return "Назад";
	if (menu == 56)
	{
		int numcore;
		vector<Processor> vecProc = ViMa.Get_processors();
		auto IT = vecProc.begin();
		auto ITend = vecProc.end();
		for (; IT != ITend; IT++)
		{
			if (IT->Get_number() == 1)
			{
				numcore = IT->Get_cores();
				break;
			}
		}
		if (IT == ITend) numcore = 0;
		return "Количество ядер на 1 процессоре: " + to_string(numcore);
	}
	if (menu == 57) 
	{
		int numcore;
		vector<Processor> vecProc = ViMa.Get_processors();
		auto IT = vecProc.begin();
		auto ITend = vecProc.end();
		for (; IT != ITend; IT++)
			if (IT->Get_number() == 2)
			{
				numcore = IT->Get_cores();
				break;
			}
		if (IT == ITend) numcore = 0;
		return "Количество ядер на 2 процессоре: " + to_string(numcore);
	}
	if (menu == 58) 
	{
		int numcore;
		vector<Processor> vecProc = ViMa.Get_processors();
		auto IT = vecProc.begin();
		auto ITend = vecProc.end();
		for (; IT != ITend; IT++)
			if (IT->Get_number() == 3)
			{
				numcore = IT->Get_cores();
				break;
			}
		if (IT == ITend) numcore = 0;
		return "Количество ядер на 3 процессоре: " + to_string(numcore);
	}
	if (menu == 59) 
	{
		int numcore;
		vector<Processor> vecProc = ViMa.Get_processors();
		auto IT = vecProc.begin();
		auto ITend = vecProc.end();
		for (; IT != ITend; IT++)
			if (IT->Get_number() == 4)
			{
				numcore = IT->Get_cores();
				break;
			}
		if (IT == ITend) numcore = 0;
		return "Количество ядер на 4 процессоре: " + to_string(numcore);
	}
	if (menu == 60) return "Назад";
	if (menu == 61)
	{
		TQueue<Program> Q = ViMa.Get_queue();
		return "Длина очереди: " + to_string(Q.Get_full_size());
	}
	if (menu == 62) return "Количество программ в очереди перед запуском: " + to_string(ViMa.Get_programm_in_queue_when_start());
	if (menu == 63) return "???";
	if (menu == 64) return "???";
	if (menu == 65) return "Назад";
	if (menu == 66)
	{
		Virtual_machine ViMa(VM);
		int maxt = ViMa.Get_max_tact();
		int mint = ViMa.Get_min_tact();
		return "Количество тактов выполнения программ: от " + to_string(mint) + " до " + to_string(maxt);
	}
	if (menu == 67)
	{
		Virtual_machine ViMa(VM);
		int maxp = ViMa.Get_max_proc();
		int minp = ViMa.Get_min_proc();
		return "Количество требуемых процессоров для программ: от " + to_string(minp) + " до " + to_string(maxp);
	}
	if (menu == 68) return "Количество требуемых ядер на N процессоре";
	if (menu == 69)
	{
		Virtual_machine ViMa(VM);
		double ppt = ViMa.Get_program_per_tact();
		string Res = "Скорость появления программ: " + to_string(ppt);
		return Res.erase(Res.find(',') + 2, Res.find('\0'));
	}
	if (menu == 70) return "Назад";
	if (menu == 71)
	{
		if (time_of_work)
		{
			return "Время работы в тактах: " + to_string(time_of_work);
		}
		else
		{
			if (style == 1)
			{
				return "Время работы в тактах: infinity war";
			}
			return "Время работы в тактах: infinity";
		}
	}
	if (menu == 72)
	{
		return "Задержка между тактами " + to_string(V) + " ms ";
	}
	if (menu == 73)
	{
		if (big_statistic_now)
		{
			return "Расширенная статистка во время работы: ДА";
		}
		else
		{
			return "Расширенная статистка во время работы: НЕТ";
		}
	}
	if (menu == 74)
	{
		if (big_statistic_after)
		{
			return "Расширенная статистка после работы: ДА";
		}
		else
		{
			return "Расширенная статистка после работы: НЕТ";
		}
	}
	if (menu == 75) return "Назад";
	if (menu == 341)
	{
		Virtual_machine ViMa(VM);
		int maxp = 0;
		int minp = 0;
		if (ViMa.Get_index_of_proc(1) != -1)
		{
			maxp = ViMa.Get_max_core(ViMa.Get_index_of_proc(1));
			minp = ViMa.Get_min_core(ViMa.Get_index_of_proc(1));
		}
		return "Количество требуемых ядер для программ на 1 процессоре: от " + to_string(minp) + " до " + to_string(maxp);
	}
	if (menu == 342)
	{
		Virtual_machine ViMa(VM);
		int maxp = 0;
		int minp = 0;
		if (ViMa.Get_index_of_proc(2) != -1)
		{
			maxp = ViMa.Get_max_core(ViMa.Get_index_of_proc(2));
			minp = ViMa.Get_min_core(ViMa.Get_index_of_proc(2));
		}
		return "Количество требуемых ядер для программ на 2 процессоре: от " + to_string(minp) + " до " + to_string(maxp);
	}
	if (menu == 343)
	{
		Virtual_machine ViMa(VM);
		int maxp = 0;
		int minp = 0;
		if (ViMa.Get_index_of_proc(3) != -1)
		{
			maxp = ViMa.Get_max_core(ViMa.Get_index_of_proc(3));
			minp = ViMa.Get_min_core(ViMa.Get_index_of_proc(3));
		}
		return "Количество требуемых ядер для программ на 3 процессоре: от " + to_string(minp) + " до " + to_string(maxp);
	}
	if (menu == 344)
	{
		Virtual_machine ViMa(VM);
		int maxp = 0;
		int minp = 0;
		if (ViMa.Get_index_of_proc(4) != -1)
		{
			maxp = ViMa.Get_max_core(ViMa.Get_index_of_proc(4));
			minp = ViMa.Get_min_core(ViMa.Get_index_of_proc(4));
		}
		return "Количество требуемых ядер для программ на 4 процессоре: от " + to_string(minp) + " до " + to_string(maxp);
	}
	if (menu == 345) return "Назад";

	return "404";
}

void START_MENU(int first_item, const Virtual_machine &VM, int ind)
{
	set_colour(mass_of_style[style][0], mass_of_style[style][1]);
	system("cls");
	int y = 0;
	for (int i = first_item; i < first_item + 5; i++)
	{
		if (i == first_item && ind == 0)
		{
			gotoxy(0, y++);
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			cout << MENU_ITEM(i, VM);
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
		}
		else
		{
			if (ind == 1)
			{
				if (i == 19)
				{
					gotoxy(0, y++);
					set_colour(mass_of_style[style][1], mass_of_style[style][0]);
					cout << MENU_ITEM(i, VM);
					set_colour(mass_of_style[style][0], mass_of_style[style][1]);
				}
				else
				{
					set_colour(mass_of_style[style][0], mass_of_style[style][1]);
					gotoxy(0, y++);
					cout << MENU_ITEM(i, VM);
				}
			}
			else
			{
				gotoxy(0, y++);
				cout << MENU_ITEM(i, VM);
			}
		}
	}
}

void plus_1_power_proc(Virtual_machine &VM, int num_proc)
{
	auto IT = VM.Get_begin_ptr_Proc();
	for (; IT != VM.Get_end_ptr_Proc(); IT++)
	{
		if (IT->Get_number() == num_proc)
			break;
	}
	if (IT != VM.Get_end_ptr_Proc())
	{
		if (IT->Get_cores() == 64)
		{
			if (VM.Get_processors().size() == 1)
			{
				VM.Set_configuration_p(num_proc, 1);
			}
			else
			{
				VM.Set_configuration_p(num_proc, 0);
			}
		}
		else
		{
			VM.Set_configuration_p(num_proc, 4 * IT->Get_cores());
		}
	}
	else
	{
		VM.Set_configuration_p(num_proc, 1);
	}
}
void minus_1_power_proc(Virtual_machine &VM, int num_proc)
{
	int PROC_NUM[5] = { 0, 1, 4, 16, 64 };
	auto IT = VM.Get_begin_ptr_Proc();
	for (; IT != VM.Get_end_ptr_Proc(); IT++)
	{
		if (IT->Get_number() == num_proc)
			break;
	}
	if (IT != VM.Get_end_ptr_Proc())
	{
		if (IT->Get_cores() == 0)
		{
			VM.Set_configuration_p(num_proc, 64);
		}
		else
		{
			if (IT->Get_cores() != 1)
			{
				VM.Set_configuration_p(num_proc, IT->Get_cores() / 4);
			}
			else
			{
				if (VM.Get_processors().size() == 1)
				{
					VM.Set_configuration_p(num_proc, 64);
				}
				else
				{
					VM.Set_configuration_p(num_proc, IT->Get_cores() / 4);
				}
			}
		}
	}
	else
	{
		VM.Set_configuration_p(num_proc, 64);
	}
}
void plus_1_elem_in_queue(Virtual_machine &VM)
{
	VM.Set_queue(VM.Get_queue().Get_full_size() + 1);
}
void minus_1_elem_in_queue(Virtual_machine &VM)
{
	if (VM.Get_programm_in_queue_when_start() != VM.Get_queue().Get_full_size())
	{
		if (VM.Get_queue().Get_full_size() > 1)
		{
			VM.Set_queue(VM.Get_queue().Get_full_size() - 1);
		}
	}
}
void plus_1_program_in_queue(Virtual_machine &VM)
{
	if (VM.Get_programm_in_queue_when_start() == VM.Get_queue().Get_full_size())
	{
		VM.Set_prog_in_queue_when_start(0);
	}
	else
	{
		VM.Set_prog_in_queue_when_start(VM.Get_programm_in_queue_when_start() + 1);
	}
}
void minus_1_program_in_queue(Virtual_machine &VM)
{
	if (VM.Get_programm_in_queue_when_start() == 0)
	{
		VM.Set_prog_in_queue_when_start(VM.Get_queue().Get_full_size());
	}
	else
	{
		VM.Set_prog_in_queue_when_start(VM.Get_programm_in_queue_when_start() - 1);
	}
}
void plus_1_style()
{
	if (style != 5)
	{
		style++;
	}
	else
	{
		style = 0;
	}

}
void minus_1_style()
{
	if (style != 0)
	{
		style--;
	}
	else
	{
		style = 5;
	}
}
string Get_name_of_style(int num)
{
	if (num == 0) return "ЧБ";
	if (num == 1) return "БЧ";
	if (num == 2) return "Украина";
	if (num == 3) return "Япония";
	if (num == 4) return "Pascal";
	if (num == 5) return "Вырви глаз";

}
void Rand_colour()
{
	col_of_text = rand() % 16;
	while (col_of_bg == col_of_text)
	{
		col_of_bg = rand() % 16;
	}
	mass_of_style[5][0] = col_of_text;
	mass_of_style[5][1] = col_of_bg;
}