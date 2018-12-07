#include "cgame.h"
#include "header.h"
#include <thread>
#include <condition_variable>
char MOVING;
bool IS_RUNNING = true;
CGAME cg;

void SubThread()
{
    cg.drawBackground();
    while (IS_RUNNING) {
		bool hitSth = false;
		if (cg.getPlayer().isImpact2(cg.getAnimal()[0])) {
			cg.getAnimal()[0]->Tell();
			hitSth = true;
		}
		if (cg.getPlayer().isImpact2(cg.getAnimal()[1])) {
			cg.getAnimal()[1]->Tell();
			hitSth = true;
		}
		if (cg.getPlayer().isImpact1(cg.getVehicle()[0]) || cg.getPlayer().isImpact1(cg.getVehicle()[1])) {
			hitSth = true;
		}
		if (hitSth) {
			cg.getPlayer().dieEffect();
			break;
		}
		cg.updateLevel();
		
		// If player is still alive
        if (!cg.getPlayer().isDead()) 
        {
			if(MOVING != ' ')
				// Update player's position from main
				cg.updatePosPlayer(MOVING); 
        } else {
            IS_RUNNING = false;
			continue;
        }

		// Waiting for next move from main
		MOVING = ' '; 

        cg.updatePosVehicle();
        cg.updatePosAnimal();
        cg.drawGame();
		cg.getPlayer().DrawPLayer();
		
        if (cg.getPlayer().getY() == 1) {
            cg.getPlayer().increaseLevel();
            if (cg.isFinish()) {
				break;
            }
			cg.resetGame();
        }
        Sleep(100);
    }
}

int main()
{
    int temp = 'Y';
	ShowConsoleCursor(false);
    FixConsoleWindow();
	cg.startGame();
	thread t1(SubThread);
    while (1) {
		if (_kbhit()) {
			temp = _getch();
			MOVING = temp;
		}
        if (!cg.getPlayer().isDead()) {
            if (temp == 27) {
                cg.exitGame(&t1, IS_RUNNING);
                return 0;
            } else if (temp == 'p') {
                cg.pauseGame(t1.native_handle());
            } else {
                cg.resumeGame((HANDLE)t1.native_handle());
            }
        } else {
            if (temp == 'y')
                cg.startGame();
            else {
                cg.exitGame(&t1, IS_RUNNING);
                return 0;
            }
        }
    }
	system("cls");
	return 0;
}