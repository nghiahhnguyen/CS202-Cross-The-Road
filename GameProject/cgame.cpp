#include "cgame.h"
#include "header.h"
#include <algorithm>
#include <experimental/filesystem>
#include <sstream>
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

CGAME::CGAME()
{
    trucks = new CTRUCK[10];
    cars = new CCAR[10];
    dinosaurs = new CDINOSAUR[10];
    birds = new CBIRD[10];
    vehicles = new CVEHICLE*[2];
    vehicles[0] = trucks;
    vehicles[1] = cars;
    animals = new CANIMAL*[2];
    animals[0] = dinosaurs;
    animals[1] = birds;

    for (int i = 0; i < getPlayer().getLevel(); ++i) {
        CTRUCK tmpTruck(min(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 110), 17);
        trucks[i] = tmpTruck;
        CCAR tmpCar(min(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 110), 13);
        cars[i] = tmpCar;
        CDINOSAUR tmpDino(min(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 110), 9);
        dinosaurs[i] = tmpDino;
        CBIRD tmpBird(min(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 110), 5);
        birds[i] = tmpBird;
    }
}

void CGAME::updateObstacle()
{
    for (int i = 0; i < getPlayer().getLevel(); ++i) {
        CTRUCK tmpTruck(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 17);
        trucks[i] = tmpTruck;
        CCAR tmpCar(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 13);
        cars[i] = tmpCar;
        CDINOSAUR tmpDino(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 9);
        dinosaurs[i] = tmpDino;
        CBIRD tmpBird(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 5);
        birds[i] = tmpBird;
    }
}

CGAME::~CGAME()
{
    delete[] trucks;
    delete[] cars;
    delete[] dinosaurs;
    delete[] birds;
    delete[] vehicles;
    delete[] animals;
}

void CGAME::drawBackground()
{
    for (int i = 0; i < MAXHEIGHT; i++) {
        for (int j = 2; j < MAXWIDTH + 1; j++) {
            if (j == MAXWIDTH || j == 2) {
                GotoXY(j, i);
                wcout << "|";
            } else if (i == MAXHEIGHT - 1 || i % 4 == 0) {
                GotoXY(j, i);
                wcout << "-";
            }
        }
    }
}

void CGAME::guide()
{
    int boxWidth = 20, boxHeight = 9, startBoxX = 149, startBoxY = 8;

    //Draw the board
    GotoXY(startBoxX, startBoxY);
    for (int j = 0; j < boxWidth; ++j) {
        cout << '=';
    }
    GotoXY(startBoxX, startBoxY + 1);
    for (int i = 1; i < boxHeight; i++) {
        GotoXY(149, 8 + i);
        for (int j = 0; j < boxWidth; ++j) {
            {
                if (j == 0 || j == boxWidth - 1)
                    cout << '|';
                else
                    cout << ' ';
            }
        }
    }
    GotoXY(startBoxX, startBoxY + boxHeight);
    for (int j = 0; j < boxWidth; ++j) {
        cout << '=';
    }
    GotoXY(150, 9);
    cout << "W:   Up";
    GotoXY(150, 10);
    cout << "S:   Down";
    GotoXY(150, 11);
    cout << "A:   Left";
    GotoXY(150, 12);
    cout << "D:   Right";
    GotoXY(150, 13);
    cout << "ESC: Exit";
    GotoXY(150, 14);
    cout << "P:   Pause";
    GotoXY(150, 15);
    cout << "T:   Save game";
    GotoXY(150, 16);
    cout << "L:   Load game";
    GotoXY(30, 30);
}

void CGAME::drawGame()
{
    //player.DrawPLayer();
    if (trucklane.getGreen()) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        GotoXY(MAXWIDTH + 1, 18);
        cout << " ";
        GotoXY(MAXWIDTH + 1, 17);
        cout << char(254);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    } else if (!trucklane.getGreen()) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        GotoXY(MAXWIDTH + 1, 17);
        cout << " ";
        GotoXY(MAXWIDTH + 1, 18);
        cout << char(254);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    if (carlane.getGreen()) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        GotoXY(1, 14);
        cout << " ";
        GotoXY(1, 13);
        cout << char(254);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    } else if (!carlane.getGreen()) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        GotoXY(1, 13);
        cout << " ";
        GotoXY(1, 14);
        cout << char(254);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    for (int i = 0; i < player.getLevel(); i++) {
        trucks[i].Draw();
        cars[i].Draw();
        birds[i].Draw();
        dinosaurs[i].Draw();
    }
    //Sleep(100);
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
    for (int i = 0; i < player.getLevel(); i++) {
        if (trucklane.getGreen()) {
            if (trucks[i].mX + 5 >= MAXWIDTH) {
                trucks[i].Move(3, trucks[i].mY);
            } else {
                trucks[i].Move(trucks[i].mX + 2, trucks[i].mY);
            }
        }
        if (carlane.getGreen()) {
            if (cars[i].mX <= 5) {
                cars[i].Move(MAXWIDTH - 4, cars[i].mY);
            } else {
                cars[i].Move(cars[i].mX - 3, cars[i].mY);
            }
        }
    }
}

