#include "cbird.h"
//Bird
int CBIRD::numBird = 3;

void CBIRD::Draw()//y=5
{
	CANIMAL::Draw();
	GotoXY(mX, mY);
	cout << "YY";
	GotoXY(mX, mY + 1);
	cout << "YYYY";
}