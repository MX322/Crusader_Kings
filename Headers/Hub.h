#include "Headers/Global.h"
#include "Headers/ClearAll.h"
#include "Headers/ShowShop.h"
#include "Headers/ShowUpgrade.h"
#include "Headers/ShowJokes.h"

//HUB SOUNDS==================================================
DWORD WINAPI Majula(void* param)
{
	PlaySoundA("Sounds/Majula.WAV", NULL, SND_ASYNC | SND_LOOP);
	return 0;
}
//============================================================

void ShowHub()
{
	CreateThread(0, 0, Majula, 0, 0, 0);
	CONSOLE_FONT_INFOEX font;

	font.cbSize = sizeof(font);
	font.dwFontSize.Y = 25;
	font.FontFamily = FF_DONTCARE;
	font.FontWeight = FW_NORMAL;

	SetCurrentConsoleFontEx(h, 0, &font);

	MoveWindow(GetConsoleWindow(), 60, 80, 1800, 900, true);

	// -----------------------------

	extern int hp;
	extern int money;
	extern int experience;

	const int rows = 20;
	const int cols = 80;

	COORD Chapter;
	Chapter.X = 50;
	Chapter.Y = 3;

	SetConsoleCursorPosition(h, Chapter);
	SetConsoleTextAttribute(h, 15);

	string chapter_txt = "Cursed Majula Garden ";

	for (int i = 0; i < chapter_txt.length(); i++)
	{
		Sleep(50);
		cout << chapter_txt[i];
	}
	SetConsoleTextAttribute(h, 2);
	cout << char(5);
	Sleep(500);

	SetConsoleCursorPosition(h, Chapter);
	SetConsoleTextAttribute(h, 0);

	for (int i = 0; i < chapter_txt.length() + 1; i++)
	{
		Sleep(50);
		cout << " ";
	}

	system("cls");

	int level[rows][cols] = {};


	// 0 - коридор 
	// 1 - стена
	// 2 - магазин
	// 3 - прокачка
	// 4 - деревья ♣
	// 5 - деревья ♠
	// 6 - артас

	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{

			if (x == 0 || y == 0 || x == cols - 1 || y == rows - 1 ||
				// прокачка
				y > rows / 2 + (rows / 5) && x == cols / 2 || y > rows / 2 + (rows / 5) && x == (cols / 2) / 2 - 1 ||
				y == rows / 2 + 4 && x > (cols / 2) / 2 - 1 && x < cols / 2 ||

				// магазин
				y < rows / 4 && x == cols / 2 - 2 || y < rows / 4 && x == (cols / 2) + (cols / 2) / 2 - 1 ||
				y == rows / 2 - 5 && x > cols / 2 - 2 && x < (cols / 2) + (cols / 2) / 2 - 1 ||

				// выход
				y == (rows / 2) + (rows / 2) / 3 && x >(cols / 2) * 1.6 ||
				y == (rows / 2) - (rows / 2) / 3 && x >(cols / 2) * 1.6)
			{
				level[y][x] = 1; // границы уровня
			}


			// магазин 

			if (x == ((cols / 2 + 2) + ((cols / 2) + (cols / 2) / 2) - 3) / 2 - 2 && y == 1 ||
				x == ((cols / 2 + 2) + ((cols / 2) + (cols / 2) / 2) - 3) / 2 - 1 && y == 1 ||
				x == ((cols / 2 + 2) + ((cols / 2) + (cols / 2) / 2) - 3) / 2 && y == 1 ||
				x == ((cols / 2 + 2) + ((cols / 2) + (cols / 2) / 2) - 3) / 2 + 1 && y == 1)
			{
				level[y][x] = 2;
			}

			// прокачка 
			if (x == ((cols / 2) / 2 - 1 + cols / 2) / 2 && y == rows - 2 ||
				x == ((cols / 2) / 2 - 1 + cols / 2) / 2 - 1 && y == rows - 2 ||
				x == ((cols / 2) / 2 - 1 + cols / 2) / 2 + 1 && y == rows - 2 ||
				x == ((cols / 2) / 2 - 1 + cols / 2) / 2 + 2 && y == rows - 2)
			{
				level[y][x] = 3;
			}


			// деревья - ♣
			if (x == 15 && y == 1 || x == 17 && y == 3 || x == 27 && y == 4 || x == 31 && y == 5 || x == 22 && y == 4 || x == 5 && y == 5 || x == 2 && y == 4 ||
				x == 15 && y == rows - 2 || x == 10 && y == rows - 5 || x == 5 && y == rows - 2 || x == 2 && y == rows - 4 ||
				x == cols - 15 && y == 1 || x == cols - 10 && y == 4 || x == cols - 5 && y == 1 || x == cols - 2 && y == 3 ||
				x == cols - 15 && y == rows - 2 || x == cols - 17 && y == rows - 4 || x == cols - 27 && y == rows - 5 || x == cols - 31 && y == rows - 6 || x == cols - 22 && y == rows - 5 || x == cols - 5 && y == rows - 6 || x == cols - 2 && y == rows - 5)
			{
				level[y][x] = 4;
			}

			// деревья - ♠
			if (x == 15 && y == 5 || x == 24 && y == 2 || x == 33 && y == 1 || x == 8 && y == 3 || x == 10 && y == 1 || x == 3 && y == 2 ||
				x == 10 && y == rows - 3 || x == 8 && y == rows - 6 || x == 17 && y == rows - 6 || x == 14 && y == rows - 4 ||
				x == cols - 10 && y == 2 || x == cols - 8 && y == 5 || x == cols - 17 && y == 5 || x == cols - 14 && y == 3 ||
				x == cols - 15 && y == rows - 6 || x == cols - 24 && y == rows - 3 || x == cols - 33 && y == rows - 2 || x == cols - 8 && y == rows - 4 || x == cols - 10 && y == rows - 2 || x == cols - 3 && y == rows - 3)
			{
				level[y][x] = 5;
			}

			// Артас
			if (x == 5 && y == 5) 
			{
				level[y][x] = 6;
			}

			// пустые проемы
			if (
				y < (rows / 2) + (rows / 2) / 3 && y >(rows / 2) - (rows / 2) / 3 && x == cols - 1 ||
				x == ((cols / 2) / 2 - 1 + cols / 2) / 2 && y == rows / 2 + (rows / 5) ||
				x == ((cols / 2) / 2 - 1 + cols / 2) / 2 - 1 && y == rows / 2 + (rows / 5) ||
				x == ((cols / 2) / 2 - 1 + cols / 2) / 2 + 1 && y == rows / 2 + (rows / 5) ||
				x == ((cols / 2) / 2 - 1 + cols / 2) / 2 + 2 && y == rows / 2 + (rows / 5) ||
				x == ((cols / 2 + 2) + ((cols / 2) + (cols / 2) / 2) - 3) / 2 - 2 && y == rows / 4 ||
				x == ((cols / 2 + 2) + ((cols / 2) + (cols / 2) / 2) - 3) / 2 - 1 && y == rows / 4 ||
				x == ((cols / 2 + 2) + ((cols / 2) + (cols / 2) / 2) - 3) / 2 && y == rows / 4 ||
				x == ((cols / 2 + 2) + ((cols / 2) + (cols / 2) / 2) - 3) / 2 + 1 && y == rows / 4)
			{
				level[y][x] = 0;
			}
		}
	}

	//показ лабиринта ----------------------------------

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{

			if (level[y][x] == 0)
			{
				cout << " ";
			}
			else if (level[y][x] == 1 || x == 0 || y == 0 || x == cols - 1 || y == rows - 1)
			{
				SetConsoleTextAttribute(h, 6);
				cout << (char)219;
			}
			else if (level[y][x] == 2 || level[y][x] == 3)
			{
				SetConsoleTextAttribute(h, 14);
				cout << (char)254;
			}
			else if (level[y][x] == 4)
			{
				SetConsoleTextAttribute(h, 10);
				cout << (char)5;
			}
			else if (level[y][x] == 5)
			{
				SetConsoleTextAttribute(h, 10);
				cout << (char)6;
			}
			else if (level[y][x] == 6)
			{
				SetConsoleTextAttribute(h, 6);
				cout << char(1);
			}
		}
		cout << "\n";
	}
	cout << "\n";

	COORD doneArthas{};
	doneArthas.X = 7;
	doneArthas.Y = rows + 3;


	//анекдоты артэса
	COORD jokes;
	jokes.X = 30;
	jokes.Y = rows + 5;

	//STATS----------------------------------------

	COORD stats;
	stats.X = cols + 2;
	stats.Y = 1;
	SetConsoleCursorPosition(h, stats);
	SetConsoleTextAttribute(h, 12);
	cout << "-==|Health: " << hp << (char)3 << setw(10) << "|==-";

	stats.Y = 4;
	SetConsoleCursorPosition(h, stats);
	SetConsoleTextAttribute(h, 15);
	cout << "-==|Experience: " << experience << (char)21 << setw(6) << "|==-";

	stats.Y = 7;
	SetConsoleCursorPosition(h, stats);
	SetConsoleTextAttribute(h, 14);
	cout << "-==|Money: " << money << (char)36 << setw(11) << "|==-";


	//меню магазина -------------------------------

	COORD shop;
	shop.X = cols + 3;
	shop.Y = rows / 2;

	//меню upgrade -------------------------------

	COORD upgrade;
	upgrade.X = cols + 3;
	upgrade.Y = rows / 2;

	//управление ----------------------------------


	COORD player;
	player.X = 2;
	player.Y = rows / 2;

	SetConsoleCursorPosition(h, player);
	SetConsoleTextAttribute(h, 9);
	cout << (char)1;

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

			if (code == 72
				&& level[player.Y - 1][player.X] != 1
				&& level[player.Y - 1][player.X] != 2
				&& level[player.Y - 1][player.X] != 3
				&& level[player.Y - 1][player.X] != 4
				&& level[player.Y - 1][player.X] != 5
				&& level[player.Y - 1][player.X] != 6)
			{
				player.Y--;
			}
			else if (code == 80
				&& level[player.Y + 1][player.X] != 1
				&& level[player.Y + 1][player.X] != 2
				&& level[player.Y + 1][player.X] != 3
				&& level[player.Y + 1][player.X] != 4
				&& level[player.Y + 1][player.X] != 5
				&& level[player.Y + 1][player.X] != 6)
			{
				player.Y++;
			}
			else if (code == 75
				&& level[player.Y][player.X - 1] != 1
				&& level[player.Y][player.X - 1] != 2
				&& level[player.Y][player.X - 1] != 3
				&& level[player.Y][player.X - 1] != 4
				&& level[player.Y][player.X - 1] != 5
				&& level[player.Y + 1][player.X] != 6)
			{
				player.X--;
			}
			else if (code == 77
				&& level[player.Y][player.X + 1] != 1
				&& level[player.Y][player.X + 1] != 2
				&& level[player.Y][player.X + 1] != 3
				&& level[player.Y][player.X + 1] != 4
				&& level[player.Y][player.X + 1] != 5
				&& level[player.Y + 1][player.X] != 6)
			{
				player.X++;
			}

			// магазин

			if (code == 72
				&& level[player.Y - 1][player.X] == 2)
			{
				ShowShop(shop, player, stats, cols, rows);
			}

			// прокачка

			if (code == 72
				&& level[player.Y - 1][player.X] == 3)
			{
				//code...
			}
			else if (code == 80
				&& level[player.Y + 1][player.X] == 3)
			{
				ShowUpgrade(upgrade, player, stats, cols, rows);
			}
			else if (code == 75
				&& level[player.Y][player.X - 1] == 3)
			{
				//code...
			}
			else if (code == 77
				&& level[player.Y][player.X + 1] == 3)
			{
				//code...
			}


			else if (code == 77 && player.X + 1 == cols)
			{
				system("cls");
				ShowLevel();
			}

			else if (code == 27)
			{
				system("cls");
				ShowMenu();
			}

			//Arthas
			if (code == 72
				&& level[player.Y - 1][player.X] == 6)
			{
				ShowJokes(jokes, doneArthas, player, cols, rows);
				Clear(23, 33, 0, 105);
				CreateThread(0, 0, Majula, 0, 0, 0);
			}
			else if (code == 80
				&& level[player.Y + 1][player.X] == 6)
			{
				ShowJokes(jokes, doneArthas, player, cols, rows);
				Clear(23, 33, 0, 105);
				CreateThread(0, 0, Majula, 0, 0, 0);
			}
			else if (code == 75
				&& level[player.Y][player.X - 1] == 6)
			{
				ShowJokes(jokes, doneArthas, player, cols, rows);
				Clear(23, 33, 0, 105);
				CreateThread(0, 0, Majula, 0, 0, 0);
			}
			else if (code == 77
				&& level[player.Y][player.X + 1] == 6)
			{
				ShowJokes(jokes, doneArthas, player, cols, rows);
				Clear(23, 33, 0, 105);
				CreateThread(0, 0, Majula, 0, 0, 0);
			}

			//показ персонажа в новом месте---------------------------
			SetConsoleCursorPosition(h, player);
			SetConsoleTextAttribute(h, 9);
			cout << (char)1;
		}
	}
	Sleep(10000);
}