void CGAME::updatePosAnimal()
{
    for (int i = 0; i < player.getLevel(); i++) {
        if (birds[i].mX <= 5) {
            birds[i].Move(MAXWIDTH - 4, birds[i].mY);
        } else {
            birds[i].Move(birds[i].mX - 3, birds[i].mY);
        }
        if (dinosaurs[i].mX + 4 >= MAXWIDTH) {
            dinosaurs[i].Move(3, dinosaurs[i].mY);
        } else {
            dinosaurs[i].Move(dinosaurs[i].mX + 1, dinosaurs[i].mY);
        }
    }
}

CPEOPLE& CGAME::getPlayer()
{
    return this->player;
}

CVEHICLE** CGAME::getVehicle()
{
    return vehicles;
}

CANIMAL** CGAME::getAnimal()
{
    return animals;
}

void CGAME::increaseTrafficAndFlock()
{
    trucks->increaseNumTruck();
    cars->increaseNumCar();
    birds->increaseNumBird();
    dinosaurs->increaseNumDino();
}

bool CGAME::isFinish()
{
    return getPlayer().getLevel() > 5;
}

void CGAME::makeSound()
{
    birds[0].Tell();
}

void CGAME::updateLevel()
{
    GotoXY(60, 30);
    cout << "              ";
    GotoXY(60, 30);
    cout << "LEVEL " << getPlayer().getLevel();
}

void CGAME::eraseOldObstacle()
{
    for (int i = 0; i < getPlayer().getLevel(); ++i) {
        trucks[i].CVEHICLE::Erase();
        cars[i].CVEHICLE::Erase();
        dinosaurs[i].CANIMAL::Erase();
        birds[i].CANIMAL::Erase();
    }
}

void CGAME::resetGame()
{
    eraseOldObstacle();
    // TODO: FIX THIS BUG
    GotoXY(MAXWIDTH, 7);
    cout << '|';
    getPlayer().eraseOldPlayer();
    getPlayer().resetPosition();
    getPlayer().DrawPLayer();
    updateObstacle();
}

void CGAME::exitGame(thread* t1, bool& IS_RUNNING)
{
    IS_RUNNING = false;
    Sleep(200);
    if (t1->joinable())
        t1->join();
    system("cls");
}

void CGAME::startGame(thread& t1)
{
    if (t1.joinable())
        t1.join();
    t1 = thread(SubThread);
}

void CGAME::pauseGame(thread& t1)
{
    SuspendThread(t1.native_handle());
}

void CGAME::resumeGame(thread& t1)
{
    ResumeThread(t1.native_handle());
}

CTRAFFICLIGHT& CGAME::getTruckLaneLight()
{
    return trucklane;
}

CTRAFFICLIGHT& CGAME::getCarLaneLight()
{
    return carlane;
}

