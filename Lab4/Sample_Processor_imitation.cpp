#include"Virtual_machine.h"
#include<conio.h>
#include<Windows.h>
#include<iostream>
#include<ctime>
#include<locale>

using namespace std;

void gotoxy(int xpos, int ypos);
void display_cursor(bool tf);
void set_colour(int colour_of_text, int colour_of_background);
void Output_information();
void START_MENU(int first_item);
void DROW(int menu_future, int menu_past);
string MENU_ITEM(int menu);
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
	int PROC_NUM[5] = { 0, 1, 4, 16, 64 };
	Virtual_machine VM;
	START_MENU(1);
	while (1)
	{
		vector<Processor> VMP = VM.Get_processors();
		_kbhit();
		switch (_getch())
		{
		case 13: // ENTER
		{
			if (menu_future < 5)
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

			break;
		}
		case 27: // ESC
		{
			exit(0);
			break;
		}
		case 72: // UP
		{
			menu_past = menu_future;
			if (menu_future % 5 != 1)
				menu_future -= 1;
			else
				menu_future += 4;
			break;
		}
		case 75: // LEFT
		{
			switch (menu_future)
			{
			case 56:
			{
				gotoxy(33, 0);
				cout << VMP[0].Get_cores() << VMP.size();

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
			default:
			{
				menu_past = menu_future;
				menu_future *= 5;
				menu_future++;
			}
			}
			break;
		}
		case 80: // DOWN
		{
			menu_past = menu_future;
			if (menu_future % 5 != 0)
				menu_future += 1;
			else
				menu_future -= 4;
			break;
		}
		default:
			break;
		}
		DROW(menu_future, menu_past);
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

void DROW(int menu_future, int menu_past)
{
	switch (menu_future)
	{
	case 26:
	{
		exit(0);
		break;
	}
	default:
	{
		if (trunc((menu_past - 1) / 5) == trunc((menu_future - 1) / 5))
		{
			int mp = menu_past % 5;
			int mf = menu_future % 5;
			if (mp == 0) mp = 5;
			if (mf == 0) mf = 5;
			gotoxy(0, mp - 1);
			set_colour(15, 0);
			cout << MENU_ITEM(menu_past);
			gotoxy(0, mf - 1);
			set_colour(0, 15);
			cout << MENU_ITEM(menu_future);
		}
		else
		{
			START_MENU(trunc((menu_future - 1) / 5) * 5 + 1);
		}
	}
	}
}

string MENU_ITEM(int menu)
{
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
	if (menu == 16) return "Отображать REALTIME информацию";
	if (menu == 17) return "Показывать процессор(-ы)";
	if (menu == 18) return "Частота отрисовки";
	if (menu == 19) return "Стиль";
	if (menu == 20) return "Назад";
	if (menu == 56) return "Количество ядер на 1 процессоре: ";
	if (menu == 57) return "Количество ядер на 2 процессоре: ";
	if (menu == 58) return "Количество ядер на 3 процессоре: ";
	if (menu == 59) return "Количество ядер на 4 процессоре: ";
	if (menu == 60) return "Назад";


}

void START_MENU(int first_item)
{
	set_colour(15, 0);
	system("cls");
	int y = 0;
	for (int i = first_item; i < first_item + 5; i++)
	{
		if (i == first_item)
		{
			gotoxy(0, y++);
			set_colour(0, 15);
			cout << MENU_ITEM(i);
			set_colour(15, 0);
		}
		else
		{
			gotoxy(0, y++);
			cout << MENU_ITEM(i);
		}
	}
}