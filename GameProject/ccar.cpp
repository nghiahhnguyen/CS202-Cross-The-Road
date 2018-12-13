#include "ccar.h"
//Car
int CCAR::numCar = 3;

void CCAR::Draw() {
	CVEHICLE::Draw();
	//GotoXY(mX, mY);
	//cout << " "<<char(220)<<char(220)<<" ";
	GotoXY(mX, mY + 1);
	cout << char(220)<<char(219)<<char(219)<<char(220);
	GotoXY(mX, mY + 2);
	cout << "0  0";
}

void CCAR::increaseNumCar() {
	++numCar;
}