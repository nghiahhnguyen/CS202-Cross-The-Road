#include "header.h"
//Bird
CBIRD::CBIRD() :CANIMAL(MAXWIDTH) {};
void CBIRD::Move(int i,int x)
{
	CANIMAL::Move(i,x);
}

int CBIRD::getX()
{
	return CANIMAL::getX();
}

int CBIRD::getY()
{
	return CANIMAL::getY();
}

void CBIRD::Draw(int y)//y=5
{
	int i = getX();
	if (i == MAXWIDTH - 1)
	{
		GotoXY(i, y);
		cout << "A";
	}
	else if (i == MAXWIDTH - 2)
	{
		GotoXY(i, y);
		cout << "A ";
		GotoXY(i, y+1);
		cout << " A";
	}
	else if (i == MAXWIDTH - 3)
	{

		GotoXY(i, y);
		cout << "A A";
		GotoXY(i, y+1);
		cout << " A ";
	}
	else if (i < MAXWIDTH - 3 && i>2)
	{
		GotoXY(i, y);
		cout << "A A";
		GotoXY(i + 3, y);
		cout << " ";
		GotoXY(i, y+1);
		cout << " A ";
		GotoXY(i + 3, y+1);
		cout << " ";
	}
	else if (i == 2)
	{
		GotoXY(i, y);
		cout << "|   ";
		GotoXY(i + 4, y);
		cout << " ";
		GotoXY(i, y+1);
		cout << "|   ";
		GotoXY(i + 4, y+1);
		cout << " ";
	}
	//Sleep(50);
}

void CBIRD::ready()
{
	CANIMAL::ready();
}