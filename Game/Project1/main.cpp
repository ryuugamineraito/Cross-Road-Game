#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "CGame.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!",sf::Style::Close);
	window.setFramerateLimit(60);
	std::srand(time(NULL));
	CGame game(&window);
	bool checkChooseWindows = true;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::LostFocus)
				checkChooseWindows = false;
			if (event.type == sf::Event::GainedFocus)
				checkChooseWindows = true;
		}
		if (checkChooseWindows)
		{
			window.clear();
			game.update();
			game.draw();
			window.display();
		}
	}
	return 0;
}