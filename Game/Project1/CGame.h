#ifndef _CGAME_H_
#define _CGAME_H_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <vector>
#include "CPeople.h"
#include "CAnimal.h"
#include "CCar.h"
using namespace std;
class CGame
{
public:
	CGame(sf::RenderWindow* window);
	void update();
	void draw();
private:
	sf::RenderWindow*m_Window;
	sf::Clock m_clock;
	sf::Time m_time;
	CPeople * player;
	vector<CVehicle*> vehicles;
	vector<CAnimal*> animals;

};
#endif // !_CGAME_H_

