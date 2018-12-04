#include "header.h"
//Car
CCAR::CCAR() :CVEHICLE(MAXWIDTH) {};
void CCAR::Move(int i,int x)
{
	CVEHICLE::Move(i,2);
}

int CCAR::getX()
{
	return CVEHICLE::getX();
}

int CCAR::getY()
{
	return CVEHICLE::getY();
}
void CCAR::Draw(int y) //y=13
{
	int i = getX();
	if (i == MAXWIDTH - 1)
	{
		GotoXY(i, y+2);
		cout << (char)254u;
	}
	else if (i == MAXWIDTH - 2)
	{
		GotoXY(i, y+1);
		cout << " "<< (char)254u;
		GotoXY(i, y+2);
		cout << (char)254u<< (char)254u;
	}
	else if (i == MAXWIDTH - 3)
	{

		GotoXY(i, y+1);
		cout << " "<< (char)254u<< (char)254u;
		GotoXY(i, y+2);
		cout << (char)254u<< (char)254u<< (char)254u;
	}
	else if (i == MAXWIDTH - 4)
	{

		GotoXY(i, y+1);
		cout << " "<< (char)254u<< (char)254u<<" ";
		GotoXY(i, y+2);
		cout << (char)254u<< (char)254u<< (char)254u<< (char)254u;
	}
	else if (i == MAXWIDTH - 5)
	{

		GotoXY(i, y + 1);
		cout << " " << (char)254u << (char)254u << " ";
		GotoXY(i, y + 2);
		cout << (char)254u << (char)254u << (char)254u << (char)254u<<" ";
	}
	else if (i < MAXWIDTH - 5 && i>2)
	{
		GotoXY(i, y + 1);
		cout << " " << (char)254u << (char)254u << "  ";
		//GotoXY(i + 4, y+1);
		//cout << " ";
		GotoXY(i, y + 2);
		cout << (char)254u << (char)254u << (char)254u << (char)254u<<" ";
	//	GotoXY(i + 4, y+2);
		//cout << " ";
	}
	else if (i == 2)
	{
		GotoXY(i, y+1);
		cout << "|    ";
	//	GotoXY(i + 4, y+1);
	//	cout << " ";
		GotoXY(i, y+2);
		cout << "|    ";
	//	GotoXY(i + 4, y+2);
	//	cout << " ";
	}
	//Sleep(50);
}