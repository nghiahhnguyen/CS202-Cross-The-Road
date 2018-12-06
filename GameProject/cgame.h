#pragma once

class CVEHICLE;
class CANIMAL;
class CCAR;
class CTRUCK;
class CDINOSAUR;
class CBIRD;
class CPEOPLE;

#include "cbird.h"
#include "ccar.h"
#include "cdinosaur.h"
#include "cpeople.h"
#include "ctruck.h"
#include "header.h"

class CGAME {
    CVEHICLE** vehicles = nullptr;
    CANIMAL** animals = nullptr;
    CTRUCK* trucks = nullptr;
    CCAR* cars = nullptr;
    CDINOSAUR* dinosaurs = nullptr;
    CBIRD* birds = nullptr;
    CPEOPLE player;
    int MAX_LEVEL = 10;
    int MAX_BIRD = 10;
    int NUMBER_LANE = 10;
    int HEIGHT = 10;
    int WIDTH = 10;

public:
    CGAME(); //init game
    void drawBackground();
    void drawGame();
    ~CGAME();
    CPEOPLE getPlayer(); //get info player
    CVEHICLE** getVehicle(); //get vehicle list
    CANIMAL** getAnimal(); //get animal list
    /*void resetGame();
	void exitGame(HANDLE);
	void startGame();
	void loadGame(istream);
	void saveGame(istream);
	void pauseGame(HANDLE);
	void resumeGame(HANDLE);*/
    void updatePosPlayer(char); //control moving player
    void updatePosVehicle(); //moving vehicle
    void updatePosAnimal(); //moving animal
    void increaseTrafficAndFlock();
	bool isFinish();
	void makeSound();
};
