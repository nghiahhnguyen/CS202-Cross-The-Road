#pragma once
#include "cvehicle.h"

class CCAR :public CVEHICLE
{
private:
	static void increaseNumCar();
public:
	static int numCar;
	CCAR() = default;
	CCAR(int x, int y) :CVEHICLE(x, y) {};
	void Draw();
};