#ifndef _header_h_
#define	_header_h_
#include <iostream>
#include <windows.h>
using namespace std;
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
	void drawGame();
	~CGAME();
	CPEOPLE getPlayer(); //get info player
	CVEHICLE getVehicle(); //get vehicle list
	CANIMAL getAnimal(); //get animal list
	void resetGame();
	void exitGame(HANDLE);
	void startGame();
	void loadGame(istream);
	void saveGame(istream);
	void pauseGame(HANDLE);
	void resumeGame(HANDLE);
	void updatePosPlayer(char); //control moving player
	void updatePosVehicle(); //moving vehicle
	void updatePosAnimal(); //moving animal
};
class CLANE
{

};
class CRECTANGLE
{

};
class CPEOPLE
{
	int mX, mY;//position
	bool mState;//status
public:
	CPEOPLE(int width) { mX = rand()%(width +1); mY = 0; };
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpact(const CVEHICLE*&);
	bool isImpact(const CANIMAL*&);
	bool isFinish();
	bool isDead();
};
class CVEHICLE
{
int mX, mY;
public:
	virtual void Move(int, int);
};
class CTRUCK :public CVEHICLE
{
	int NUMBER_TRUCK;
public:

};
class CCAR :public CVEHICLE
{
	int NUMBER_CAR;
public:
};
class CANIMAL
{
	int mX, mY;
public:
	virtual void Move(int, int);
	virtual void Tell();
};
class CDINOSAUR : public CANIMAL
{
	int NUMBER_DINOSAUR;
public:
};
class CBIRD : public CANIMAL
{
	int NUMBER_BIRD;
public:
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