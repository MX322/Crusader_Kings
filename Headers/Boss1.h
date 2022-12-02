#include "Headers/Global.h"
#include "Headers/Boss1Fight.h"

//BEFORE BOSS ROOM============================================
DWORD WINAPI Silence_room(void* param)
{
    PlaySoundA("Sounds/Silence.WAV", NULL, SND_ASYNC | SND_LOOP);
    return 0;
}
//============================================================

void ShowBoss1()
{
    CreateThread(0, 0, Silence_room, 0, 0, 0);
    srand(time(0));

    extern int color;

    extern int hp;
    extern int money;

    CONSOLE_FONT_INFOEX font;

    font.cbSize = sizeof(font);
    font.dwFontSize.Y = 30;
    font.FontFamily = FF_DONTCARE;
    font.FontWeight = FW_NORMAL;

    SetCurrentConsoleFontEx(h, 0, &font);
    MoveWindow(GetConsoleWindow(), 220, 80, 1520, 900, true);

    const int rows = 12;
    const int cols = 100;

    int level[rows][cols] = {};

    // 0 - коридор
    // 1 - cтена 
    // 2 - дверь
    // 3 - boss

    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            if (x == 0 || y == 4 || x == cols / 2 - 1 || y == rows - 1)
            {
                level[y][x] = 1; // границы уровня
            }
            if (x > cols / 2 - 1) // коридор
            {
                level[y][x] = 0;
            }
            if (x == 0 && y == rows - 3 || x == cols / 2 - 1 && y == rows - 3) // двери
            {
                level[y][x] = 2;
            }
        }
    }
    //показ лабиринта ----------------------------------
    COORD room;
    room.X = 0;
    room.Y = 4;
    SetConsoleCursorPosition(h, room);

    for (int y = 4; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            if (level[y][x] == 0)
            {
                cout << " ";
            }
            else if (level[y][x] == 2)
            {
                SetConsoleTextAttribute(h, 15);
                cout << (char)186;
            }
            else if (level[y][x] == 1)
            {
                switch (color)
                {
                case 0:
                    SetConsoleTextAttribute(h, 8); // серый 
                    break;
                case 1:
                    SetConsoleTextAttribute(h, 7); // белый
                    break;
                case 2:
                    SetConsoleTextAttribute(h, 14); // желтый
                    break;
                case 3:
                    SetConsoleTextAttribute(h, 3); // синий
                    break;
                }

                cout << (char)219;
            }
        }
        cout << "\n";
    }
    cout << "\n";

    //STATS---------------------------------------------
    COORD stats;
    stats.X = cols / 2 + 4;
    stats.Y = 7;
    SetConsoleCursorPosition(h, stats);
    SetConsoleTextAttribute(h, 12);
    cout << "-==|Health: " << setw(5) << hp << (char)3 << "|==-";

    stats.Y = 4;
    SetConsoleCursorPosition(h, stats);
    SetConsoleTextAttribute(h, 15);
    cout << "-==|Experience: " << setw(1) << experience << (char)21 << "|==-";

    stats.Y = 10;
    SetConsoleCursorPosition(h, stats);
    SetConsoleTextAttribute(h, 14);
    cout << "-==|Money:  " << setw(5) << money << (char)36 << "|==-";
    //---------------------------------------------------
    COORD player;
    player.X = 1;
    player.Y = 9;

    SetConsoleCursorPosition(h, player);
    SetConsoleTextAttribute(h, 9);
    cout << (char)1;

    COORD Boss;
    Boss.X = cols / 2 - 4;
    Boss.Y = 9;

    SetConsoleCursorPosition(h, Boss);
    SetConsoleTextAttribute(h, 4);
    cout << char(126) << (char)2 << char(126);

    while (true)
    {
        if (_kbhit())
        {
            int code = _getch();
            if (code == 224)
            {
                code = _getch();
            }
            //удаление персонажа в старых кординатах------------------
            SetConsoleCursorPosition(h, player);
            cout << " ";
            if (code == 72 && level[player.Y - 1][player.X] != 1 && level[player.Y - 1][player.X] != 2)
            {
                player.Y--;
            }
            else if (code == 80 && level[player.Y + 1][player.X] != 1 && level[player.Y + 1][player.X] != 2)
            {
                player.Y++;
            }
            else if (code == 75 && level[player.Y][player.X - 1] != 1 && level[player.Y][player.X - 1] != 2)
            {
                player.X--;
            }
            else if (code == 77 && level[player.Y][player.X + 1] != 1 && level[player.Y][player.X + 1] != 2)
            {
                player.X++;
            }
            //показ персонажа в новом месте---------------------------
            SetConsoleCursorPosition(h, player);
            SetConsoleTextAttribute(h, 9);
            cout << (char)1;

            //пересечение с боссом------------------------------------
            if (player.Y == Boss.Y && player.X == Boss.X - 2 ||
                player.Y == Boss.Y + 1 && player.X == Boss.X - 1 ||
                player.Y == Boss.Y - 1 && player.X == Boss.X - 1 ||
                player.Y == Boss.Y + 1 && player.X == Boss.X ||
                player.Y == Boss.Y - 1 && player.X == Boss.X)
            {
                system("cls");
                BossFight();
                break;
            }
        }
    }

}
