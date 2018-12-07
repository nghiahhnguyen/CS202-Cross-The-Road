#pragma once

class CVEHICLE;
class CANIMAL;

#include "canimal.h"
#include "cvehicle.h"
#include "header.h"
class CPEOPLE {
    int mX, mY; // position
    bool mState; // status
    string name;
    int score;
    short level;
    int tempX, tempY;

public:
    CPEOPLE()
    {
        mX = (MAXWIDTH / 2) - 1;
        mY = 21;
        level = 1;
        score = 0;
        mState = true;
        tempX = (MAXWIDTH / 2) - 1;
        tempY = 21;
    };
    void Up(int);
    void Left(int);
    void Right(int);
    void Down(int);
    bool isImpact1(CVEHICLE* const& vehicle); // true = impact, false = not impact
    bool isImpact2(CANIMAL* const& animal);
    bool isFinish();
    bool isDead();
    int getScore();
    int getLevel();
    void DrawPLayer();
    void increaseLevel();
	inline int getX() { return mX; };
	inline int getY() { return mY; };
	inline void resetPosition() {
		mY = 21;
	}
	void eraseOldPlayer();
};
