#include "header.h"
//Bird
CBIRD::CBIRD() :CANIMAL() {};
void CBIRD::Move(int x, int y)
{
	CANIMAL::Move(x, y);
}

int CBIRD::getX()
{
	return CANIMAL::getX();
}

int CBIRD::getY()
{
	return CANIMAL::getY();
}