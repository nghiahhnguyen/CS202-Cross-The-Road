#ifndef _header_h_
#define	_header_h_
#include <iostream>
#include <windows.h>
#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
using namespace std;
const int MAXWIDTH = 110;
const int MAXHEIGHT = 25;

class CVEHICLE
{
protected:
	int mX, mY, prevX, prevY;
	static int n, m;
public:
	CVEHICLE() = default;
	CVEHICLE(int, int);
	virtual void Move(int x, int y);
	virtual void Draw();
};

int CVEHICLE::n = 2;
int CVEHICLE::m = 5;

class CTRUCK :public CVEHICLE
{
private:
	static void increaseNumTruck();
public:
	static int numTruck;
	CTRUCK();
	CTRUCK(int x, int y) :CVEHICLE(x, y) {};
	void Draw();
};

int CTRUCK::numTruck = 3;

class CCAR :public CVEHICLE
{
private:
	static void increaseNumCar();
public:
	static int numCar;
	CCAR();
	CCAR(int x, int y) :CVEHICLE(x, y) {};
};

int CCAR::numCar = 3;

class CANIMAL
{
	int mX, mY, prevX, prevY;
	static int n, m;
public:
	CANIMAL(int x, int y) {};
	virtual void Move(int i, int x);
	virtual void Draw();
};

int CANIMAL::n = 2;
int CANIMAL::m = 5;

class CBIRD : public CANIMAL
{
	int NUMBER_BIRD;
public:
	CBIRD();
	void Move(int i,int x);
	void Draw(int y);

};

class CDINOSAUR : public CANIMAL
{
	int NUMBER_DINOSAUR;
public:
	CDINOSAUR();
	void Move(int i,int x);
	void Draw(int y);
};

class CPEOPLE
{
	int mX, mY;//position
	bool mState;//status
	string name;
	int score;
	short level;
	int tempX, tempY;
public:
	CPEOPLE() { mX = (MAXWIDTH / 2) - 1; mY = 21; level = 10; score = 0; mState = true; tempX = (MAXWIDTH / 2) - 1; tempY = 21; };
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpact1(CVEHICLE *const&vehicle);//true = impact, false = not impact
	bool isImpact2(CANIMAL *const&animal);
	bool isFinish();
	bool isDead();
	int getScore();
	int getLevel();
	void DrawPLayer();
};

class CGAME
{
	CVEHICLE** vehicles;
	CANIMAL** animals;
	CTRUCK* trucks;
	CCAR* cars;
	CDINOSAUR* dinosaurs;
	CBIRD* birds;
	CPEOPLE player;
	int MAX_LEVEL = 10;
	int MAX_BIRD = 10;
	int NUMBER_LANE = 10;
	int HEIGHT = 10;
	int WIDTH = 10;
public:
	void Input();
	CGAME(); //init game
	void drawBackground();
	void drawGame();
	//~CGAME();
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
};

void FixConsoleWindow() 
{
	 HWND consoleWindow = GetConsoleWindow();
	 long style = GetWindowLong(consoleWindow, GWL_STYLE);
	 style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	 SetWindowLong(consoleWindow, GWL_STYLE, style);
}

inline void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

#endif