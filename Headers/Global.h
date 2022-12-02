#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <windows.h> 
#include <cmath>
#pragma comment(lib, "winmm.lib")
using namespace std;

//FUNCTIONS=====================================================
void ShowIntroLevel();
void ShowMenu();
void ShowLevel();
void ShowIntro();
void ShowOptions();
void ShowHub();
void StartTitles();
void Wasted(string txt, int indent, bool isDeath);
void ShowInventory(int beginX, int beginY, COORD stats_player);
void light(int beginX, int beginY, int value, int color, int time);
void clear(int beginX, int beginY);
void Clear(int y_min, int y_max, int x_min, int x_max);
void ShowShop(COORD shop, COORD player, COORD stats, int cols, int rows);
void ShowUpgrade(COORD upgrade, COORD player, COORD stats, int cols, int rows);
void ShowJokes(COORD jokes, COORD doneArthas, COORD player, int cols, int rows);
void ShowBoss1();
void BossFight();
//=============================================================
