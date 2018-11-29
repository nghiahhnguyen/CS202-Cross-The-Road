#include "header.h"
//Truck
CTRUCK::CTRUCK() :CVEHICLE() {};
void CTRUCK::Draw(int y)
{
	int i = getX(); int j = 6;
	if (i + j == MAXWIDTH)
	{
		GotoXY(i + j, 13);
		cout << "|";
		GotoXY(i + j, 14);
		cout << "|";
		GotoXY(i + j, 15);
		cout << "|";
		j--;
	}
	else
	{
		GotoXY(i, 13);
		cout << "AAAAA";
		GotoXY(i - 1, 13);
		cout << " ";
		GotoXY(i, 14);
		cout << "AAAAAAA";
		GotoXY(i - 1, 14);
		cout << " ";
		GotoXY(i, 15);
		cout << "AAAAAAA";
		GotoXY(i - 1, 15);
		cout << " ";
	}
	if (i > 1)
	{
		GotoXY(i - 1, 13);
		cout << " ";
		GotoXY(i - 1, 14);
		cout << " ";
		GotoXY(i - 1, 15);
		cout << " ";
	}
	else if (i == 1)
	{
		GotoXY(i - 1, 13);
		cout << "|";
		GotoXY(i - 1, 14);
		cout << "|";
		GotoXY(i - 1, 15);
		cout << "|";
	}
	Sleep(50);
}

void CTRUCK::Move(int x, int y)
{
	CVEHICLE::Move(1, y);
}

int CTRUCK::getX()
{
	return CVEHICLE::getX();
}

int CTRUCK::getY()
{
	return CVEHICLE::getY();
}