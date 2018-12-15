#include "cgame.h"
#include "header.h"
#include <random>
#include <chrono>
#include <consoleapi.h>
#include "header.cpp"

char MOVING;
bool IS_RUNNING = true; 
CGAME cg;
chrono::steady_clock sc;
mutex mx;
int level = 1;
bool backToMainMenu = false;
int temp = ' ';

void SubThread()
{
	cg.guide();
	int preLevel = 11;
	int templv = 11;
	cg.drawBackground();
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
			if (sound) cg.getAnimal()[0]->Tell();
			hitSth = true;
		}
		if (cg.getPlayer().isImpact2(cg.getAnimal()[1])) {
			if (sound) cg.getAnimal()[1]->Tell();
			hitSth = true;
		}
		if (cg.getPlayer().isImpact1(cg.getVehicle()[0])) {
			if (sound) cg.getVehicle()[0]->Crash();
			hitSth = true;
		}
		if (cg.getPlayer().isImpact1(cg.getVehicle()[1])) {
			if (sound) cg.getVehicle()[1]->Crash();
			hitSth = true;
		}
		if (hitSth) {
			cg.getPlayer().dieEffect();
			cg.getPlayer().setDead();
			//if (sound) cg.ambulanceVoice();
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
		cg.getPlayer().DrawPLayer();
		cg.updatePosVehicle();
		cg.updatePosAnimal();
		cg.drawGame();
		mx.unlock();
		
		if (cg.getPlayer().getY() == 1) {
			cg.getPlayer().increaseLevel();
			if (cg.isFinish()) {
				cg.congrats();
				if (sound) cg.congratsVoice();
				if (cg.askForRestart(mx)) {
					cg.getPlayer().getLevel() = 1;
					if (templv != cg.getPlayer().getLevel())
					{
						startCar = endCar;
						startTruck = endTruck;
					}
				}
				else
					break;
			}
			cg.drawBackground();
			cg.resetGame();
			cg.drawBackground();
		}
		Sleep(150/difficulty);
	}
}

int main()
{
	//cg.congrats();
	//system("pause");
	ShowConsoleCursor(false);
	FixConsoleWindow();
	//menu = 0;
	bool loadGameFromMenu = false;
	while (1)
	{
		if (loadGameFromMenu)
			menu = 0;
		else
		{
			system("cls");
			StartMenu();
			EraseMenu();
		}
		thread t1;
		if (menu == 0)
		{
			cg.loadingBar();
			if(!loadGameFromMenu)
				cg.resetData();
			loadGameFromMenu = false;
			IS_RUNNING = true;
			cg.getPlayer().setAlive();
			temp = ' ';
			cg.startGame(t1);
			bool exitFromSaveGame = false;
			while (1) {
				if (exitFromSaveGame) {
					exitFromSaveGame = false;
					break;
				}
				if (_kbhit()) {
					temp = _getch();
					MOVING = temp;
				}
				if (!cg.getPlayer().isDead()) {
					if (temp == 27) {
						cg.exitGame(&t1, IS_RUNNING);
						break;
					}
					else if (temp == 'p') {
						cg.pauseGame(t1);
						while (1)
						{
							IngameMenu();
							EraseMenu();
							if (menuInGame == 0)
							{
								cg.drawBackground();
								cg.guide();
								cg.resumeGame(t1);
								break;
							}
							else if (menuInGame == 1)
							{
								if (cg.saveGame(mx, true)) {
									cg.resumeGame(t1);
									cg.exitGame(&t1, IS_RUNNING);
									exitFromSaveGame = true;
									break;
								}
							}
							else if (menuInGame == 2)
							{
								cg.loadGame(mx, true);
								cg.drawBackground();
								cg.guide();
								cg.resumeGame(t1);
								break;
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
					}
					else if (temp == 't') {
						cg.pauseGame(t1);
						cg.loadGame(mx);
						cg.drawBackground();
						cg.guide();
						cg.resumeGame(t1);
					}
					else if (temp == 'l') {
						cg.pauseGame(t1);
						if (cg.saveGame(mx))
						{
							cg.resumeGame(t1);
							cg.exitGame(&t1, IS_RUNNING);
							break;
						}
						cg.resumeGame(t1);
					}
					else if(temp == 'w' || temp =='a' ||temp == 's' || temp == 'd'){
						cg.resumeGame(t1);
					}
				}
				else {
					Sleep(2000);
					if(sound) 
						cg.ambulanceVoice(mx);
					Sleep(2000);
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
				temp = ' ';
			}
		}
		else if (menu == 1)
		{
			cg.loadGame(mx, true);
			system("cls");
			loadGameFromMenu = true;
			//cg.startGame(t1);
			continue;
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
}