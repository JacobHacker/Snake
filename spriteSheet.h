#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <SFML/Graphics.hpp>

class SpriteSheet{
	public:
	SpriteSheet(sf::Sprite sprite, int tileSize);
	
	void setSprite();
	
	sf::Sprite getTile(int row, int col);
	
	private:
	sf::Sprite m_sprite;
	int m_tileSize;
};

#endif
