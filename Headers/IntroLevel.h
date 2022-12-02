#include "Headers/Global.h"
#include "Headers/Level.h"

//ARTHAS VOL==================================================
DWORD WINAPI Arthas_vol2(void* param)
{
	PlaySoundA("Sounds/Arthas_vol2.WAV", NULL, SND_NODEFAULT | SND_ASYNC);
	return 0;
}
DWORD WINAPI Arthas_vol1(void* param)
{
	PlaySoundA("Sounds/Arthas_vol1.WAV", NULL, SND_NODEFAULT | SND_ASYNC);
	return 0;
}
//============================================================

//UTHER VOL===================================================
DWORD WINAPI Uter_vol1(void* param)
{
	PlaySoundA("Sounds/Uter_vol1.WAV", NULL, SND_NODEFAULT | SND_ASYNC);
	return 0;
}
//============================================================

//DOOR SOUND==================================================
DWORD WINAPI DoorBreak(void* param)
{
	PlaySoundA("Sounds/DoorBreak.WAV", NULL, SND_NODEFAULT | SND_ASYNC);
	return 0;
}
//============================================================

void ShowIntroLevel()
{
	const int rows = 12;
	const int cols = 28;

	int level[rows][cols] = {};

	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			if (x == 0 || y == 4 || x == cols / 2 - 1 || y == rows - 1)
			{
				level[y][x] = 1; // границы уровня
			}

			if (x > cols / 2 - 1)
			{
				level[y][x] = 0;
			}
		}
	}

	//показ лабиринта ----------------------------------

	COORD room;
	room.X = 0;
	room.Y = 4;
	SetConsoleCursorPosition(h, room);

	for (int y = 4; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			if (level[y][x] == 0)
			{
				cout << " ";
			}
			if (y == rows && x == cols / 4 + 1 || y == rows && x == cols / 4)
			{
				SetConsoleTextAttribute(h, 5);
				cout << (char)219;
			}
			else if (level[y][x] == 1)
			{
				SetConsoleTextAttribute(h, 8);
				cout << (char)219;
			}

		}
		cout << "\n";
	}
	cout << "\n";


	//диалоги ----------------------------------

	COORD player;
	player.X = 1;
	player.Y = 8;

	COORD Arthas;
	Arthas.X = cols / 2 - 2;
	Arthas.Y = 8;

	COORD Uter;
	Uter.X = cols / 4;
	Uter.Y = 5;

	SetConsoleCursorPosition(h, Uter);
	SetConsoleTextAttribute(h, 14);
	cout << (char)1;

	SetConsoleCursorPosition(h, player);
	SetConsoleTextAttribute(h, 9);
	cout << (char)1;

	SetConsoleCursorPosition(h, Arthas);
	SetConsoleTextAttribute(h, 6);
	cout << (char)1;
	
	Sleep(1500);

	COORD text_Arthas;
	text_Arthas.X = 16;
	text_Arthas.Y = 4;
	SetConsoleCursorPosition(h, text_Arthas);

	CreateThread(0, 0, Arthas_vol1, 0, 0, 0);

	SetConsoleTextAttribute(h, 6);
	cout << "Arthur Menethil: ";

	SetConsoleTextAttribute(h, 15);
	string volArthas = "Hey, you, finally awake, \n\t\tyou were trying to cross the border, right? \n\t\tWalked right into that German ambush, same as us and that thief over there.";

	for (int i = 0; i < volArthas.length(); i++)
	{
		Sleep(60);
		cout << volArthas[i];
	}

	Sleep(2000);

	COORD text_Uther;
	text_Uther.X = 16;
	text_Uther.Y = 8;
	SetConsoleCursorPosition(h, text_Uther);

	CreateThread(0, 0, Uter_vol1, 0, 0, 0);

	SetConsoleTextAttribute(h, 14);
	cout << "Uther Pendragon: ";

	SetConsoleTextAttribute(h, 15);
	string volUther = "Yeah... \n\t\tSo it's because of you that so many guards were assigned to me! \n\t\tSo I would have slashed that dunce! I took a horse and ran away from here.\n\n";

	for (int i = 0; i < volUther.length(); i++)
	{
		Sleep(60);
		cout << volUther[i];
	}
	Sleep(4000);

	COORD Exit1, Exit2;
	Exit1.X = cols / 4;
	Exit1.Y = 11;

	Exit2.X = cols / 4 - 1;
	Exit2.Y = 11;

	CreateThread(0, 0, DoorBreak, 0, 0, 0);
	Sleep(1000);

	SetConsoleCursorPosition(h, Exit1);
	SetConsoleTextAttribute(h, 5);
	cout << " ";

	SetConsoleCursorPosition(h, Exit2);
	SetConsoleTextAttribute(h, 5);
	cout << " ";

	/*CreateThread(0, 0, Arthas_vol2, 0, 0, 0);*/
	for (int i = 0; i < 6; i++) //Утер уходит
	{
		SetConsoleCursorPosition(h, Uter);
		cout << " ";
		Uter.Y++;
		SetConsoleCursorPosition(h, Uter);
		SetConsoleTextAttribute(h, 14);
		cout << (char)1;
		Sleep(250);
	}
	SetConsoleCursorPosition(h, Uter);
	cout << " ";

	for (int i = 0; i < 8; i++) //Артас уходит
	{
		SetConsoleCursorPosition(h, Arthas);
		cout << " ";
		if (i < 5) 
		{
			Arthas.X--;
		}
		else 
		{
			Arthas.Y++;
		}
		SetConsoleCursorPosition(h, Arthas);
		SetConsoleTextAttribute(h, 6);
		cout << (char)1;
		Sleep(250);

	}
	SetConsoleCursorPosition(h, Arthas);
	cout << " ";


	while (true)
	{
		if (_kbhit())
		{
			int code = _getch();

			if (code == 224)
			{
				code = _getch();
			}

			//удаление персонажа в старых кординатах------------------
			SetConsoleCursorPosition(h, player);
			cout << " ";

			if (code == 72 && level[player.Y - 1][player.X] != 1)
			{
				player.Y--;
			}
			else if (code == 80 && level[player.Y + 1][player.X] != 1)
			{
				player.Y++;
			}
			else if (code == 75 && level[player.Y][player.X - 1] != 1)
			{
				player.X--;
			}
			else if (code == 77 && level[player.Y][player.X + 1] != 1)
			{
				player.X++;
			}

			//показ персонажа в новом месте---------------------------
			SetConsoleCursorPosition(h, player);
			SetConsoleTextAttribute(h, 9);
			cout << (char)1;

			if (player.Y == Exit1.Y - 1 &&
				player.X == Exit1.X ||
				player.Y == Exit2.Y - 1 &&
				player.X == Exit2.X)
			{
				system("cls");
				ShowLevel();
			}
		}
	}
}

