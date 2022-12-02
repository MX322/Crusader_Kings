#include "Headers/Global.h"
#include "Headers/IntroLevel.h"

void ShowIntro()
{
	CONSOLE_FONT_INFOEX font;

	font.cbSize = sizeof(font);
	font.dwFontSize.Y = 30;
	SetCurrentConsoleFontEx(h, 0, &font);

	MoveWindow(GetConsoleWindow(), 220, 80, 1520, 900, true);

	system("color 0F");
	string intro1 = "\n\n\t\t\t\t\t  France\n";

	for (int i = 0; i < intro1.length(); i++)
	{
		Sleep(50);
		cout << intro1[i];
	}
	Sleep(80);

	string intro2 = "\t\t\t\t\t   1096\n";
	for (int i = 0; i < intro2.length(); i++)
	{
		Sleep(50);
		cout << intro2[i];
	}
	Sleep(80);

	string intro3 = "\t\t\t\t       First Crusade\n\n";

	for (int i = 0; i < intro3.length(); i++)
	{
		Sleep(50);
		cout << intro3[i];
	}

	Sleep(500);

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n Loading Please Wait";
	for (int i = 0; i <= 5; i++)
	{
		Sleep(100);
		cout << "." << flush;
		Sleep(100);
		cout << "." << flush;
		Sleep(100);
		cout << "." << flush;
		Sleep(100);
		cout << "\b\b\b   \b\b\b" << flush;
	}
	system("cls");

	ShowIntroLevel();
}
