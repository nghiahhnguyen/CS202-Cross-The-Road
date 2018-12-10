#include "cgame.h"
#include <algorithm>
#include <mutex>

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
    GotoXY(60, 30);
    cout << "              ";
    GotoXY(60, 30);
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
    GotoXY(MAXWIDTH, 7);
    cout << '|';
    getPlayer().eraseOldPlayer();
    getPlayer().resetPosition();
    getPlayer().DrawPLayer();
    updateObstacle();
}

void CGAME::exitGame(thread* t1, bool& IS_RUNNING)
{
    IS_RUNNING = false;
    if (t1->joinable())
        t1->join();
    system("cls");
}

void CGAME::startGame(thread& t1)
{
	if (t1.joinable()) t1.join();
	t1 = thread(SubThread);
}

void CGAME::pauseGame(thread& t1)
{
    SuspendThread(t1.native_handle());
}

void CGAME::resumeGame(thread& t1)
{
	ResumeThread(t1.native_handle());
}

CTRAFFICLIGHT& CGAME::getTruckLaneLight()
{
    return trucklane;
}

CTRAFFICLIGHT& CGAME::getCarLaneLight()
{
    return carlane;
}

bool CGAME::askForRestart() {
	int boxWidth = 42, boxHeight = 4, startBoxX = 44, startBoxY = 32;

	mutex mx;
	mx.lock();

	//Draw the board
	GotoXY(startBoxX, startBoxY);
	for (int j = 0; j < boxWidth; ++j) {
		cout << '=';
	}
	GotoXY(startBoxX, startBoxY + 1);
	for (int j = 0; j < boxWidth; ++j) {
		if (j == 0 || j == boxWidth - 1)
			cout << '|';
		else
			cout << ' ';
	}
	/*GotoXY(startBoxX, startBoxY + 2);
	for (int j = 0; j < boxWidth; ++j) {
		if (j == 0 || j == boxWidth - 1)
			cout << '|';
		else
			cout << ' ';
	}*/
	GotoXY(startBoxX, startBoxY + 2);
	for (int j = 0; j < boxWidth; ++j) {
		cout << '=';
	}
	
	/*string line1;
	if (isDead)
		line1 = "You are dead!";
	else
		line1 = "You have finished the game!";
	GotoXY(startBoxX + (boxWidth - line1.size())/2, startBoxY + 1);
	cout << line1;*/

	string line2 = "Do you want to restart the game? (Y/n)";
	GotoXY(startBoxX + (boxWidth - line2.size()) / 2, startBoxY + 1);
	cout << line2;

	char answer = _getch();
	mx.unlock();
	if (answer == 'y')
		return true;
	else
		return false;
}