#include "cpeople.h"
int CPEOPLE::getLevel()
{
	return level;
}

int CPEOPLE::getScore()
{
	return score;
}

void CPEOPLE::Up(int y)
{
	tempY = mY;
	tempX = mX;
	if (mY - y < 0)
	{
		//tempY = mY;
		mY = mY;
	}
	else
	{
	//	tempY = mY;
		mY -= y;
	}
}

void CPEOPLE::Down(int y)
{
	tempY = mY;
	tempX = mX;
	if (mY + y > MAXHEIGHT)
	{
		//tempY = mY;
		mY = mY;
	}
	else 
	{
		//tempY = mY;
		mY += y;
	}
}

void CPEOPLE::Left(int x)
{
	tempY = mY;
	tempX = mX;
	if (mX - x < 3)
	{
		mX = mX;
	}
	else
	{
		//tempX = mX;
		mX -= x;
	}
}

void CPEOPLE::Right(int x)
{
	tempY = mY;
	tempX = mX;
	if (mX + x >= MAXWIDTH)
	{
		mX = mX;
	}
	else {
		mX += x;
	}
}

bool CPEOPLE::isImpact1(CVEHICLE *const&vehicle)
{
	for (int i = 0; i < 10; i++)
	{
		if (mX == vehicle[i].mX && mY == vehicle[i].mY)
		{
			mState = true;
			return true;
		}
	}
	mState = false;
	return false;
}

bool CPEOPLE::isImpact2(CANIMAL *const&animal)
{
	for (int i = 0; i < 10; i++)
	{
		if (mX == animal[i].mX && mY == animal[i].mY)
		{
			mState = true;
			return true;
		}
	}
	mState = false;
	return false;
}

bool CPEOPLE::isFinish()
{
	if (level == 11)
		return true;
	return false;
}

bool CPEOPLE::isDead()
{
	if (mState == true)
		return false;
	return true;
}

void CPEOPLE::DrawPLayer()
{
	GotoXY(tempX, tempY);
	cout << "   ";
	GotoXY(tempX, tempY+1);
	cout << "   ";
	GotoXY(tempX, tempY+2);
	cout << "   ";
	GotoXY(mX, mY);
	cout << " 0 ";
	GotoXY(mX, mY+1);
	cout << "<|/";
	GotoXY(mX, mY+2);
	cout << "|'|";
}
