#include "cgame.h"
#include "header.h"
#include <thread>
#include <condition_variable>
#include <random>
#include <chrono>
#include <consoleapi.h>
//#include <cls>
char MOVING;
bool IS_RUNNING = true; 
CGAME cg;
chrono::steady_clock sc;
mutex mx;
int level = 1;

void SubThread()
{
    cg.drawBackground();
	int preLevel = 11;
	int templv = 11;
	auto startTruck = sc.now();
	auto startCar = sc.now();
	while (IS_RUNNING) {
		// functions to simulate traffic lights
		level = cg.getPlayer().getLevel();
		mx.lock();
		auto endTruck = sc.now();
		auto endCar = sc.now();
		auto time_spanTruck = static_cast<chrono::duration<double>>(endTruck - startTruck);
		auto time_spanCar = static_cast<chrono::duration<double>>(endCar - startCar);

		if (templv < cg.getPlayer().getLevel())
		{
			startCar = endCar;
			startTruck = endTruck;
		}
		else
		{
			if (int(time_spanTruck.count()) < 5)
			cg.getTruckLaneLight().setGreen(true);
		else if (int(time_spanTruck.count()) > 5 && int(time_spanTruck.count()) < 10)
			cg.getTruckLaneLight().setGreen(false);
		else if (int(time_spanTruck.count()) > 10)
			startTruck = endTruck;
		if (int(time_spanCar.count()) < 10)
			cg.getCarLaneLight().setGreen(true);
		else if (int(time_spanCar.count()) > 5 && int(time_spanCar.count()) < 15)
			cg.getCarLaneLight().setGreen(false);
		else if (int(time_spanCar.count()) > 15)
			startCar = endCar;
		}
		templv = cg.getPlayer().getLevel();
		mx.unlock();

		bool hitSth = false;
		if (cg.getPlayer().isImpact2(cg.getAnimal()[0])) {
			cg.getAnimal()[0]->Tell();
			hitSth = true;
		}
		if (cg.getPlayer().isImpact2(cg.getAnimal()[1])) {
			cg.getAnimal()[1]->Tell();
			hitSth = true;
		}
		if (cg.getPlayer().isImpact1(cg.getVehicle()[0]) || cg.getPlayer().isImpact1(cg.getVehicle()[1])) {
			hitSth = true;
		}
		if (hitSth) {
			cg.getPlayer().dieEffect();
			cg.getPlayer().setDead();
			cg.ambulanceEffect();
			break;
		}
		cg.updateLevel();
		
		// If player is still alive
		if (!cg.getPlayer().isDead()) 
		{
			if(MOVING != ' ')
				// Update player's position from main
				cg.updatePosPlayer(MOVING); 
		} else {
			IS_RUNNING = false;
			continue;
		}

		// Waiting for next move from main
		MOVING = ' '; 

		mx.lock();
		cg.updatePosVehicle();
		cg.updatePosAnimal();
		cg.drawGame();
		cg.getPlayer().DrawPLayer();
		mx.unlock();
		
		if (cg.getPlayer().getY() == 1) {
			cg.getPlayer().increaseLevel();
			if (cg.isFinish()) {
				break;
			}
			cg.resetGame();
		}
		Sleep(150/difficulty);
	}
}

int main()
{
	int temp = ' ';
	ShowConsoleCursor(false);
	FixConsoleWindow();
	StartMenu();
	EraseMenu();
	thread t1;
	if (menu == 0)
		cg.startGame(t1);
	else if (menu == 1)
	{

	}
	else if (menu == 2)
	{
		Settings();
		EraseMenu();
		if (settings == 0)
		{
			ChangeSound();
		}
		else if (settings == 1)
		{
			DifficultyByLevel(level);
		}
	}
	if (menu != 3)
	{
		while (1) {
			if (_kbhit()) {
				temp = _getch();
				MOVING = temp;
			}
			if (!cg.getPlayer().isDead()) {
				if (temp == 27) {
					cg.exitGame(&t1, IS_RUNNING);
					return 0;
				}
				else if (temp == 'p') {
					cg.pauseGame(t1);
				}
				else {
					cg.resumeGame(t1);
				}
			}
			else {
				Sleep(3000);
				if (cg.askForRestart()) {
					cg.getPlayer() = CPEOPLE();
					system("cls");
					IS_RUNNING = true;
					cg.startGame(t1);
				}
				else {
					cg.exitGame(&t1, IS_RUNNING);
					break;
				}
			}
		}
	}
	system("cls");
	return 0;
}