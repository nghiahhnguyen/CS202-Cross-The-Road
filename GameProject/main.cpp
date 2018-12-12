#include "cgame.h"
#include "header.h"
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
bool backToMainMenu = false;

void SubThread()
{
    cg.drawBackground();
	cg.guide();
	int preLevel = 11;
	int templv = 11;
	auto startTruck = sc.now();
	auto startCar = sc.now();
	while (IS_RUNNING) {
		// functions to simulate traffic lights
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

		bool hitSth = false;
		if (cg.getPlayer().isImpact2(cg.getAnimal()[0])) {
			cg.getAnimal()[0]->Tell();
			hitSth = true;
		}
		if (cg.getPlayer().isImpact2(cg.getAnimal()[1])) {
			cg.getAnimal()[1]->Tell();
			hitSth = true;
		}
		if (cg.getPlayer().isImpact1(cg.getVehicle()[0])) {
			cg.getVehicle()[0]->Crash();
			hitSth = true;
		}
		if (cg.getPlayer().isImpact1(cg.getVehicle()[1])) {
			cg.getVehicle()[1]->Crash();
			hitSth = true;
		}
		if (hitSth) {
			cg.getPlayer().dieEffect();
			cg.getPlayer().setDead();
			cg.ambulanceEffect(mx);
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
	//menu = 0;
	while (1)
	{
		StartMenu();
		EraseMenu();
		thread t1;
		if (menu == 0)
		{
			cg.resetData();
			IS_RUNNING = true;
			temp = ' ';
			cg.startGame(t1);
			while (1) {
				if (_kbhit()) {
					temp = _getch();
					MOVING = temp;
				}
				if (!cg.getPlayer().isDead()) {
					if (temp == 27) {
						cg.exitGame(&t1, IS_RUNNING);
						break;
						//return 0;
					}
					else if (temp == 'p') {
						cg.pauseGame(t1);
						while (1)
						{
							IngameMenu();
							EraseMenu();
							if (menuInGame == 0)
							{
								break;
							}
							else if (menuInGame == 1)
							{
								
							}
							else if (menuInGame == 2)
							{

							}
							else if (menuInGame == 3)
							{
								while (1)
								{
									Settings();
									EraseMenu();
									//temp = ' ';
									if (settings == 0)
									{
										ChangeSound();
										temp = ' ';
										continue;
									}
									else if (settings == 1)
									{
										DifficultyByLevel(level);
										temp = ' ';
										continue;
									}
									else if (settings == 2)
									{
										Credit();
										temp = ' ';
										continue;
									}
									else if (settings == 3)
									{
										temp = ' ';
										break;
									}
								}
							}
						}
						cg.resumeGame(t1);
					}
					/*else if(temp == 'w' || temp =='a' ||temp == 's' || temp == 'd'){
						cg.resumeGame(t1);
					}*/
				}
				else {
					Sleep(5000);
					if (cg.askForRestart(mx)) {
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
		else if (menu == 1)
		{

		}
		else if (menu == 2)
		{
			while (1)
			{
				Settings();
				EraseMenu();
				//temp = ' ';
				if (settings == 0)
				{
					ChangeSound();
					temp = ' ';
					continue;
				}
				else if (settings == 1)
				{
					DifficultyByLevel(level);
					temp = ' ';
					continue;
				}
				else if (settings == 2)
				{
					Credit();
					temp = ' ';
					continue;
				}
				else if (settings == 3)
				{
					temp = ' ';
					break;
				}
			}
		}
		else if (menu == 3)
		{
			break;
		}
		//system("cls");
	}
	return 0;
	//return 0;
}