#ifndef TILE_H
#define TILE_H

#include <vector>
#include <SFML/Graphics.hpp>

class Tile{
	public:
	Tile(sf::Sprite sprite, int ID);
	bool canCollide();
	
	void setSprite(sf::Sprite sprite);
	sf::Sprite getSprite();
	
	void setPosition(float x, float y);
	
	void setID(int ID){ m_ID = ID; }
	int getID(){ return m_ID; }
	
	private:
	bool m_collide;
	sf::Sprite m_sprite;
	int m_ID;
};

#endif
