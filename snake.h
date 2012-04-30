#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>

const int DIRECT_UP = 0;
const int DIRECT_DOWN = 1;
const int DIRECT_LEFT = 2;
const int DIRECT_RIGHT = 3;

class Snake{
	public:
	void setSprite(sf::Sprite sprite);
	sf::Sprite getSprite();

	void render();
	void getEvents();
	void logic();
	
	private:
	int m_direction;
	sf::Sprite m_sprite;

};

#endif
