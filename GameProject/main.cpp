#include "cgame.h"
#include "header.h"
#include <thread>
#include <random>
char MOVING;
bool IS_RUNNING = true;
CGAME cg;

void SubThread()
{
    cg.drawBackground();
	int preLevel = -1;
    while (IS_RUNNING) {
		cg.updateLevel();
        if (!cg.getPlayer().isDead()) // If player is still alive
        {
			if(MOVING != ' ')
				cg.updatePosPlayer(MOVING); // Update player's position from main
        } else {
            IS_RUNNING = false;
			continue;
        }
        MOVING = ' '; // Waiting for next move from main
        cg.updatePosVehicle(); //
        cg.updatePosAnimal(); //Cập nhật vị trí thú
        cg.drawGame();
		cg.getPlayer().DrawPLayer();

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
		if (hitSth)
			break;
        if (cg.getPlayer().getY() == 1) {
            cg.getPlayer().increaseLevel();
            if (cg.isFinish()) {
				break;
            } else {
                cg.increaseTrafficAndFlock();
			}
			cg.eraseOldObstacle();
			// TODO: FIX THIS BUG
			GotoXY(MAXWIDTH, 7);
			cout << '|';
			cg.getPlayer().eraseOldPlayer();
			cg.getPlayer().resetPosition();
			cg.getPlayer().DrawPLayer();
			preLevel = cg.getPlayer().getLevel();
			cg.updateObstacle();
        }
        Sleep(100);
    }
}

int main()
{
    int temp;
	ShowConsoleCursor(false);
    FixConsoleWindow();
    thread t1(SubThread);
    while (1) {
		if (_kbhit()) {
			temp = _getch();
			MOVING = temp;
		}        
        //if (!cg.getPlayer().isDead()) {
        //    if (temp == 27) {
        //        cg.exitGame(t1.native_handle());
        //        return;
        //    } else if (temp == 'P') {
        //        cg.pauseGame(t1.native_handle());
        //    } else {
        //        cg.resumeGame((HANDLE)t1.native_handle());
        //        MOVING = temp; //Cập nhật bước di chuyển
        //    }
        //} else {
        //    if (temp == 'Y')
        //        cg.startGame();
        //    else {
        //        cg.exitGame(t1.native_handle());
        //        return;
        //    }
        //}
    }
	t1.join();
	return 0;
}

void sound() {
	while (true) {
		cg.makeSound();
	}
}

//int o_main()
//{
//    FixConsoleWindow();
//    cg.drawBackground();
//    cg.getPlayer().DrawPLayer();
//	//thread t1(sound);
//    while (1) {
//        if (_kbhit()) //Nếu người vẫn còn sống
//        {
//            MOVING = _getch();
//            cg.updatePosPlayer(MOVING); //Cập nhật vị trí người theo thông tin từ main
//        }
//        MOVING = ' '; // Tạm khóa không cho di chuyển, chờ nhận phím từ hàm main
//        cg.getPlayer().DrawPLayer();
//        cg.updatePosVehicle(); //Cập nhật vị trí xe
//        cg.updatePosAnimal(); //Cập nhật vị trí thú
//        cg.drawGame();
//    }
//	//t1.join();
//	return 0;
//}