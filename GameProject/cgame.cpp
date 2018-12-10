#include "cgame.h"
#include <algorithm>

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
        CTRUCK tmpTruck(min(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 110), 17);
        trucks[i] = tmpTruck;
        CCAR tmpCar(min(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 110), 13);
        cars[i] = tmpCar;
        CDINOSAUR tmpDino(min(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 110), 9);
        dinosaurs[i] = tmpDino;
        CBIRD tmpBird(min(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 110), 5);
        birds[i] = tmpBird;
    }
}

void CGAME::updateObstacle()
{
    for (int i = 0; i < getPlayer().getLevel(); ++i) {
        CTRUCK tmpTruck(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 17);
        trucks[i] = tmpTruck;
        CCAR tmpCar(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 13);
        cars[i] = tmpCar;
        CDINOSAUR tmpDino(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 9);
        dinosaurs[i] = tmpDino;
        CBIRD tmpBird(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 5);
        birds[i] = tmpBird;
    }
}

CGAME::~CGAME()
{
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
    if (trucklane.getGreen()) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        GotoXY(MAXWIDTH + 1, 18);
        cout << " ";
        GotoXY(MAXWIDTH + 1, 17);
        cout << char(254);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    } else if (!trucklane.getGreen()) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        GotoXY(MAXWIDTH + 1, 17);
        cout << " ";
        GotoXY(MAXWIDTH + 1, 18);
        cout << char(254);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    if (carlane.getGreen()) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        GotoXY(1, 14);
        cout << " ";
        GotoXY(1, 13);
        cout << char(254);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    } else if (!carlane.getGreen()) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        GotoXY(1, 13);
        cout << " ";
        GotoXY(1, 14);
        cout << char(254);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
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
        player.Left(2);
    else if (a == 'd')
        player.Right(2);
    else if (a == 's')
        player.Down(4);
}

void CGAME::updatePosVehicle()
{
    for (int i = 0; i < player.getLevel(); i++) {
        if (trucklane.getGreen()) {
            if (trucks[i].mX + 5 >= MAXWIDTH) {
                trucks[i].Move(3, trucks[i].mY);
            } else {
                trucks[i].Move(trucks[i].mX + 2, trucks[i].mY);
            }
        }
        if (carlane.getGreen()) {
            if (cars[i].mX <= 5) {
                cars[i].Move(MAXWIDTH - 4, cars[i].mY);
            } else {
                cars[i].Move(cars[i].mX - 3, cars[i].mY);
            }
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

bool CGAME::isFinish()
{
    return getPlayer().getLevel() > 5;
}

void CGAME::makeSound()
{
    birds[0].Tell();
}

void CGAME::updateLevel()
{
    GotoXY(45, 30);
    cout << "              ";
    GotoXY(45, 30);
    cout << "LEVEL " << getPlayer().getLevel();
}

void CGAME::eraseOldObstacle()
{
    for (int i = 0; i < getPlayer().getLevel(); ++i) {
        trucks[i].CVEHICLE::Erase();
        cars[i].CVEHICLE::Erase();
        dinosaurs[i].CANIMAL::Erase();
        birds[i].CANIMAL::Erase();
    }
}

void CGAME::resetGame()
{
    eraseOldObstacle();
    // TODO: FIX THIS BUG
	for (int i = 0; i < MAXHEIGHT; i++)
	{
		GotoXY(MAXWIDTH, i);
		cout << '|';
		GotoXY(2, i);
		cout << '|';
	}
    getPlayer().eraseOldPlayer();
    getPlayer().resetPosition();
    getPlayer().DrawPLayer();
    updateObstacle();
}

void CGAME::exitGame(thread* t1, bool& IS_RUNNING)
{
	Sleep(60000);
    IS_RUNNING = false;
    if (t1->joinable())
        t1->join();
    system("cls");
}

void CGAME::startGame()
{
}

void CGAME::pauseGame(HANDLE hd)
{
    SuspendThread(hd);
}

void CGAME::resumeGame(HANDLE hd)
{
	ResumeThread(hd);

}

CTRAFFICLIGHT& CGAME::getTruckLaneLight()
{
    return trucklane;
}

CTRAFFICLIGHT& CGAME::getCarLaneLight()
{
    return carlane;
}

//ambulance effect
void CGAME::ambulanceEffect()
{
	if (player.getY() == 17 )
	{
		for (int i = 0; i < getPlayer().getLevel(); ++i)
			trucks[i].CVEHICLE::Erase();
	}
	else if (player.getY() == 13)
	{
		for (int i = 0; i < getPlayer().getLevel(); ++i)
			cars[i].CVEHICLE::Erase();
	}
	else if (player.getY() == 9)
	{
		for (int i = 0; i < getPlayer().getLevel(); ++i)
			dinosaurs[i].CANIMAL::Erase();
	}
	else if (player.getY() == 5)
	{
		for (int i = 0; i < getPlayer().getLevel(); ++i)
			birds[i].CANIMAL::Erase();
	}
	GotoXY(mX, mY);
	cout << "\\ /";
	GotoXY(mX, mY + 1);
	cout << " X ";
	GotoXY(mX, mY + 2);
	cout << "/" << " " << "\\";
	if (player.getX() > MAXWIDTH / 2)
	{
		CAMBULANCE ambulance(3, player.getY());
		for (int i = 1; i < 100; i++)
		{
			if (ambulance.mX + 5 >= player.getX()) {
				ambulance.Move(ambulance.mX, ambulance.mY);
			}
			else 
			{
				ambulance.Move(ambulance.mX + 2, ambulance.mY);
			}
			ambulance.DrawRight();
			Sleep(50);
		}
		player.eraseOldPlayer();
		for (int i = 1; i < 100; i++)
		{
			if (ambulance.mX  <= 5)
			{
				GotoXY(ambulance.mX, player.getY());
				cout << "    ";
				GotoXY(ambulance.mX, player.getY() + 1);
				cout << "    ";
				GotoXY(ambulance.mX, player.getY() + 2);
				cout << "    ";
			}
			else {
				ambulance.Move(ambulance.mX - 2, ambulance.mY);
				ambulance.DrawLeft();
			}
				Sleep(50);
		}
	}
	else if (player.getX() < MAXWIDTH / 2)
	{
		CAMBULANCE ambulance(MAXWIDTH-4, player.getY());
		for (int i = 1; i < 100; i++)
		{
			if (ambulance.mX <= player.getX()+ 5) {
				ambulance.Move(ambulance.mX, ambulance.mY);
			}
			else {
				ambulance.Move(ambulance.mX - 2, ambulance.mY);

			}
			ambulance.DrawLeft();
			Sleep(50);
		}
		player.eraseOldPlayer();
		for (int i = 0; i < 100; i++)
		{
			if (ambulance.mX + 5 >=MAXWIDTH)
			{
				GotoXY(ambulance.mX, player.getY());
				cout << "    ";
				GotoXY(ambulance.mX, player.getY()+1);
				cout << "    ";
				GotoXY(ambulance.mX, player.getY()+2);
				cout << "    ";
			}
			else {
				ambulance.Move(ambulance.mX + 2, ambulance.mY);
				ambulance.DrawRight();
			}
			Sleep(50);
		}
	}
}
