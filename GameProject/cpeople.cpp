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
    if (mY - y < 0) {
        // tempY = mY;
        mY = mY;
    } else {
        //	tempY = mY;
        mY -= y;
    }
}

void CPEOPLE::Down(int y)
{
    tempY = mY;
    tempX = mX;
    if (mY + y > MAXHEIGHT) {
        // tempY = mY;
        mY = mY;
    } else {
        // tempY = mY;
        mY += y;
    }
}

void CPEOPLE::Left(int x)
{
    tempY = mY;
    tempX = mX;
    if (mX - x < 3) {
        mX = mX;
    } else {
        // tempX = mX;
        mX -= x;
    }
}

void CPEOPLE::Right(int x)
{
    tempY = mY;
    tempX = mX;
    if (mX + x >= MAXWIDTH) {
        mX = mX;
    } else {
        mX += x;
    }
}

bool CPEOPLE::isImpact1(CVEHICLE* const& vehicle)
{
    if (mY != vehicle[0].mY)
        return false;
    for (int i = 0; i < level; i++) {
        if ((mX <= vehicle[i].mX + 3 && mX >= vehicle[i].mX) || (mX+2 <= vehicle[i].mX && mX+2 >= vehicle[i].mX)) {
            mState = false;
            return true;
        }
    }
    return false;
}

bool CPEOPLE::isImpact2(CANIMAL* const& animal)
{
    if (mY != animal[0].mY)
        return false;
    for (int i = 0; i < level; i++) {
		if ((mX <= animal[i].mX + 3 && mX >= animal[i].mX) || (mX + 2 <= animal[i].mX && mX + 2 >= animal[i].mX)) {
            mState = false;
            return true;
        }
    }
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
    // The size of human image is 3x3
    GotoXY(tempX, tempY);
    cout << "   ";
    GotoXY(tempX, tempY + 1);
    cout << "   ";
    GotoXY(tempX, tempY + 2);
    cout << "   ";
    GotoXY(mX, mY);
    cout << " 0 ";
    GotoXY(mX, mY + 1);
    cout << "<|/";
    GotoXY(mX, mY + 2);
    cout << "|'|";
}

void CPEOPLE::increaseLevel()
{
    if (level < 11) {
        ++level;
    }
}

void CPEOPLE::eraseOldPlayer() {
	GotoXY(mX, mY);
	cout << "   ";
	GotoXY(mX, mY + 1);
	cout << "   ";
	GotoXY(mX, mY + 2);
	cout << "   ";
}

void CPEOPLE::dieEffect()
{
	for (int i = 0; i < 8; i++)
	{
		if (i == 0 || i == 2)
		{
			GotoXY(mX, mY);
			cout << "   ";
			GotoXY(mX, mY + 1);
			cout << "   ";
			GotoXY(mX, mY + 2);
			cout << "   ";
		}
		else
		{
			GotoXY(mX, mY);
			cout << "\\ /";
			GotoXY(mX, mY + 1);
			cout << " X ";
			GotoXY(mX, mY + 2);
			cout << "/" << " " << "\\";
		}
		Sleep(800);
	}
}