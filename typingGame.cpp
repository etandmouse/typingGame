/*------------------------------------------------
Game Nmae : Typing Game
Build by : etandmouse@gmail.com
Description : It's a typing game to practice typing English
------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

#define KLETTER_COUNT 10
#define KSPEED 1000
#define KBULLET_SPEED 50

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


// Draw Letter
void drawLetter(char ch, int x, int y);

//Check letter is displayed or not
void judgeLetterDisplay();

//letterMoving: drop down all letters
void letterMoving();

//bulletMoving
void bulletMoving();

//Score
int calcResult();

int main(void)
{
	int k = 0;
	system("cls");
	gotoxy(30, 12);
	printf("Game start!!\n");
	system("pause");
	system("cls");
	initLetters();
	while (letters[KLETTER_COUNT - 1].y < 25)
	{
		letterMoving();
		if (_kbhit())
		{
			char ch = _getch();
			ch = toupper(ch);
			for(k = 0; k < KLETTER_COUNT; k++)
			{ 
				if (letters[k].isDisplay == 1 && letters[k].ch == ch)
				{
					initBullet(letters[k].x);
					while (bullet.y > 0)
					{
						bulletMoving();
						if (bullet.y == letters[k].y)
						{
							letters[k].life = 0;
							bullet.life = 0;
							drawLetter(' ', bullet.x, bullet.y);
							printf("\a");
						}
						Sleep(KBULLET_SPEED);
					}					
				}
			}
		}
		Sleep(KSPEED);
	}

	//Game finished
	gotoxy(30, 12);
	printf("User got %d, total %d\n", calcResult(), KLETTER_COUNT);

	getchar();
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
	bullet.life = 1;
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

void drawLetter(char ch, int x, int y)
{
	gotoxy(x, y);
	printf("%c", ch);
}

void judgeLetterDisplay()
{
	int i = 0;
	for (i = 0; i < KLETTER_COUNT; i++)
	{
		if (letters[i].life == 0)
		{
			letters[i].isDisplay = 0;
		}
		else
		{
			if (letters[i].y < 0 || letters[i].y > 24)
			{
				letters[i].isDisplay = 0;
			}
			else
			{
				letters[i].isDisplay = 1;
			}
		}
	}
}

void letterMoving()
{
	int i = 0;
	judgeLetterDisplay();
	for (i = 0; i < KLETTER_COUNT; i++)
	{
		if (letters[i].y < 25)
		{
			if (letters[i].isDisplay == 1)
			{
				drawLetter(' ', letters[i].x, letters[i].y);
				drawLetter(letters[i].ch, letters[i].x, letters[i].y + 1);
			}
			else
			{
				drawLetter(' ', letters[i].x, letters[i].y);
			}
			letters[i].y++;
		}
		else
		{
			drawLetter(' ', letters[i].x, letters[i].y);
		}
	}
}

void bulletMoving()
{
	if (bullet.life == 1)
	{
		drawLetter(' ', bullet.x, bullet.y);
		drawLetter(bullet.ch, bullet.x, bullet.y - 1);
	}
	bullet.y--;
}

int calcResult()
{
	int counter = 0;
	int i = 0;
	for (i = 0; i < KLETTER_COUNT; i++)
	{
		if (letters[i].life == 0)
		{
			counter++;
		}
	}
	return counter;
}