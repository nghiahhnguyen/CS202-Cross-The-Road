#include "cbird.h"
//Bird
int CBIRD::numBird = 3;

void CBIRD::Draw()//y=5
{
	CANIMAL::Draw();
	GotoXY(mX, mY);
	cout << "Y  Y";		
	GotoXY(mX, mY + 1);
	cout << " YY ";
}

void CBIRD::Tell() {
	PlaySound(L"crow-1.wav", NULL, SND_FILENAME);
}