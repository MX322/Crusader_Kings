#include "Headers/Global.h"
#include "Headers/Titles.h"

int main()
{
	system("title Crusader Kings IV");
	MoveWindow(GetConsoleWindow(), 220, 80, 800, 600, true);

	CONSOLE_FONT_INFOEX font;
	 
	font.cbSize = sizeof(font);
	font.dwFontSize.Y = 25;
	font.FontFamily = FF_DONTCARE;
	font.FontWeight = FW_NORMAL;

	wcscpy_s(font.FaceName, 9, L"Algerian");
	SetCurrentConsoleFontEx(h, 0, &font);

	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = false;
	cursor.dwSize = 1;
	SetConsoleCursorInfo(h, &cursor);

	StartTitles();
}
