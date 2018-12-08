#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include <Mmsystem.h>
#include <mciapi.h>
#pragma comment(lib, "Winmm.lib")
using namespace std;
const int MAXWIDTH = 130;
const int MAXHEIGHT = 25;
inline void FixConsoleWindow() 
{
	 HWND consoleWindow = GetConsoleWindow();
	 long style = GetWindowLong(consoleWindow, GWL_STYLE);
	 style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	 SetWindowLong(consoleWindow, GWL_STYLE, style);
}

inline void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

inline void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void SubThread();