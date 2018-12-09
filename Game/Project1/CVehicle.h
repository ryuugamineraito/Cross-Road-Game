#ifndef _CVEHICLE_H_
#define _CVHICLE_H_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <time.h>
class CVehicle
{
public:
	//CVehicle(sf::RenderWindow* window);
	virtual void update()=0;
	void draw();
	sf::Vector2f getposition();
	
protected:
	sf::RenderWindow * m_Window;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	float mX, mY;
};
#endif // !_CVEHICLE_H_

