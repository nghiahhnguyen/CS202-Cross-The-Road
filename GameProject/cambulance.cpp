#include "cambulance.h"
//Truck
int CAMBULANCE::numAmbulance = 1;

void CAMBULANCE::DrawRight() {
	CVEHICLE::Draw();
	GotoXY(prevX, prevY+2);
	cout << "    ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	GotoXY(mX+1, mY);
	cout << char(254);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	GotoXY(mX, mY+1);
	cout <<char(219)<< char(219)<<char(219)<<char(220);
	GotoXY(mX, mY + 2);
	cout << "0  0";
}

void CAMBULANCE::DrawLeft()
{
	CVEHICLE::Draw();
	GotoXY(prevX, prevY+2);
	cout << "    ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	GotoXY(mX + 2, mY);
	cout << char(254);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	GotoXY(mX, mY + 1);
	cout <<char(220)<<char(219)<<char(219)<<char(219);
	GotoXY(mX, mY + 2);
	cout << "0  0";
}

