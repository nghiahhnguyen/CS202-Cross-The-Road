#include"header.h"
const int MAXWIDTH = 40;
const int MAXHEIGHT = 5;
//CGAME
void CGAME::drawBackground()
{
	for (int i = 0; i < MAXHEIGHT; i++)
	{
		for (int j = 0; j < MAXWIDTH + 1; j++)
		{
			if (j == MAXWIDTH || j == 0)
			{
				GotoXY(j, i);
				wcout << "|";
			}
			else if (i == MAXHEIGHT - 1 || i % 4 == 0)
			{
				GotoXY(j, i);
				wcout << "-";
			}
		}
	}
}

void CGAME::drawGame()
{

	GotoXY(0, MAXHEIGHT + 3);
	wcout << "Score: " << player.getScore << "| Level: " << player.getLevel << endl;
}

void CGAME::updatePosPlayer(char a)
{
	if (a == 'w')
		player.Up(4);
	else if (a == 'a')
		player.Left(2);
	else if (a == 'd')
		player.Right(2);
	else if (a == 's')
		player.Down(4);
}

void CGAME::updatePosVehicle()
{
	for (int i = 0; i < 10; i++)
	{
		truck[i].Move(truck[i].getX(), truck[i].getY());
		car[i].Move(car[i].getX(), car[i].getY());
	}
}

void CGAME::updatePosAnimal()
{
	for (int i = 0; i < 10; i++)
	{
		bird[i].Move(bird[i].getX(), bird[i].getY());
		dinosaur[i].Move(dinosaur[i].getX(), dinosaur[i].getY());
	}
}


CPEOPLE CGAME::getPlayer()
{
	return this->player;
}

CVEHICLE** CGAME::getVehicle()
{
	CVEHICLE **vehicle = new CVEHICLE*[2];
	car = new CCAR;
	truck = new CTRUCK;
	vehicle[0] = car;
	vehicle[1] = truck;
	return vehicle;
}

CANIMAL** CGAME::getAnimal()
{
	CANIMAL **animal = new CANIMAL*[2];
	bird = new CBIRD;
	dinosaur = new CDINOSAUR;
	animal[0] = bird;
	animal[1] = dinosaur;
	return animal;
}
//PEOPLE
int CPEOPLE::getLevel()
{
	return level;
}

int CPEOPLE::getScore()
{
	return score;
}

void CPEOPLE::Up(int y)
{
	mY-=y;
}

void CPEOPLE::Down(int y)
{
	mY+=y;
}

void CPEOPLE::Left(int x)
{
	mX-=x;
}

void CPEOPLE::Right(int x)
{
	mX+=x;
}

bool CPEOPLE::isImpact1( CVEHICLE *const&vehicle)
{
	for (int i = 0; i < 10; i++)
	{
		if (mX == vehicle[i].getX() && mY == vehicle[i].getY())
		{
			mState = true;
			return true;
		}
	}
	mState = false;
	return false;
}

bool CPEOPLE::isImpact2( CANIMAL *const&animal)
{
	for (int i = 0; i < 10; i++)
	{
		if (mX == animal[i].getX() && mY == animal[i].getY())
		{
			mState = true;
			return true;
		}
	}
	mState = false;
	return false;
}

bool CPEOPLE::isFinish()
{
	if (level == 11)
		return true;
	return false;
}

bool CPEOPLE::isDead()
{
	if (mState == true)
		return false;
	return true;
}

void CPEOPLE::DrawPLayer()
{
	GotoXY(mX, mY);
	cout << " 0 ";
	cout << "\|/";
	cout << "|'|";
}
//Vehicle
void CVEHICLE::Move(int x, int y) 
{
	if (x > 1)
	{
		mX++;
		if (mX == MAXWIDTH)
			mX = -2;
	}
	else
	{
		mX--;
		if (mX == 0)
			mX = MAXWIDTH + 2;
	}
};

int CVEHICLE::getX()
{
	return mX;
}

int CVEHICLE::getY()
{
	return mY;
}

void CVEHICLE::Draw(int y) {};

