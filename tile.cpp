#include "tile.h"

Tile::Tile(sf::Sprite sprite, int ID){
	m_sprite = sprite;
	m_ID = ID;
}

bool Tile::canCollide(){
	return m_collide;
}

sf::Sprite Tile::getSprite(){
	return m_sprite;
}

void Tile::setPosition(float x, float y){
	m_sprite.setPosition(x, y);
}

