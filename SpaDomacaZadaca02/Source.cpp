#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include "Game_of_life.h"

using namespace std;
using namespace chrono;
using namespace chrono_literals;


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game of Life");
	window.setFramerateLimit(60);
	game_of_life game(&window);
	game.inicijalizacija();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		this_thread::sleep_for(1s);
		window.clear();
		game.iscrtaj();
		game.sljedeca_generacija();
		window.display();
	}

	return 0;
}