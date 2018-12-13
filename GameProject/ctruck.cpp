#include "ctruck.h"
//Truck
int CTRUCK::numTruck = 3;

void CTRUCK::Draw() {
	CVEHICLE::Draw();
	//GotoXY(mX, mY);
	//cout << char(220)<<char(220)<<char(220);
	GotoXY(mX, mY + 1);
	cout << char(219)<<char(219)<<char(219)<<char(220);
	GotoXY(mX, mY + 2);
	cout << "0  0";
}

void CTRUCK::increaseNumTruck() {
	++numTruck;
}