#include "Headers/Global.h"
#include "Headers/Stats.h"

//GAME OVER SOUND=============================================
DWORD WINAPI Wasted(void* param)
{
	PlaySoundA("Sounds/wasted.WAV", NULL, SND_ASYNC | SND_NODEFAULT);
	return 0;
}
DWORD WINAPI YouDied(void* param)
{
	PlaySoundA("Sounds/YouDied.WAV", NULL, SND_ASYNC | SND_NODEFAULT);
	return 0;
}
//============================================================

void Wasted(string txt, int indent, bool isDeath)
{
	extern int hp;
	hp = 1;
	money = money / 2;
	small_heal = 0;
	medium_heal = 0;
	large_heal = 0;

	if (isDeath)
	{
		CreateThread(0, 0, YouDied, 0, 0, 0);
	}
	else if (!isDeath)
	{
		CreateThread(0, 0, Wasted, 0, 0, 0);
	}

	Sleep(500);

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX font;

	font.cbSize = sizeof(font);
	font.dwFontSize.Y = 120;
	SetCurrentConsoleFontEx(h, 0, &font);
	MoveWindow(GetConsoleWindow(), 221, 80, 1500, 900, true);

	COORD ur_death;
	ur_death.X = indent;
	ur_death.Y = 2;
	SetConsoleCursorPosition(h, ur_death);
	SetConsoleTextAttribute(h, 4);

	string death = txt;
	
	for (int i = 0; i < death.length(); i++)
	{
		Sleep(600);
		cout << death[i];
	}

	Sleep(1000);

	int choice = MessageBoxA(0, "    Continue from last checkpoint?", "We live in matrix", MB_YESNO);

	if (choice == IDYES)
	{
		system("cls");
		ShowLevel();
	}
	else
	{
		system("cls");
		ShowMenu();
	}
}