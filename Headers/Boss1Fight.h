#include "Headers/Global.h"
#include "Headers/ShowInventory.h"
#include "Headers/ShowLights.h"
#include "Headers/ClearBoss.h"

//BOSS FIGHT MUSIC============================================
DWORD WINAPI Boss_vol1(void* param)
{
	PlaySoundA("Sounds/Boss1_ost.WAV", NULL, SND_ASYNC | SND_LOOP);
	return 0;
}
//============================================================

//BOSS WIN PHRASE=============================================
DWORD WINAPI Boss_win1(void* param)
{
	PlaySoundA("Sounds/Boss_vol/boss_win1.WAV", NULL, SND_ASYNC | SND_NODEFAULT);
	return 0;
}
DWORD WINAPI Boss_win2(void* param)
{
	PlaySoundA("Sounds/Boss_vol/boss_win2.WAV", NULL, SND_ASYNC | SND_NODEFAULT);
	return 0;
}
DWORD WINAPI Boss_win3(void* param)
{
	PlaySoundA("Sounds/Boss_vol/boss_win3.WAV", NULL, SND_ASYNC | SND_NODEFAULT);
	return 0;
}
//============================================================

//BOSS LOSE PHRASE============================================
DWORD WINAPI Boss_lose1(void* param)
{
	PlaySoundA("Sounds/Boss_vol/boss_lose1.WAV", NULL, SND_ASYNC | SND_NODEFAULT);
	return 0;
}
DWORD WINAPI Boss_lose2(void* param)
{
	PlaySoundA("Sounds/Boss_vol/boss_lose2.WAV", NULL, SND_ASYNC | SND_NODEFAULT);
	return 0;
}
DWORD WINAPI Boss_lose3(void* param)
{
	PlaySoundA("Sounds/Boss_vol/boss_lose3.WAV", NULL, SND_ASYNC | SND_NODEFAULT);
	return 0;
}
//============================================================