bool CGAME::askForRestart(mutex& mx)
{
    int boxWidth = 42, boxHeight = 4, startBoxX = 44, startBoxY = 32;
    lock_guard<mutex> lock(mx);

    //Draw the board
    GotoXY(startBoxX, startBoxY);
    for (int j = 0; j < boxWidth; ++j) {
        cout << '=';
    }
    GotoXY(startBoxX, startBoxY + 1);
    for (int j = 0; j < boxWidth; ++j) {
        if (j == 0 || j == boxWidth - 1)
            cout << '|';
        else
            cout << ' ';
    }

    GotoXY(startBoxX, startBoxY + 2);
    for (int j = 0; j < boxWidth; ++j) {
        cout << '=';
    }

    string line2 = "Do you want to restart the game? (y/n)";
    GotoXY(startBoxX + (boxWidth - line2.size()) / 2, startBoxY + 1);
    cout << line2;

    char answer = _getch();
    if (answer == 'y')
        return true;
    else
        return false;
}
//ambulance effect
void CGAME::ambulanceEffect(mutex& mx)
{
    lock_guard<mutex> lock(mx);
    if (player.getY() == 17) {
        for (int i = 0; i < getPlayer().getLevel(); ++i)
            trucks[i].CVEHICLE::Erase();
    } else if (player.getY() == 13) {
        for (int i = 0; i < getPlayer().getLevel(); ++i)
            cars[i].CVEHICLE::Erase();
    } else if (player.getY() == 9) {
        for (int i = 0; i < getPlayer().getLevel(); ++i)
            dinosaurs[i].CANIMAL::Erase();
    } else if (player.getY() == 5) {
        for (int i = 0; i < getPlayer().getLevel(); ++i)
            birds[i].CANIMAL::Erase();
    }
    GotoXY(getPlayer().getX(), getPlayer().getY());
    cout << "\\ /";
    GotoXY(getPlayer().getX(), getPlayer().getY() + 1);
    cout << " X ";
    GotoXY(getPlayer().getX(), getPlayer().getY() + 2);
    cout << "/"
         << " "
         << "\\";
    if (player.getX() > MAXWIDTH / 2) {
        CAMBULANCE ambulance(3, player.getY());
        for (int i = 1; i < 50; i++) {
            if (ambulance.mX + 5 >= player.getX()) {
                ambulance.Move(ambulance.mX, ambulance.mY);
            } else {
                ambulance.Move(ambulance.mX + 2, ambulance.mY);
            }
            ambulance.DrawRight();
            Sleep(50);
        }
        player.eraseOldPlayer();
        for (int i = 1; i < 50; i++) {
            if (ambulance.mX <= 5) {
                GotoXY(ambulance.mX, player.getY());
                cout << "    ";
                GotoXY(ambulance.mX, player.getY() + 1);
                cout << "    ";
                GotoXY(ambulance.mX, player.getY() + 2);
                cout << "    ";
            } else {
                ambulance.Move(ambulance.mX - 2, ambulance.mY);
                ambulance.DrawLeft();
            }
            Sleep(50);
        }
    } else if (player.getX() < MAXWIDTH / 2) {
        CAMBULANCE ambulance(MAXWIDTH - 4, player.getY());
        for (int i = 1; i < 50; i++) {
            if (ambulance.mX <= player.getX() + 5) {
                ambulance.Move(ambulance.mX, ambulance.mY);
            } else {
                ambulance.Move(ambulance.mX - 2, ambulance.mY);
            }
            ambulance.DrawLeft();
            Sleep(50);
        }
        player.eraseOldPlayer();
        for (int i = 0; i < 50; i++) {
            if (ambulance.mX + 5 >= MAXWIDTH) {
                GotoXY(ambulance.mX, player.getY());
                cout << "    ";
                GotoXY(ambulance.mX, player.getY() + 1);
                cout << "    ";
                GotoXY(ambulance.mX, player.getY() + 2);
                cout << "    ";
            } else {
                ambulance.Move(ambulance.mX + 2, ambulance.mY);
                ambulance.DrawRight();
            }
            Sleep(50);
        }
    }
}

bool CGAME::fileExist(const string& fileName)
{
    struct stat buffer;
    return stat(fileName.c_str(), &buffer) == 0;
}

void clearLine(int x, int y, int length)
{
    GotoXY(x, y);
    for (int i = 0; i < length; ++i) {
        cout << ' ';
    }
}

