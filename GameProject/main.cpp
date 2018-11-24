#include"header.h"
#include <thread>
char MOVING;
bool IS_RUNNING = false;
CGAME cg;


void SubThread()
{
	while (IS_RUNNING) {
		if (!cg.getPeople().isDead()) //Nếu người vẫn còn sống
		{
			cg.updatePosPeople(MOVING);//Cập nhật vị trí người theo thông tin từ main
		}
		MOVING = ' ';// Tạm khóa không cho di chuyển, chờ nhận phím từ hàm main
		cg.updatePosVehicle();//Cập nhật vị trí xe
		cg.updatePosAnimal(); //Cập nhật vị trí thú
		cg.drawGame();
		if (cg.getPeople().isImpact(cg.getVehicle() ||
			cg.getPeople().isImpact(cg.getAnimal())
		{
			// Xử lý khi đụng xe hay thú
		}
		if (cg.getPeople().isFinish()) {
			// Xử lý khi về đích

		}
		Sleep(100);

	}
}


void main()
{
	int temp;
	FixConsoleWindow();
	cg.startGame();
	thread t1(SubThread);
	while (1)
		{
		temp = toupper(getchar());
		if (!cg.getPeople().isDead())
			{
			if (temp == 27) {
			cg.exitGame(t1.native_handle());
				return;
			
			}
			else if (temp == 'P') {
				cg.pauseGame(t1.native_handle());
				}
			else 
				{
				 cg.resumeGame((HANDLE)t1.native_handle());
				 MOVING = temp; //Cập nhật bước di chuyển
				}
			}
		else
			{
			 if (temp == 'Y') cg.startGame();
			 else 
			 {
				 cg.exitGame(t1.native_handle());
				 return;
			}
			}
		 }
}