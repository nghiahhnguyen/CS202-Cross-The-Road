#include "header.h"
//Animal
void CANIMAL::Move(int x, int y)
{
	if (x > 1)
	{
		mX++;
		if (mX == MAXWIDTH)
			mX = -2;
	}
	else
	{
		mX--;
		if (mX == 0)
			mX = MAXWIDTH + 2;
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