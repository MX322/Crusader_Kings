#include "Headers/Global.h"
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


void ShowOptions()
{
	COORD options;
	options.X = 7 * 4;
	options.Y = 11;
	SetConsoleCursorPosition(h, options);
	SetConsoleTextAttribute(h, 4);

	cout << "-====--====--====-\n";
	cout << "\t\t\t       " << char(30) << " move up \n";
	cout << "\t\t\t       " << char(31) << " move down \n";
	cout << "\t\t\t       " << char(16) << " move right \n";
	cout << "\t\t\t       " << char(17) << " move left \n";
	cout << "\t\t\t       " << "Enter  choice \n";
	cout << "\t\t\t       " << "Space  attack \n";
	cout << "\t\t\t    -====--====--====-";
}
