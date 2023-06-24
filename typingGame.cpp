/*------------------------------------------------
Game Nmae : Typing Game
Build by : etandmouse@gmail.com
Description : It's a typing game to practice typing English
------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define KLETTER_COUNT 10
#define KSPEED 10

/*-------------------Initial--------------------*/
//Design letter and bullet
typedef struct tag_letter
{
	//ASCII
	char ch;
	//position
	int x;
	int y;
	//Display: 0 off 1 on
	int isDisplay;
	//life 0 die 1 life 
	int life;
}Letter;

Letter letters[KLETTER_COUNT];
Letter bullet;
//Game role initial
void initLetters();
void initBullet(int x);

/*-------------------Functions--------------------*/
// positioning to Command Prompt
void gotoxy(int x, int y);

void bulletMoving();

int main(void)
{

	return 0;
}

void initLetters()
{
	int i = 0;
	srand((unsigned)time(NULL));
	for (i = 0; i < KLETTER_COUNT; i++)
	{
		//Random letter
		letters[i].ch = rand() % 26 + 65;
		//Random x position
		letters[i].x = rand() % 80;
		//y position
		letters[i].y = - 2 * i;
		letters[i].life = 1;
	}
	
}

void initBullet(int x)
{
	bullet.ch = '^';
	bullet.x = x;
	bullet.y = 25;
}

void gotoxy(int x, int y)
{
	HANDLE handle;
	COORD coord;
	coord.X = x;
	coord.Y = y;
	
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(handle, coord);
}

void bulletMoving()
{
	COORD bullet;
	bullet.X = 10;
	bullet.Y = 24;

	//move bullet
	while (bullet.Y > 0)
	{
		gotoxy(bullet.X, bullet.Y);
		printf(" ");
		gotoxy(bullet.X, bullet.Y - 1);
		printf("%c", '^');
		Sleep(1000);
		bullet.Y--;
	}
}