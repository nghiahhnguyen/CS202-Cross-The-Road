#include "header.h"
//Truck
CTRUCK::CTRUCK() :CVEHICLE(0) {};
void CTRUCK::Draw(int y) //y =17
{
	int i = getX();
	if (i + 6 == MAXWIDTH)
	{
		GotoXY(i, 17);
		cout << "      ";
		GotoXY(i - 1, 17);
		cout << " ";
		GotoXY(i, 18);
		cout << "      ";
		GotoXY(i - 1, 18);
		cout << " ";
		GotoXY(i, 19);
		cout << "      ";
		GotoXY(i - 1, 19);
		cout << " ";
	}
	else {
		GotoXY(i, 17);
		cout <<(char)254u << (char)254u << (char)254u<<(char)254u;
		GotoXY(i, 18);
		cout << (char)254u << (char)254u << (char)254u << (char)254u <<" "<< (char)254u << (char)254u;
		GotoXY(i, 19);
		cout << (char)254u << (char)254u << (char)254u << (char)254u <<" "<< (char)254u << (char)254u;
	}
	if (i > 3)
	{
		GotoXY(i - 1, 17);
		cout << " ";
		GotoXY(i - 1, 18);
		cout << " ";
		GotoXY(i - 1, 19);
		cout << " ";
	}
	else if (i == 3)
	{
		GotoXY(i - 1, 17);
		cout << "|";
		GotoXY(i - 1, 18);
		cout << "|";
		GotoXY(i - 1, 19);
		cout << "|";
	}
	//Sleep(50);
}

void CTRUCK::Move(int i,int x)
{
	CVEHICLE::Move(i,1);
}

int CTRUCK::getX()
{
	return CVEHICLE::getX();
}

int CTRUCK::getY()
{
	return CVEHICLE::getY();
}

void CTRUCK::ready()
{
	CVEHICLE::ready();
}