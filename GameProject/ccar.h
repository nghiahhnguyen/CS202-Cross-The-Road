#pragma once
#include "cvehicle.h"

class CCAR :public CVEHICLE
{
private:
	static int numCar;
public:
	CCAR() = default;
	CCAR(int x, int y) :CVEHICLE(x, y) {};
	void Draw();
	static void increaseNumCar();
};