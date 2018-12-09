#include "CCar.h"
#include "CCar.h"
CCar::CCar(sf::RenderWindow* window)
{
	m_Window = window;
	m_texture.loadFromFile(image);
	m_texture.setSmooth(true);
	m_sprite.setTexture(m_texture);
	m_sprite.scale(1.2, 1.2);
	mX = (float)m_texture.getSize().x / 2;
	mY = (float)m_texture.getSize().y / 2;
	m_sprite.setOrigin(mX, mY);
	//It will be configured later
	//float x = std::rand() % 250 + 25;
	m_sprite.setPosition(100, 160);
}
void CCar::update()
{
	m_sprite.move(2, 0);
}
/*void CCar::draw()
{

}*/
