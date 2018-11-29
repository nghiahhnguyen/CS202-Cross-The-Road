#include "header.h"
void CGAME::drawBackground()
{
	for (int i = 0; i < MAXHEIGHT; i++)
	{
		for (int j = 0; j < MAXWIDTH + 1; j++)
		{
			if (j == MAXWIDTH || j == 0)
			{
				GotoXY(j, i);
				wcout << "|";
			}
			else if (i == MAXHEIGHT - 1 || i % 4 == 0)
			{
				GotoXY(j, i);
				wcout << "-";
			}
		}
	}
}

void CGAME::drawGame()
{

	GotoXY(0, MAXHEIGHT + 3);
	wcout << "Score: " << player.getScore << "| Level: " << player.getLevel << endl;
}

void CGAME::updatePosPlayer(char a)
{
	if (a == 'w')
		player.Up(4);
	else if (a == 'a')
		player.Left(2);
	else if (a == 'd')
		player.Right(2);
	else if (a == 's')
		player.Down(4);
}

void CGAME::updatePosVehicle()
{
	for (int i = 0; i < 10; i++)
	{
		truck[i].Move(truck[i].getX(), truck[i].getY());
		car[i].Move(car[i].getX(), car[i].getY());
	}
}

void CGAME::updatePosAnimal()
{
	for (int i = 0; i < 10; i++)
	{
		bird[i].Move(bird[i].getX(), bird[i].getY());
		dinosaur[i].Move(dinosaur[i].getX(), dinosaur[i].getY());
	}
}


CPEOPLE CGAME::getPlayer()
{
	return this->player;
}

CVEHICLE** CGAME::getVehicle()
{
	CVEHICLE **vehicle = new CVEHICLE*[2];
	car = new CCAR;
	truck = new CTRUCK;
	vehicle[0] = car;
	vehicle[1] = truck;
	return vehicle;
}

CANIMAL** CGAME::getAnimal()
{
	CANIMAL **animal = new CANIMAL*[2];
	bird = new CBIRD;
	dinosaur = new CDINOSAUR;
	animal[0] = bird;
	animal[1] = dinosaur;
	return animal;
}