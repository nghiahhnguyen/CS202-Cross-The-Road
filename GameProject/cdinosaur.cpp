#include "header.h"
//Dinosaur
CDINOSAUR::CDINOSAUR() :CANIMAL() {};
void CDINOSAUR::Move(int x, int y)
{
	CANIMAL::Move(x, y);
}

int CDINOSAUR::getX()
{
	return CANIMAL::getX();
}

int CDINOSAUR::getY()
{
	return CANIMAL::getY();
}