#include "CVehicle.h"
/*CVehicle::CVehicle(sf::RenderWindow *window)
{
	m_Window = window;
	
}*/
void CVehicle::draw()
{
	this->m_Window->draw(this->m_sprite);
}
sf::Vector2f CVehicle::getposition()
{
	return this->m_sprite.getPosition();
}
