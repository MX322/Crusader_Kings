#include "Headers/Global.h"


void Clear(int y_min, int y_max, int x_min, int x_max)
{
	COORD Clear;
	Clear.X = x_min;
	Clear.Y = y_min;

	for (int y = y_min; y < y_max; y++)
	{
		for (int x = x_min; x < x_max; x++)
		{
			Clear.Y = y;
			Clear.X = x;
			SetConsoleCursorPosition(h, Clear);
			cout << " ";
		}
	}
}
