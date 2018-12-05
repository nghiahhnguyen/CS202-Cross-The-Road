#pragma once
#include "cvehicle.h"

class CTRUCK :public CVEHICLE
{
private:
	static void increaseNumTruck();
public:
	static int numTruck;
	CTRUCK() = default;
	CTRUCK(int x, int y) :CVEHICLE(x, y) {};
	void Draw();
};