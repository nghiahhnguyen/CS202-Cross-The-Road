#pragma once
#include "canimal.h"

class CBIRD : public CANIMAL {
    static int numBird;

public:
    CBIRD() = default;
    CBIRD(int x, int y)
        : CANIMAL(x, y){};
    void Draw();
    inline static void increaseNumBird() { ++numBird; }
};