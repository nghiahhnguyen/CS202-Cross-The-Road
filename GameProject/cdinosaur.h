#pragma once
#include "canimal.h"
class CDINOSAUR : public CANIMAL
{
	static int numDino;
public:
	CDINOSAUR() = default;
	CDINOSAUR(int x, int y) :CANIMAL(x, y) {};
	void Draw();
};