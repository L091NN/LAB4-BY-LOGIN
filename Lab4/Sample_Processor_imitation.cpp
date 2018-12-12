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
unsigned int V = 100;
bool big_statistic_now = 0;
bool big_statistic_after = 0;
unsigned int LOGIN = 0;
int queue_last = 0;
Virtual_machine past_VM;

void gotoxy(int xpos, int ypos);
void display_cursor(bool tf);
void set_colour(int colour_of_text, int colour_of_background);
void Output_information(const Virtual_machine &VM);
int L091NN();
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
void DROW_BG_WORK(int x_move = 0, int y_move = 0);
void DROW_QUEUE_STATUS(int size, int size_full, int x_move = 0, int y_move = 0);
void DROW_INFORMATION_WORK(const Virtual_machine &VM);
void DROW_BEGIN_PROCESSORS(const Virtual_machine &VM, int xi = 0, int yi = 0);
void DROW_PROCESSORS(const Virtual_machine &VM, bool repeat = 1, int xi = 0, int yi = 0);


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
	Virtual_machine VM;
	past_VM = VM;
	int proc_num = VM.Get_processors().size();
	while(1)
	{
		char key = 0;
		bool start_indicator = 0;
		START_MENU(1, VM);
		Output_information(VM);

		while (!start_indicator)
		{
			if (style == 5 && (menu_future - 1) / 5 != (menu_past - 1) / 5) Rand_colour();
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
						start_indicator = 1;
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
						if (!Show_Proc)
						{
							big_statistic_now -= 1;
						}
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
						if (Show_RTI == 0)
						{
							big_statistic_now = 0;
						}
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
						if (!Show_Proc)
						{
							if (!Show_RTI)
							{
								big_statistic_now -= 1;
							}
						}
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
					case 1:
					{
						start_indicator = 1;
						break;
					}
					case 16:
					{
						Show_RTI -= 1;
						if (Show_RTI == 0)
						{
							big_statistic_now = 0;
						}
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
						if (!Show_Proc)
						{
							if (!Show_RTI)
							{
								big_statistic_now -= 1;
							}
						}
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
			if (start_indicator == 0 && key != -32)
			{
				DROW(menu_future, menu_past, menu_post, VM);
			}
		}

		system("cls");
		past_VM = VM;

		if (LOGIN == 2)
		{
			L091NN();
			LOGIN = 0;
		}
		else
		{
			if (Show_Proc)
			{
				DROW_BG_WORK();
				DROW_BEGIN_PROCESSORS(VM);
				DROW_PROCESSORS(VM, 0);
			}
			if (Show_RTI)
			{
				DROW_INFORMATION_WORK(VM);
			}
			VM.START();
			if (Show_Proc || Show_RTI)
			{
				_getch();
				while (1)
				{
					VM.plus_tact();
					if (Show_Proc)
					{
						DROW_PROCESSORS(VM);
						DROW_QUEUE_STATUS(VM.Get_queue().size(), VM.Get_queue().Get_full_size());
					}
					if (Show_RTI)
					{
						DROW_INFORMATION_WORK(VM);
						if (big_statistic_now)
						{

						}
						else
						{

						}
					}
				}
			}
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

void Output_information(const Virtual_machine &VM)
{
	Virtual_machine V(VM);
	int yout = 0;
	int xout = 60;
	int all_cores = 0;
	for (int i = 0; i < 4; i++)
	{
		if (V.Get_index_of_proc(i + 1) != -1)
		{
			all_cores += V.Get_processors()[V.Get_index_of_proc(i + 1)].Get_cores();
		}
	}
	gotoxy(xout, yout++);
	cout << "Всего процессоров: " + to_string(V.Get_processors().size());
	gotoxy(xout, yout++);
	cout << "Всего ядер: " + to_string(all_cores);
	gotoxy(xout, yout++);
	cout << "Длина очереди: " + to_string(V.Get_queue().Get_full_size());
	gotoxy(xout, yout++);
	cout << MENU_ITEM(69, VM);
	gotoxy(xout, yout++);
	cout << MENU_ITEM(71, VM);
	gotoxy(xout, yout++);
	cout << MENU_ITEM(72, VM);
	gotoxy(xout, yout++);
	cout << MENU_ITEM(73, VM);
	gotoxy(xout, yout++);
	cout << MENU_ITEM(74, VM);
	gotoxy(xout, yout++);
	cout << MENU_ITEM(16, VM);
	gotoxy(xout, yout++);
	cout << MENU_ITEM(17, VM);

	
}

int L091NN()
{
	gotoxy(0, 28);
	cout << "Powered by LOGIN";
	gotoxy(0, 29);
	cout << "c++";
	gotoxy(99, 29);
	cout << "developed in 28 days";
	_getch();
	int text_color = 0;
	int bg_color = 14;
	for (int L = 0; L < 120; L++)
	{
		for (int O = 10; O < 20; O++)
		{
			set_colour(text_color, bg_color);
			gotoxy(L, O);
			cout << ' ';
		}
	}
	// G
	int G = 0;
	int I = 0;
	while (_getch() != 13)
	{
		G = ++G % 16;
		if (G == 14) G = G ++;
		set_colour(G, G);
		if (G == 12)
		{
			if (I == 0)
			{

				for (int N = 0; N < 2; N++)
				{
					gotoxy(10, 13 + N);
					cout << ' ';
					gotoxy(21, 13 + N);
					cout << ' ';
				}
				for (int N = 0; N < 4; N++)
				{
					gotoxy(11, 12 + N);
					cout << ' ';
					gotoxy(20, 12 + N);
					cout << ' ';
				}
				for (int N = 0; N < 6; N++)
				{
					gotoxy(12, 11 + N);
					cout << ' ';
					gotoxy(19, 11 + N);
					cout << ' ';
				}
				for (int N = 0; N < 7; N++)
				{
					gotoxy(13, 11 + N);
					cout << ' ';
					gotoxy(18, 11 + N);
					cout << ' ';
				}
				for (int N = 0; N < 7; N++)
				{
					gotoxy(14, 12 + N);
					cout << ' ';
					gotoxy(17, 12 + N);
					cout << ' ';
				}
				for (int N = 0; N < 7; N++)
				{
					gotoxy(15, 13 + N);
					cout << ' ';
					gotoxy(16, 13 + N);
					cout << ' ';
				}
			}
			if (I == 1)
			{
				for (int N = 0; N < 2; N++)
				{
					gotoxy(110, 13 + N);
					cout << ' ';
					gotoxy(99, 13 + N);
					cout << ' ';
				}
				for (int N = 0; N < 4; N++)
				{
					gotoxy(109, 12 + N);
					cout << ' ';
					gotoxy(100, 12 + N);
					cout << ' ';
				}
				for (int N = 0; N < 6; N++)
				{
					gotoxy(108, 11 + N);
					cout << ' ';
					gotoxy(101, 11 + N);
					cout << ' ';
				}
				for (int N = 0; N < 7; N++)
				{
					gotoxy(107, 11 + N);
					cout << ' ';
					gotoxy(102, 11 + N);
					cout << ' ';
				}
				for (int N = 0; N < 7; N++)
				{
					gotoxy(106, 12 + N);
					cout << ' ';
					gotoxy(103, 12 + N);
					cout << ' ';
				}
				for (int N = 0; N < 7; N++)
				{
					gotoxy(105, 13 + N);
					cout << ' ';
					gotoxy(104, 13 + N);
					cout << ' ';
				}
			}
			if (I < 2) I++;
		}
		if (I == 2)
		{
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			gotoxy(56, 0);
			cout << "PALDIES!";
		}
		if (I == 3)
		{
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			gotoxy(57, 1);
			cout << "RAHMAT";
		}
		if (I == 4)
		{
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			gotoxy(55, 2);
			cout << "EVKARISTO!";
		}
		if (I == 5)
		{
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			gotoxy(56, 3);
			cout << "GRACIAS!";
		}
		if (I == 6)
		{
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			gotoxy(58, 4);
			cout << "TAK!";
		}
		if (I == 7)
		{
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			gotoxy(56, 5);
			cout << "СПАСИБО!";
		}
		set_colour(G, G);
		if (I > 7)
		{
			if (I % 2 == 1)
			{
				for (int N = 0; N < 2; N++)
				{
					gotoxy(10, 13 + N);
					cout << ' ';
					gotoxy(21, 13 + N);
					cout << ' ';
				}
				for (int N = 0; N < 4; N++)
				{
					gotoxy(11, 12 + N);
					cout << ' ';
					gotoxy(20, 12 + N);
					cout << ' ';
				}
				for (int N = 0; N < 6; N++)
				{
					gotoxy(12, 11 + N);
					cout << ' ';
					gotoxy(19, 11 + N);
					cout << ' ';
				}
				for (int N = 0; N < 7; N++)
				{
					gotoxy(13, 11 + N);
					cout << ' ';
					gotoxy(18, 11 + N);
					cout << ' ';
				}
				for (int N = 0; N < 7; N++)
				{
					gotoxy(14, 12 + N);
					cout << ' ';
					gotoxy(17, 12 + N);
					cout << ' ';
				}
				for (int N = 0; N < 7; N++)
				{
					gotoxy(15, 13 + N);
					cout << ' ';
					gotoxy(16, 13 + N);
					cout << ' ';
				}
			}
			else
			{
				for (int N = 0; N < 2; N++)
				{
					gotoxy(110, 13 + N);
					cout << ' ';
					gotoxy(99, 13 + N);
					cout << ' ';
				}
				for (int N = 0; N < 4; N++)
				{
					gotoxy(109, 12 + N);
					cout << ' ';
					gotoxy(100, 12 + N);
					cout << ' ';
				}
				for (int N = 0; N < 6; N++)
				{
					gotoxy(108, 11 + N);
					cout << ' ';
					gotoxy(101, 11 + N);
					cout << ' ';
				}
				for (int N = 0; N < 7; N++)
				{
					gotoxy(107, 11 + N);
					cout << ' ';
					gotoxy(102, 11 + N);
					cout << ' ';
				}
				for (int N = 0; N < 7; N++)
				{
					gotoxy(106, 12 + N);
					cout << ' ';
					gotoxy(103, 12 + N);
					cout << ' ';
				}
				for (int N = 0; N < 7; N++)
				{
					gotoxy(105, 13 + N);
					cout << ' ';
					gotoxy(104, 13 + N);
					cout << ' ';
				}
			}
		}
		if(I > 1) I++;
		gotoxy(62, 11);
		cout << ' ';
		gotoxy(61, 11);
		cout << ' ';
		gotoxy(60, 11);
		cout << ' ';
		gotoxy(59, 11);
		cout << ' ';
		gotoxy(58, 11);
		cout << ' ';
		gotoxy(57, 11);
		cout << ' ';
		gotoxy(57, 12);
		cout << ' ';
		gotoxy(57, 13);
		cout << ' ';
		gotoxy(57, 14);
		cout << ' ';
		gotoxy(57, 15);
		cout << ' ';
		gotoxy(57, 16);
		cout << ' ';
		gotoxy(57, 17);
		cout << ' ';
		gotoxy(57, 18);
		cout << ' ';
		gotoxy(58, 18);
		cout << ' ';
		gotoxy(59, 18);
		cout << ' ';
		gotoxy(60, 18);
		cout << ' ';
		gotoxy(61, 18);
		cout << ' ';
		gotoxy(62, 18);
		cout << ' ';
		gotoxy(62, 17);
		cout << ' '; 
		gotoxy(62, 16);
		cout << ' ';
		gotoxy(62, 15);
		cout << ' ';
		gotoxy(62, 14);
		cout << ' ';
		gotoxy(61, 14);
		cout << ' ';
		gotoxy(60, 14);
		cout << ' ';
		//O
		gotoxy(49, 11);
		cout << ' ';
		gotoxy(49, 12);
		cout << ' ';
		gotoxy(49, 13);
		cout << ' ';
		gotoxy(49, 14);
		cout << ' ';
		gotoxy(49, 15);
		cout << ' ';
		gotoxy(49, 16);
		cout << ' ';
		gotoxy(49, 17);
		cout << ' ';
		gotoxy(49, 18);
		cout << ' ';
		gotoxy(50, 18);
		cout << ' ';
		gotoxy(51, 18);
		cout << ' ';
		gotoxy(52, 18);
		cout << ' ';
		gotoxy(53, 18);
		cout << ' ';
		gotoxy(54, 18);
		cout << ' ';
		gotoxy(54, 17);
		cout << ' ';
		gotoxy(54, 16);
		cout << ' ';
		gotoxy(54, 15);
		cout << ' ';
		gotoxy(54, 14);
		cout << ' ';
		gotoxy(54, 13);
		cout << ' ';
		gotoxy(54, 12);
		cout << ' ';
		gotoxy(54, 11);
		cout << ' ';
		gotoxy(53, 11);
		cout << ' ';
		gotoxy(52, 11);
		cout << ' ';
		gotoxy(51, 11);
		cout << ' ';
		gotoxy(50, 11);
		cout << ' ';
		// L
		gotoxy(41, 11);
		cout << ' ';
		gotoxy(41, 12);
		cout << ' ';
		gotoxy(41, 13);
		cout << ' ';
		gotoxy(41, 14);
		cout << ' ';
		gotoxy(41, 15);
		cout << ' ';
		gotoxy(41, 16);
		cout << ' ';
		gotoxy(41, 17);
		cout << ' ';
		gotoxy(41, 18);
		cout << ' ';
		gotoxy(42, 18);
		cout << ' ';
		gotoxy(43, 18);
		cout << ' ';
		gotoxy(44, 18);
		cout << ' ';
		gotoxy(45, 18);
		cout << ' ';
		gotoxy(46, 18);
		cout << ' ';
		//I
		gotoxy(65, 11);
		cout << ' ';
		gotoxy(66, 11);
		cout << ' ';
		gotoxy(67, 11);
		cout << ' ';
		gotoxy(68, 11);
		cout << ' ';
		gotoxy(69, 11);
		cout << ' ';
		gotoxy(67, 12);
		cout << ' ';
		gotoxy(67, 13);
		cout << ' ';
		gotoxy(67, 14);
		cout << ' ';
		gotoxy(67, 15);
		cout << ' ';
		gotoxy(67, 16);
		cout << ' ';
		gotoxy(67, 17);
		cout << ' ';
		gotoxy(65, 18);
		cout << ' ';
		gotoxy(66, 18);
		cout << ' ';
		gotoxy(67, 18);
		cout << ' ';
		gotoxy(68, 18);
		cout << ' ';
		gotoxy(69, 18);
		cout << ' ';
		// N
		gotoxy(72, 18);
		cout << ' ';
		gotoxy(72, 17);
		cout << ' ';
		gotoxy(72, 16);
		cout << ' ';
		gotoxy(72, 15);
		cout << ' ';
		gotoxy(72, 14);
		cout << ' ';
		gotoxy(72, 13);
		cout << ' ';
		gotoxy(72, 12);
		cout << ' ';
		gotoxy(72, 11);
		cout << ' ';
		gotoxy(73, 12);
		cout << ' ';
		gotoxy(74, 13);
		cout << ' ';
		gotoxy(74, 14);
		cout << ' ';
		gotoxy(75, 15);
		cout << ' ';
		gotoxy(75, 16);
		cout << ' ';
		gotoxy(76, 17);
		cout << ' ';
		gotoxy(77, 18);
		cout << ' ';
		gotoxy(77, 17);
		cout << ' ';
		gotoxy(77, 16);
		cout << ' ';
		gotoxy(77, 15);
		cout << ' ';
		gotoxy(77, 14);
		cout << ' ';
		gotoxy(77, 13);
		cout << ' ';
		gotoxy(77, 12);
		cout << ' ';
		gotoxy(77, 11);
		cout << ' ';

		Sleep(500);
		_getch();
	}

	return 91;
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
			if ((menu_past - 1) / 5 != (menu_future - 1) / 5 && menu_future == 1)
			{
				Output_information(VM);
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
void DROW_BG_WORK(int x_move, int y_move)
{
	int xi = 0;
	int yi = 0;
	set_colour(mass_of_style[style][1], mass_of_style[style][0]);
	// коробка PG
	gotoxy(104 + xi, 18 + yi);
	cout << " ";
	gotoxy(103 + xi, 18 + yi);
	cout << " ";
	gotoxy(102 + xi, 18 + yi);
	cout << " ";
	gotoxy(101 + xi, 18 + yi);
	cout << " ";
	gotoxy(100 + xi, 18 + yi);
	cout << " ";
	gotoxy(99 + xi, 18 + yi);
	cout << " ";
	gotoxy(98 + xi, 18 + yi);
	cout << " ";
	gotoxy(97 + xi, 18 + yi);
	cout << " ";
	gotoxy(96 + xi, 18 + yi);
	cout << " ";
	gotoxy(95 + xi, 18 + yi);
	cout << " ";
	gotoxy(94 + xi, 18 + yi);
	cout << " ";
	gotoxy(93 + xi, 18 + yi);
	cout << " ";
	gotoxy(92 + xi, 18 + yi);
	cout << " ";
	gotoxy(92 + xi, 19 + yi);
	cout << " ";
	gotoxy(92 + xi, 20 + yi);
	cout << " ";
	gotoxy(92 + xi, 21 + yi);
	cout << " ";
	gotoxy(92 + xi, 22 + yi);
	cout << " ";
	gotoxy(92 + xi, 23 + yi);
	cout << " ";
	gotoxy(92 + xi, 24 + yi);
	cout << " ";
	gotoxy(92 + xi, 25 + yi);
	cout << " ";
	gotoxy(92 + xi, 26 + yi);
	cout << " ";
	gotoxy(93 + xi, 26 + yi);
	cout << " ";
	gotoxy(94 + xi, 26 + yi);
	cout << " ";
	gotoxy(95 + xi, 26 + yi);
	cout << " ";
	gotoxy(96 + xi, 26 + yi);
	cout << " ";
	gotoxy(97 + xi, 26 + yi);
	cout << " ";
	gotoxy(98 + xi, 26 + yi);
	cout << " ";
	gotoxy(99 + xi, 26 + yi);
	cout << " ";
	gotoxy(100 + xi, 26 + yi);
	cout << " ";
	gotoxy(101 + xi, 26 + yi);
	cout << " ";
	gotoxy(102 + xi, 26 + yi);
	cout << " ";
	gotoxy(103 + xi, 26 + yi);
	cout << " ";
	gotoxy(104 + xi, 26 + yi);
	cout << " ";
	gotoxy(104 + xi, 25 + yi);
	cout << " ";
	gotoxy(104 + xi, 24 + yi);
	cout << " ";
	gotoxy(104 + xi, 23 + yi);
	cout << " ";
	gotoxy(104 + xi, 22 + yi);
	cout << " ";
	gotoxy(104 + xi, 21 + yi);
	cout << " ";
	gotoxy(104 + xi, 20 + yi);
	cout << " ";
	gotoxy(104 + xi, 19 + yi);
	cout << " ";
	// P
	gotoxy(94 + xi, 24 + yi);
	cout << " ";
	gotoxy(94 + xi, 23 + yi);
	cout << " ";
	gotoxy(94 + xi, 22 + yi);
	cout << " ";
	gotoxy(94 + xi, 21 + yi);
	cout << " ";
	gotoxy(94 + xi, 20 + yi);
	cout << " ";
	gotoxy(95 + xi, 20 + yi);
	cout << " ";
	gotoxy(96 + xi, 20 + yi);
	cout << " ";
	gotoxy(97 + xi, 20 + yi);
	cout << " ";
	gotoxy(97 + xi, 21 + yi);
	cout << " ";
	gotoxy(97 + xi, 22 + yi);
	cout << " ";
	gotoxy(96 + xi, 22 + yi);
	cout << " ";
	gotoxy(95 + xi, 22 + yi);
	cout << " ";
	//G
	gotoxy(102 + xi, 20 + yi);
	cout << " ";
	gotoxy(101 + xi, 20 + yi);
	cout << " ";
	gotoxy(100 + xi, 20 + yi);
	cout << " ";
	gotoxy(99 + xi, 20 + yi);
	cout << " ";
	gotoxy(99 + xi, 21 + yi);
	cout << " ";
	gotoxy(99 + xi, 22 + yi);
	cout << " ";
	gotoxy(99 + xi, 23 + yi);
	cout << " ";
	gotoxy(99 + xi, 24 + yi);
	cout << " ";
	gotoxy(100 + xi, 24 + yi);
	cout << " ";
	gotoxy(101 + xi, 24 + yi);
	cout << " ";
	gotoxy(102 + xi, 24 + yi);
	cout << " ";
	gotoxy(102 + xi, 23 + yi);
	cout << " ";
	gotoxy(102 + xi, 22 + yi);
	cout << " ";
	gotoxy(101 + xi, 22 + yi);
	cout << " ";
	// track to queue
	gotoxy(91 + xi, 22 + yi);
	cout << " ";
	gotoxy(90 + xi, 22 + yi);
	cout << " ";
	gotoxy(89 + xi, 22 + yi);
	cout << " ";
	gotoxy(88 + xi, 22 + yi);
	cout << " ";
	gotoxy(87 + xi, 22 + yi);
	cout << " ";
	gotoxy(86 + xi, 22 + yi);
	cout << " ";
	gotoxy(85 + xi, 22 + yi);
	cout << " ";
	gotoxy(84 + xi, 22 + yi);
	cout << " ";
	gotoxy(83 + xi, 22 + yi);
	cout << " ";
	gotoxy(82 + xi, 22 + yi);
	cout << " ";
	gotoxy(82 + xi, 23 + yi);
	cout << " ";
	// qeueu
	for (int x = 83 + xi; x != 60 + xi; x--)
	{
		gotoxy(x + xi, 24 + yi);
		cout << " ";
	}
	for (int x = 83 + xi; x != 60 + xi; x--)
	{
		gotoxy(x + xi, 26 + yi);
		cout << " ";
	}
	gotoxy(61 + xi, 25 + yi);
	cout << " ";
	gotoxy(83 + xi, 25 + yi);
	cout << " ";
	// track to processors
	gotoxy(62 + xi, 23 + yi);
	cout << " ";
	gotoxy(62 + xi, 22 + yi);
	cout << " ";
	gotoxy(61 + xi, 22 + yi);
	cout << " ";
	gotoxy(61 + xi, 21 + yi);
	cout << " ";
	gotoxy(60 + xi, 21 + yi);
	cout << " ";
	gotoxy(60 + xi, 20 + yi);
	cout << " ";
	for (int y = 19; y != 10; y--)
	{
		gotoxy(60 + xi, y + yi);
		cout << " ";
		gotoxy(61 + xi, y + yi);
		cout << " ";
	}
	// track to 1 processors
	int px = 60;
	int py = 11;
	while (!(px == 45 && py == 3))
	{
		int orin = rand() % 2;
		if (orin == 0 && px > 45)
		{
			px--;
			gotoxy(px + xi, py + yi);
			cout << " ";
		}
		if (orin == 1 && py > 3)
		{
			py--;
			gotoxy(px + xi, py + yi);
			cout << " ";
		}
	}
	// track to 2 processors
	px = 61;
	py = 11;
	while (!(px == 76 && py == 3))
	{
		int orin = rand() % 2;
		if (orin == 0 && px < 76)
		{
			px++;
			gotoxy(px + xi, py + yi);
			cout << " ";
		}
		if (orin == 1 && py > 3)
		{
			py--;
			gotoxy(px + xi, py + yi);
			cout << " ";
		}
	}
	// track to 3 processors
	px = 60;
	py = 11;
	while (!(px == 45 && py == 19))
	{
		int orin = rand() % 2;
		if (orin == 0 && px > 45)
		{
			px--;
			gotoxy(px + xi, py + yi);
			cout << " ";
		}
		if (orin == 1 && py < 19)
		{
			py++;
			gotoxy(px + xi, py + yi);
			cout << " ";
		}
	}
	// track to 4 processors
	px = 61;
	py = 11;
	while (!(px == 76 && py == 19))
	{
		int orin = rand() % 2;
		if (orin == 0 && px < 76)
		{
			px++;
			gotoxy(px + xi, py + yi);
			cout << " ";
		}
		if (orin == 1 && py < 19)
		{
			py++;
			gotoxy(px + xi, py + yi);
			cout << " ";
		}
	}

	set_colour(mass_of_style[style][0], mass_of_style[style][1]);
}
void DROW_QUEUE_STATUS(int size, int size_full, int x_move, int y_move)
{
	int xi = x_move;
	int yi = y_move;
	if (size_full < 1) throw("ERROR! size_full < 1");
	if (size < 0) throw ("ERROR! size < 0");
	if (size > 0)
	{
		if (queue_last < 0)
		{
			queue_last = 0;
		}
		double ref = size_full / 20;
		if (trunc(queue_last / ref) < trunc(size / ref))
		{
			for (int i = trunc(queue_last / ref); i != trunc(size / ref); i++)
			{
				if (i < 11)
				{
					set_colour(2, 2);
					gotoxy(62 + i, 25);
					cout << " ";
				}
				if (i >= 11 && i < 18)
				{
					set_colour(6, 6);
					gotoxy(62 + i, 25);
					cout << " ";
				}
				if (i >= 18 && i <= 21)
				{
					set_colour(4, 4);
					gotoxy(62 + i, 25);
					cout << " ";
				}
				set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			}
		}
		if (trunc(queue_last / ref) > trunc(size / ref))
		{
			if (queue_last == size_full)
			{
				for (int i = 0; i != 21; i++)
				{
					if (i < 11)
					{
						set_colour(2, 2);
						gotoxy(62 + i, 25);
						cout << " ";
					}
					if (i >= 11 && i < 18)
					{
						set_colour(6, 6);
						gotoxy(62 + i, 25);
						cout << " ";
					}
					if (i >= 18 && i < 20)
					{
						set_colour(4, 4);
						gotoxy(62 + i, 25);
						cout << " ";
					}
					if (i == 20)
					{
						set_colour(mass_of_style[style][0], mass_of_style[style][1]);
						gotoxy(62 + i, 25);
						cout << " ";

					}
				}
				set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			}
			else
			{
				for (int i = trunc(queue_last / ref); i != trunc(size / ref); i--)
				{
					set_colour(mass_of_style[style][0], mass_of_style[style][1]);
					gotoxy(62 + i, 25);
					cout << " ";
				}
			}
		}
		if (queue_last == size_full && size == size_full)
		{
			for (int j = 0; j < 21; j++)
			{
				int randd = rand() % 2;
				if (randd == 0)
				{
					set_colour(4, 4);
					gotoxy(62 + j, 25);
					cout << " ";
				}
				else
				{
					set_colour(12, 12);
					gotoxy(62 + j, 25);
					cout << " ";
				}
			}
		}

		queue_last = size;
	}
	else
	{
		if (queue_last-- <= 0)
		{
			for (int i = 0; i > queue_last % 20; i--)
			{
				if (queue_last % 2 == -1)
				{
					if (i % 2 == 0)
					{
						gotoxy(62 - i, 25);
						cout << "z";
					}
					else
					{
						gotoxy(62 - i, 25);
						cout << " ";
					}
				}
				else
				{
					if (i % 2 == -1)
					{
						gotoxy(62 - i, 25);
						gotoxy(62 - i, 25);
						cout << "z";
					}
					else
					{
						gotoxy(62 - i, 25);
						cout << " ";
					}
				}
				
			}
		}
	}
}
void DROW_INFORMATION_WORK(const Virtual_machine &VM)
{
	Virtual_machine V(VM);
	unsigned int xpos = 0;
	unsigned int ypos = 0;
	int all_cores = 0;
	for (int i = 0; i < 4; i++)
	{
		if (V.Get_index_of_proc(i + 1) != -1)
		{
			all_cores += V.Get_processors()[V.Get_index_of_proc(i + 1)].Get_cores();
		}
	}
	set_colour(mass_of_style[style][0], mass_of_style[style][1]);
	gotoxy(xpos, ypos++);
	if (time_of_work)
	{
		cout << "Такт: " + to_string(V.Get_tact()) + '/' + to_string(time_of_work);
	}
	else
	{
		cout << "Такт: " + to_string(V.Get_tact());
	}
	gotoxy(xpos, ypos++);
	cout << "Программы: " + to_string(V.Get_Act_Program().size()) + '/' + to_string(V.Get_Complete_Program().size()) + '/' + to_string(V.Get_Act_Program().size() + V.Get_Complete_Program().size() + V.Get_Fail_Program_p().size() + V.Get_Fail_Program_q().size());
	gotoxy(xpos, ypos++);
	cout << "Отказы: " + to_string(V.Get_Fail_Program_p().size()) + '/' + to_string(V.Get_Fail_Program_q().size());
}
void DROW_BEGIN_PROCESSORS(const Virtual_machine &VM, int xi, int yi)
{
	Virtual_machine V(VM);
	for (int num = 1; num < 5; num++)
	{
		int size_side = 8;
		int xpos = 75 + xi;
		int ypos = 19 + yi;
		bool xsign = 0;
		bool ysign = 0;
		if (num % 2 == 1)
		{
			xpos = 45 + xi;
			xsign = 1;
		}
		if ((num - 1) / 2 == 0)
		{
			ypos = 3 + yi;
			ysign = 1;
		}
		if (V.Get_index_of_proc(num) != -1)
		{
			set_colour(mass_of_style[style][1], mass_of_style[style][0]);
			size_side = sqrt(V.Get_processors()[V.Get_index_of_proc(num)].Get_cores());
		}
		else
		{
			set_colour(mass_of_style[style][0], mass_of_style[style][1]);
			//set_colour(mass_of_style[style][1], 12);
		}
		for (int yy = 0; yy < size_side;)
		{
			for (int xx = 0; xx < size_side;)
			{
				if (xsign == 0 && ysign == 0)
				{
					gotoxy(xpos - xx * 2, ypos - yy);
				}
				if (xsign == 1 && ysign == 0)
				{
					gotoxy(xpos + xx * 2, ypos - yy);
				}
				if (xsign == 0 && ysign == 1)
				{
					gotoxy(xpos - xx * 2, ypos + yy);
				}
				if (xsign == 1 && ysign == 1)
				{
					gotoxy(xpos + xx * 2, ypos + yy);
				}
				if (xx == size_side - 1)
				{
					if (xsign == 0)
					{
						if (ysign)
						{
							gotoxy(xpos - xx * 2 + 1, ypos + yy);
						}
						else
						{
							gotoxy(xpos - xx * 2 + 1, ypos - yy);
						}
					}
				}
				cout << ' ';
				if (xx != size_side - 1)
				{
					cout << ' ';
				}
				xx++;
			}
			yy++;
		}
	}
	set_colour(mass_of_style[style][0], mass_of_style[style][1]);
}
void DROW_PROCESSORS(const Virtual_machine &VM,bool repeat, int xi, int yi)
{
	Virtual_machine V(VM);
	for (int num = 1; num < 5; num++)
	{
		if (V.Get_index_of_proc(num) != -1)
		{
			int size_side = sqrt(V.Get_processors()[V.Get_index_of_proc(num)].Get_cores());
			int xpos = 75 + xi;
			int ypos = 19 + yi;
			bool xsign = 0;
			bool ysign = 0;
			if (num % 2 == 1)
			{
				xpos = 45 + xi;
				xsign = 1;
			}
			if ((num - 1) / 2 == 0)
			{
				ypos = 3 + yi;
				ysign = 1;
			}
			for (int yy = 0; yy < size_side;)
			{
				for (int xx = 0; xx < size_side;)
				{
					if (xsign == 0 && ysign == 0)
					{
						gotoxy(xpos - xx * 2 + 1, ypos - yy);
					}
					if (xsign == 1 && ysign == 0)
					{
						gotoxy(xpos + xx * 2, ypos - yy);
					}
					if (xsign == 0 && ysign == 1)
					{
						gotoxy(xpos - xx * 2 + 1, ypos + yy);
					}
					if (xsign == 1 && ysign == 1)
					{
						gotoxy(xpos + xx * 2, ypos + yy);
					}
					if (repeat)
					{
							if (V.Get_processors()[V.Get_index_of_proc(num)].Get_core(yy * size_side + xx).is_work
								!= past_VM.Get_processors()[V.Get_index_of_proc(num)].Get_core(yy * size_side + xx).is_work)
							{
								if (V.Get_processors()[V.Get_index_of_proc(num)].Get_core(yy * size_side + xx).is_work)
								{
									set_colour(mass_of_style[style][1], 12);
									cout << '1';
									set_colour(mass_of_style[style][0], mass_of_style[style][1]);
								}
								else
								{
									set_colour(mass_of_style[style][1], 10);
									cout << '0';
									set_colour(mass_of_style[style][0], mass_of_style[style][1]);
								}
							}
					}
					else
					{
						set_colour(mass_of_style[style][1], 10);
						cout << '0';
						set_colour(mass_of_style[style][0], mass_of_style[style][1]);
					}
					xx++;
				}
				yy++;
			}


		}
	}
}
