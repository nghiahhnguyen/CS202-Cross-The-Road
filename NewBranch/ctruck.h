#pragma once
#include "cvehicle.h"

class CTRUCK :public CVEHICLE
{
	static int numTruck;
public:
	CTRUCK() = default;
	CTRUCK(int x, int y) :CVEHICLE(x, y) {};
	void Draw();
	static void increaseNumTruck();
};