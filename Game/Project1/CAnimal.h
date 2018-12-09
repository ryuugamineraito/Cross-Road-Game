#ifndef _CANIMAL_H_
#define _CANIMAL_H_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
class CAnimal
{
public:
	CAnimal(sf::RenderWindow* window);
	void update();
	void draw();
	sf::Vector2f getposition();
private:
	sf::RenderWindow * m_Window;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	float mX, mY;
};
#endif // !_CANIMAL_H_

