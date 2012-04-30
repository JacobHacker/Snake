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

	void pollEvent(sf::Event *event);
	void logic();
	void render(sf::RenderWindow *app);

	private:
	int m_direction;
	sf::Sprite m_sprite;

};

#endif
