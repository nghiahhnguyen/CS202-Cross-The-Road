#pragma once
#include "cvehicle.h"
class CAMBULANCE :public CVEHICLE
{
	static int numAmbulance;
public:
	CAMBULANCE() = default;
	CAMBULANCE(int x, int y) :CVEHICLE(x, y) {};
	//void Draw();
	void DrawLeft();
	void DrawRight();
	//static void increaseNumTruck();
};