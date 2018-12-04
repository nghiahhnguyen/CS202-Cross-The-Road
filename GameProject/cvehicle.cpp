#include "header.h"
//Vehicle
void CVEHICLE::Move(int i,int x)
{
	if (mX > 2 && x==1)
	{
			mX++;
			if (mX + 5 == MAXWIDTH)
				mX = 3;
	}
	if (mX < MAXWIDTH&&x==2)
	{
		if (mX == 1)
			mX = MAXWIDTH - 1;
		else mX--;		
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

void CVEHICLE::ready()
{
	if(mX==0)
		mX = 3;
	else if (mX == MAXWIDTH)
		mX = MAXWIDTH-1;
}