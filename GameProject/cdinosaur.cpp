#include "cdinosaur.h"
//Dinosaur
int CDINOSAUR::numDino = 3;

void CDINOSAUR::Draw()//y=5
{
	CANIMAL::Draw();
	GotoXY(mX, mY);
	cout <<"  "<<char(219)<<char(220);
	GotoXY(mX, mY + 1);
	cout <<" "<<char(219)<<char(219);
	GotoXY(mX, mY + 2);
	cout <<char(219)<<char(219)<<char(219);
}

void CDINOSAUR::Tell() {
	//if(sound)
		PlaySound(L"dino-snarl (audio-cutter.com).wav", NULL, SND_ASYNC | SND_FILENAME);
}