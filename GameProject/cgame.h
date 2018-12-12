#pragma once

class CVEHICLE;
class CANIMAL;
class CCAR;
class CTRUCK;
class CDINOSAUR;
class CBIRD;
class CPEOPLE;
class CTRAFFICLIGHT;

#include <thread>
#include "cbird.h"
#include "ccar.h"
#include "cdinosaur.h"
#include "cpeople.h"
#include "ctruck.h"
#include "header.h"
#include "ctrafficlight.h"
#include <fstream>
#include "cambulance.h"
#include <sys/stat.h>

class CGAME {
    CVEHICLE** vehicles = nullptr;
    CANIMAL** animals = nullptr;
    CTRUCK* trucks = nullptr;
    CCAR* cars = nullptr;
    CDINOSAUR* dinosaurs = nullptr;
    CBIRD* birds = nullptr;
    CPEOPLE player;
	CTRAFFICLIGHT carlane;
	CTRAFFICLIGHT trucklane;
	//CAMBULANCE ambulane;
    int MAX_LEVEL = 10;
    int MAX_BIRD = 10;
    int NUMBER_LANE = 10;
    int HEIGHT = 10;
    int WIDTH = 10;

public:
	//init game
    CGAME(); 
    void drawBackground();
    void drawGame();
	void guide();
    ~CGAME();
	//get info player
    CPEOPLE& getPlayer(); 
	//get vehicle list
    CVEHICLE** getVehicle(); 
	//get animal list
    CANIMAL** getAnimal(); 
    void resetGame();
	void exitGame(thread*, bool&);
	void startGame(thread&);
	//void loadGame(istream);
	void saveGame(mutex&);
	void pauseGame(thread&);
	void resumeGame(thread&);
	//control moving player
    void updatePosPlayer(char);
	//moving vehicle
    void updatePosVehicle(); 
	//moving animal
    void updatePosAnimal(); 
    void increaseTrafficAndFlock();
	bool isFinish();
	void makeSound();
	void updateLevel();
	void updateObstacle();
	void eraseOldObstacle();
	bool askForRestart(mutex&);
	void ambulanceEffect(mutex&);
	CTRAFFICLIGHT& getCarLaneLight();
	CTRAFFICLIGHT& getTruckLaneLight();
	bool fileExist(const string&);
	void resetData();
};
