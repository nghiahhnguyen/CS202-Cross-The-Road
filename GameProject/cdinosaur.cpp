#include "header.h"
//Dinosaur
CDINOSAUR::CDINOSAUR() :CANIMAL(0) {};
void CDINOSAUR::Move(int i,int x)
{
	CANIMAL::Move(i,x);
}

int CDINOSAUR::getX()
{
	return CANIMAL::getX();
}

int CDINOSAUR::getY()
{
	return CANIMAL::getY();
}

void CDINOSAUR::Draw(int y)//y=9
{
	int i = getX();
	if (i + 5 == MAXWIDTH)
	{
		GotoXY(i, y);
		cout << "     ";
		GotoXY(i, y+1);
		cout << "     ";
		GotoXY(i, y+2);
		cout << "     ";
	}
	else
	{
		GotoXY(i, y);
		cout <<" "<< (char)254u << (char)254u <<" ";
		GotoXY(i, y+1);
		cout << " " << (char)254u << (char)254u << (char)254u;
		GotoXY(i, y+2);
		cout << (char)254u << (char)254u << (char)254u << " ";
	}
	if (i > 3)
	{
		GotoXY(i - 1, y);
		cout << " ";
		GotoXY(i - 1, y+1);
		cout << " ";
		GotoXY(i - 1, y+2);
		cout << " ";
	}
	else if (i == 3)
	{
		GotoXY(i - 1, y);
		cout << "|";
		GotoXY(i - 1, y+1);
		cout << "|";
		GotoXY(i - 1, y+2);
		cout << "|";
	}
	//Sleep(50);
}

void CDINOSAUR::ready()
{
	CANIMAL::ready();
}