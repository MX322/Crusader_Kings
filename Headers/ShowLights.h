#include "Headers/Global.h"

void light(int beginX, int beginY, int value, int color, int time)
{
	COORD indicator;

	// открисовка индекатора --------------------------------
	for (int y = beginY - 2; y >= beginY - 3; y--)
	{
		for (int x = beginX + value; x <= beginX + value + 3; x++)
		{

			indicator.Y = y;
			indicator.X = x;

			SetConsoleCursorPosition(h, indicator);
			SetConsoleTextAttribute(h, color);


			cout << (char)219;

		}
	}
	Sleep(time);
}