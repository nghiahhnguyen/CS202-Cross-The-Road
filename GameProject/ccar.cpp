#include "ccar.h"
//Car
int CCAR::numCar = 3;

void CCAR::Draw() {
	CVEHICLE::Draw();
	GotoXY(mX, mY);
	cout << "AA";
	GotoXY(mX, mY + 1);
	cout << "AAAA";
}

void CCAR::increaseNumCar() {
	++numCar;
}