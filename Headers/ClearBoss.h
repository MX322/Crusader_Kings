#pragma once

void clear(int beginX, int beginY)
{
	for (int y = beginY - 2; y >= beginY - 3; y--)
	{
		for (int x = beginX + 1; x <= beginX + 37 + 4; x++)
		{

			COORD clear;
			clear.Y = y;
			clear.X = x;

			SetConsoleCursorPosition(h, clear);

			cout << " ";
		}
	}
}