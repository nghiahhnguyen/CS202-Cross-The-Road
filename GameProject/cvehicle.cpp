#include "header.h"
//Vehicle

CVEHICLE::CVEHICLE(int x, int y)
	:mX(x), mY(y), prevX(0), prevY(0) {
};

void CVEHICLE::Move(int x, int y)
{
	prevX = mX;
	prevY = mY;
	mX = x;
	mY = y;
};

void CVEHICLE::Draw() {
	for (int i = 0; i < n; ++i) {
		GotoXY(prevX, prevY + i);
		for (int j = 0; j < m; ++j) {
			cout << ' ';
		}
	}
};