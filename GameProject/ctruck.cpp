#include "header.h"
//Truck
CTRUCK::CTRUCK() :CVEHICLE() {}

void CTRUCK::Draw() {
	CVEHICLE::Draw();
	GotoXY(mX, mY);
	cout << "AA";
	GotoXY(mX, mY + 1);
	cout << "AAAA";
}