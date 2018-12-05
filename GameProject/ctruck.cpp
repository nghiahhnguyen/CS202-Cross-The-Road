#include "ctruck.h"
//Truck
int CTRUCK::numTruck = 3;

void CTRUCK::Draw() {
	CVEHICLE::Draw();
	GotoXY(mX, mY);
	cout << "AAA";
	GotoXY(mX, mY + 1);
	cout << "AAAA";
}

void CTRUCK::increaseNumTruck() {
	numTruck++;
}