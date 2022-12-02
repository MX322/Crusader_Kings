#include "Headers/Global.h"

void ShowShop(COORD shop, COORD player, COORD stats, int cols, int rows)
{

	int BucklerPrice = 425 - speech_price;        // +4 брони
	int QuellingBladePrice = 500 - speech_price;  // +7 урона
	int PlatemailPrice = 1400 - speech_price;     // +14 брони
	int ClaymorePrice = 1350 - speech_price;      // +20 урону
	int DivineRapierPrice = 5950 - speech_price;  // +350 урону

	int price[5]{ BucklerPrice ,QuellingBladePrice ,PlatemailPrice ,ClaymorePrice ,DivineRapierPrice };

	SetConsoleCursorPosition(h, player); // игрок не будет проподать после перехода к меню магазина
	cout << (char)1;

	for (int y = (rows / 2) + 3; y < (rows / 2) + 10; y++)
	{
		for (int x = cols + 3; x < cols + 6; x++)
		{
			if (y == (rows / 2) + 3)
			{
				shop.Y = y;
				shop.X = x;
				SetConsoleCursorPosition(h, shop);
				SetConsoleTextAttribute(h, 14);
				cout << setw(10) << "SHOP";
			}

			else if (x == cols + 3 && y == (rows / 2) + 4)
			{
				shop.Y = y;
				shop.X = x;
				SetConsoleCursorPosition(h, shop);
				SetConsoleTextAttribute(h, 4);
				cout << (char)254; // первый квадрат будет красным
			}

			else if (x == cols + 3 && y >= (rows / 2) + 5)
			{
				shop.Y = y;
				shop.X = x;
				SetConsoleCursorPosition(h, shop);
				SetConsoleTextAttribute(h, 8);
				cout << (char)254; // квадратики (слева от айтемов)
			}

			else if (x == cols + 5 && y == (rows / 2) + 4) // Item 1
			{
				if (!buckler)
				{
					shop.Y = y;
					shop.X = x;
					SetConsoleCursorPosition(h, shop);
					SetConsoleTextAttribute(h, 15);
					cout << "Buckler ";
					SetConsoleTextAttribute(h, 10);
					cout << setw(8) << char(186) << " " << BucklerPrice << char(186) << " +4 armor";
				}

				else
				{
					shop.Y = y;
					shop.X = x;
					SetConsoleCursorPosition(h, shop);
					SetConsoleTextAttribute(h, 15);
					cout << "Buckler ";
					SetConsoleTextAttribute(h, 4);
					cout << setw(8) << char(186) << "SOLD OUT!" << char(186);
				}

			}

			else if (x == cols + 5 && y == (rows / 2) + 5) // Item 2
			{
				if (!axe)
				{
					shop.Y = y;
					shop.X = x;
					SetConsoleCursorPosition(h, shop);
					SetConsoleTextAttribute(h, 15);
					cout << "Quelling Blade ";
					SetConsoleTextAttribute(h, 10);
					cout << char(186) << " " << QuellingBladePrice << char(186) << " +12 damage";
				}

				else
				{
					shop.Y = y;
					shop.X = x;
					SetConsoleCursorPosition(h, shop);
					SetConsoleTextAttribute(h, 15);
					cout << "Quelling Blade ";
					SetConsoleTextAttribute(h, 4);
					cout << char(186) << "SOLD OUT!" << char(186);
				}
			}

			else if (x == cols + 5 && y == (rows / 2) + 6) // Item 3
			{
				if (!platemail)
				{
					shop.Y = y;
					shop.X = x;
					SetConsoleCursorPosition(h, shop);
					SetConsoleTextAttribute(h, 15);
					cout << "Platemail ";
					SetConsoleTextAttribute(h, 10);
					cout << setw(6) << char(186) << PlatemailPrice << char(186) << " +14 armor";
				}

				else
				{
					shop.Y = y;
					shop.X = x;
					SetConsoleCursorPosition(h, shop);
					SetConsoleTextAttribute(h, 15);
					cout << "Platemail ";
					SetConsoleTextAttribute(h, 4);
					cout << setw(6) << char(186) << "SOLD OUT!" << char(186);
				}
			}

			else if (x == cols + 5 && y == (rows / 2) + 7) // Item 4
			{
				if (!claymore)
				{
					shop.Y = y;
					shop.X = x;
					SetConsoleCursorPosition(h, shop);
					SetConsoleTextAttribute(h, 15);
					cout << "Claymore ";
					SetConsoleTextAttribute(h, 10);
					cout << setw(7) << char(186) << ClaymorePrice << char(186) << " +24 damage";
				}

				else
				{
					shop.Y = y;
					shop.X = x;
					SetConsoleCursorPosition(h, shop);
					SetConsoleTextAttribute(h, 15);
					cout << "Claymore ";
					SetConsoleTextAttribute(h, 4);
					cout << setw(7) << char(186) << "SOLD OUT!" << char(186);
				}
			}

			else if (x == cols + 5 && y == (rows / 2) + 8) // Item 5
			{
				if (!rapier)
				{
					shop.Y = y;
					shop.X = x;
					SetConsoleCursorPosition(h, shop);
					SetConsoleTextAttribute(h, 15);
					cout << "Divine Rapier ";
					SetConsoleTextAttribute(h, 10);
					cout << setw(2) << char(186) << DivineRapierPrice << char(186) << " +350 damage";
				}

				else
				{
					shop.Y = y;
					shop.X = x;
					SetConsoleCursorPosition(h, shop);
					SetConsoleTextAttribute(h, 15);
					cout << "Divine Rapier ";
					SetConsoleTextAttribute(h, 4);
					cout << setw(2) << char(186) << "SOLD OUT!" << char(186);
				}
			}

			else if (x == cols + 5 && y == (rows / 2) + 9) // exit
			{
				shop.Y = y;
				shop.X = x;
				SetConsoleCursorPosition(h, shop);
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

			// покупка ----------------------------------------
			else if (code == 13 && cursor.Y != (rows / 2) + 9)
			{
				// если не хватает бабок
				if (money < price[cursor.Y - (rows / 2 + 4)])
				{
					COORD MoneyTxt;
					MoneyTxt.X = cols + 3;
					MoneyTxt.Y = rows;

					SetConsoleCursorPosition(h, MoneyTxt);
					SetConsoleTextAttribute(h, 4);

					string NotEnough = "Not enough money!";

					for (int i = 0; i < NotEnough.length(); i++)
					{
						Sleep(25);
						cout << NotEnough[i];
					}

					Sleep(1000);
					SetConsoleCursorPosition(h, MoneyTxt);
					SetConsoleTextAttribute(h, 0);

					for (int i = 0; i < NotEnough.length() + 1; i++)
					{
						Sleep(25);
						cout << " ";
					}
				}

				// если хватает бабок
				else if (money >= price[cursor.Y - (rows / 2 + 4)])
				{
					// по отдельным айтамам ------------------

					if (cursor.Y == (rows / 2) + 4)
					{
						// Item 1
						if (!buckler)
						{
							if (BucklerPrice <= 0)
							{
								BucklerPrice = 1;
							}

							COORD MoneyTxt;
							MoneyTxt.X = cols + 3;
							MoneyTxt.Y = rows + 1;

							SetConsoleCursorPosition(h, MoneyTxt);
							SetConsoleTextAttribute(h, 2);

							money -= BucklerPrice;
							buckler = 1;

							int temp_armor = armor;
							armor += 4;

							string Enough = "Armor increased! ";

							for (int i = 0; i < Enough.length(); i++)
							{
								Sleep(15);
								cout << Enough[i];
							}
							cout << temp_armor << " " << char(16) << " " << armor;

							Sleep(1500);
							SetConsoleCursorPosition(h, MoneyTxt);
							for (int i = 0; i <= Enough.length() + 20; i++)
							{
								Sleep(15);
								cout << " ";
							}

							stats.Y = 7;
							SetConsoleCursorPosition(h, stats);
							SetConsoleTextAttribute(h, 14);
							cout << "-==|Money: " << money << (char)36 << setw(11) << "|==-";

							for (int y = (rows / 2) + 3; y < (rows / 2) + 10; y++)
							{
								for (int x = cols + 3; x < cols + 45; x++)
								{
									shop.Y = y;
									shop.X = x;
									SetConsoleCursorPosition(h, shop);
									cout << " ";
								}
							}
							return;
						}

					}

					else if (cursor.Y == (rows / 2) + 5)
					{
						//Item 2
						if (!axe)
						{
							if (QuellingBladePrice <= 0)
							{
								QuellingBladePrice = 1;
							}

							COORD MoneyTxt;
							MoneyTxt.X = cols + 3;
							MoneyTxt.Y = rows + 1;

							SetConsoleCursorPosition(h, MoneyTxt);
							SetConsoleTextAttribute(h, 2);

							money -= QuellingBladePrice;
							axe = 1;

							int temp_dmg = dmg;
							dmg += 12;

							string Enough = "Damage increased! ";

							for (int i = 0; i < Enough.length(); i++)
							{
								Sleep(15);
								cout << Enough[i];
							}
							cout << temp_dmg << " " << char(16) << " " << dmg;

							Sleep(1500);
							SetConsoleCursorPosition(h, MoneyTxt);
							for (int i = 0; i <= Enough.length() + 20; i++)
							{
								Sleep(15);
								cout << " ";
							}

							stats.Y = 7;
							SetConsoleCursorPosition(h, stats);
							SetConsoleTextAttribute(h, 14);
							cout << "-==|Money: " << money << (char)36 << setw(11) << "|==-";

							for (int y = (rows / 2) + 3; y < (rows / 2) + 10; y++)
							{
								for (int x = cols + 3; x < cols + 45; x++)
								{
									shop.Y = y;
									shop.X = x;
									SetConsoleCursorPosition(h, shop);
									cout << " ";
								}
							}
							return;
						}
					}

					else if (cursor.Y == (rows / 2) + 6)
					{
						//Item 3
						if (!platemail)
						{
							if (PlatemailPrice <= 0)
							{
								PlatemailPrice = 1;
							}

							COORD MoneyTxt;
							MoneyTxt.X = cols + 3;
							MoneyTxt.Y = rows + 1;

							SetConsoleCursorPosition(h, MoneyTxt);
							SetConsoleTextAttribute(h, 2);

							money -= PlatemailPrice;
							platemail = 1;

							int temp_armor = armor;
							armor += 14;

							string Enough = "Armor increased! ";

							for (int i = 0; i < Enough.length(); i++)
							{
								Sleep(15);
								cout << Enough[i];
							}
							cout << temp_armor << " " << char(16) << " " << armor;

							Sleep(1500);
							SetConsoleCursorPosition(h, MoneyTxt);
							for (int i = 0; i <= Enough.length() + 20; i++)
							{
								Sleep(15);
								cout << " ";
							}

							stats.Y = 7;
							SetConsoleCursorPosition(h, stats);
							SetConsoleTextAttribute(h, 14);
							cout << "-==|Money: " << money << (char)36 << setw(11) << "|==-";

							for (int y = (rows / 2) + 3; y < (rows / 2) + 10; y++)
							{
								for (int x = cols + 3; x < cols + 45; x++)
								{
									shop.Y = y;
									shop.X = x;
									SetConsoleCursorPosition(h, shop);
									cout << " ";
								}
							}
							return;
						}
					}

					else if (cursor.Y == (rows / 2) + 7)
					{
						//Item 4
						if (!claymore)
						{
							if (ClaymorePrice <= 0)
							{
								ClaymorePrice = 1;
							}

							COORD MoneyTxt;
							MoneyTxt.X = cols + 3;
							MoneyTxt.Y = rows + 1;

							SetConsoleCursorPosition(h, MoneyTxt);
							SetConsoleTextAttribute(h, 2);

							money -= ClaymorePrice;
							claymore = 1;

							int temp_dmg = dmg;
							dmg += 24;

							string Enough = "Damage increased! ";

							for (int i = 0; i < Enough.length(); i++)
							{
								Sleep(15);
								cout << Enough[i];
							}
							cout << temp_dmg << " " << char(16) << " " << dmg;

							Sleep(1500);
							SetConsoleCursorPosition(h, MoneyTxt);
							for (int i = 0; i <= Enough.length() + 20; i++)
							{
								Sleep(15);
								cout << " ";
							}

							stats.Y = 7;
							SetConsoleCursorPosition(h, stats);
							SetConsoleTextAttribute(h, 14);
							cout << "-==|Money: " << money << (char)36 << setw(11) << "|==-";

							for (int y = (rows / 2) + 3; y < (rows / 2) + 10; y++)
							{
								for (int x = cols + 3; x < cols + 45; x++)
								{
									shop.Y = y;
									shop.X = x;
									SetConsoleCursorPosition(h, shop);
									cout << " ";
								}
							}
							return;
						}
					}

					else if (cursor.Y == (rows / 2) + 8)
					{
						//Item 5
						if (!rapier)
						{
							if (DivineRapierPrice <= 0)
							{
								DivineRapierPrice = 1;
							}

							COORD MoneyTxt;
							MoneyTxt.X = cols + 3;
							MoneyTxt.Y = rows + 1;

							SetConsoleCursorPosition(h, MoneyTxt);
							SetConsoleTextAttribute(h, 2);

							money -= DivineRapierPrice;
							rapier = 1;

							int temp_dmg = dmg;
							dmg += 350;

							string Enough = "Damage increased! ";

							for (int i = 0; i < Enough.length(); i++)
							{
								Sleep(15);
								cout << Enough[i];
							}
							cout << temp_dmg << " " << char(16) << " " << dmg;

							Sleep(1500);
							SetConsoleCursorPosition(h, MoneyTxt);
							for (int i = 0; i <= Enough.length() + 20; i++)
							{
								Sleep(15);
								cout << " ";
							}

							stats.Y = 7;
							SetConsoleCursorPosition(h, stats);
							SetConsoleTextAttribute(h, 14);
							cout << "-==|Money: " << money << (char)36 << setw(11) << "|==-";

							for (int y = (rows / 2) + 3; y < (rows / 2) + 10; y++)
							{
								for (int x = cols + 3; x < cols + 45; x++)
								{
									shop.Y = y;
									shop.X = x;
									SetConsoleCursorPosition(h, shop);
									cout << " ";
								}
							}
							return;
						}
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
						shop.Y = y;
						shop.X = x;
						SetConsoleCursorPosition(h, shop);
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
