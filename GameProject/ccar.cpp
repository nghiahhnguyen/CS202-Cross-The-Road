#include "header.h"
//Car
CCAR::CCAR() :CVEHICLE() {};
void CCAR::Move(int x, int y)
{
	CVEHICLE::Move(1, y);
}

int CCAR::getX()
{
	return CVEHICLE::getX();
}

int CCAR::getY()
{
	return CVEHICLE::getY();
}
void CCAR::Draw(int y)
{
	GotoXY(getX(), y);
	int j = 6;
	for (int i = 1; i<MAXWIDTH + 1; i++)
	{
		if (i + j == MAXWIDTH)
		{
			GotoXY(i + j, 17);
			cout << "|";
			GotoXY(i + j, 18);
			cout << "|";
			GotoXY(i + j, 19);
			cout << "|";
			j--;
		}
		else
		{
			GotoXY(i, 17);
			cout << "AAAAA";
			GotoXY(i - 1, 17);
			cout << " ";
			GotoXY(i, 18);
			cout << "AAAAAAA";
			GotoXY(i - 1, 18);
			cout << " ";
			GotoXY(i, 19);
			cout << "AAAAAAA";
			GotoXY(i - 1, 19);
			cout << " ";
		}
		if (i > 1)
		{
			GotoXY(i - 1, 17);
			cout << " ";
			GotoXY(i - 1, 18);
			cout << " ";
			GotoXY(i - 1, 19);
			cout << " ";
		}
		else if (i == 1)
		{
			GotoXY(i - 1, 17);
			cout << "|";
			GotoXY(i - 1, 18);
			cout << "|";
			GotoXY(i - 1, 19);
			cout << "|";
		}
		Sleep(50);
	}
}