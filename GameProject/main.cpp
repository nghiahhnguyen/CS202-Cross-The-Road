#include"header.h"
#include <thread>
char MOVING;
bool IS_RUNNING = false;
CGAME cg;


void SubThread()
{
	cg.drawBackground();
	while (IS_RUNNING) {
		if (!cg.getPlayer().isDead()) //Nếu người vẫn còn sống
		{
			cg.updatePosPlayer(MOVING);//Cập nhật vị trí người theo thông tin từ main
		}
		MOVING = ' ';// Tạm khóa không cho di chuyển, chờ nhận phím từ hàm main
		cg.updatePosVehicle();//Cập nhật vị trí xe
		cg.updatePosAnimal(); //Cập nhật vị trí thú
		cg.drawGame();
		if (cg.getPlayer().isImpact1(cg.getVehicle()[0])|| cg.getPlayer().isImpact1(cg.getVehicle()[1])
			|| cg.getPlayer().isImpact2(cg.getAnimal()[0]) || cg.getPlayer().isImpact2(cg.getAnimal()[1]))
		{
			if (cg.getPlayer().isImpact2(cg.getAnimal()[0]))
				cg.getAnimal()[0]->Tell();
			if (cg.getPlayer().isImpact2(cg.getAnimal()[1]))
				cg.getAnimal()[1]->Tell();
		}
		if (cg.getPlayer().isFinish())
		{
			// Xử lý khi về đích
		}
		Sleep(100);

	}
}


void main()
{

	int temp;
	FixConsoleWindow();
	thread t1(SubThread);
	while (1)
		{
		temp = toupper(getchar());
		cout << "█";
		MOVING = temp;
		//if (!cg.getPlayer().isDead())
		//	{
		//	if (temp == 27) {
		//	cg.exitGame(t1.native_handle());
		//		return;
		//	}
		//	else if (temp == 'P') {
		//		cg.pauseGame(t1.native_handle());
		//		}
		//	else 
		//		{
		//		 cg.resumeGame((HANDLE)t1.native_handle());
		//		 MOVING = temp; //Cập nhật bước di chuyển
		//		}
		//	}
		//else
		//	{
		//	 if (temp == 'Y') cg.startGame();
		//	 else 
		//	 {
		//		 cg.exitGame(t1.native_handle());
		//		 return;
		//	}
		//	}
		// }
}

/*void main()
{
	CGAME cg;
	cg.drawBackground();
	cg.getPlayer().DrawPLayer();
	while (1) {
		MOVING = _getch();
		if (!cg.getPlayer().isDead()) //Nếu người vẫn còn sống
		{
			cg.updatePosPlayer(MOVING);//Cập nhật vị trí người theo thông tin từ main
		}
		MOVING = ' ';// Tạm khóa không cho di chuyển, chờ nhận phím từ hàm main
		cg.getPlayer().DrawPLayer();
		cg.updatePosVehicle();//Cập nhật vị trí xe
		cg.updatePosAnimal(); //Cập nhật vị trí thú
		cg.drawGame();
		/*if (cg.getPlayer().isImpact1(cg.getVehicle()[0]) || cg.getPlayer().isImpact1(cg.getVehicle()[1])
			|| cg.getPlayer().isImpact2(cg.getAnimal()[0]) || cg.getPlayer().isImpact2(cg.getAnimal()[1]))
		{
			if (cg.getPlayer().isImpact2(cg.getAnimal()[0]))
				cg.getAnimal()[0]->Tell();
			if (cg.getPlayer().isImpact2(cg.getAnimal()[1]))
				cg.getAnimal()[1]->Tell();
		}
		if (cg.getPlayer().isFinish())
		{
			// Xử lý khi về đích
		}
		//Sleep(50);
	}
}*/