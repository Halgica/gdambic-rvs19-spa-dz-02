#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <SFML/Graphics.hpp>
using namespace std;

class game_of_life {
private:
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 40;
	bool _generacija[REDAKA][STUPACA];
	bool _sljedeca_generacija[REDAKA][STUPACA];
	//bool slucajna_vrijednost();
	bool celija_zauzeta(int i, int j);
	void provjera_okolo(int i, int j);
	void pravila(int brojac, int i, int j);

	sf::RenderWindow* window;

public:
	game_of_life(sf::RenderWindow* window);
	void iscrtaj();
	void inicijalizacija();
	void sljedeca_generacija();
	/*void test();*/
};

#endif
