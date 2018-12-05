#include "cdinosaur.h"
//Dinosaur
int CDINOSAUR::numDino = 3;

void CDINOSAUR::Draw()//y=5
{
	CANIMAL::Draw();
	GotoXY(mX, mY);
	cout << "YY";
	GotoXY(mX, mY + 1);
	cout << "YYYY";
}