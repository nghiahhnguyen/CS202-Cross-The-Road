#include "cgame.h"

CGAME::CGAME()
{
	trucks = new CTRUCK[10];
	cars = new CCAR[10];
	dinosaurs = new CDINOSAUR[5];
	birds = new CBIRD[5];

	for (int i = 0; i < 5; ++i) {
		CTRUCK tmpTruck(17, i*MAXWIDTH / 5);
		trucks[i] = tmpTruck;
		CCAR tmpCar(13, i*MAXWIDTH / 5);
		cars[i] = tmpCar;
		CDINOSAUR tmpDino(9, i*MAXWIDTH / 5);
		dinosaurs[i] = tmpDino;
		CBIRD tmpBird(5, i*MAXWIDTH / 5);
		birds[i] = tmpBird;
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
		trucks[i].Draw();
		cars[i].Draw();
		birds[i].Draw();
		dinosaurs[i].Draw();
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
		if (trucks[i].mX + 6 >= MAXWIDTH) {
			trucks[i].Move(0, trucks[i].mY);
		}
		else {
			trucks[i].Move(trucks[i].mX + 3, trucks[i].mY);
		}
		if (cars[i].mX + 6 >= MAXWIDTH) {
			cars[i].Move(0, cars[i].mY);
		}
		else {
			cars[i].Move(cars[i].mX + 3, cars[i].mY);
		}
	}
}

void CGAME::updatePosAnimal()
{
	for (int i = 0; i < player.getLevel(); i++)
	{
		if (birds[i].mX + 6 >= MAXWIDTH) {
			birds[i].Move(0, birds[i].mY);
		}
		else {
			birds[i].Move(birds[i].mX + 3, birds[i].mY);
		}
		if (dinosaurs[i].mX + 6 >= MAXWIDTH) {
			dinosaurs[i].Move(0, dinosaurs[i].mY);
		}
		else {
			dinosaurs[i].Move(dinosaurs[i].mX + 3, dinosaurs[i].mY);
		}
	}
}


CPEOPLE CGAME::getPlayer()
{
	return this->player;
}

CVEHICLE** CGAME::getVehicle()
{
	return vehicles; 
}

CANIMAL** CGAME::getAnimal()
{
	return animals;
}

