#include "Headers/Global.h"
#include "Headers/Wasted.h"
#include "Headers/Boss1.h"
#include "Headers/Hub.h"

//LEVEL MUSIC=================================================
DWORD WINAPI Music_Game(void* param)
{
	PlaySoundA("Sounds/level_music.WAV", NULL, SND_ASYNC | SND_LOOP);
	return 0;
}
//============================================================

void ShowLevel()
{
	extern int hp;
	extern int money;
	extern int color;
	bool key = false;

	CONSOLE_FONT_INFOEX font;

	font.cbSize = sizeof(font);
	font.dwFontSize.Y = 30;
	font.FontFamily = FF_DONTCARE;
	font.FontWeight = FW_NORMAL;

	SetCurrentConsoleFontEx(h, 0, &font);

	MoveWindow(GetConsoleWindow(), 220, 80, 1520, 900, true);

	CreateThread(0, 0, Music_Game, 0, 0, 0);
	srand(time(0));



	int CoinPosX = rand() % 40;
	int CoinPosY = rand() % 13;

	int KeyPosX = rand() % 40;
	int KeyPosY = rand() % 13;

	int HealPosX = rand() % 40;
	int HealPosY = rand() % 13;

	const int rows = 15;
	const int cols = 50;


	int level[rows][cols] = {};


	// 0 - коридор 
	// 1 - стена
	// 2 - граница
	// 3 - враг
	// 4 - ключ
	// 5 - дверь
	// 6 - аптечка
	// 7 - монетка


	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			level[y][x] = rand() % 4; // остатки от деления 0 1 2 3

			if (level[y][x] == 3) // если рандомно загенерился враг
			{
				int probability = rand() % 15; // 0 1 2 3 4 5 6 7 8 9
				if (probability > 0) level[y][x] = 0; // превращаем врага в коридор в 90% случаев
			}
			if (level[y][x] == 1) // если в лабиринте сгенерировалась стена
			{
				int probability = rand() % 2; // 0...1, если выпало 0 - стена останется, останется только половина стен
				if (probability != 0) // убираем стену
				{
					level[y][x] = 0; // на место стены ставим коридор
				}
			}

			if (x == KeyPosX + 1 && y == KeyPosY + 1)
			{
				level[y][x] = 4; // ключ
			}

			if (x == cols - 2 && y == rows - 3)
			{
				level[y][x] = 5;
			}

			if (x == 0 || y == 0 || x == cols - 1 || y == rows - 1)
			{
				level[y][x] = 1; // границы уровня
			}

			//выход и вход в уровень не будут застроенны
			if (x == cols - 2 && y == rows - 3 ||
				x == cols - 2 && y == rows - 4 ||
				x == cols - 2 && y == rows - 2 ||
				x == 2 && y == 2 ||
				x == 1 && y == 2 ||
				x == 2 && y == 1)
			{
				level[y][x] = 0;
			}

			if (x == HealPosX + 1 && y == HealPosY + 1)
			{
				level[y][x] = 6; // аптечка
			}

			if (x == CoinPosX + 1 && y == CoinPosY + 1)
			{
				level[y][x] = 7; // монетка
			}
		}
	}

	//показ лабиринта ----------------------------------

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
				switch (color)
				{
				case 0:
					SetConsoleTextAttribute(h, 8); // серый 
					break;
				case 1:
					SetConsoleTextAttribute(h, 7); // белый
					break;
				case 2:
					SetConsoleTextAttribute(h, 14); // желтый
					break;
				case 3:
					SetConsoleTextAttribute(h, 3); // синий
					break;
				}

				cout << (char)219;
			}
			else if (level[y][x] == 2)
			{
				SetConsoleTextAttribute(h, 14);
				cout << " ";
			}
			else if (level[y][x] == 3)
			{
				SetConsoleTextAttribute(h, 12);
				cout << (char)1;
			}
			else if (level[y][x] == 4)
			{
				SetConsoleTextAttribute(h, 6);
				cout << (char)20;
			}
			if (level[y][x] == 6)
			{
				SetConsoleTextAttribute(h, 4);
				cout << (char)3;
			}
			if (level[y][x] == 7)
			{
				SetConsoleTextAttribute(h, 6);
				cout << (char)36;
			}

		}
		cout << "\n";
	}
	cout << "\n";

	COORD exit;
	exit.X = cols - 1;
	exit.Y = rows - 3;
	SetConsoleCursorPosition(h, exit);
	SetConsoleTextAttribute(h, 15);
	cout << (char)186;

	//характеристики ----------------------------------

	COORD stats;
	stats.X = cols + 2;
	stats.Y = 4;
	SetConsoleCursorPosition(h, stats);
	SetConsoleTextAttribute(h, 12);
	cout << "-==|Health: " << setw(5) << hp << (char)3 << "|==-";

	stats.Y = 1;
	SetConsoleCursorPosition(h, stats);
	SetConsoleTextAttribute(h, 15);
	cout << "-==|Experience: " << setw(1) << experience << (char)21 << "|==-";

	stats.Y = 7;
	SetConsoleCursorPosition(h, stats);
	SetConsoleTextAttribute(h, 14);
	cout << "-==|Money:  " << setw(5) << money << (char)36 << "|==-";


	//управление ----------------------------------

	COORD player;
	player.X = 1;
	player.Y = 1;

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

			// подбор ключа-------------------------------------------
			if (level[player.Y][player.X] == 4)
			{
				key = true;
				level[KeyPosY + 1][KeyPosX + 1] = 0;

				COORD showKey;
				showKey.X = cols + 2;
				showKey.Y = 8;

				for (int y = 8; y <= 12; y++)
				{
					for (int x = cols + 3; x < cols + 19; x++)
					{
						if (x <= cols + 7 && y == 10 ||
							x == cols + 3 && y == 11 || x >= cols + 7 && y == 11 ||
							x <= cols + 7 && y == 12 || x == cols + 14 && y == 12 || x == cols + 17 && y == 12)
						{
							showKey.X = x;
							showKey.Y = y;
							SetConsoleCursorPosition(h, showKey);

							SetConsoleTextAttribute(h, 6);
							cout << (char)219;
						}
					}
				}
			}
			// подбор аптечки-------------------------------------------
			if (level[player.Y][player.X] == 6)
			{
				hp = hp_max;
				// -------------------------------------------------------
				int heal = rand() % 11; // random для размера аптеки

				if (heal <= 5) // small heal
				{
					COORD Heal_txt;
					Heal_txt.X = 5;
					Heal_txt.Y = rows + 1;

					SetConsoleCursorPosition(h, Heal_txt);
					SetConsoleTextAttribute(h, 2);

					string txt_heal = "You got small heal ";

					for (int i = 0; i < txt_heal.length(); i++)
					{
						Sleep(50);
						cout << txt_heal[i];
					}
					cout << char(30);

					SetConsoleCursorPosition(h, Heal_txt);
					SetConsoleTextAttribute(h, 0);

					for (int i = 0; i < txt_heal.length() + 1; i++)
					{
						Sleep(50);
						cout << " ";
					}

					small_heal++;
				}

				else if (heal >= 6 && heal <= 9) // medium heal
				{
					COORD Heal_txt;
					Heal_txt.X = 5;
					Heal_txt.Y = rows + 1;

					SetConsoleCursorPosition(h, Heal_txt);
					SetConsoleTextAttribute(h, 2);

					string txt_heal = "You got medium heal ";

					for (int i = 0; i < txt_heal.length(); i++)
					{
						Sleep(50);
						cout << txt_heal[i];
					}
					cout << char(30);

					SetConsoleCursorPosition(h, Heal_txt);
					SetConsoleTextAttribute(h, 0);

					for (int i = 0; i < txt_heal.length() + 1; i++)
					{
						Sleep(50);
						cout << " ";
					}

					medium_heal++;
				}

				else if (heal == 10) // big heal
				{
					COORD Heal_txt;
					Heal_txt.X = 5;
					Heal_txt.Y = rows + 1;

					SetConsoleCursorPosition(h, Heal_txt);
					SetConsoleTextAttribute(h, 2);

					string txt_heal = "You got big heal ";

					for (int i = 0; i < txt_heal.length(); i++)
					{
						Sleep(50);
						cout << txt_heal[i];
					}
					cout << char(30);

					SetConsoleCursorPosition(h, Heal_txt);
					SetConsoleTextAttribute(h, 0);

					for (int i = 0; i < txt_heal.length() + 1; i++)
					{
						Sleep(50);
						cout << " ";
					}

					large_heal++;
				}

				// ---------------------------------------------------------------
				level[HealPosY + 1][HealPosX + 1] = 0; // превращает аптеку в коридор  

				COORD Heal_txt;
				Heal_txt.X = 5;
				Heal_txt.Y = rows + 1;

				SetConsoleCursorPosition(h, Heal_txt);
				SetConsoleTextAttribute(h, 2);

				string txt_heal = "Health restored ";

				for (int i = 0; i < txt_heal.length(); i++)
				{
					Sleep(50);
					cout << txt_heal[i];
				}
				cout << char(30);

				SetConsoleCursorPosition(h, Heal_txt);
				SetConsoleTextAttribute(h, 0);

				for (int i = 0; i < txt_heal.length() + 1; i++)
				{
					Sleep(50);
					cout << " ";
				}

				stats.Y = 4;
				SetConsoleCursorPosition(h, stats);
				SetConsoleTextAttribute(h, 12);
				cout << "-==|Health: " << setw(5) << hp << (char)3 << "|==-";

			}

			// подбор монетки-------------------------------------------
			if (level[player.Y][player.X] == 7)
			{
				money += (50 + rand() % 150) + luck;
				level[CoinPosY + 1][CoinPosX + 1] = 0;

				COORD Coin_txt;
				Coin_txt.X = 5;
				Coin_txt.Y = rows + 1;

				SetConsoleCursorPosition(h, Coin_txt);
				SetConsoleTextAttribute(h, 2);

				string txt_coin = "Money received ";

				for (int i = 0; i < txt_coin.length(); i++)
				{
					Sleep(50);
					cout << txt_coin[i];
				}
				cout << char(30);

				SetConsoleCursorPosition(h, Coin_txt);
				SetConsoleTextAttribute(h, 0);

				for (int i = 0; i < txt_coin.length() + 1; i++)
				{
					Sleep(50);
					cout << " ";
				}

				stats.Y = 7;
				SetConsoleCursorPosition(h, stats);
				SetConsoleTextAttribute(h, 14);
				cout << "-==|Money:  " << setw(5) << money << (char)36 << "|==-";


			}

			// выход из уровня----------------------------------------
			if (player.Y == exit.Y && player.X == exit.X - 1 && key == true)
			{
				system("cls");
				break;
			}

			//пересечение с врагом------------------------------------
			if (level[player.Y][player.X] == 3)
			{
				hp = 0;
				stats.X = cols + 2;
				stats.Y = 4;
				SetConsoleCursorPosition(h, stats);
				SetConsoleTextAttribute(h, 12);
				cout << "-==|Health: " << setw(5) << hp << (char)3 << "|==-"; // обновляем хп

				level[player.Y][player.X] = 3;  // убиваем героя
				break;
			}
		}
		else //движение врагов---------------------------
		{
			Sleep(20);

			COORD enemy_pos[1000];
			int enemy_count = 0;

			for (int y = 0; y < rows; y++) //подсчет врагов-----------------------
			{
				for (int x = 0; x < cols; x++)
				{
					if (level[y][x] == 3)
					{
						enemy_pos[enemy_count].X = x;
						enemy_pos[enemy_count].Y = y;
						enemy_count++;
					}
				}
			}

			for (int i = 0; i < enemy_count; i++)
			{
				int move_direction = rand() % 75; // 0-left, 1-right, 2-up, 3-down

				if (move_direction == 0 &&
					level[enemy_pos[i].Y][enemy_pos[i].X - 1] != 1 &&
					level[enemy_pos[i].Y][enemy_pos[i].X - 1] != 3 &&
					level[enemy_pos[i].Y][enemy_pos[i].X - 1] != 4 &&
					level[enemy_pos[i].Y][enemy_pos[i].X - 1] != 6 &&
					level[enemy_pos[i].Y][enemy_pos[i].X - 1] != 7)
				{
					//удаление врага в старых кординатах------------------
					COORD temp = enemy_pos[i];
					SetConsoleCursorPosition(h, temp);
					cout << " ";
					level[enemy_pos[i].Y][enemy_pos[i].X] = 0;

					// перемещаем врага в новую позицию------------------------
					temp.X = enemy_pos[i].X - 1;
					temp.Y = enemy_pos[i].Y;
					SetConsoleCursorPosition(h, temp);
					SetConsoleTextAttribute(h, 12);

					cout << (char)1;
					level[enemy_pos[i].Y][enemy_pos[i].X - 1] = 3;
				}


				else if (move_direction == 1 &&
					level[enemy_pos[i].Y][enemy_pos[i].X + 1] != 1 &&
					level[enemy_pos[i].Y][enemy_pos[i].X + 1] != 3 &&
					level[enemy_pos[i].Y][enemy_pos[i].X + 1] != 4 &&
					level[enemy_pos[i].Y][enemy_pos[i].X + 1] != 6 &&
					level[enemy_pos[i].Y][enemy_pos[i].X + 1] != 7)
				{
					COORD temp = enemy_pos[i];
					SetConsoleCursorPosition(h, temp);
					cout << " ";
					level[enemy_pos[i].Y][enemy_pos[i].X] = 0;


					temp.X = enemy_pos[i].X + 1;
					temp.Y = enemy_pos[i].Y;
					SetConsoleCursorPosition(h, temp);
					SetConsoleTextAttribute(h, 12);

					cout << (char)1;
					level[enemy_pos[i].Y][enemy_pos[i].X + 1] = 3;
				}


				else if (move_direction == 2 &&
					level[enemy_pos[i].Y - 1][enemy_pos[i].X] != 1 &&
					level[enemy_pos[i].Y - 1][enemy_pos[i].X] != 3 &&
					level[enemy_pos[i].Y - 1][enemy_pos[i].X] != 4 &&
					level[enemy_pos[i].Y - 1][enemy_pos[i].X] != 6 &&
					level[enemy_pos[i].Y - 1][enemy_pos[i].X] != 7)
				{
					COORD temp = enemy_pos[i];
					SetConsoleCursorPosition(h, temp);
					cout << " ";
					level[enemy_pos[i].Y][enemy_pos[i].X] = 0;


					temp.X = enemy_pos[i].X;
					temp.Y = enemy_pos[i].Y - 1;
					SetConsoleCursorPosition(h, temp);
					SetConsoleTextAttribute(h, 12);

					cout << (char)1;
					level[enemy_pos[i].Y - 1][enemy_pos[i].X] = 3;
				}


				else if (move_direction == 3 &&
					level[enemy_pos[i].Y + 1][enemy_pos[i].X] != 1 &&
					level[enemy_pos[i].Y + 1][enemy_pos[i].X] != 3 &&
					level[enemy_pos[i].Y + 1][enemy_pos[i].X] != 4 &&
					level[enemy_pos[i].Y + 1][enemy_pos[i].X] != 6 &&
					level[enemy_pos[i].Y + 1][enemy_pos[i].X] != 7)
				{
					COORD temp = enemy_pos[i];
					SetConsoleCursorPosition(h, temp);
					cout << " ";
					level[enemy_pos[i].Y][enemy_pos[i].X] = 0;


					temp.X = enemy_pos[i].X;
					temp.Y = enemy_pos[i].Y + 1;
					SetConsoleCursorPosition(h, temp);
					SetConsoleTextAttribute(h, 12);

					cout << (char)1;
					level[enemy_pos[i].Y + 1][enemy_pos[i].X] = 3;
				}
			}
		}
	}

	if (player.Y == exit.Y && player.X == exit.X - 1 && key == true)
	{
		system("cls");
		ShowBoss1();
	}
	if (hp <= 0)
	{
		string deat_txt = "WASTED";
		bool isDeath = false;
		int indent = 8;

		system("cls");
		Wasted(deat_txt, indent, isDeath);
	}

}