void BossFight()
{
	srand(time(NULL));
	int deal_dmg;

	CONSOLE_FONT_INFOEX font;

	font.cbSize = sizeof(font);
	font.dwFontSize.Y = 27;
	SetCurrentConsoleFontEx(h, 0, &font);

	MoveWindow(GetConsoleWindow(), 200, 80, 1520, 900, true);

	COORD artArthas;
	artArthas.X;
	artArthas.Y;
	//y + 1
	//x + 40

	for (artArthas.Y = 4; artArthas.Y < 11; artArthas.Y++)
	{
		for (artArthas.X = 42; artArthas.X < 54; artArthas.X++)
		{
			if (artArthas.Y == 4 && artArthas.X >= 45 && artArthas.X <= 50 ||
				artArthas.Y == 9 && artArthas.X >= 45 && artArthas.X <= 46 ||
				artArthas.Y >= 5 && artArthas.X >= 43 && artArthas.X <= 44 ||
				artArthas.Y == 5 && artArthas.X >= 51 && artArthas.X <= 52 ||
				artArthas.Y == 9 && artArthas.X >= 51 && artArthas.X <= 52 ||
				artArthas.Y >= 7 && artArthas.X <= 2)
			{
				switch (color)
				{
				case 0:
					SetConsoleTextAttribute(h, 14); // желтый
					break;
				case 1:
					SetConsoleTextAttribute(h, 6); // рыжий
					break;
				case 2:
					SetConsoleTextAttribute(h, 8); // серый
					break;
				case 3:
					SetConsoleTextAttribute(h, 7); // белый
					break;
				}

			}
			else if (artArthas.Y == 6 && artArthas.X == 46 ||
				artArthas.Y == 7 && artArthas.X == 46 ||
				artArthas.Y == 6 && artArthas.X == 50 ||
				artArthas.Y == 7 && artArthas.X == 50)
			{
				SetConsoleTextAttribute(h, 4); //зрачки
			}
			else if (artArthas.Y == 6 && artArthas.X == 47 ||
				artArthas.Y == 6 && artArthas.X == 51)
			{
				SetConsoleTextAttribute(h, 0);// не зрачки
			}
			else if (artArthas.Y == 5 && artArthas.X >= 45 && artArthas.X <= 50 ||
				artArthas.Y == 6 && artArthas.X == 45 ||
				artArthas.Y == 6 && artArthas.X == 48 ||
				artArthas.Y == 6 && artArthas.X == 49 ||
				artArthas.Y == 6 && artArthas.X == 52 ||
				artArthas.Y == 7 && artArthas.X == 45 ||
				artArthas.Y == 7 && artArthas.X >= 47 && artArthas.X <= 49 ||
				artArthas.Y == 7 && artArthas.X >= 51 && artArthas.X <= 52 ||
				artArthas.Y == 8 && artArthas.X >= 45 && artArthas.X <= 51 ||
				artArthas.Y == 9 && artArthas.X >= 47 && artArthas.X <= 50 ||
				artArthas.Y == 10 && artArthas.X >= 45 && artArthas.X <= 51)
			{
				if (color == 3)
				{
					SetConsoleTextAttribute(h, 8); // кожа 8 ( 7 )
				}
				else
				{
					SetConsoleTextAttribute(h, 7); // кожа 8 ( 7 )
				}

			}
			else
			{
				SetConsoleTextAttribute(h, 0); // фон (прозрчный)
			}

			SetConsoleCursorPosition(h, artArthas);

			cout << char(219);
		}
	}

	// пафосные фразы босса---------------------------
	COORD Boss_txt;
	Boss_txt.X = 30;
	Boss_txt.Y = 12;

	COORD Narator_txt;
	Narator_txt.X = 36;
	Narator_txt.Y = 14;

	Sleep(1000);

	string boss_txt1 = "DiD y0u reAlLy ThInK abo0uT ruNNing aWay!?";

	SetConsoleCursorPosition(h, Boss_txt);
	SetConsoleTextAttribute(h, 15);
	for (int i = 0; i < boss_txt1.length(); i++)
	{
		Sleep(25);
		cout << boss_txt1[i];
	}
	Sleep(1000);

	SetConsoleCursorPosition(h, Boss_txt);
	SetConsoleTextAttribute(h, 0);
	for (int i = 0; i < boss_txt1.length(); i++)
	{
		Sleep(25);
		cout << " ";
	}

	CreateThread(0, 0, Boss_vol1, 0, 0, 0);

	// -----------------------------------------------



	// статы босса------------------------------------
	int boss_hp = (100 + rand() % 125) + 15;
	int boss_dmg = (rand() % 20) + dmg / 7;

	COORD stats_boss;
	stats_boss.X = 44;
	stats_boss.Y = 0;
	SetConsoleCursorPosition(h, stats_boss);
	SetConsoleTextAttribute(h, 4);
	cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187);

	stats_boss.Y = 1;
	SetConsoleCursorPosition(h, stats_boss);
	cout << char(186) << setw(4) << boss_hp << char(3) << setw(2) << char(186);

	stats_boss.Y = 2;
	SetConsoleCursorPosition(h, stats_boss);
	cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188);

	// -----------------------------------------------


	//статы игрока -----------------------------------
	COORD stats_player;
	stats_player.X = 65;
	stats_player.Y = 0;

	for (stats_player.Y; stats_player.Y <= 10; stats_player.Y++) // для боковой грани стат игрока
	{
		SetConsoleCursorPosition(h, stats_player);
		SetConsoleTextAttribute(h, 8);
		cout << char(186);
	}

	SetConsoleCursorPosition(h, stats_player);
	cout << char(200);
	for (int i = 0; i <= 50; i++) // для нижней грани стат игрока
	{
		cout << char(205);
	}

	// хп игрока
	stats_player.X = 68;
	stats_player.Y = 2;
	SetConsoleCursorPosition(h, stats_player);
	SetConsoleTextAttribute(h, 12);
	cout << "-==|Health: " << setw(5) << hp << (char)3 << "|==-";

	// броня игрока
	stats_player.Y = 4;
	SetConsoleCursorPosition(h, stats_player);
	SetConsoleTextAttribute(h, 7);
	cout << "-==|Armor: " << setw(6) << armor << (char)127 << "|==-";

	// урон игрока
	stats_player.Y = 6;
	SetConsoleCursorPosition(h, stats_player);
	SetConsoleTextAttribute(h, 4);
	cout << "-==|Damage: " << setw(5) << dmg << (char)15 << "|==-";

	// деньги игрока
	stats_player.Y = 8;
	SetConsoleCursorPosition(h, stats_player);
	SetConsoleTextAttribute(h, 6);
	cout << "-==|Money: " << setw(6) << money << (char)36 << "|==-";
	// -----------------------------------------------

	// координаты кнопок ---------------------------------------

	int beginX = 27;
	int beginY = 18;

	COORD buttons;
	buttons.X = beginX;
	buttons.Y = beginY;


	//вывод зеленого текста
	COORD WinTxt;
	WinTxt.X = 6;
	WinTxt.Y = 24;

	// открисовка граней кнопки --------------------------------


	// 1 кнопка -------------------------------

	for (int y = beginY; y < beginY + 3; y++)
	{
		for (int x = beginX; x < beginX + 11; x++)
		{
			if (y == beginY && x < beginX + 11 || // верхняя линия
				y < beginY + 3 && x == beginX || // левая линия
				y == beginY + 2 && x < beginX + 11 || // нижняя линия
				y < beginY + 3 && x == beginX + 10) // правая линия

			{
				buttons.X = x;
				buttons.Y = y;

				SetConsoleCursorPosition(h, buttons);
				SetConsoleTextAttribute(h, 4);

				cout << (char)219;
			}
		}
	}

	// 2 кнопка -------------------------------

	for (int y = beginY; y < beginY + 3; y++)
	{
		for (int x = beginX + 16; x < beginX + 27; x++)
		{
			if (y == beginY && x < beginX + 27 || // верхняя линия
				y < beginY + 3 && x == beginX + 16 || // левая линия
				y == beginY + 2 && x < beginX + 27 || // нижняя линия
				y < beginY + 3 && x == beginX + 26) // правая линия

			{
				buttons.X = x;
				buttons.Y = y;

				SetConsoleCursorPosition(h, buttons);
				SetConsoleTextAttribute(h, 8);

				cout << (char)219;
			}
		}
	}

	// 3 кнопка -------------------------------

	for (int y = beginY; y < beginY + 3; y++)
	{
		for (int x = beginX + 32; x < beginX + 43; x++)
		{
			if (y == beginY && x < beginX + 43 || // верхняя линия
				y < beginY + 3 && x == beginX + 32 || // левая линия
				y == beginY + 2 && x < beginX + 43 || // нижняя линия
				y < beginY + 3 && x == beginX + 42) // правая линия

			{
				buttons.X = x;
				buttons.Y = y;

				SetConsoleCursorPosition(h, buttons);
				SetConsoleTextAttribute(h, 8);

				cout << (char)219;
			}
		}
	}
	// ---------------------------------------------------------

	// координаты текста кнопок ---------------------------------------

	SetConsoleTextAttribute(h, 15);
	COORD buttonText;

	// text - FIGHT ----------

	buttonText.X = beginX + 3;
	buttonText.Y = beginY + 1;
	SetConsoleCursorPosition(h, buttonText);
	cout << "FIGHT";

	// text - ACT ------------

	buttonText.X = beginX + 20;
	buttonText.Y = beginY + 1;
	SetConsoleCursorPosition(h, buttonText);
	cout << "ACT";

	// text - ITEMS ----------

	buttonText.X = beginX + 35;
	buttonText.Y = beginY + 1;
	SetConsoleCursorPosition(h, buttonText);
	cout << "ITEMS";

	// ---------------------------------------------------------

	//курсор---------------------------------------------
	COORD cursor;
	cursor.X = beginX;
	cursor.Y = beginY;

	SetConsoleCursorPosition(h, cursor);
	//---------------------------------------------------



	while (true)
	{
		if (_kbhit())
		{
			SetConsoleCursorPosition(h, cursor);
			int code = _getch();

			// 13 - enter 27 - escape 32 - space up - 72 down - 80 right - 77 left - 75

			if (code == 224)
			{
				code = _getch();
			}

			// RIGHT ---------------------------------------------------------------------------------------
			if (code == 77 && cursor.X + 1 <= 50)
			{
				cursor.X += 16;
				cursor.Y = beginY;

				int next = cursor.X;
				int previous = cursor.X - 16;

				// новая кнопка - красная --------------------------
				for (int y = beginY; y < beginY + 3; y++)
				{
					for (int x = next; x < next + 11; x++)
					{
						if (y == beginY && x < next + 11 || // верхняя линия
							y < beginY + 3 && x == next || // левая линия
							y == beginY + 2 && x < next + 11 || // нижняя линия
							y < beginY + 3 && x == next + 10) // правая линия

						{
							buttons.X = x;
							buttons.Y = y;

							SetConsoleCursorPosition(h, buttons);
							SetConsoleTextAttribute(h, 4);

							cout << (char)219;
						}
					}
				}

				// старая кнопка - серая ---------------------------
				for (int y = beginY; y < beginY + 3; y++)
				{
					for (int x = previous; x < previous + 11; x++)
					{
						if (y == beginY && x < previous + 11 || // верхняя линия
							y < beginY + 3 && x == previous || // левая линия
							y == beginY + 2 && x < previous + 11 || // нижняя линия
							y < beginY + 3 && x == previous + 10) // правая линия

						{
							buttons.X = x;
							buttons.Y = y;

							SetConsoleCursorPosition(h, buttons);
							SetConsoleTextAttribute(h, 8);

							cout << (char)219;
						}
					}
				}
				SetConsoleCursorPosition(h, cursor);
			}


			// LEFT ----------------------------------------------------------------------------------------

			if (code == 75 && cursor.X - 1 >= beginX)
			{
				cursor.X -= 16;
				cursor.Y = beginY;

				int next = cursor.X;
				int previous = cursor.X + 16;

				// новая кнопка - красная --------------------------
				for (int y = beginY; y < beginY + 3; y++)
				{
					for (int x = next; x < next + 11; x++)
					{
						if (y == beginY && x < next + 11 || // верхняя линия
							y < beginY + 3 && x == next || // левая линия
							y == beginY + 2 && x < next + 11 || // нижняя линия
							y < beginY + 3 && x == next + 10) // правая линия

						{
							buttons.X = x;
							buttons.Y = y;

							SetConsoleCursorPosition(h, buttons);
							SetConsoleTextAttribute(h, 4);

							cout << (char)219;
						}
					}
				}

				// старая кнопка - серая ---------------------------
				for (int y = beginY; y < beginY + 3; y++)
				{
					for (int x = previous; x < previous + 11; x++)
					{
						if (y == beginY && x < previous + 11 || // верхняя линия
							y < beginY + 3 && x == previous || // левая линия
							y == beginY + 2 && x < previous + 11 || // нижняя линия
							y < beginY + 3 && x == previous + 10) // правая линия

						{
							buttons.X = x;
							buttons.Y = y;

							SetConsoleCursorPosition(h, buttons);
							SetConsoleTextAttribute(h, 8);

							cout << (char)219;
						}
					}
				}
				SetConsoleCursorPosition(h, cursor);
			}


			// Enter
			if (code == 13 && cursor.X == beginX) // fight
			{

				bool red = false;
				bool yellow = false;
				bool green = false;



				// запуск инидкаторов

				int key = 0;

				while (true)
				{

					// *файт происходит через ПРОБЕЛ* если надо, то поменяй : if (key == кнопка)

					// фективное отображение индикаторов
					for (int i = 2; i <= 37; i += 7)
					{
						light(beginX, beginY, i, 8, 0); // light (начало по Х, начало по Y, сдвиг в право, цвет, Sleep)
					}

					Sleep(150);

					// красные индикаторы --------------------------
					for (int i = 2; i <= 16; i += 7)
					{

						light(beginX, beginY, i, 4, 150);

						if (_kbhit() != 0)
						{
							key = _getch();
							if (key == 32)
							{
								clear(beginX, beginY);
							}
						}


					}
					if (key == 32)
					{
						clear(beginX, beginY);
						red = true;
						break;
					}
					// желтые индикаторы ---------------------------
					for (int i = 23; i <= 30; i += 7)
					{
						light(beginX, beginY, i, 6, 150);
						if (_kbhit() != 0)
						{
							key = _getch();
							if (key == 32)
							{
								clear(beginX, beginY);
							}
						}
					}

					if (key == 32)
					{
						clear(beginX, beginY);
						yellow = true;
						break;
					}
					// зеленый индикатор ---------------------------
					light(beginX, beginY, 37, 2, 150);

					if (_kbhit() != 0)
					{
						key = _getch();
						if (key == 32)
						{
							clear(beginX, beginY);
							green = true;
							break;
						}
					}
				}


				// действия при нажатом индикоторе
				if (red)
				{
					//если красная атака мы не наносим урон, босс выкрикивает рандомную фразочку
					int num_txt = rand() % 5;
					string boss_txtRand;

					SetConsoleTextAttribute(h, 4);
					Narator_txt.X = 36;
					SetConsoleCursorPosition(h, Narator_txt);
					cout << "You don't deal any damage";

					switch (num_txt)
					{
					case 0:
						Boss_txt.X = 35;
						Boss_txt.Y = 12;
						boss_txtRand = "HAHAHA, YO0U ArE NOtHiNGG!";
						break;
					case 1:
						Boss_txt.X = 38;
						Boss_txt.Y = 12;
						boss_txtRand = "GO0 CrY TOo DaDdDY!";
						break;
					case 2:
						Boss_txt.X = 26;
						Boss_txt.Y = 12;
						boss_txtRand = "CalL AMBUlaNCE, CalL AMBuLANcE, BUT NOT FOR ME!";
						break;
					case 3:
						Boss_txt.X = 30;
						Boss_txt.Y = 12;
						boss_txtRand = "VraCHA! VRAchA! POzOViTE VRACHA!";
						break;
					case 4:
						Boss_txt.X = 40;
						Boss_txt.Y = 12;
						boss_txtRand = "BEee NO0T TiMiD!";
						break;
					default:
						break;
					}
					SetConsoleCursorPosition(h, Boss_txt);
					SetConsoleTextAttribute(h, 15);
					for (int i = 0; i < boss_txtRand.length(); i++)
					{
						Sleep(15);
						cout << boss_txtRand[i];
					}

					Sleep(1200);

					SetConsoleCursorPosition(h, Narator_txt);
					SetConsoleTextAttribute(h, 0);
					for (int i = 0; i < 25; i++)
					{
						Sleep(10);
						cout << " ";
					}

					SetConsoleCursorPosition(h, Boss_txt);
					SetConsoleTextAttribute(h, 0);
					for (int i = 0; i < boss_txtRand.length(); i++)
					{
						Sleep(10);
						cout << " ";
					}
				}
				if (yellow)
				{
					int num_txt = rand() % 5;
					string boss_txtRand;

					SetConsoleTextAttribute(h, 6);
					Narator_txt.X = 40;
					SetConsoleCursorPosition(h, Narator_txt);
					deal_dmg = dmg - rand() % 5;
					cout << "You deal " << deal_dmg << " damage";


					//наносим боссу урон----------------------------------
					boss_hp -= deal_dmg;

					if (boss_hp <= 0) //player win
					{
						boss_hp = 0;
						Sleep(500);
						stats_boss.Y = 1;
						SetConsoleTextAttribute(h, 4);
						SetConsoleCursorPosition(h, stats_boss);
						cout << char(186) << setw(4) << boss_hp << char(3) << setw(2) << char(186);
						break;
					}

					stats_boss.Y = 1;
					SetConsoleTextAttribute(h, 4);
					SetConsoleCursorPosition(h, stats_boss);
					cout << char(186) << setw(4) << boss_hp << char(3) << setw(2) << char(186);
					//----------------------------------------------------

					switch (num_txt)
					{
					case 0:
						Boss_txt.X = 35;
						boss_txtRand = "DiD y0u sTeaL my swEEt roLL?";
						break;
					case 1:
						Boss_txt.X = 38;
						boss_txtRand = "Is THiS AlL Y0U CAn?";
						break;
					case 2:
						Boss_txt.X = 39;
						boss_txtRand = "He hE, TRy BEtteR!";
						break;
					case 3:
						Boss_txt.X = 25;
						boss_txtRand = "If thEre WAs a sEEa of ​​BEER, I`D become a BeAuTiFuL DoLpHiN!";
						break;
					case 4:
						Boss_txt.X = 32;
						boss_txtRand = "I AM WrAitH KiNg, NOT Rage KiNg!";
						break;
					default:
						break;
					}
					SetConsoleCursorPosition(h, Boss_txt);
					SetConsoleTextAttribute(h, 15);
					for (int i = 0; i < boss_txtRand.length(); i++)
					{
						Sleep(15);
						cout << boss_txtRand[i];
					}
					Sleep(1200);

					SetConsoleCursorPosition(h, Narator_txt);
					SetConsoleTextAttribute(h, 0);
					for (int i = 0; i < 25; i++)
					{
						Sleep(10);
						cout << " ";
					}

					SetConsoleCursorPosition(h, Boss_txt);
					SetConsoleTextAttribute(h, 0);
					for (int i = 0; i < boss_txtRand.length(); i++)
					{
						Sleep(10);
						cout << " ";
					}


				}
				if (green)
				{
					int num_txt = rand() % 5;
					string boss_txtRand;

					SetConsoleTextAttribute(h, 2);
					Narator_txt.X = 40;
					SetConsoleCursorPosition(h, Narator_txt);
					deal_dmg = dmg + rand() % 9;
					cout << "You deal " << deal_dmg << " damage";


					//наносим боссу урон----------------------------------
					boss_hp -= deal_dmg;

					if (boss_hp <= 0) //player win
					{
						boss_hp = 0;
						Sleep(500);
						stats_boss.Y = 1;
						SetConsoleTextAttribute(h, 4);
						SetConsoleCursorPosition(h, stats_boss);
						cout << char(186) << setw(4) << boss_hp << char(3) << setw(2) << char(186);
						break;
					}

					stats_boss.Y = 1;
					SetConsoleTextAttribute(h, 4);
					SetConsoleCursorPosition(h, stats_boss);
					cout << char(186) << setw(4) << boss_hp << char(3) << setw(2) << char(186);
					//----------------------------------------------------

					switch (num_txt)
					{
					case 0:
						Boss_txt.X = 30;
						boss_txtRand = "DiG MY grAve AnD I'LL pUt Y0u in IT!";
						break;
					case 1:
						Boss_txt.X = 36;
						boss_txtRand = "DeATh hAs NO GriP ON ME!";
						break;
					case 2:
						Boss_txt.X = 44;
						boss_txtRand = "KILL ME!";
						break;
					case 3:
						Boss_txt.X = 40;
						boss_txtRand = "I MiSS MY B0neS";
						break;
					case 4:
						Boss_txt.X = 30;
						boss_txtRand = "IT HuRTs m0Re ThaN an ARROW t0 ThE KnEE";
						break;
					default:
						break;
					}
					SetConsoleCursorPosition(h, Boss_txt);
					SetConsoleTextAttribute(h, 15);
					for (int i = 0; i < boss_txtRand.length(); i++)
					{
						Sleep(15);
						cout << boss_txtRand[i];
					}
					Sleep(1200);

					SetConsoleCursorPosition(h, Narator_txt);
					SetConsoleTextAttribute(h, 0);
					for (int i = 0; i < 25; i++)
					{
						Sleep(10);
						cout << " ";
					}

					SetConsoleCursorPosition(h, Boss_txt);
					SetConsoleTextAttribute(h, 0);
					for (int i = 0; i < boss_txtRand.length(); i++)
					{
						Sleep(10);
						cout << " ";
					}
				}



				//атака босса -----------------------------------------
				Sleep(500);

				SetConsoleTextAttribute(h, 4);
				Narator_txt.X = 40;
				Narator_txt.Y = 12;
				SetConsoleCursorPosition(h, Narator_txt);

				string boss_txt = "Leoric attacks!";

				for (int i = 0; i < boss_txt.length(); i++)
				{
					Sleep(15);
					cout << boss_txt[i];
				}

				Sleep(1000);

				int boss_deal_dmg = rand() % 7;
				hp -= (boss_dmg + boss_deal_dmg + dmg / 2) - armor;

				Narator_txt.X = 38;
				Narator_txt.Y = 14;
				SetConsoleCursorPosition(h, Narator_txt);
				cout << "You receive " << boss_dmg + boss_deal_dmg + dmg / 2 << " damage";

				Sleep(1200);

				Narator_txt.X = 40;
				Narator_txt.Y = 12;
				SetConsoleCursorPosition(h, Narator_txt);
				SetConsoleTextAttribute(h, 0);

				for (int i = 0; i < 25; i++)
				{
					Sleep(10);
					cout << " ";
				}

				Narator_txt.X = 38;
				Narator_txt.Y = 14;
				SetConsoleCursorPosition(h, Narator_txt);

				for (int i = 0; i < 25; i++)
				{
					Sleep(10);
					cout << " ";
				}

				stats_player.X = 68;
				stats_player.Y = 2;
				SetConsoleCursorPosition(h, stats_player);
				SetConsoleTextAttribute(h, 12);
				cout << "-==|Health: " << setw(5) << hp << (char)3 << "|==-";

				if (hp <= 0) //boss win
				{
					hp = 0;
					stats_player.Y = 2;
					SetConsoleCursorPosition(h, stats_player);
					SetConsoleTextAttribute(h, 12);
					cout << "-==|Health: " << setw(5) << hp << (char)3 << "|==-";
					Sleep(500);
					break;
				}

				Sleep(1000);

				if (recovery > 0) //реген хп после атаки босса
				{
					SetConsoleCursorPosition(h, WinTxt);
					SetConsoleTextAttribute(h, 2);
					cout << "+" << recovery << " HP";
					hp += recovery;

					Sleep(1000);

					SetConsoleCursorPosition(h, WinTxt);
					for (int i = 0; i < 10; i++)
					{
						Sleep(30);
						cout << " ";
					}

					stats_player.X = 68;
					stats_player.Y = 2;
					SetConsoleCursorPosition(h, stats_player);
					SetConsoleTextAttribute(h, 12);
					cout << "-==|Health: " << setw(5) << hp << (char)3 << "|==-";
				}
			}


			if (code == 13 && cursor.X == beginX + 16) // act
			{
				// идея в том что с вероятностью в 20% при депозите монет игрок получает +20 к hp
				if (money >= depos_money - speech_depos)
				{
					int current_depos = depos_money - speech_depos;

					if (depos_money - speech_depos <= 0)
					{
						current_depos = 1;
					}

					money -= current_depos;
					stats_player.X = 68;
					stats_player.Y = 8;
					SetConsoleCursorPosition(h, stats_player);
					SetConsoleTextAttribute(h, 6);
					cout << "-==|Money: " << setw(5) << money << (char)36 << "|==-";
					if (rand() % 5 == 1)
					{
						// text -------------------------------------
						COORD SuccessTxt;
						SuccessTxt.X = 40;
						SuccessTxt.Y = 13;

						SetConsoleCursorPosition(h, SuccessTxt);
						SetConsoleTextAttribute(h, 6);

						string Success = "Deal is success!";

						for (int i = 0; i < Success.length(); i++)
						{
							Sleep(40);
							cout << Success[i];
						}

						Sleep(100);
						SetConsoleCursorPosition(h, SuccessTxt);
						SetConsoleTextAttribute(h, 0);

						for (int i = 0; i < Success.length() + 1; i++)
						{
							Sleep(50);
							cout << " ";
						}
						// ------------------------------------------

						hp += 20;

						stats_player.X = 68;
						stats_player.Y = 2;
						SetConsoleCursorPosition(h, stats_player);
						SetConsoleTextAttribute(h, 12);
						cout << "-==|Health: " << setw(5) << hp << (char)3 << "|==-";
					}

					else
					{

						// text -------------------------------------
						COORD NotSuccessTxt;
						NotSuccessTxt.X = 40;
						NotSuccessTxt.Y = 13;

						SetConsoleCursorPosition(h, NotSuccessTxt);
						SetConsoleTextAttribute(h, 4);

						string NotSuccess = "Deal is not success!";

						for (int i = 0; i < NotSuccess.length(); i++)
						{
							Sleep(40);
							cout << NotSuccess[i];
						}

						Sleep(100);
						SetConsoleCursorPosition(h, NotSuccessTxt);
						SetConsoleTextAttribute(h, 0);

						for (int i = 0; i < NotSuccess.length() + 1; i++)
						{
							Sleep(50);
							cout << " ";
						}
						// ------------------------------------------
					}

				}

				else
				{
					COORD MoneyTxt;
					MoneyTxt.X = 40;
					MoneyTxt.Y = 13;

					SetConsoleCursorPosition(h, MoneyTxt);
					SetConsoleTextAttribute(h, 4);

					string NotEnough = "Not enough money!";

					for (int i = 0; i < NotEnough.length(); i++)
					{
						Sleep(40);
						cout << NotEnough[i];
					}

					Sleep(100);
					SetConsoleCursorPosition(h, MoneyTxt);
					SetConsoleTextAttribute(h, 0);

					for (int i = 0; i < NotEnough.length() + 1; i++)
					{
						Sleep(50);
						cout << " ";
					}
				}
			}

			if (code == 13 && cursor.X == beginX + 32) // items
			{
				ShowInventory(beginX, beginY, stats_player);
			}

			else if (code == 27) // break на escape
			{
				break;
			}
		}
	}

	if (hp <= 0) //boss win
	{
		int rand_win_phrase = rand() % 3;
		string boss_txtRand;

		SetConsoleTextAttribute(h, 4);

		switch (rand_win_phrase)
		{
		case 0:
			Boss_txt.X = 38;
			Boss_txt.Y = 12;
			CreateThread(0, 0, Boss_win1, 0, 0, 0);
			boss_txtRand = "CoMMenDaBLE HumILIty";
			break;
		case 1:
			Boss_txt.X = 42;
			Boss_txt.Y = 12;
			CreateThread(0, 0, Boss_win2, 0, 0, 0);
			boss_txtRand = "DEAl WIth IT";
			break;
		case 2:
			Boss_txt.X = 37;
			Boss_txt.Y = 12;
			CreateThread(0, 0, Boss_win3, 0, 0, 0);
			boss_txtRand = "YoU COME T0 a BaD eND...";
			break;
		default:
			break;
		}

		SetConsoleCursorPosition(h, Boss_txt);
		SetConsoleTextAttribute(h, 15);
		for (int i = 0; i < boss_txtRand.length(); i++)
		{
			Sleep(15);
			cout << boss_txtRand[i];
		}

		Sleep(3000);

		SetConsoleCursorPosition(h, Narator_txt);
		SetConsoleTextAttribute(h, 0);
		for (int i = 0; i <= 25; i++)
		{
			Sleep(10);
			cout << " ";
		}

		SetConsoleCursorPosition(h, Boss_txt);
		SetConsoleTextAttribute(h, 0);
		for (int i = 0; i <= boss_txtRand.length(); i++)
		{
			Sleep(10);
			cout << " ";
		}

		bool isDeath = true;
		string deat_txt = "YOU DIED";
		int indent = 7;

		system("cls");
		Wasted(deat_txt, indent, isDeath);
	}

	if (boss_hp <= 0) //player win
	{
		int rand_lose_phrase = rand() % 3;
		string boss_txtRand;

		SetConsoleTextAttribute(h, 4);

		switch (rand_lose_phrase)
		{
		case 0:
			Boss_txt.X = 36;
			Boss_txt.Y = 12;
			CreateThread(0, 0, Boss_lose1, 0, 0, 0);
			boss_txtRand = "S0... this is what it is";
			break;
		case 1:
			Boss_txt.X = 33;
			Boss_txt.Y = 12;
			CreateThread(0, 0, Boss_lose2, 0, 0, 0);
			boss_txtRand = "I Sh0UlD haVe ChoSen a QUeeN!";
			break;
		case 2:
			Boss_txt.X = 34;
			Boss_txt.Y = 12;
			CreateThread(0, 0, Boss_lose3, 0, 0, 0);
			boss_txtRand = "HOW C0MeS A WrAiTH TO DIE!?";
			break;
		default:
			break;
		}

		SetConsoleCursorPosition(h, Boss_txt);
		SetConsoleTextAttribute(h, 15);
		for (int i = 0; i < boss_txtRand.length(); i++)
		{
			Sleep(15);
			cout << boss_txtRand[i];
		}

		Sleep(3000);

		SetConsoleCursorPosition(h, Narator_txt);
		SetConsoleTextAttribute(h, 0);
		for (int i = 0; i <= 25; i++)
		{
			Sleep(10);
			cout << " ";
		}

		SetConsoleCursorPosition(h, Boss_txt);
		SetConsoleTextAttribute(h, 0);
		for (int i = 0; i <= boss_txtRand.length(); i++)
		{
			Sleep(10);
			cout << " ";
		}

		Sleep(500);

		int gain_money = 300 + rand() % 500;
		int gain_exp = 700 + rand() % 1400;

		money += gain_money + luck;
		experience += gain_exp + faith;

		stats_player.Y = 8;
		SetConsoleCursorPosition(h, stats_player);
		SetConsoleTextAttribute(h, 6);
		cout << "-==|Money: " << setw(6) << money << (char)36 << "|==-";

		SetConsoleCursorPosition(h, WinTxt);
		SetConsoleTextAttribute(h, 2);

		string money_txt = "Money received ";
		string exp_txt = "Experience Gained ";

		boss_lifes--;
		string life_txt = " lives left";

		for (int i = 0; i < money_txt.length(); i++)
		{
			Sleep(35);
			cout << money_txt[i];
		}
		cout << char(30) << setw(8) << gain_money << "$";

		WinTxt.Y = 26;
		SetConsoleCursorPosition(h, WinTxt);

		for (int i = 0; i < exp_txt.length(); i++)
		{
			Sleep(35);
			cout << exp_txt[i];
		}
		cout << char(30) << setw(5) << gain_exp << char(21);

		WinTxt.Y = 28;
		SetConsoleTextAttribute(h, 4);
		SetConsoleCursorPosition(h, WinTxt);

		cout << boss_lifes;
		for (int i = 0; i < life_txt.length(); i++)
		{
			Sleep(35);
			cout << life_txt[i];
		}
		
		Sleep(200);

		WinTxt.Y = 24;
		SetConsoleCursorPosition(h, WinTxt);
		SetConsoleTextAttribute(h, 0);

		for (int i = 0; i <= money_txt.length() + 10; i++)
		{
			Sleep(20);
			cout << " ";
		}

		WinTxt.Y = 26;
		SetConsoleCursorPosition(h, WinTxt);

		for (int i = 0; i <= exp_txt.length() + 10; i++)
		{
			Sleep(20);
			cout << " ";
		}
		Sleep(200);

		WinTxt.Y = 28;
		SetConsoleCursorPosition(h, WinTxt);

		for (int i = 0; i <= life_txt.length() + 2; i++)
		{
			Sleep(20);
			cout << " ";
		}
		Sleep(200);

		if (color < 4)
		{
			color++;
		}
		if (color == 4)
		{
			color = 0;
		}
		system("cls");
		ShowHub();
	}
}









