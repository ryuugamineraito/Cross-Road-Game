#ifndef _CPEOPLE_H_
#define _CPEOPLE_H_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
class CPeople
{
public:
	CPeople(sf::RenderWindow* window);
	void update();
	void draw();
	sf::Vector2f getposition();
	
/*	CPeople();
	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);
	bool isImpact(const CVehicle*&);
	bool isImpact(const CAnimal*&);
	bool isFinish();
	bool isDead();*/
private:
	sf::RenderWindow * m_Window;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	
	float mX, mY;
	//bool mState;
};
#endif // !_CPEOPLE_H_

