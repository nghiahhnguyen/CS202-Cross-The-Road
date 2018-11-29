#include "header.h"
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
	mY -= y;
}

void CPEOPLE::Down(int y)
{
	mY += y;
}

void CPEOPLE::Left(int x)
{
	mX -= x;
}

void CPEOPLE::Right(int x)
{
	mX += x;
}

bool CPEOPLE::isImpact1(CVEHICLE *const&vehicle)
{
	for (int i = 0; i < 10; i++)
	{
		if (mX == vehicle[i].getX() && mY == vehicle[i].getY())
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
		if (mX == animal[i].getX() && mY == animal[i].getY())
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
	GotoXY(mX, mY);
	cout << " 0 ";
	cout << "\|/";
	cout << "|'|";
}