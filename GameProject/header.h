#ifndef _header_h_
#define	_header_h_
#include <iostream>
#include <windows.h>
#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;
class CVEHICLE
{
	int mX, mY;
public:
	CVEHICLE() { mX = 0; };
	virtual void Move(int x, int y);
	virtual void Draw(int y);
	virtual int getX();
	virtual int getY();
};
class CTRUCK :public CVEHICLE
{
	int NUMBER_TRUCK;
public:
	CTRUCK();
	void Move(int x, int y);
	void Draw(int y);
	int getX();
	int getY();
};
class CCAR :public CVEHICLE
{
	int NUMBER_CAR;
public:
	CCAR();
	void Move(int x, int y);
	void Draw(int y);
	int getX();
	int getY();
};
class CANIMAL
{
	int mX, mY;
public:
	CANIMAL() { mX = 0; };
	virtual void Move(int x, int y);
	virtual void Draw(int y);
	virtual void Tell();
	virtual int getX();
	virtual int getY();
};
class CBIRD : public CANIMAL
{
	int NUMBER_BIRD;
public:
	CBIRD();
	void Move(int x, int y);
	void Draw(int y);
	void Tell();
	int getX();
	int getY();
};
class CDINOSAUR : public CANIMAL
{
	int NUMBER_DINOSAUR;
public:
	CDINOSAUR();
	void Move(int x, int y);
	void Draw(int y);
	void Tell();
	int getX();
	int getY();
};

class CPEOPLE
{
	int mX, mY;//position
	bool mState=true;//status
	string name;
	int score;
	short level;
public:
	CPEOPLE(int width, int length) { mX = rand() % (length + 1); mY = 18; };
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpact1( CVEHICLE *const&vehicle);//true = impact, false = not impact
	bool isImpact2( CANIMAL *const&animal);
	bool isFinish();
	bool isDead();
	int getScore();
	int getLevel();
	void DrawPLayer();
};
class CGAME
{
	CTRUCK *truck;
	CCAR *car;
	CDINOSAUR *dinosaur;
	CBIRD *bird;
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
};



void FixConsoleWindow() 
{
	 HWND consoleWindow = GetConsoleWindow();
	 long style = GetWindowLong(consoleWindow, GWL_STYLE);
	 style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	 SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
#endif