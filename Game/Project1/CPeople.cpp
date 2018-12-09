#include "CPeople.h"

CPeople::CPeople(sf::RenderWindow *window)
{
	this->m_Window = window;
	this->m_texture.loadFromFile("D:\\CS202\\Game\\Debug\\Media\\cpeople.png");
	this->m_texture.setSmooth(true);
	this->m_sprite.setTexture(this->m_texture);
	this->m_sprite.scale(1.1, 1.1);
	this->mX = (float)this->m_texture.getSize().x / 2;
	this->mY = (float)this->m_texture.getSize().y / 2;
	this->m_sprite.setOrigin( mX,mY);
	this->m_sprite.setPosition(400, 300);
}
void CPeople::update()
{
	sf::Vector2f cur_pos = this->m_sprite.getPosition();
	//boundary :)). Need to fix
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		cur_pos.y -= 5.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		cur_pos.x -= 5.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		cur_pos.y += 5.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		cur_pos.x += 5.0f;
	}
	if (cur_pos.x <= 0.0f+ mX)
		cur_pos.x = 0.0f+ mX;
	if (cur_pos.x >= 800.0f - mX)
		cur_pos.x = 800.0f- mX;
	if (cur_pos.y <= 0.0f+ mY)
		cur_pos.y = 0.0f+ mY;
	if (cur_pos.y >= 600.0f - mY)
		cur_pos.y = 600.0f - mY;
	this->m_sprite.setPosition(cur_pos);
}
void CPeople::draw()
{
	this->m_Window->draw(this->m_sprite);
}
sf::Vector2f CPeople::getposition()
{
	return this->m_sprite.getPosition();
}