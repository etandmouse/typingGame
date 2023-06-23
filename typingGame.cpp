#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void gotoxy(int x, int y);
void bulletMoving();

int main(void)
{

	printf("%c", 'A');
	bulletMoving();
	system("pause");
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
		printf("%c", 'A');
		Sleep(1000);
		bullet.Y--;
	}
}