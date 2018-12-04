#include "header.h"

CGAME::CGAME()
{
	for (int i = 0; i < 3; ++i) {
		CTRUCK tmpTruck(3*4, i*MAXWIDTH / 3);
		trucks.push_back(tmpTruck);
		CCAR tmpCar(1*4, i*MAXWIDTH / 3);
		cars.push_back(tmpCar);
		CDINOSAUR tmpDino(4, i*MAXWIDTH / 3);
		dinosaurs.push_back(tmpDino);
		CBIRD tmpBird(0, i*MAXWIDTH / 3);
	}
}

void CGAME::drawBackground()
{
	for (int i = 0; i < MAXHEIGHT; i++)
	{
		for (int j = 2; j < MAXWIDTH + 1; j++)
		{
			if (j == MAXWIDTH || j == 2)
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
	//player.DrawPLayer();
	for (int i = 0; i < player.getLevel(); i++)
	{
		for (int j = 0; j < 2; ++j) {
			for(int k = 0; k < )
		}
	}
	Sleep(50);
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
	for (int i = 0; i < player.getLevel(); i++)
	{
		if (i > 0)
		{
			if ( truck[i].getX() +20 < truck[i - 1].getX())
			{
				truck[i].ready();
				truck[i].Move(i, 1);
			}
			else truck[i].Move(i, 1);
			if ( car[i].getX() - 20 > car[i - 1].getX())
			{
				car[i].ready();
				car[i].Move(i, 2);
			}
			else car[i].Move(i,2);
		}
		else
		{
			truck[i].ready();
			truck[i].Move(i, 1);
			car[i].ready();
			car[i].Move(i, 2);
		}
	}
}

void CGAME::updatePosAnimal()
{
	for (int i = 0; i < player.getLevel(); i++)
	{
		if (i > 0)
		{
			if (dinosaur[i].getX() + 25 < dinosaur[i - 1].getX())
			{
				dinosaur[i].ready();
				dinosaur[i].Move(i, 1);
			}
			else dinosaur[i].Move(i, 1);
			if (bird[i].getX() - 15 > bird[i - 1].getX())
			{
				bird[i].ready();
				bird[i].Move(i, 2);
			}
			else bird[i].Move(i, 2);
		}
		else
		{
			dinosaur[i].ready();
			dinosaur[i].Move(i, 1);
			bird[i].ready();
			bird[i].Move(i, 2);
		}
	}
}


CPEOPLE CGAME::getPlayer()
{
	return this->player;
}

CVEHICLE** CGAME::getVehicle()
{
	return vehicle; 
}

CANIMAL** CGAME::getAnimal()
{
	return animal;
}

