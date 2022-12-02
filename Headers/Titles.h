#include "Headers/Global.h"
#include "Headers/Menu.h"

//LOGO SOUND==================================================
DWORD WINAPI Logo(void* param)
{
	PlaySoundA("Sounds/showLogo.WAV", NULL, SND_NODEFAULT | SND_ASYNC);
	return 0;
}
//============================================================

void StartTitles()
{
	CONSOLE_FONT_INFOEX font;

	font.cbSize = sizeof(font);
	font.dwFontSize.Y = 30;
	system("color 0F");

	COORD IntroTxt;
	IntroTxt.X = 30;
	IntroTxt.Y = 4;

	string intro0 = "CCGames Presents";

	SetConsoleCursorPosition(h, IntroTxt);
	for (int i = 0; i < intro0.length(); i++)
	{
		Sleep(100);
		cout << intro0[i];
	}
	Sleep(500);

	SetConsoleCursorPosition(h, IntroTxt);
	for (int i = 0; i < intro0.length() + 1; i++)
	{
		Sleep(100);
		cout << " ";
	}
	system("cls");

	MoveWindow(GetConsoleWindow(), 220, 80, 1200, 700, true);
	font.cbSize = sizeof(font);
	font.dwFontSize.Y = 45;
	SetCurrentConsoleFontEx(h, 0, &font);

	cout << "\n\n\n" << setw(35) << "-===8===-" << endl;
	SetConsoleTextAttribute(h, 4);
	cout << "\n" << setw(39) << "Crusader Kings IV" << endl;
	SetConsoleTextAttribute(h, 15);
	cout << "\n" << setw(35) << "-===8===-" << endl;

	CreateThread(0, 0, Logo, 0, 0, 0);
	Sleep(2700);
	system("cls");
	ShowIntro();
}