//Truck
CTRUCK::CTRUCK() :CVEHICLE() {};
void CTRUCK::Draw(int y)
{
	int i = getX(); int j = 6;
	if (i + j == MAXWIDTH)
	{
		GotoXY(i + j, 13);
		cout << "|";
		GotoXY(i + j, 14);
		cout << "|";
		GotoXY(i + j, 15);
		cout << "|";
		j--;
	}
	else
	{
		GotoXY(i, 13);
		cout << "AAAAA";
		GotoXY(i - 1, 13);
		cout << " ";
		GotoXY(i, 14);
		cout << "AAAAAAA";
		GotoXY(i - 1, 14);
		cout << " ";
		GotoXY(i, 15);
		cout << "AAAAAAA";
		GotoXY(i - 1, 15);
		cout << " ";
	}
	if (i > 1)
	{
		GotoXY(i - 1, 13);
		cout << " ";
		GotoXY(i - 1, 14);
		cout << " ";
		GotoXY(i - 1, 15);
		cout << " ";
	}
	else if (i == 1)
	{
		GotoXY(i - 1, 13);
		cout << "|";
		GotoXY(i - 1, 14);
		cout << "|";
		GotoXY(i - 1, 15);
		cout << "|";
	}
	Sleep(50);
}

void CTRUCK::Move(int x, int y)
{
	CVEHICLE::Move(x, y);
}

int CTRUCK::getX()
{
	return CVEHICLE::getX();
}

int CTRUCK::getY()
{
	return CVEHICLE::getY();
}

//Car
CCAR::CCAR():CVEHICLE() {};
void CCAR::Move(int x, int y)
{
	CVEHICLE::Move(x, y);
}

int CCAR::getX()
{
	return CVEHICLE::getX();
}

int CCAR::getY()
{
	return CVEHICLE::getY();
}
void CCAR::Draw(int y)
{
	GotoXY(getX(), y);
	int j = 6;
	for (int i = 1; i<MAXWIDTH + 1; i++)
	{
		if (i + j == MAXWIDTH)
		{
			GotoXY(i + j, 17);
			cout << "|";
			GotoXY(i + j, 18);
			cout << "|";
			GotoXY(i + j, 19);
			cout << "|";
			j--;
		}
		else
		{
			GotoXY(i, 17);
			cout << "AAAAA";
			GotoXY(i - 1, 17);
			cout << " ";
			GotoXY(i, 18);
			cout << "AAAAAAA";
			GotoXY(i - 1, 18);
			cout << " ";
			GotoXY(i, 19);
			cout << "AAAAAAA";
			GotoXY(i - 1, 19);
			cout << " ";
		}
		if (i > 1)
		{
			GotoXY(i - 1, 17);
			cout << " ";
			GotoXY(i - 1, 18);
			cout << " ";
			GotoXY(i - 1, 19);
			cout << " ";
		}
		else if (i == 1)
		{
			GotoXY(i - 1, 17);
			cout << "|";
			GotoXY(i - 1, 18);
			cout << "|";
			GotoXY(i - 1, 19);
			cout << "|";
		}
		Sleep(50);
	}
}
//Animal
void CANIMAL::Move(int x, int y)
{
	if (x > 1)
	{
		mX++;
		if (mX == MAXWIDTH)
			mX = -2;
	}
	else
	{
		mX--;
		if (mX == 0)
			mX = MAXWIDTH + 2;
	}
};

int CANIMAL::getX()
{
	return mX;
}

int CANIMAL::getY()
{
	return mY;
}
//Bird
CBIRD::CBIRD() :CANIMAL() {};
void CBIRD::Move(int x, int y)
{
	CANIMAL::Move(x, y);
}

int CBIRD::getX()
{
	return CANIMAL::getX();
}

int CBIRD::getY()
{
	return CANIMAL::getY();
}

//Dinosaur
CDINOSAUR::CDINOSAUR() :CANIMAL() {};
void CDINOSAUR::Move(int x, int y)
{
	CANIMAL::Move(x, y);
}

int CDINOSAUR::getX()
{
	return CANIMAL::getX();
}

int CDINOSAUR::getY()
{
	return CANIMAL::getY();
}


