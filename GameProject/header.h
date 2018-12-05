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
const int MAXWIDTH = 110;
const int MAXHEIGHT = 25;
inline void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
class CVEHICLE
{
	int mX, mY;
public:
	CVEHICLE(int x) { mX = x; };
	virtual void Move(int i, int x);
	virtual void Draw(int y);
	virtual int getX();
	virtual int getY();
	virtual void ready();

};
class CTRUCK :public CVEHICLE
{
	int NUMBER_TRUCK;
public:
	CTRUCK();
	void Move(int i, int x);
	void Draw(int y);
	int getX();
	int getY();
	void ready();

};
class CCAR :public CVEHICLE
{
	int NUMBER_CAR;
public:
	CCAR();
	void Move(int i, int x);
	void Draw(int y);
	int getX();
	int getY();
	//void changeX();

};
class CANIMAL
{
	int mX, mY;
public:
	CANIMAL(int x) { mX = x; };
	virtual void Move(int i, int x);
	virtual void Draw(int y);
	//virtual void Tell();
	virtual int getX();
	virtual int getY();
	virtual void ready();
	//virtual void changeX();

};
class CBIRD : public CANIMAL
{
	int NUMBER_BIRD;
public:
	CBIRD();
	void Move(int i,int x);
	void Draw(int y);
	//void Tell();
	int getX();
	int getY();
	//void changeX(int x);
	void ready();

};
class CDINOSAUR : public CANIMAL
{
	int NUMBER_DINOSAUR;
public:
	CDINOSAUR();
	void Move(int i,int x);
	void Draw(int y);
	//void Tell();
	int getX();
	int getY();
//	void changeX(int x);
	void ready();
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
	bool isImpact1(CCAR *const&vehicle);//true = impact, false = not impact
	bool isImpact2(CANIMAL *const&animal);
	bool isFinish();
	bool isDead();
	int getScore();
	int getLevel();
	void DrawPLayer();
};
class CGAME
{
	CVEHICLE** vehicle;
	CANIMAL** animal;
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
	//void Input();
	CGAME(); //init game
	void drawBackground();
	void drawGame();
	//~CGAME();
	CPEOPLE getPlayer(); //get info player
	CVEHICLE** getVehicle(); //get vehicle list
	CANIMAL** getAnimal(); //get animal list
	CVEHICLE* getCar();
/*	void resetGame();
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
/*void FixConsoleWindow() 
{
	 HWND consoleWindow = GetConsoleWindow();
	 long style = GetWindowLong(consoleWindow, GWL_STYLE);
	 style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	 SetWindowLong(consoleWindow, GWL_STYLE, style);
}*/

#endif