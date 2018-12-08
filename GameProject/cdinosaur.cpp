#include "cdinosaur.h"
//Dinosaur
int CDINOSAUR::numDino = 3;

void CDINOSAUR::Draw()//y=5
{
	CANIMAL::Draw();
	GotoXY(mX, mY);
	cout << "  YY";
	GotoXY(mX, mY + 1);
	cout << " YY ";
	GotoXY(mX, mY + 2);
	cout << "YYY ";
}

void CDINOSAUR::Tell() {
	PlaySound(L"dino-snarl (audio-cutter.com).wav", NULL, SND_ASYNC | SND_FILENAME);
}