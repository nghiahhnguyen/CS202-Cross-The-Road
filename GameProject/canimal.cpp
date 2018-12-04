#include "header.h"
//Vehicle

CANIMAL::CANIMAL(int x, int y)
	:mX(x), mY(y), prevX(0), prevY(0) {};

void CANIMAL::Move(int x, int y)
{
	prevX = mX;
	prevY = mY;
	mX = x;
	mY = y;
};

void CANIMAL::Draw() {
	for (int i = 0; i < n; ++i) {
		GotoXY(prevX, prevY + i);
		for (int j = 0; j < m; ++j) {
			cout << ' ';
		}
	}
	for (int i = 0; i < n; ++i) {
		GotoXY(mX, mY + 1);
		cout << graphic[i];
	}
};