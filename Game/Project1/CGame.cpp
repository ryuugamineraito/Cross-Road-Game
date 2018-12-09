#include "CGame.h"
//float x = 600;
CGame::CGame(sf::RenderWindow *window)
{
	this->m_Window = window;
	player = new CPeople(this->m_Window);
	CVehicle*p = new CTruck(this->m_Window);
	vehicles.push_back(p);
	p = new CCar(this->m_Window);
	vehicles.push_back(p);
}
void CGame::update()
{
	this->player->update();
	if (this->vehicles.size() > 0)
	{
		for (auto iter = vehicles.begin(); iter != vehicles.end(); ++iter)
		{
			(*iter)->update();
		}
		//This also will be configured later
		if (this->vehicles[0]->getposition().x <= 100||this->vehicles[0]->getposition().x>700)
			this->vehicles.erase(this->vehicles.begin());
			//this->vehicles.pop_front
	}
	CVehicle*p;
	this->m_time = this->m_clock.getElapsedTime();
	
	if (this->m_time.asSeconds() > 1)// should be considered about random further
	{
		p = new CTruck(this->m_Window);
		vehicles.push_back(p);
		p = new CCar(this->m_Window);
		vehicles.push_back(p);
		this->m_clock.restart();
		
	//	x = std::rand() % 500 + 201;
	}
}
void CGame::draw()
{
	this->player->draw();
	if (this->vehicles.size() > 0)
	{
		for (vector<CVehicle*>::iterator iter = vehicles.begin(); iter != vehicles.end(); ++iter)
		{
			(*iter)->draw();
		}
	}
}