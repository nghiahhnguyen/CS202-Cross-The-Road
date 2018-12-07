#include "cgame.h"

CGAME::CGAME()
{
    trucks = new CTRUCK[10];
    cars = new CCAR[10];
    dinosaurs = new CDINOSAUR[10];
    birds = new CBIRD[10];
	vehicles = new CVEHICLE*[2];
	vehicles[0] = trucks;
	vehicles[1] = cars;
	animals = new CANIMAL*[2];
	animals[0] = dinosaurs;
	animals[1] = birds;

    for (int i = 0; i < getPlayer().getLevel(); ++i) {
		CTRUCK tmpTruck(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH/10)), 17);
		trucks[i] = tmpTruck;
		CCAR tmpCar(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 13);
		cars[i] = tmpCar;
		CDINOSAUR tmpDino(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 9);
		dinosaurs[i] = tmpDino;
		CBIRD tmpBird(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 5);
		birds[i] = tmpBird;
    }
}

CGAME::~CGAME() {
	delete[] trucks;
	delete[] cars;
	delete[] dinosaurs;
	delete[] birds;
	delete[] vehicles;
	delete[] animals;
}

void CGAME::drawBackground()
{
    for (int i = 0; i < MAXHEIGHT; i++) {
        for (int j = 2; j < MAXWIDTH + 1; j++) {
            if (j == MAXWIDTH || j == 2) {
                GotoXY(j, i);
                wcout << "|";
            } else if (i == MAXHEIGHT - 1 || i % 4 == 0) {
                GotoXY(j, i);
                wcout << "-";
            }
        }
    }
}

void CGAME::drawGame()
{
    //player.DrawPLayer();
    for (int i = 0; i < player.getLevel(); i++) {
        trucks[i].Draw();
        cars[i].Draw();
        birds[i].Draw();
        dinosaurs[i].Draw();
    }
    //Sleep(100);
}

void CGAME::updatePosPlayer(char a)
{
    if (a == 'w')
        player.Up(4);
    else if (a == 'a')
        player.Left(5);
    else if (a == 'd')
        player.Right(5);
    else if (a == 's')
        player.Down(4);
}

void CGAME::updatePosVehicle()
{
    for (int i = 0; i < player.getLevel(); i++) {
        if (trucks[i].mX + 5 >= MAXWIDTH) {
            trucks[i].Move(3, trucks[i].mY);
        } else {
            trucks[i].Move(trucks[i].mX + 2, trucks[i].mY);
        }
        if (cars[i].mX <= 5) {
            cars[i].Move(MAXWIDTH - 4, cars[i].mY);
        } else {
            cars[i].Move(cars[i].mX - 3, cars[i].mY);
        }
    }
}

void CGAME::updatePosAnimal()
{
    for (int i = 0; i < player.getLevel(); i++) {
        if (birds[i].mX <= 5) {
            birds[i].Move(MAXWIDTH - 4, birds[i].mY);
        } else {
            birds[i].Move(birds[i].mX - 3, birds[i].mY);
        }
        if (dinosaurs[i].mX + 4 >= MAXWIDTH) {
            dinosaurs[i].Move(3, dinosaurs[i].mY);
        } else {
            dinosaurs[i].Move(dinosaurs[i].mX + 1, dinosaurs[i].mY);
        }
    }
}

CPEOPLE& CGAME::getPlayer()
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

void CGAME::increaseTrafficAndFlock()
{
    trucks->increaseNumTruck();
    cars->increaseNumCar();
    birds->increaseNumBird();
    dinosaurs->increaseNumDino();
}

bool CGAME::isFinish() {
	return getPlayer().getLevel() > 10;
}

void CGAME::makeSound() {
	birds[0].Tell();
}

void CGAME::updateLevel() {
	GotoXY(45, 27);
	cout << "              ";
	GotoXY(45, 27);
	cout << "LEVEL " << getPlayer().getLevel();
}