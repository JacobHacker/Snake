#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "map.h"
#include "tile.h"

int main(){
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Snake");
	
	sf::Image mapTiles;
	if( !mapTiles.LoadFromFile("spritesheet.png") ){
		//exit
	}
	
	
	sf::Sprite spr(mapTiles);
	Map map( spr );
	map.openFile("map/level1.map");
	
	while( App.IsOpened() ){
		sf::Event event;
		while( App.GetEvent(event) ){
			if(event.Type == sf::Event::Closed){
				App.Close();
			}
		}
		
		App.Clear( sf::Color(0, 0, 0) );
		map.render(&App);
		App.Display();
	}
	return 0;
}
