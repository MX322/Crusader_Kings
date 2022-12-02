#include "Headers/Global.h"
// extern тут не используется 

int level = 1; // уровень игрока
int color = 0;
int boss_lifes = 4; //сколько раз нужно ебнуть леорика перед финалом

int hp = 1;
int hp_max = 150;

int armor = 5;

int money = 0;

int dmg = 25;

int recovery = 5;

int experience = 0;

int small_heal = 0;
int medium_heal = 0;
int large_heal = 0;

int luck = 0; //увеличивает кол-во получаемых монеток на уровне и после босса

int speech_price = 0; //уменьшает цены в магазине вещей
int speech_depos = 0; // уменьшает цену при депозите

int depos_money = 150;

int faith = 0;			//вера (уменьшает стоимость прокачки навыков)
int pumping_cost = 400; // стоимость прокачки (растет с каждым уровнем)

bool buckler = 0;	   //куплена шмотка в магазине или нет		// +4 брони
bool axe = 0;		   //куплена шмотка в магазине или нет		// +12 урона
bool platemail = 0;	   //куплена шмотка в магазине или нет		// +14 брони
bool claymore = 0;	   //куплена шмотка в магазине или нет		// +24 урону
bool rapier = 0;	   //куплена шмотка в магазине или нет		// +350 урону
