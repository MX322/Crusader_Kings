#include "Headers/Global.h"

void ShowInventory(int beginX, int beginY, COORD stats_player)
{
	beginX += 5;
	COORD Inventory;
	Inventory.Y = beginY - 2;
	Inventory.X = beginX + 48;

	// отрисовка инвенторя -----------------------------------
	for (int i = -2; i < 6; i += 2)
	{
		// кнопки -----------------------------------
		Inventory.Y = beginY + i;
		Inventory.X = beginX + 48;
		SetConsoleTextAttribute(h, 8);
		SetConsoleCursorPosition(h, Inventory);
		cout << (char)254;

		//-------------------------------------------

		// текст ------------------------------------
		Inventory.X = beginX + 50;
		SetConsoleTextAttribute(h, 15);
		SetConsoleCursorPosition(h, Inventory);

		if (i == -2)
		{
			cout << "Small heal";
		}

		else if (i == 0)
		{
			cout << "Medium heal";
		}

		else if (i == 2)
		{
			cout << "Large heal";
		}

		else if (i == 4)
		{
			cout << "Exit";
		}

		// -------------------------------------------

		// количество аптечек-------------------------

		Inventory.X = beginX + 62;
		SetConsoleCursorPosition(h, Inventory);
		SetConsoleTextAttribute(h, 12);

		if (i == -2)
		{
			cout << small_heal;
		}

		else if (i == 0)
		{
			cout << medium_heal;
		}

		else if (i == 2)
		{
			cout << large_heal;
		}

		// -------------------------------------------
	}

	// -------------------------------------------------------

	// работа с кнопками --------------------------------------------------

	//курсор---------------------------------------------
	COORD cursor;
	cursor.X = beginX + 48;
	cursor.Y = beginY - 2;

	SetConsoleCursorPosition(h, cursor);
	SetConsoleTextAttribute(h, 4);
	cout << char(254);
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


			// up/down -------------------------------------------		
			if (code == 80 && cursor.Y + 2 != beginY + 6)
			{
				cursor.Y += 2;
			}

			else if (code == 72 && cursor.Y - 2 != beginY - 4)
			{
				cursor.Y -= 2;
			}
			// ---------------------------------------------------

			// работа с кнопками -------------------------------------------------
			else if (code == 13 && cursor.Y == beginY - 2) // small heal
			{
				if (small_heal > 0)
				{
					small_heal--;
					hp += hp_max / 4;

					if (hp > hp_max)
					{
						hp = hp_max;
					}

					// текст восполнение хп -------------------------
					COORD Heal_txt;
					Heal_txt.X = 40;
					Heal_txt.Y = 13;

					SetConsoleCursorPosition(h, Heal_txt);
					SetConsoleTextAttribute(h, 2);

					string txt_heal = "Health restored ";

					for (int i = 0; i < txt_heal.length(); i++)
					{
						Sleep(20);
						cout << txt_heal[i];
					}
					cout << char(30);
					Sleep(1000);
					SetConsoleCursorPosition(h, Heal_txt);
					SetConsoleTextAttribute(h, 0);

					for (int i = 0; i < txt_heal.length() + 1; i++)
					{
						Sleep(20);
						cout << " ";
					}

					// ----------------------------------------------

					// обновление хп -------------------
					stats_player.X = 68;
					stats_player.Y = 2;
					SetConsoleCursorPosition(h, stats_player);
					SetConsoleTextAttribute(h, 12);
					cout << "-==|Health: " << setw(5) << hp << (char)3 << "|==-";
					// ----------------------------------

					// обновление кол аптек -------------
					Inventory.X = beginX + 62;
					Inventory.Y = beginY - 2;
					SetConsoleCursorPosition(h, Inventory);
					cout << small_heal << "   ";
					// ----------------------------------
				}

				else
				{
					// недостаточно аптек
					COORD Heal_txt;
					Heal_txt.X = 38;
					Heal_txt.Y = 13;

					SetConsoleCursorPosition(h, Heal_txt);
					SetConsoleTextAttribute(h, 12);

					string txt_heal = "Not enough small heals ";

					for (int i = 0; i < txt_heal.length(); i++)
					{
						Sleep(20);
						cout << txt_heal[i];
					}
					Sleep(1000);
					SetConsoleCursorPosition(h, Heal_txt);
					SetConsoleTextAttribute(h, 0);

					for (int i = 0; i < txt_heal.length() + 1; i++)
					{
						Sleep(20);
						cout << " ";
					}
				}
			}

			// -------------------------------------------------

			else if (code == 13 && cursor.Y == beginY) // medium heal
			{
				if (medium_heal > 0)
				{
					medium_heal--;
					hp += hp_max / 2;

					if (hp > hp_max)
					{
						hp = hp_max;
					}

					// текст восполнение хп -------------------------
					COORD Heal_txt;
					Heal_txt.X = 40;
					Heal_txt.Y = 13;

					SetConsoleCursorPosition(h, Heal_txt);
					SetConsoleTextAttribute(h, 2);

					string txt_heal = "Health restored ";

					for (int i = 0; i < txt_heal.length(); i++)
					{
						Sleep(20);
						cout << txt_heal[i];
					}
					cout << char(30);
					Sleep(1000);
					SetConsoleCursorPosition(h, Heal_txt);
					SetConsoleTextAttribute(h, 0);

					for (int i = 0; i < txt_heal.length() + 1; i++)
					{
						Sleep(20);
						cout << " ";
					}

					// ----------------------------------------------

					// обновление хп -------------------
					stats_player.X = 68;
					stats_player.Y = 2;
					SetConsoleCursorPosition(h, stats_player);
					SetConsoleTextAttribute(h, 12);
					cout << "-==|Health: " << setw(5) << hp << (char)3 << "|==-";
					// ----------------------------------

					// обновление кол аптек -------------
					Inventory.X = beginX + 62;
					Inventory.Y = beginY;
					SetConsoleCursorPosition(h, Inventory);
					cout << medium_heal << "   ";
					// ----------------------------------
				}

				else
				{
					// недостаточно аптек
					COORD Heal_txt;
					Heal_txt.X = 38;
					Heal_txt.Y = 13;

					SetConsoleCursorPosition(h, Heal_txt);
					SetConsoleTextAttribute(h, 12);

					string txt_heal = "Not enough medium heals ";

					for (int i = 0; i < txt_heal.length(); i++)
					{
						Sleep(20);
						cout << txt_heal[i];
					}
					Sleep(1000);
					SetConsoleCursorPosition(h, Heal_txt);
					SetConsoleTextAttribute(h, 0);

					for (int i = 0; i < txt_heal.length() + 1; i++)
					{
						Sleep(20);
						cout << " ";
					}
				}

			}

			// -------------------------------------------------------------------

			else if (code == 13 && cursor.Y == beginY + 2) // large heal
			{
				if (large_heal > 0)
				{
					large_heal--;
					hp = hp_max;

					// текст восполнение хп -------------------------
					COORD Heal_txt;
					Heal_txt.X = 40;
					Heal_txt.Y = 13;

					SetConsoleCursorPosition(h, Heal_txt);
					SetConsoleTextAttribute(h, 2);

					string txt_heal = "Health restored ";

					for (int i = 0; i < txt_heal.length(); i++)
					{
						Sleep(20);
						cout << txt_heal[i];
					}
					cout << char(30);
					Sleep(1000);
					SetConsoleCursorPosition(h, Heal_txt);
					SetConsoleTextAttribute(h, 0);

					for (int i = 0; i < txt_heal.length() + 1; i++)
					{
						Sleep(20);
						cout << " ";
					}

					// ----------------------------------------------

					// обновление хп -------------------
					stats_player.X = 68;
					stats_player.Y = 2;
					SetConsoleCursorPosition(h, stats_player);
					SetConsoleTextAttribute(h, 12);
					cout << "-==|Health: " << setw(5) << hp << (char)3 << "|==-";
					// ----------------------------------

					// обновление кол аптек -------------
					Inventory.X = beginX + 62;
					Inventory.Y = beginY + 2;
					SetConsoleCursorPosition(h, Inventory);
					cout << large_heal << "   ";
					// ----------------------------------
				}

				else
				{
					// недостаточно аптек
					COORD Heal_txt;
					Heal_txt.X = 38;
					Heal_txt.Y = 13;

					SetConsoleCursorPosition(h, Heal_txt);
					SetConsoleTextAttribute(h, 12);

					string txt_heal = "Not enough large heals ";

					for (int i = 0; i < txt_heal.length(); i++)
					{
						Sleep(20);
						cout << txt_heal[i];
					}
					Sleep(1000);
					SetConsoleCursorPosition(h, Heal_txt);
					SetConsoleTextAttribute(h, 0);

					for (int i = 0; i < txt_heal.length() + 1; i++)
					{
						Sleep(20);
						cout << " ";
					}
				}

			}

			// -------------------------------------------------------------------

			// EXIT --------------------------------------------------------------

			COORD Clear;
			Clear.X = beginX + 48;
			Clear.Y = beginY - 2;

			if (code == 13 && cursor.Y == beginY + 4)
			{
				for (int y = -2; y < 6; y++)
				{
					for (int x = 48; x < 63; x++)
					{
						Clear.X = beginX + x;
						Clear.Y = beginY + y;

						SetConsoleCursorPosition(h, Clear);
						cout << " ";
					}
				}
				return;
			}

			// -------------------------------------------------------------------

			// красный курсор
			SetConsoleCursorPosition(h, cursor);
			SetConsoleTextAttribute(h, 4);
			cout << char(254);
		}
	}
	// -------------------------------------------------------
}