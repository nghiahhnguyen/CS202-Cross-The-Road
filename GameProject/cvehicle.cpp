#include "header.h"
//Vehicle
void CVEHICLE::Move(int x, int y)
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

int CVEHICLE::getX()
{
	return mX;
}

int CVEHICLE::getY()
{
	return mY;
}

void CVEHICLE::Draw(int y) {};
