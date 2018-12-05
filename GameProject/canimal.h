#pragma once
#include "header.h"
class CANIMAL
{
protected:
	int mX, mY, prevX, prevY;
	static int n, m;
public:
	friend class CGAME;
	friend class CPEOPLE;
	CANIMAL() = default;
	CANIMAL(int x, int y);
	virtual void Move(int x, int y);
	virtual void Draw();
};