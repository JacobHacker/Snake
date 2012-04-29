#include "spriteSheet.h"

SpriteSheet::SpriteSheet(sf::Sprite sprite, int tileSize){
	m_tileSize = tileSize;
	m_sprite = sprite;
}

sf::Sprite SpriteSheet::getTile(int row, int col){
	m_sprite.SetSubRect(sf::IntRect(row*m_tileSize, col*m_tileSize, (row+1)*m_tileSize, (col+1)*m_tileSize));
	
	return m_sprite;
}

