#include <fstream>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <boost/lexical_cast.hpp>

#include "map.h"
#include "spriteSheet.h"

const int TILESIZE = 64;

// map tiles spritesheet
const int MAP_TILE_TOPLEFT = 0;
const int MAP_TILE_TOPCENTER = 1;
const int MAP_TILE_TOPRIGHT = 2;

const int MAP_TILE_CENTERLEFT = 5;
const int MAP_TILE_CENTER = 6;
const int MAP_TILE_CENTERRIGHT = 7;

const int MAP_TILE_BOTTOMLEFT = 10;
const int MAP_TILE_BOTTOMCENTER = 11;
const int MAP_TILE_BOTTOMRIGHT = 12;

void Map::updateTiles(){
	for(int i=0; i<tiles.size(); ++i){
		// check tile above current tile
		//if( tiles[i-m_width].get ==  )
		// top edge
		// upper right corner
		// left edge
		// no edge
		// right edge
		// bottom left corner
		// bottom edge
		// bottom right corner
	}
}

Map::Map(sf::Sprite mapTiles) : m_spriteSheet(mapTiles, TILESIZE){

	for(int y=0; y<3; y++){ //load all sprites from spritesheet
		for(int x=0; x<3; x++){
			m_tileSheet.push_back( Tile(m_spriteSheet.getTile(x, y), 0) );
		}
	}
}

bool Map::openFile( std::string filename ){
	std::ifstream iFile( filename.c_str() );
	
	std::string mapData;
	
	std::string tmp;
	int lineNum = 0; //parse map file
	while( iFile.good() ){
		iFile >> tmp;
		//first line is the width,height
		if(lineNum == 0){
			std::string curNum;
			
			for(int i=0; i<tmp.size(); i++){
				if(tmp[i] == ','){
					m_width = boost::lexical_cast<int>(curNum);
					curNum = "";
					//hop over the comma
					i++;
				}
					curNum += tmp[i];
			}
			//whats left from the above loop is the height
			m_height = boost::lexical_cast<int>(curNum);
		}else if(lineNum == 1){ //map data should be on line2 or beyond;
			std::string curNum;
			int x=0, y=0;//number between commas
			
			for(int i=0; i<tmp.size(); i++){
				if(tmp[i] == ','){
					int tileNum = boost::lexical_cast<int>(curNum);
					
					//move tile to proper position
					m_tileSheet[tileNum].setPosition(x, y);
					tiles.push_back( m_tileSheet[1] );
					
					
					curNum = "";
					x += 64;
					if(x >= m_width*64){
						y += 64;
						x = 0;
					}
					//hop over the comma
					++i;
				}
				
				curNum += tmp[i];
			}
		}
		++lineNum;
	}
	
	updateTiles();
}

void Map::render(sf::RenderWindow *App){
	for(int i=0; i<tiles.size(); ++i){
		App->draw(tiles[i].getSprite());
	}
	

}

