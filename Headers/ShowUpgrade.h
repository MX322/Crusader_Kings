#include "Headers/Global.h"

void ShowUpgrade(COORD upgrade, COORD player, COORD stats, int cols, int rows)
{
	SetConsoleCursorPosition(h, player); // игрок не будет проподать после перехода к меню магазина
	cout << (char)1;

	for (int y = (rows / 2) + 3; y < (rows / 2) + 10; y++)
	{
		for (int x = cols + 3; x < cols + 6; x++)
		{
			if (y == (rows / 2) + 3)
			{
				upgrade.Y = y;
				upgrade.X = x;
				SetConsoleCursorPosition(h, upgrade);
				SetConsoleTextAttribute(h, 14);
				cout << setw(10) << "UPGRADE";
			}

			else if (x == cols + 3 && y == (rows / 2) + 4)
			{
				upgrade.Y = y;
				upgrade.X = x;
				SetConsoleCursorPosition(h, upgrade);
				SetConsoleTextAttribute(h, 4);
				cout << (char)254; // первый квадрат будет красным
			}

			else if (x == cols + 3 && y >= (rows / 2) + 5)
			{
				upgrade.Y = y;
				upgrade.X = x;
				SetConsoleCursorPosition(h, upgrade);
				SetConsoleTextAttribute(h, 8);
				cout << (char)254; // квадратики (слева от скиллов)
			}

			else if (x == cols + 5 && y == (rows / 2) + 4) // Skill 1
			{
				upgrade.Y = y;
				upgrade.X = x;
				SetConsoleCursorPosition(h, upgrade);
				SetConsoleTextAttribute(h, 15);
				cout << "Strength";
				SetConsoleTextAttribute(h, 10);
				cout << setw(2) << char(186) << pumping_cost << char(186) << " +HP";
			}

			else if (x == cols + 5 && y == (rows / 2) + 5) // Skill 2
			{
				upgrade.Y = y;
				upgrade.X = x;
				SetConsoleCursorPosition(h, upgrade);
				SetConsoleTextAttribute(h, 15);
				cout << "Recovery";
				SetConsoleTextAttribute(h, 10);
				cout << setw(2) << char(186) << pumping_cost << char(186) << " Regen after damage";
			}

			else if (x == cols + 5 && y == (rows / 2) + 6) // Skill 3
			{
				upgrade.Y = y;
				upgrade.X = x;
				SetConsoleCursorPosition(h, upgrade);
				SetConsoleTextAttribute(h, 15);
				cout << "Luck";
				SetConsoleTextAttribute(h, 10);
				cout << setw(6) << char(186) << pumping_cost << char(186) << " NEED MORE GOLD!";
			}

			else if (x == cols + 5 && y == (rows / 2) + 7) // Skill 4
			{
				upgrade.Y = y;
				upgrade.X = x;
				SetConsoleCursorPosition(h, upgrade);
				SetConsoleTextAttribute(h, 15);
				cout << "Speech";
				SetConsoleTextAttribute(h, 10);
				cout << setw(4) << char(186) << pumping_cost << char(186) << " Price reduction";

			}

			else if (x == cols + 5 && y == (rows / 2) + 8) // Skill 5
			{
				upgrade.Y = y;
				upgrade.X = x;
				SetConsoleCursorPosition(h, upgrade);
				SetConsoleTextAttribute(h, 15);
				cout << "Faith";
				SetConsoleTextAttribute(h, 10);
				cout << setw(5) << char(186) << pumping_cost << char(186) << " Do u believe in God?";
			}

			else if (x == cols + 5 && y == (rows / 2) + 9) // exit
			{
				upgrade.Y = y;
				upgrade.X = x;
				SetConsoleCursorPosition(h, upgrade);
				SetConsoleTextAttribute(h, 12);
				cout << "Exit ";
			}
		}
	}

	//курсор---------------------------------------------
	COORD cursor;
	cursor.X = cols + 3;
	cursor.Y = (rows / 2) + 4;

	SetConsoleCursorPosition(h, cursor);
	SetConsoleTextAttribute(h, 4);
	//---------------------------------------------------



	while (true)
	{
		if (_kbhit())
		{
			SetConsoleCursorPosition(h, cursor);
			SetConsoleTextAttribute(h, 8);
			cout << char(254);
			int code = _getch();


			if (code == 224)
			{
				code = _getch();
			}

			if (code == 80 && cursor.Y + 1 != (rows / 2) + 10)
			{
				cursor.Y++;
			}

			else if (code == 72 && cursor.Y - 1 != (rows / 2) + 3)
			{
				cursor.Y--;
			}


			// прокачка  ----------------------------------------
			else if (code == 13 && cursor.Y != (rows / 2) + 9)
			{
				// если не хватает экспы

				if (experience < pumping_cost)
				{
					COORD MoneyTxt;
					MoneyTxt.X = cols + 3;
					MoneyTxt.Y = rows;

					SetConsoleCursorPosition(h, MoneyTxt);
					SetConsoleTextAttribute(h, 4);

					string NotEnough = "Not enough experience!";

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


				// если хватает экспы
				else if (experience >= pumping_cost)
				{
					// по отдельным айтамам ------------------

					if (cursor.Y == (rows / 2) + 4)
					{
						// Item 1
						COORD MoneyTxt;
						MoneyTxt.X = cols + 3;
						MoneyTxt.Y = rows + 1;

						SetConsoleCursorPosition(h, MoneyTxt);
						SetConsoleTextAttribute(h, 2);

						//расчеты для прокачки------------
						int hp_temp = hp_max;
						hp_max += 20;
						hp = hp_max;
						experience -= pumping_cost;
						level++;
						pumping_cost = pumping_cost + pumping_cost / 8;
						//--------------------------------

						string Enough = "Max health increased! ";

						for (int i = 0; i < Enough.length(); i++)
						{
							Sleep(15);
							cout << Enough[i];
						}
						cout << hp_temp << " " << char(16) << " " << hp_max;

						Sleep(1500);
						SetConsoleCursorPosition(h, MoneyTxt);
						for (int i = 0; i <= Enough.length() + 20; i++)
						{
							Sleep(15);
							cout << " ";
						}

						stats.X = cols + 2;
						stats.Y = 1;
						SetConsoleCursorPosition(h, stats);
						SetConsoleTextAttribute(h, 12);
						cout << "-==|Health: " << hp << (char)3 << setw(10) << "|==-";

						stats.Y = 4;
						SetConsoleCursorPosition(h, stats);
						SetConsoleTextAttribute(h, 15);
						cout << "-==|Experience: " << experience << (char)21 << setw(6) << "|==-";

						for (int y = (rows / 2) + 3; y < (rows / 2) + 10; y++)
						{
							for (int x = cols + 3; x < cols + 45; x++)
							{
								upgrade.Y = y;
								upgrade.X = x;
								SetConsoleCursorPosition(h, upgrade);
								cout << " ";
							}
						}
						return;
					}

					else if (cursor.Y == (rows / 2) + 5)
					{
						//Item 2
						COORD MoneyTxt;
						MoneyTxt.X = cols + 3;
						MoneyTxt.Y = rows + 1;

						SetConsoleCursorPosition(h, MoneyTxt);
						SetConsoleTextAttribute(h, 2);

						//расчеты для прокачки------------
						int recovery_temp = recovery;
						recovery += 2;
						experience -= pumping_cost;
						level++;
						pumping_cost = pumping_cost + pumping_cost / 8;
						//--------------------------------

						string Enough = "Recovery increased! ";

						for (int i = 0; i < Enough.length(); i++)
						{
							Sleep(15);
							cout << Enough[i];
						}
						cout << recovery_temp << " " << char(16) << " " << recovery;

						Sleep(1500);
						SetConsoleCursorPosition(h, MoneyTxt);
						for (int i = 0; i <= Enough.length() + 20; i++)
						{
							Sleep(15);
							cout << " ";
						}

						stats.X = cols + 2;
						stats.Y = 4;
						SetConsoleCursorPosition(h, stats);
						SetConsoleTextAttribute(h, 15);
						cout << "-==|Experience: " << experience << (char)21 << setw(6) << "|==-";

						for (int y = (rows / 2) + 3; y < (rows / 2) + 10; y++)
						{
							for (int x = cols + 3; x < cols + 45; x++)
							{
								upgrade.Y = y;
								upgrade.X = x;
								SetConsoleCursorPosition(h, upgrade);
								cout << " ";
							}
						}
						return;
					}

					else if (cursor.Y == (rows / 2) + 6)
					{
						//Item 3
						COORD MoneyTxt;
						MoneyTxt.X = cols + 3;
						MoneyTxt.Y = rows + 1;

						SetConsoleCursorPosition(h, MoneyTxt);
						SetConsoleTextAttribute(h, 2);

						//расчеты для прокачки------------
						level++;
						luck += 10 * level;
						experience -= pumping_cost;
						pumping_cost = pumping_cost + pumping_cost / 8;
						//--------------------------------

						string Enough = "Better be born lucky than rich! ";

						for (int i = 0; i < Enough.length(); i++)
						{
							Sleep(15);
							cout << Enough[i];
						}

						Sleep(1500);
						SetConsoleCursorPosition(h, MoneyTxt);
						for (int i = 0; i <= Enough.length() + 20; i++)
						{
							Sleep(15);
							cout << " ";
						}

						stats.X = cols + 2;
						stats.Y = 4;
						SetConsoleCursorPosition(h, stats);
						SetConsoleTextAttribute(h, 15);
						cout << "-==|Experience: " << experience << (char)21 << setw(6) << "|==-";

						for (int y = (rows / 2) + 3; y < (rows / 2) + 10; y++)
						{
							for (int x = cols + 3; x < cols + 45; x++)
							{
								upgrade.Y = y;
								upgrade.X = x;
								SetConsoleCursorPosition(h, upgrade);
								cout << " ";
							}
						}
						return;
					}

					else if (cursor.Y == (rows / 2) + 7)
					{
						//Item 4
						COORD MoneyTxt;
						MoneyTxt.X = cols + 3;
						MoneyTxt.Y = rows + 1;

						SetConsoleCursorPosition(h, MoneyTxt);
						SetConsoleTextAttribute(h, 2);

						//расчеты для прокачки------------
						level++;
						speech_price += 17 * level;
						speech_depos += 15;
						experience -= pumping_cost;
						pumping_cost = pumping_cost + pumping_cost / 8;
						//--------------------------------

						string Enough = "The best prices from the best merchants! ";

						for (int i = 0; i < Enough.length(); i++)
						{
							Sleep(15);
							cout << Enough[i];
						}

						Sleep(1500);
						SetConsoleCursorPosition(h, MoneyTxt);
						for (int i = 0; i <= Enough.length() + 20; i++)
						{
							Sleep(15);
							cout << " ";
						}

						stats.X = cols + 2;
						stats.Y = 4;
						SetConsoleCursorPosition(h, stats);
						SetConsoleTextAttribute(h, 15);
						cout << "-==|Experience: " << experience << (char)21 << setw(6) << "|==-";

						for (int y = (rows / 2) + 3; y < (rows / 2) + 10; y++)
						{
							for (int x = cols + 3; x < cols + 40; x++)
							{
								upgrade.Y = y;
								upgrade.X = x;
								SetConsoleCursorPosition(h, upgrade);
								cout << " ";
							}
						}
						return;
					}

					else if (cursor.Y == (rows / 2) + 8)
					{
						//Item 5
						COORD MoneyTxt;
						MoneyTxt.X = cols + 3;
						MoneyTxt.Y = rows + 1;

						SetConsoleCursorPosition(h, MoneyTxt);
						SetConsoleTextAttribute(h, 2);

						//расчеты для прокачки------------
						level++;
						faith += 17 * level;
						experience -= pumping_cost;
						pumping_cost = pumping_cost + pumping_cost / 8;
						//--------------------------------

						string Enough = "God believes in you! ";

						for (int i = 0; i < Enough.length(); i++)
						{
							Sleep(15);
							cout << Enough[i];
						}

						Sleep(1500);
						SetConsoleCursorPosition(h, MoneyTxt);
						for (int i = 0; i <= Enough.length() + 20; i++)
						{
							Sleep(15);
							cout << " ";
						}

						stats.X = cols + 2;
						stats.Y = 4;
						SetConsoleCursorPosition(h, stats);
						SetConsoleTextAttribute(h, 15);
						cout << "-==|Experience: " << experience << (char)21 << setw(6) << "|==-";

						for (int y = (rows / 2) + 3; y < (rows / 2) + 10; y++)
						{
							for (int x = cols + 3; x < cols + 40; x++)
							{
								upgrade.Y = y;
								upgrade.X = x;
								SetConsoleCursorPosition(h, upgrade);
								cout << " ";
							}
						}
						return;
					}
					// ---------------------------------------
				}
			}
			//---------------------------------------------------------------

			// exit------------------------------------------
			else if (code == 13 && cursor.Y == (rows / 2) + 9)
			{

				for (int y = (rows / 2) + 3; y < (rows / 2) + 10; y++)
				{
					for (int x = cols + 3; x < cols + 45; x++)
					{
						upgrade.Y = y;
						upgrade.X = x;
						SetConsoleCursorPosition(h, upgrade);
						cout << " ";
					}
				}
				return;
			}
			// ----------------------------------------------

			// красный курсор
			SetConsoleCursorPosition(h, cursor);
			SetConsoleTextAttribute(h, 4);
			cout << char(254);
		}
	}
}
