#include <iostream>
#include <Windows.h>
#include "CGame.h"
#include <conio.h>
#include <mmsystem.h>
using namespace std;
char MOVING;
CGame cg;

bool IS_RUNNING = true;
void SubThread();
void FixConsoleWindow();
void resizeConsole(int width, int height);
void exitGame(thread* t);
void main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	int temp;
	FixConsoleWindow();
	resizeConsole(800, 600);
	cg.startGame();
	thread t1(SubThread);
	
	while (1)
	{
		
		temp = toupper(_getch());
		if (!cg.getPeople()->isDead())
		{
			if (temp == 27) {
				cg.exitGame(&t1,IS_RUNNING);
				return;

			}
		else if (temp == 'P') {
			cg.pauseGame(t1.native_handle());

			}
		else if (temp == 'T')
		{
			wcout.flush();//still need some fix for better
			system("cls");
			cg.pauseGame(t1.native_handle());
			cg.loadGame();
			cg.resumeGame(t1.native_handle());
		}
		else if (temp == 'L')
		{
			wcout.flush();//still need some fix for better
			system("cls");
			cg.pauseGame(t1.native_handle());
			cg.saveGame();
			cg.resumeGame(t1.native_handle());
		}
			else {
				cg.resumeGame(t1.native_handle());
				MOVING = temp; //update move

			}
		}
		else
		{
			if (temp == 'Y') cg.resetGame(0);
			else {
				cg.exitGame(&t1, IS_RUNNING);
				return;

			}
		}
	}
}
void SubThread()
{
	PlaySound(TEXT("Street SOUND EFFECTS - Street Ambience Hintergrundgeräusche Straße.wav"), NULL, SND_ASYNC);
	
	while (IS_RUNNING) {
		cg.drawMap();
		if (!cg.getPeople()->isDead()) //if still alive
		{
			cg.updatePosPeople(MOVING);//update move from main
		//}
			MOVING = ' ';// block and wait for user hit key
			cg.updatePosVehicle();//update pos vehicle
			cg.updatePosAnimal(); //update pos animal
			cg.drawGame();
		}
		if (cg.getPeople()->isImpact(cg.getVehicle()) ||
			cg.getPeople()->isImpact(cg.getAnimal()))
		{
			system("cls");
			wcout << "\n\n\n\t\t\tYou lose" << endl;
			wcout << "\t\t\tPress y if you want to play again." << endl;

		}
		if (cg.getPeople()->isFinish()) {
			cg.levelup(IS_RUNNING);

		}
		Sleep(100);
	}
}
void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width,height, TRUE);
}
void exitGame(thread* t) {
	ClearScreen();
	IS_RUNNING = false;
	t->join();
}
