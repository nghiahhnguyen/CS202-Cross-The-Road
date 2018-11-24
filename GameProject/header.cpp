#include"header.h"

CGAME::CGAME()
{

}
void CGAME::drawGame()
{

}

void CPEOPLE::Up(int)
{
	//GotoXY(mX, mY);
	//putch('\b');
	mY--;
}

void CPEOPLE::Down(int)
{
	mY++;
}

void CPEOPLE::Left(int)
{
	mX--;
}

void CPEOPLE::Right(int)
{
	mX++;
}

bool CPEOPLE::isImpact(const CVEHICLE*&)
{

}

bool CPEOPLE::isFinish() {

}