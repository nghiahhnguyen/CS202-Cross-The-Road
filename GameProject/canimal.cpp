#include "header.h"
//Animal
void CANIMAL::Move(int i,int x)
{
	if (mX > 2 && x == 1)
	{
		mX++;
		if (mX + 4 == MAXWIDTH)
			mX = 3;
	}
	if (mX < MAXWIDTH&&x == 2)
	{
		if (mX == 1)
			mX = MAXWIDTH - 1;
		else mX--;
	}
};

int CANIMAL::getX()
{
	return mX;
}

int CANIMAL::getY()
{
	return mY;
}

void CANIMAL::Draw(int y) {};

void CANIMAL::ready()
{
	if (mX == 0)
		mX = 3;
	else if (mX == MAXWIDTH)
		mX = MAXWIDTH - 1;
}