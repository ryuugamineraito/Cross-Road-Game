#ifndef _CGAME_H_
#define _CGAME_H_
#include <iostream>
#include <Windows.h>
#include <vector>
#include "CPeople.h"
#include <thread>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <fstream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <sftools\Chronometer.hpp>
using namespace std;

class CGame
{
	int lv;
	wchar_t map[50][70];
	vector<CVehicle*> vehicles;
	vector<CAnimal*> animals;
	CPeople* cn;
	sf::Time m_time;
	sftools::Chronometer chrono;
	CTrafficLight CTLtruck, CTLcar;
public:
	CGame(); //Chuẩn bị dữ liệu cho tất cả các đối tượng
	void drawGame(); //Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
	void drawPeople();
	void clearMap();
	void drawMap();
	void drawTruck(CVehicle* obj);
	void drawCar(CVehicle *obj);
	void drawBird(CAnimal*obj);
	void drawDinosaur(CAnimal*obj);
	void levelup(bool & is_running);
	void menu();
	~CGame(); // Hủy tài nguyên đã cấp phát
	CPeople* getPeople();
	vector<CVehicle*> getVehicle();
	vector<CAnimal*> getAnimal(); 
	void resetGame(int cmd); // 0-reset game 1-reset to level up Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
	void exitGame(thread* t,bool& is_running ); // Thực hiện thoát Thread
	void startGame(); // Thực hiện bắt đầu vào trò chơi
	void loadGame(); // Thực hiện tải lại trò chơi đã lưu
	void saveGame(); // Thực hiện lưu lại dữ liệu trò chơi
	void pauseGame(HANDLE pause); // Tạm dừng Thread
	void resumeGame(HANDLE resume); //Quay lai Thread
	void updatePosPeople(const char& key); //Thực hiện điều khiển di chuyển của CPEOPLE
	void updatePosVehicle(); //Thực hiện cho CTRUCK & CCAR di chuyển
	void updatePosAnimal();//Thực hiện cho CDINAUSOR & CBIRD di chuyển
	

};
void textcolor(int x);
void GotoXY(int x, int y);
void ClearScreen();
void createTitle();
#endif // !_CGAME_H_