void CGAME::saveGame(mutex& mx)
{

    lock_guard<mutex> lock(mx);
    int boxWidth = 62, boxHeight = 4, startBoxX = 34, startBoxY = 32;

    //Draw the board
    GotoXY(startBoxX, startBoxY);
    for (int j = 0; j < boxWidth; ++j) {
        cout << '=';
    }
    GotoXY(startBoxX, startBoxY + 1);
    for (int j = 0; j < boxWidth; ++j) {
        if (j == 0 || j == boxWidth - 1)
            cout << '|';
        else
            cout << ' ';
    }
    GotoXY(startBoxX, startBoxY + 2);
    for (int j = 0; j < boxWidth; ++j) {
        if (j == 0 || j == boxWidth - 1)
            cout << '|';
        else
            cout << ' ';
    }

    GotoXY(startBoxX, startBoxY + 3);
    for (int j = 0; j < boxWidth; ++j) {
        cout << '=';
    }

    string line2 = "Enter the name of save file: ", fileName, buffer;
    buffer.reserve(10000);
    GotoXY(startBoxX + (boxWidth - line2.size()) / 2, startBoxY + 1);
    cout << line2;
    GotoXY(startBoxX + (boxWidth - line2.size()) / 2, startBoxY + 2);
    ShowConsoleCursor(true);

    while (true) {

        cin >> fileName;
        clearLine(startBoxX + (boxWidth - line2.size()) / 2, startBoxY + 2, line2.size());
        fileName = "\\saves" + fileName + ".bin";
        // if the file already exists
        if (fileExist(fileName)) {
            clearLine(startBoxX + (boxWidth - line2.size()) / 2, startBoxY + 1, line2.size());
            // write the line
            string line3 = "File already exist. Do you want to override? (y/n)";
            GotoXY(startBoxX + (boxWidth - line3.size()) / 2, startBoxY + 1);
            cout << line3;

            string ans;
            GotoXY(startBoxX + boxWidth / 2, startBoxY + 2);
            cin >> ans;
            if (ans != "y") {
                clearLine(startBoxX + 1, startBoxY + 1, boxWidth - 2);
                clearLine(startBoxX + 1, startBoxY + 2, boxWidth - 2);
                string line4 = "Enter another file name:";
                GotoXY(startBoxX + (boxWidth - line4.size()) / 2, startBoxY + 1);
                cout << line4;
                GotoXY(startBoxX + (boxWidth - line4.size()) / 2, startBoxY + 2);
                continue;
            }
        }
        ofstream fout(fileName, ios::binary);
        buffer.clear();

        // player
        buffer += to_string(getPlayer().getX());
        buffer.push_back(' ');
        buffer += to_string(getPlayer().getY());
        buffer += "\n";

        // level
        buffer += to_string(getPlayer().getLevel());
        buffer.push_back('\n');

        // trucks
        for (int i = 0; i < getPlayer().getLevel(); ++i) {
            if (i > 0)
                buffer.push_back(' ');
            buffer += to_string(trucks[i].mX);
            buffer.push_back(' ');
            buffer += to_string(trucks[i].mY);
        }
        buffer.push_back('\n');

        // cars
        for (int i = 0; i < getPlayer().getLevel(); ++i) {
            if (i > 0)
                buffer.push_back(' ');
            buffer += to_string(cars[i].mX);
            buffer.push_back(' ');
            buffer += to_string(cars[i].mY);
        }
        buffer.push_back('\n');

        // dinos
        for (int i = 0; i < getPlayer().getLevel(); ++i) {
            if (i > 0)
                buffer.push_back(' ');
            buffer += to_string(dinosaurs[i].mX);
            buffer.push_back(' ');
            buffer += to_string(dinosaurs[i].mY);
        }
        buffer.push_back('\n');

        // birds
        for (int i = 0; i < getPlayer().getLevel(); ++i) {
            if (i > 0)
                buffer.push_back(' ');
            buffer += to_string(birds[i].mX);
            buffer.push_back(' ');
            buffer += to_string(birds[i].mY);
        }

        fout.open(fileName, ios::binary);
        fout.write(buffer.c_str(), sizeof buffer);
        fout.close();
        ShowConsoleCursor(false);
        break;
    }
    for (int i = 0; i < 4; ++i) {
        clearLine(startBoxX, startBoxY + i, boxWidth);
    }
}

