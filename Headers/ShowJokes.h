#include "Headers/Global.h"

//ARTHAS VOL==================================================
DWORD WINAPI Arthas_vol3(void* param)
{
	PlaySoundA("Sounds/Arthas_vol3.WAV", NULL, SND_NODEFAULT | SND_ASYNC);
	return 0;
}
//============================================================

void ShowJokes(COORD jokes, COORD doneArthas, COORD player, int cols, int rows)
{
	SetConsoleCursorPosition(h, player); // игрок не будет проподать после перехода к меню магазина
	cout << (char)1;

	COORD artArthas{};
	artArthas.X;
	artArthas.Y;

	for (artArthas.Y = doneArthas.Y; artArthas.Y < doneArthas.Y + 10; artArthas.Y++) {
		for (artArthas.X = doneArthas.X; artArthas.X < doneArthas.X + 20; artArthas.X++) {

			if (artArthas.Y == doneArthas.Y && artArthas.X > doneArthas.X + 5 && artArthas.X < doneArthas.X + 18 ||
				artArthas.Y == doneArthas.Y + 1 && artArthas.X > doneArthas.X + 3 && artArthas.X < doneArthas.X + 10 ||
				artArthas.Y == doneArthas.Y + 1 && artArthas.X > doneArthas.X + 15 && artArthas.X < doneArthas.X + 20 ||
				artArthas.Y >= doneArthas.Y + 2 && artArthas.Y <= doneArthas.Y + 3 && artArthas.X > doneArthas.X + 1 && artArthas.X < doneArthas.X + 6 ||
				artArthas.Y >= doneArthas.Y + 2 && artArthas.X > doneArthas.X + 17 && artArthas.X < doneArthas.X + 20 ||
				artArthas.Y >= doneArthas.Y + 4 && artArthas.Y <= doneArthas.Y + 5 && artArthas.X > doneArthas.X - 1 && artArthas.X < doneArthas.X + 4 ||
				artArthas.Y >= doneArthas.Y + 6 && artArthas.Y <= doneArthas.Y + 8 && artArthas.X > doneArthas.X - 1 && artArthas.X < doneArthas.X + 6 ||
				artArthas.Y == doneArthas.Y + 9 && artArthas.X > doneArthas.X - 1 && artArthas.X < doneArthas.X + 8)
			{

				SetConsoleTextAttribute(h, 6);
			}

			else if (artArthas.Y == doneArthas.Y + 3 && artArthas.X >= doneArthas.X + 8 && artArthas.X <= doneArthas.X + 9 ||
				artArthas.Y == doneArthas.Y + 3 && artArthas.X >= doneArthas.X + 14 && artArthas.X <= doneArthas.X + 15)
			{
				SetConsoleTextAttribute(h, 15);
			}

			else if (artArthas.Y == doneArthas.Y + 4 && artArthas.X >= doneArthas.X + 8 && artArthas.X <= doneArthas.X + 9 ||
				artArthas.Y == doneArthas.Y + 4 && artArthas.X >= doneArthas.X + 14 && artArthas.X <= doneArthas.X + 15)
			{
				SetConsoleTextAttribute(h, 9);
			}

			else if (artArthas.Y >= doneArthas.Y + 4 && artArthas.Y <= doneArthas.Y + 5 && artArthas.X >= doneArthas.X + 12 && artArthas.X <= doneArthas.X + 13 ||
				artArthas.Y == doneArthas.Y + 6 && artArthas.X >= doneArthas.X + 12 && artArthas.X <= doneArthas.X + 15)
			{
				SetConsoleTextAttribute(h, 12);
			}

			else if (artArthas.Y == doneArthas.Y + 8 && artArthas.X >= doneArthas.X + 12 && artArthas.X <= doneArthas.X + 15 ||
				artArthas.Y == doneArthas.Y && artArthas.X <= doneArthas.X + 20 ||
				artArthas.Y == doneArthas.Y + 1 && artArthas.X <= doneArthas.X + 6 ||
				artArthas.Y == doneArthas.Y + 2 && artArthas.X <= doneArthas.X + 4 ||
				artArthas.Y == doneArthas.Y + 3 && artArthas.X <= doneArthas.X + 4)
			{
				SetConsoleTextAttribute(h, 0);
			}

			else {
				SetConsoleTextAttribute(h, 14);
			}


			SetConsoleCursorPosition(h, artArthas);
			cout << char(219);
		}
	}


	SetConsoleCursorPosition(h, jokes);

	CreateThread(0, 0, Arthas_vol3, 0, 0, 0);

	SetConsoleTextAttribute(h, 6);
	cout << "Arthur Menethil: ";
	SetConsoleTextAttribute(h, 15);
	string jokeArthas[5] = {
		"(An elf walks into a bar with a parrot on his shoulder.)\n\t\t\t\t\t\tBartender: Where did you buy it?\n\t\t\t\t\t\tParrot: Who are we, who are we? Who are you addressing\n\t\t\t\t\t\t\tin the plural!? I'm the only one here!",

	};
	for (int i = 0; i < jokeArthas[0].length(); i++)
	{
		Sleep(38);
		cout << jokeArthas[0][i];
	}

	Sleep(4000);
}
