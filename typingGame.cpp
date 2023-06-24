#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>

void gotoxy(int x, int y);
void bulletMoving();

int main(void)
{
	//printf("%d", '^');
	//int i = 0;
	////srand((unsigned)time(NULL));
	//for (i = 0; i < 10; i++)
	//{
	//	printf("%d \n", rand());
	//	//printf("%d ", time(NULL));
	//}
	//printf("\n");
	//system("pause");
	char ch;
	while (1)
	{
		ch = _getch();
		
		if (ch == 0x1b)
		{
			break;
		}
		printf("%c\n", ch);
	}
	
	return 0;
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
		printf("%c", 94);
		Sleep(1000);
		bullet.Y--;
	}
}