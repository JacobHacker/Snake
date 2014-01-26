#ifndef MAP_H
#define MAP_H

#include <vector>
#include <SFML/Graphics.hpp>

#include "tile.h"
#include "spriteSheet.h"

const int TILE_NONE = 0;
const int TILE_DIRT = 1;
const int TILE_GRASS = 2;

class Map{
	public:
	Map(sf::Sprite mapTiles);
	bool openFile(std::string filename);
	void render(sf::RenderWindow *App);
	
	private:
	int m_width, m_height;
	
	void updateTiles();
	
	sf::Sprite m_tilesImage;
	std::vector<Tile> tiles;
	std::vector<Tile> m_tileSheet;
	SpriteSheet m_spriteSheet;
};

#endif