void CGAME::loadGame(mutex& mx)
{
    string path = "D:\\Nghia\\Hoc Tap Nghia\\Cross-The-Road\\GameProject\\saves", extension = ".bin";
	lock_guard<mutex> lock(mx);
	int boxWidth = 62, boxHeight = 4, startBoxX = 34, startBoxY = 32;

	//Draw the board
	GotoXY(startBoxX, startBoxY);
	for (int j = 0; j < boxWidth; ++j) {
		cout << '=';
	}
	GotoXY(startBoxX, startBoxY + 1);
	for (int j = 0; j < boxWidth; ++j) {
		if (j == 0 || j == boxWidth - 1)
			cout << '|';
		else
			cout << ' ';
	}
	GotoXY(startBoxX, startBoxY + 2);
	for (int j = 0; j < boxWidth; ++j) {
		if (j == 0 || j == boxWidth - 1)
			cout << '|';
		else
			cout << ' ';
	}

	GotoXY(startBoxX, startBoxY + 3);
	for (int j = 0; j < boxWidth; ++j) {
		cout << '=';
	}

	string line2 = "Enter the name of save file: ", fileName, buffer;
	buffer.reserve(10000);
	GotoXY(startBoxX + (boxWidth - line2.size()) / 2, startBoxY + 1);
	cout << line2;
	GotoXY(startBoxX + (boxWidth - line2.size()) / 2, startBoxY + 2);
	ShowConsoleCursor(true);
	while (true) {

		cin >> fileName;
		clearLine(startBoxX + (boxWidth - line2.size()) / 2, startBoxY + 2, line2.size());
		
		bool isNonexistent = false;

		char buffer[1000];
		ifstream fin(fileName, ios::binary);
		if (!fin.read(buffer, 1000)) {
			isNonexistent = true;
		}

		if (isNonexistent) {
			clearLine(startBoxX + (boxWidth - line2.size()) / 2, startBoxY + 1, line2.size());
			// write the line
			string line3 = "File do not exist. Do you want to abort? (y/n)";
			GotoXY(startBoxX + (boxWidth - line3.size()) / 2, startBoxY + 1);
			cout << line3;

			string ans;
			GotoXY(startBoxX + boxWidth / 2, startBoxY + 2);
			cin >> ans;
			if (ans != "y") {
				clearLine(startBoxX + 1, startBoxY + 1, boxWidth - 2);
				clearLine(startBoxX + 1, startBoxY + 2, boxWidth - 2);
				string line4 = "Enter another file name:";
				GotoXY(startBoxX + (boxWidth - line4.size()) / 2, startBoxY + 1);
				cout << line4;
				GotoXY(startBoxX + (boxWidth - line4.size()) / 2, startBoxY + 2);
				continue;
			}
			else break;
		}
		string tmp(buffer);
		stringstream ss(tmp);
		
		// player
		getPlayer().tempX = getPlayer().mX;
		getPlayer().tempY = getPlayer().mY;
		ss >> getPlayer().mX;
		ss >> getPlayer().mY;

		// level
		ss >> getPlayer().level;

		// trucks
		for (int i = 0; i < getPlayer().getLevel(); ++i) {
			trucks[i].prevX = trucks[i].mX;
			trucks[i].prevX = trucks[i].mY;
			ss >> trucks[i].mX >> trucks[i].mY;
		}

		// cars
		for (int i = 0; i < getPlayer().getLevel(); ++i) {
			cars[i].prevX = cars[i].mX;
			cars[i].prevX = cars[i].mY;
			ss >> cars[i].mX >> cars[i].mY;
		}

		// dinos
		for (int i = 0; i < getPlayer().getLevel(); ++i) {
			dinosaurs[i].prevX = dinosaurs[i].mX;
			dinosaurs[i].prevX = dinosaurs[i].mY;
			ss >> dinosaurs[i].mX >> dinosaurs[i].mY;
		}

		// birds
		for (int i = 0; i < getPlayer().getLevel(); ++i) {
			birds[i].prevX = birds[i].mX;
			birds[i].prevX = birds[i].mY;
			ss >> birds[i].mX >> birds[i].mY;
		}
	}


}

void CGAME::resetData()
{
    delete[] trucks;
    delete[] cars;
    delete[] dinosaurs;
    delete[] birds;
    trucks = new CTRUCK[10];
    cars = new CCAR[10];
    dinosaurs = new CDINOSAUR[10];
    birds = new CBIRD[10];
    vehicles = new CVEHICLE*[2];
    vehicles[0] = trucks;
    vehicles[1] = cars;
    animals = new CANIMAL*[2];
    animals[0] = dinosaurs;
    animals[1] = birds;

    for (int i = 0; i < getPlayer().getLevel(); ++i) {
        CTRUCK tmpTruck(min(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 110), 17);
        trucks[i] = tmpTruck;
        CCAR tmpCar(min(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 110), 13);
        cars[i] = tmpCar;
        CDINOSAUR tmpDino(min(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 110), 9);
        dinosaurs[i] = tmpDino;
        CBIRD tmpBird(min(3 + (i * MAXWIDTH) / getPlayer().getLevel() + (rand() % (MAXWIDTH / 10)), 110), 5);
        birds[i] = tmpBird;
    }
    player = CPEOPLE();
    carlane = CTRAFFICLIGHT();
    trucklane = CTRAFFICLIGHT();
}