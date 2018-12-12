#pragma once
#include "header.h"
class CVEHICLE
{
protected:
	int mX, mY, prevX, prevY;
	static int n, m;
public:
	friend class CGAME;
	friend class CPEOPLE;
	CVEHICLE() = default;
	CVEHICLE(int, int);
	virtual void Move(int x, int y);
	virtual void Draw();
	void Erase();
	virtual void Crash() {
		if(sound)
			PlaySound(L"Car-crash-sound-effect (edited).wav", NULL, SND_FILENAME);
	};
};