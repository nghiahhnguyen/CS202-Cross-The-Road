#include "cbird.h"
//Bird
int CBIRD::numBird = 3;

void CBIRD::Draw()//y=5
{
	CANIMAL::Draw();
	GotoXY(mX, mY);
	cout << "<@__";		
	GotoXY(mX, mY + 1);
	cout << "(_-/";
	GotoXY(mX, mY + 2);
	cout << " \\ \\";
}

void CBIRD::Tell() {
	//if(sound)
		PlaySound(L"crow-1.wav", NULL, SND_FILENAME);
}